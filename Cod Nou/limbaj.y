%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
extern int yylex();
extern int yylineno;
void yyerror(const char* s);
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
}

%token STOP RETURN 
%token CLASS PUBLIC PROTECTED PRIVATE STATIC
%token<type_var> INT FLOAT CHAR STRING BOOL VOID
%token<id_var> START CLASS_ID FUNCTION_ID I_VAR_ID F_VAR_ID B_VAR_ID S_VAR_ID C_VAR_ID
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
%type<type_var> type
%type<id_var> statement param 
%type<id_var> param_list 
%type<id_var> aexp bexp call

%start program

%%
program:    
    global_section main_body
    ;

global_section:
    /* empty */
    | classes_section
    | global_var
    | global_func
    | classes_section global_var
    | classes_section global_func
    | global_var global_func
    | classes_section global_var global_func
    ;

main_body: 
    START seq STOP
    ;

seq: 
    statement
    | seq statement
    ;

statement: 
    assignment
    | condition
    | loop
    | return_statement
    | function_call
    | print_statement
    | TYPEOF_statement
    ;

assignment: 
    VAR_ID ASSIGN expression ';'            
    | VAR_ID '[' aexp ']' ASSIGN expression ';'
    | CLASS_ID '.' VAR_ID ASSIGN expression ';'
    ;

condition:
    if_statement
    ;

if_statement:
    IF '(' bexp ')' '{' seq '}'
    ;

loop:
    WHILE '(' bexp ')' '{' seq '}'
    ;

return_statement:
    RETURN expression ';'
    ;

function_call:
    FUNCTION_ID '(' optional_param_list ')' ';'
    ;

print_statement:
    PRINT '(' expression ')' ';'
    ;

TYPEOF_statement:
    TYPEOF '(' expression ')' ';'
    ;

expression: 
    call
    | aexp
    | CHAR_VALUE
    | STRING_VALUE
    | bexp
    ;

aexp: 
    INT_VALUE
    | FLOAT_VALUE
    | I_VAR_ID
    | F_VAR_ID
    | aexp '+' aexp 
    | aexp '-' aexp
    | aexp '*' aexp
    | aexp '/' aexp
    | '(' aexp ')'
    | aexp '%' aexp
    | '-' aexp
    ;

bexp: 
    BOOL_VALUE
    | B_VAR_ID
    | aexp comparison_op aexp
    | NOT bexp
    | bexp AND bexp
    | bexp OR bexp
    | '(' bexp ')'
    ;

comparison_op:
    LESS
    | GREATER
    | EQUAL
    | NOT_EQUAL
    | GREATER_EQUAL
    | LESS_EQUAL
    ;

call: 
    FUNCTION_ID '(' optional_param_list ')'
    ;

var_decl: 
    type VAR_ID ';'           
    | type VAR_ID ASSIGN expression ';'
    | type VAR_ID '[' aexp ']' ';'
    ;

func_decl:
    type FUNCTION_ID '(' optional_param_list ')' '{' seq '}'
    ;

optional_param_list:
    /* empty */
    | param_list
    ;

param_list:
    param
    | param_list ',' param
    ;

param:
    type VAR_ID 
    | type VAR_ID '[' ']'
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
    /* empty */
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
