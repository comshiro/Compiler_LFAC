%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include "symtable.h"
#include <fstream>
using namespace std;
extern int yylex();
extern int yylineno;
void yyerror(const char* s);

SymTable globalScope("global");
SymTable* currentScope = &globalScope;

void enterScope(const std::string& name) {
    SymTable* newScope = new SymTable(name, scopeStack.empty() ? &globalScope : scopeStack.top());
    scopeStack.push(newScope);
}

void enterScope(const std::string& name) {
    SymTable* newScope = new SymTable(name, currentScope);
    currentScope = newScope;
}

void exitScope() {
    if (currentScope->parent != nullptr) {
        currentScope = currentScope->parent;
    }
}

bool lookupVariableInScope(SymTable* scope, const std::string& name, VariableInfo*& result) {
    if (scope == nullptr) return false;
    result = scope->lookupVariable(name);
    if (result != nullptr) return true;
    for (SymTable* child : scope->children) {
        if (lookupVariableInScope(child, name, result)) return true;
    }
    return false;
}

bool lookupVariable(const std::string& name, VariableInfo*& result) {
    return lookupVariableInScope(&globalScope, name, result);
}

bool isVariableInCurrentScope(const std::string& name) {
    return currentScope->isVariableInCurrentScope(name);
}

bool areVariablesInSameScope(const std::string& name1, const std::string& name2) {
    return currentScope->areVariablesInSameScope(name1, name2);
}

bool is_int(int value) {
    return true;
}

bool compare_values(int left, int right, bool op) {
    return true; 
}

%}

%union {
    char* id_var;
    char* id_func;
    char* id_class;
    char* type_var;
    int int_val;
    float float_val;
    char char_val;
    char* string_val;
    bool bool_val;
    void* generic_val;
}

%token STOP RETURN 
%token CLASS PUBLIC PROTECTED PRIVATE STATIC
%token<type_var> INT FLOAT CHAR STRING BOOL VOID
%token<id_var> I_VAR_ID F_VAR_ID B_VAR_ID S_VAR_ID C_VAR_ID
%token<id_class> CLASS_ID
%token<id_func> FUNCTION_ID START
%token<int_val> INT_VALUE
%token<float_val> FLOAT_VALUE
%token<char_val> CHAR_VALUE
%token<string_val> STRING_VALUE
%token<bool_val> BOOL_VALUE
%token IF WHILE
%token ASSIGN AND OR NOT
%token EQUAL NOT_EQUAL LESS LESS_EQUAL GREATER GREATER_EQUAL
%token PRINT TYPEOF

%left OR
%left AND
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL
%left '+' '-'
%left '*' '/' '%'
%left NOT
%left '{' '}' '[' ']' '(' ')'

%type<id_var> param 
%type<id_var> param_list 
%type<int_val> aexp 
%type<bool_val> bexp
%type <type_var> type      
%type <id_var> VAR_ID       
%type <id_var> var_decl     
%type <generic_val> statement 
%type <generic_val> seq
%type <generic_val> assignment
%type <generic_val> condition
%type <generic_val> if_statement
%type <generic_val> loop
%type <generic_val> return_statement
%type <generic_val> function_call
%type <generic_val> print_statement
%type <generic_val> TYPEOF_statement
%type <generic_val> expression
%type <bool_val> comparison_op
%type <generic_val> optional_param_list
%type <generic_val> func_decl

%start program

%%
program:    
    global_section main_body
    ;

global_section:
    | classes_section
    | global_var
    | global_func
    | classes_section global_var
    | classes_section global_func
    | global_var global_func
    | classes_section global_var global_func
    ;

main_body: 
    START  { enterScope("main"); } seq STOP { exitScope(); }
    ;

seq: 
    statement
    | seq statement
    ;

statement: 
    assignment { $$ = $1; } 
    | condition { $$ = $1; } 
    | loop { $$ = $1; } 
    | return_statement { $$ = $1; } 
    | function_call { $$ = $1; } 
    | print_statement { $$ = $1; } 
    | TYPEOF_statement { $$ = $1; } 
    | var_decl { $$ = $1; }
    | func_decl { $$ = $1; }
    ;

assignment: 
    VAR_ID ASSIGN expression ';'     
    {
        printf("Assignment: %s = expression\n", $1);
        
        VariableInfo* var = nullptr;
        if (!lookupVariable($1, var)) {
            yyerror("Variable not declared");
        } else {
            if (var->type != $3->type) 
                char error_msg[100];
                sprintf(error_msg, "Type mismatch in assignment. Expected %s but got %s", 
                    var->type.c_str(), $3->type.c_str());
                yyerror(error_msg);
            } else {
                var->value = $3->value;
            }
        }          
    | VAR_ID '[' aexp ']' ASSIGN expression ';'
     { 
        VariableInfo* var = nullptr;
        if (!lookupVariable($1, var)) {
            yyerror("Array not declared");
        } else {
            if ($3 < 0) {
                yyerror("Array index cannot be negative");
        } else {
            if (var->type != $6->type) {
                char error_msg[100];
                sprintf(error_msg, "Type mismatch in array assignment. Expected %s but got %s", 
                    var->type.c_str(), $6->type.c_str());
                yyerror(error_msg);
            } else {
                var->value = $6->value;
                printf("Array Assignment: %s[%d] = %s\n", $1, $3, var->value.c_str());
            }
        }
    }
}
    | CLASS_ID '.' VAR_ID ASSIGN expression ';'
    { 
    ClassInfo* cls = nullptr;
    if (!lookupClass($1, cls)) {
        yyerror("Class not declared");
    } else {
        if (cls->memberVariables.find($3) == cls->memberVariables.end()) {
            yyerror("Class member not declared");
        } else {
            VariableInfo& memberVar = cls->memberVariables[$3];
            if (memberVar.type != $5->type) {
                char error_msg[100];
                sprintf(error_msg, "Type mismatch in class member assignment. Expected %s but got %s", 
                    memberVar.type.c_str(), $5->type.c_str());
                yyerror(error_msg);
            } else {
                memberVar.value = $5->value;
                printf("Class Assignment: %s.%s = %s\n", $1, $3, memberVar.value.c_str());
            }
        }
    }
}
;

condition:
    if_statement
    ;

if_statement:
    IF '(' bexp ')' { enterScope("if");} '{' seq '}'
     {
        printf("IF statement");
        if ($3) {
            $$ = $8;  
        }
        exitScope();
    }
    ;

loop:
    WHILE '(' bexp ')' {enterScope("while");} '{' seq '}' {
        if ($3) {
            printf("While condition is true\n");
            $$ = $7; 
        } else {
            printf("While condition is false, skipping loop body\n");
            $$ = NULL;  
        }
        exitScope();
    }
    ;

return_statement:
    RETURN expression ';' 
    {
        SymTable* scope = currentScope;
        while (scope != nullptr && scope->name != "main" && !scope->isFunction) {
            scope = scope->parent;
        }
        
        if (scope == nullptr || scope->name == "main") {
            yyerror("Return statement outside of function");
        } else {
            if (scope->returnType != $2->type) {
                char error_msg[100];
                sprintf(error_msg, "Return type mismatch. Expected %s but got %s", 
                    scope->returnType.c_str(), $2->type.c_str());
                yyerror(error_msg);
            }
            $$ = $2;
        }
    }
    ;

function_call:
    FUNCTION_ID '(' optional_param_list ')' ';'  
    {
        FunctionInfo* func = nullptr;
        if (!lookupFunction($1, func)) {
            yyerror("Function not declared");
        } else {
            if (func->paramTypes.size() != $3->paramCount) {
                char error_msg[100];
                sprintf(error_msg, "Function %s expects %lu parameters but got %d", 
                    $1, func->paramTypes.size(), $3->paramCount);
                yyerror(error_msg);
            } else {
                for (int i = 0; i < $3->paramCount; i++) {
                    if (func->paramTypes[i] != $3->paramTypes[i]) {
                        char error_msg[100];
                        sprintf(error_msg, "Parameter %d type mismatch in function %s", i+1, $1);
                        yyerror(error_msg);
                    }
                }
                $$ = func->returnType;
            }
        }
    }
    ;
print_statement:
    PRINT '(' expression ')' ';'{printf("print <expression>\n"); }
    ;

TYPEOF_statement:
    TYPEOF '(' expression ')' ';' {
        printf("type of <expression>");
        if ($3 == nullptr) {
            yyerror("Cannot determine type of null expression");
        } else {
            printf("Type of expression: %s\n", $3->type.c_str());
            $$ = $3->type;
        }
    }
    ;

expression: 
    function_call { $$ = $1; }     
    | aexp { $$ = (void*)$1; }     
    | CHAR_VALUE { $$ = (void*)$1; }     
    | STRING_VALUE { $$ = $1; }     
    | bexp { $$ = (void*)$1; }     
    ;

aexp: 
    INT_VALUE {$$ = $1; }
    | FLOAT_VALUE {$$ = $1; }
    | I_VAR_ID { lookup($1); }
    | F_VAR_ID { lookup($1); }
    | aexp '+' aexp 
    {
          if (is_int($1) && is_int($3)) {
              $$ = $1 + $3; 
          } else {
              $$ = (float)$1 + (float)$3;  
          }
      }

    | aexp '-' aexp
    {
          if (is_int($1) && is_int($3)) {
              $$ = $1 - $3;  
          } else {
              $$ = (float)$1 - (float)$3;  
          }
      }
    | aexp '*' aexp
    {
          if (is_int($1) && is_int($3)) {
              $$ = $1 * $3; 
          } else {
              $$ = (float)$1 * (float)$3; 
          }
      }
    | aexp '/' aexp
    {
          if (is_int($1) && is_int($3)) {
              $$ = $1 / $3; 
          } else {
              $$ = (float)$1 / (float)$3; 
          }
      }
    | '(' aexp ')' { $$ = $2; }
    | aexp '%' aexp {
        if (is_int($1) && is_int($3)) 
              $$ = $1 % $3;  }
    | '-' aexp {$$ = -$2;}
    ;

bexp: 
    BOOL_VALUE { $$ = (void*)$1; } 
    | B_VAR_ID { $$ = lookup($1); }
    | aexp comparison_op aexp
        {$$ = compare_values($1, $3, $2);}
    | NOT bexp { $$ = !($2); }  
    | bexp AND bexp { $$ = $1 && $3; }   
    | bexp OR bexp { $$ = $1 || $3; } 
    | '(' bexp ')' { $$ = $2; }   
    ;

comparison_op:
      LESS { $$ = "<"; }
    | GREATER { $$ = ">"; }
    | EQUAL { $$ = "="; }
    | NOT_EQUAL { $$ = "!="; }
    | GREATER_EQUAL { $$ = ">="; }
    | LESS_EQUAL { $$ = "<="; }
    ;

var_decl: 
    type VAR_ID ';'    { 
        printf("Declared variable %s of type %s\n", $2, $1); 
        $$ = $2; 
    }       
    | type VAR_ID ASSIGN expression ';' { 
        printf("Declared variable %s of type %s and assigned value\n", $2, $1);
        $$ = $2; 
    }
    | type VAR_ID '[' aexp ']' ';' { 
        printf("Declared array %s of type %s with size %d\n", $2, $1, $4); 
        $$ = $2; 
    }
    ;

func_decl:
    type FUNCTION_ID '(' optional_param_list ')' '{' seq '}'
    {printf("Function call: %s with <parameters>\n ", $2); }
    ;

optional_param_list:
    /* empty */  { $$ = NULL; }   
    | param_list  { $$ = $1; }   
    ; 

param_list:
    param { $$ = $1; }   
    | param_list ',' param { $$ = $1; }   
    ;

param:
    type VAR_ID {  printf("Parameter: %s %s\n", $1, $2);}
    | type VAR_ID '[' ']' {printf("Array Parameter: %s %s\n", $1, $2);}
    ;

type: 
    INT 
    | FLOAT 
    | CHAR 
    | STRING 
    | BOOL 
    ;

classes_section:
    class
    | classes_section class
    ;

class: 
    CLASS CLASS_ID '{' '}'
    | access_modifier CLASS CLASS_ID '{' class_body '}'
    ;

access_modifier:
    PRIVATE
    | PUBLIC
    | PROTECTED
    ;

class_body: 
    | class_body_item
    ;

class_body_item:
    var_decl
    | func_decl
    | class_body_item var_decl
    | class_body_item func_decl
    ;

global_var:
    var_decl
    | global_var var_decl
    ;

global_func:
    func_decl
    | global_func func_decl
    ;

VAR_ID:
    I_VAR_ID
    | F_VAR_ID
    | B_VAR_ID
    | S_VAR_ID
    | C_VAR_ID
    ;

%%

void yyerror(const char* s) {
    cout << "error: " << s << " at line: " << yylineno << endl;
}

int main() {
    yyparse();
    return 0;
}
