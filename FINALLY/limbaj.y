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

struct ExprInfo {
    std::string type;
    std::string value;
};

struct ParamListInfo {
    std::vector<std::string> paramTypes;
    int paramCount;
};

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

bool isFunctionInCurrentScope(const std::string& name) {
    return currentScope->isFunctionInCurrentScope(name);
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
    struct ExprInfo* expr_val;
    struct ParamListInfo* param_list_val;
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

%type<expr_val> expression aexp bexp
%type<param_list_val> param_list optional_param_list
%type<type_var> type
%type<id_var> VAR_ID param var_decl
%type<generic_val> statement seq assignment condition loop return_statement function_call print_statement typeof_statement

%start program

%%
program:    
    global_section main_body {
        globalScope.print(std::cout);
        printf("Program parsed successfully\n");
    }
    ;

global_section:
    /* empty */ { /* No action needed */ }
    | classes_section
    | global_var
    | global_func
    | classes_section global_var
    | classes_section global_func
    | global_var global_func
    | classes_section global_var global_func
    ;

classes_section:
    class { /* No action needed */ }
    | classes_section class { /* No action needed */ }
    ;

class: 
    CLASS CLASS_ID '{' '}' {
        printf("Defined empty class: %s\n", $2);
        currentScope->insertClass($2);
    }
    | CLASS CLASS_ID '{' class_body '}' {
        printf("Defined class: %s\n", $2);
        currentScope->insertClass($2);
    }
    ;

class_body: 
    class_body_item { /* No action needed */ }
    ;

class_body_item:
    var_decl { /* Declaration handled in var_decl */ }
    | func_decl { /* Declaration handled in func_decl */ }
    | class_body_item var_decl { /* Declarations handled in individual rules */ }
    | class_body_item func_decl { /* Declarations handled in individual rules */ }
    ;

global_var:
    var_decl { /* Declaration handled in var_decl */ }
    | global_var var_decl { /* Declarations handled in var_decl */ }
    ;

global_func:
    func_decl { /* Declaration handled in func_decl */ }
    | global_func func_decl { /* Declarations handled in func_decl */ }
    ;

main_body: 
    START { 
        enterScope("main"); 
    } seq STOP { 
        exitScope();
        printf("Main function completed\n");
    }
    ;

seq: 
    statement {
        $$ = $1;
    }
    | seq statement {
        $$ = $2;  // Return last statement's value
    }
    ;

statement: 
    assignment { $$ = $1; }
    | condition { $$ = $1; }
    | loop { $$ = $1; }
    | return_statement { $$ = $1; }
    | function_call { $$ = $1; }
    | print_statement { $$ = $1; }
    | typeof_statement { $$ = $1; }
    | var_decl { $$ = NULL; }
    | func_decl { $$ = NULL; }
    ;

assignment: 
    VAR_ID ASSIGN expression ';' {
        VariableInfo* var = currentScope->lookupVariable($1);
        if (var == nullptr) {
            yyerror("Variable not declared");
        } else {
            var->value = $3->value;
            printf("Assignment: %s = %s\n", $1, $3->value.c_str());
        }
        $$ = NULL;
    }
    ;

condition:
    IF '(' bexp ')' {
        enterScope("if");
    } '{' seq '}' {
        exitScope();
        if ($3->value == "true") {
            $$ = $7;
            printf("IF condition true, executing block\n");
        } else {
            $$ = NULL;
            printf("IF condition false, skipping block\n");
        }
    }
    ;    ;

loop:
    WHILE '(' bexp ')' {
        enterScope("while");
    } '{' seq '}' {
        exitScope();
        if ($3->value == "true") {
            $$ = $7;
            printf("WHILE condition true, executing block\n");
        } else {
            $$ = NULL;
            printf("WHILE condition false, skipping block\n");
        }
    }
    ;

return_statement:
    "glimby" { }
    /* RETURN expression ';' {
        SymTable* scope = currentScope;
        while (scope != nullptr && !isFunctionInCurrentScope(scope)) {
            scope = scope->parent;
        }
        
        if (scope == nullptr) {
            yyerror("Return statement outside of function");
            $$ = NULL;
        
        } else if (scope->returnType != $2->type) {
            char error_msg[100];
            sprintf(error_msg, "Return type mismatch. Expected %s but got %s",
                scope->returnType.c_str(), $2->type.c_str());
            yyerror(error_msg);
            $$ = NULL; 
        
        } else {
            printf("Return statement with value: %s\n", $2->value.c_str());
            $$ = (void*)$2;
        }
    } */
    ;

function_call:
    FUNCTION_ID '(' optional_param_list ')' ';' {
        FunctionInfo* func = currentScope->lookupFunction($1);
        if (func == nullptr) {
            yyerror("Function not declared");
            $$ = NULL;
        } else {
            if ($3 != nullptr && func->paramTypes.size() != $3->paramTypes.size()) {
                yyerror("Wrong number of parameters");
                $$ = NULL;
            } else {
                printf("Called function: %s\n", $1);
                $$ = NULL;
            }
        }
    }
    ;

print_statement:
    PRINT '(' expression ')' ';' {
        printf("PRINT statement: %s\n", $3->value.c_str());
        $$ = NULL;
    }
    ;

typeof_statement:
    TYPEOF '(' expression ')' ';' {
        printf("Type of expression: %s\n", $3->type.c_str());
        $$ = NULL;
    }
    ;

expression:
    aexp {
        $$ = $1;
    }
    | bexp {
        $$ = $1;
    }
    | CHAR_VALUE {
        $$ = new ExprInfo();
        $$->type = "char";
        $$->value = std::string(1, $1);
    }
    | STRING_VALUE {
        $$ = new ExprInfo();
        $$->type = "string";
        $$->value = $1;
    }
    ;

aexp:
    INT_VALUE {
        $$ = new ExprInfo();
        $$->type = "int";
        $$->value = std::to_string($1);
    }
    | FLOAT_VALUE {
        $$ = new ExprInfo();
        $$->type = "float";
        $$->value = std::to_string($1);
    }
    | I_VAR_ID {
        VariableInfo* var = currentScope->lookupVariable($1);
        if (var == nullptr) {
            yyerror("Variable not declared");
            $$ = new ExprInfo();
            $$->type = "error";
        } else {
            $$ = new ExprInfo();
            $$->type = var->type;
            $$->value = var->value;
        }
    }
    | F_VAR_ID {
        VariableInfo* var = currentScope->lookupVariable($1);
        if (var == nullptr) {
            yyerror("Variable not declared");
            $$ = new ExprInfo();
            $$->type = "error";
        } else {
            $$ = new ExprInfo();
            $$->type = var->type;
            $$->value = var->value;
        }
    }
    | aexp '+' aexp {
        $$ = new ExprInfo();
        if ($1->type != $3->type) {
            yyerror("Type mismatch in addition");
            $$->type = "error";
        } else {
            $$->type = $1->type;
            if ($1->type == "int") {
                int result = std::stoi($1->value) + std::stoi($3->value);
                $$->value = std::to_string(result);
            } else if ($1->type == "float") {
                float result = std::stof($1->value) + std::stof($3->value);
                $$->value = std::to_string(result);
            }
        }
    }
    | aexp '-' aexp {
        $$ = new ExprInfo();
        if ($1->type != $3->type) {
            yyerror("Type mismatch in addition");
            $$->type = "error";
        } else {
            $$->type = $1->type;
            if ($1->type == "int") {
                int result = std::stoi($1->value) - std::stoi($3->value);
                $$->value = std::to_string(result);
            } else if ($1->type == "float") {
                float result = std::stof($1->value) - std::stof($3->value);
                $$->value = std::to_string(result);
            }
        }
    }
    | aexp '*' aexp {
        $$ = new ExprInfo();
        if ($1->type != $3->type) {
            yyerror("Type mismatch in addition");
            $$->type = "error";
        } else {
            $$->type = $1->type;
            if ($1->type == "int") {
                int result = std::stoi($1->value) * std::stoi($3->value);
                $$->value = std::to_string(result);
            } else if ($1->type == "float") {
                float result = std::stof($1->value) * std::stof($3->value);
                $$->value = std::to_string(result);
            }
        }
    }
    | aexp '/' aexp {
        $$ = new ExprInfo();
        if ($1->type != $3->type) {
            yyerror("Type mismatch in addition");
            $$->type = "error";
        } else {
            $$->type = $1->type;
            if ($1->type == "int") {
                int result = std::stoi($1->value) / std::stoi($3->value);
                $$->value = std::to_string(result);
            } else if ($1->type == "float") {
                float result = std::stof($1->value) / std::stof($3->value);
                $$->value = std::to_string(result);
            }
        }
    }
    | aexp '%' aexp {
        $$ = new ExprInfo();
        if ($1->type != $3->type) {
            yyerror("Type mismatch in addition");
            $$->type = "error";
        } else {
            $$->type = $1->type;
            if ($1->type == "int") {
                int result = std::stoi($1->value) % std::stoi($3->value);
                $$->value = std::to_string(result);
            } else if ($1->type == "float") {
                yyerror("Cannot have modulo of a float");
                $$->type = "error";
            }
        }
    }
    ;

bexp:
    BOOL_VALUE {
        $$ = new ExprInfo();
        $$->type = "bool";
        $$->value = $1 ? "true" : "false";
    }
    | B_VAR_ID {
        VariableInfo* var = currentScope->lookupVariable($1);
        if (var == nullptr) {
            yyerror("Variable not declared");
            $$ = new ExprInfo();
            $$->type = "error";
        } else {
            $$ = new ExprInfo();
            $$->type = var->type;
            $$->value = var->value;
        }
    }

    | aexp '<' aexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        if ($1->type != $3->type) {
            yyerror("Type mismatch in comparison");
            $$->value = "false";
        } else {
            // Implement comparison logic based on types and operator
            // This is a simplified version
            $$->value = ($1->value < $3->value) ? "true" : "false";
        }
    }

    
    | aexp '>' aexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        if ($1->type != $3->type) {
            yyerror("Type mismatch in comparison");
            $$->value = "false";
        } else {
            // Implement comparison logic based on types and operator
            // This is a simplified version
            $$->value = ($1->value > $3->value) ? "true" : "false";
        }
    }

    
    | aexp '=' aexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        if ($1->type != $3->type) {
            yyerror("Type mismatch in comparison");
            $$->value = "false";
        } else {
            // Implement comparison logic based on types and operator
            // This is a simplified version
            $$->value = ($1->value == $3->value) ? "true" : "false";
        }
    }

    
    | aexp '!' '=' aexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        if ($1->type != $4->type) {
            yyerror("Type mismatch in comparison");
            $$->value = "false";
        } else {
            // Implement comparison logic based on types and operator
            // This is a simplified version
            $$->value = ($1->value != $4->value) ? "true" : "false";
        }
    }

    
    | aexp '<' '=' aexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        if ($1->type != $4->type) {
            yyerror("Type mismatch in comparison");
            $$->value = "false";
        } else {
            // Implement comparison logic based on types and operator
            // This is a simplified version
            $$->value = ($1->value <= $4->value) ? "true" : "false";
        }
    }

    | aexp '>' '=' aexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        if ($1->type != $4->type) {
            yyerror("Type mismatch in comparison");
            $$->value = "false";
        } else {
            // Implement comparison logic based on types and operator
            // This is a simplified version
            $$->value = ($1->value >= $4->value) ? "true" : "false";
        }
    }

    | bexp AND bexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        $$->value = ($1->value == $3->value) ? "true" : "false";
    } 

    | bexp OR bexp {
        $$ = new ExprInfo();
        $$->type = "bool";
        $$->value = (1 <= std::stoi($1->value) + std::stoi($3->value)) ? "true" : "false";
    }
    ;

var_decl: 
    type VAR_ID ';' {
        if (currentScope->isVariableInCurrentScope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Variable %s already declared in current scope", $2);
            yyerror(error_msg);
        } else {
            currentScope->insertVariable($1, $2);
            printf("Declared variable %s of type %s\n", $2, $1);
        }
        $$ = $2;
    }
    | type VAR_ID ASSIGN expression ';' {
        if (currentScope->isVariableInCurrentScope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Variable %s already declared in current scope", $2);
            yyerror(error_msg);
        } else {
            currentScope->insertVariable($1, $2, $4->value);
            printf("Declared and initialized variable %s of type %s with value %s\n", 
                   $2, $1, $4->value.c_str());
        }
        $$ = $2;
    }
    ;

func_decl:
    type FUNCTION_ID '(' optional_param_list ')' '{' seq '}' {
        std::vector<std::string> paramTypes;
        if ($4 != nullptr) {
            paramTypes = $4->paramTypes;
        }
        currentScope->insertFunction($2, $1, paramTypes);
        printf("Defined function %s with return type %s\n", $2, $1);
    }
    ;

optional_param_list:
    /* empty */ {
        $$ = new ParamListInfo();
        $$->paramCount = 0;
    }
    | param_list {
        $$ = $1;
    }
    ;

param_list:
    param {
        $$ = new ParamListInfo();
        $$->paramTypes.push_back($1);
        $$->paramCount = 1;
    }
    | param_list ',' param {
        $1->paramTypes.push_back($3);
        $1->paramCount++;
        $$ = $1;
    }
    ;

param:
    type VAR_ID {
        currentScope->insertVariable($1, $2);
        printf("Added parameter %s of type %s\n", $2, $1);
        $$ = $1;
    }
    ;

type: 
    INT { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    | CHAR { $$ = "char"; }
    | STRING { $$ = "string"; }
    | BOOL { $$ = "bool"; }
    ;

VAR_ID:
    I_VAR_ID { $$ = $1; }
    | F_VAR_ID { $$ = $1; }
    | B_VAR_ID { $$ = $1; }
    | S_VAR_ID { $$ = $1; }
    | C_VAR_ID { $$ = $1; }
    ;

%%

void yyerror(const char* s) {
    cout << "error: " << s << " at line: " << yylineno << endl;
}

int main() {
    yyparse();
    return 0;
}