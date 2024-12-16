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
%token<id_var> START CLASS_ID FUNCTION_ID VAR_ID
%token<int_val> INT_VALUE
%token<float_val> FLOAT_VALUE
%token<char_val> CHAR_VALUE
%token<string_val> STRING_VALUE
%token<bool_val> BOOL_VALUE
%token IF WHILE
%token ASSIGN AND OR NOT
%token EQUAL NOT_EQUAL LESS LESS_EQUAL GREATER GREATER_EQUAL
%token PRINT TYPEOF
%token ACCES_TYPE

%left OR
%left AND
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL
%left '+' '-'
%left '*' '/' '%'
%left NOT
%left '{' '}' '[' ']' '(' ')'

%type<id_var> ID
%type<type_var> TYPE
%type<int_val> numeric_expr
%type<id_var> statement param 
%type<id_var> list_param call_list 
%type<id_var> aexp bexp call

%start program

%%
program:    classes_section global_var global_func main_body
    | classes_section global_var main_body
    | classes_section global_func main_body
    | classes_section main_body
    | global_var global_func main_body
    | global_var main_body
    | global_func main_body
    | main_body
    ;

main_body:  declarations main
    ;

classes_section: class
    | classes_section class
    ;

global_func: func_decl
    | global_func func_decl
    ;

global_var: var_decl
    | global_var var_decl
    ;

class: ACCES_TYPE CLASS CLASS_ID '{' '}'
    | ACCES_TYPE CLASS CLASS_ID '{' class_body '}'
    | ACCES_TYPE CLASS CLASS_ID ':' ACCES_TYPE CLASS_ID '{' '}'
    | ACCES_TYPE CLASS CLASS_ID ':' ACCES_TYPE CLASS_ID '{' class_body '}'
    ;

class_body: 
    var_decl
    | func_decl
    | ACCES_TYPE ':' var_decl
    | ACCES_TYPE ':' func_decl
    ;

main: START list STOP  
    ;

declarations: decl           
    | declarations decl    
    ;

decl: TYPE ID 
    | TYPE ID '(' list_param ')'
    ;

var_decl: TYPE ID 
    | TYPE ID ASSIGN numeric_expr 
    | TYPE ID '[' numeric_expr ']' 
    | TYPE ID '[' numeric_expr ']' ASSIGN '{' list_param '}'
    ;

func_decl: TYPE ID '(' list_param ')' 
    | TYPE ID '(' ')'
    ;

list_param: param
    | list_param ',' param 
    ;
            
param: TYPE ID 
    ; 
      
statement: ID ASSIGN ID
    | ID ASSIGN numeric_expr 
    | ID ASSIGN call
    | ID ASSIGN aexp
    | ID ASSIGN bexp 
    | ID '(' call_list ')'
    ;
        
call_list: numeric_expr
    | call_list ',' numeric_expr
    ;
        
aexp: numeric_expr '+' numeric_expr
    | numeric_expr '-' numeric_expr
    | numeric_expr '*' numeric_expr
    | numeric_expr '/' numeric_expr
    | '(' numeric_expr ')'
    | numeric_expr '%' numeric_expr
    ;

bexp: numeric_expr '>' numeric_expr
    | numeric_expr '<' numeric_expr
    | numeric_expr EQUAL numeric_expr
    | numeric_expr NOT_EQUAL numeric_expr
    | numeric_expr LESS_EQUAL numeric_expr
    | numeric_expr GREATER_EQUAL numeric_expr
    | NOT numeric_expr
    | numeric_expr AND numeric_expr
    | numeric_expr OR numeric_expr
    ;

list: 
    | list statement
    ;

call: ID '(' call_list ')'
    ;

ID: VAR_ID | FUNCTION_ID | CLASS_ID
    ;

TYPE: INT | FLOAT | CHAR | STRING | BOOL | VOID
    ;

numeric_expr: INT_VALUE | FLOAT_VALUE | CHAR_VALUE | STRING_VALUE | BOOL_VALUE
    ;

%%

void yyerror(const char* s) {
    cout << "error: " << s << " at line: " << yylineno << endl;
}

int main() {
    yyparse();
    return 0;
}
