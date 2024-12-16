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

%left OR
%left AND
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL
%left '+' '-'
%left '*' '/' '%'
%left NOT
%left '{' '}' '[' ']' '(' ')'

%type<type_var> TYPE
%type<int_val> aexp
%type<id_var> statement param 
%type<id_var> param_list 
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

main_body: START seq STOP
    ;

seq: statement
    | seq statement
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

class: acces_type CLASS CLASS_ID '{' '}'
    | acces_type CLASS CLASS_ID '{' class_body '}'
    | acces_type CLASS CLASS_ID ':' acces_type CLASS_ID '{' '}'
    | acces_type CLASS CLASS_ID ':' acces_type CLASS_ID '{' class_body '}'
    ;

acces_type: PUBLIC | PROTECTED | PRIVATE | STATIC
    ;

class_body: 
    | var_decl func_decl class_body
    | acces_type : var_decl func_decl class_body
    | acces_type : var_decl acces_type func_decl class_body
    | acces_type : var_decl func_decl acces_type class_body
    ;

var_decl: TYPE VAR_ID ';'           
    | TYPE VAR_ID ASSIGN expression ';'
    | TYPE VAR_ID '[' aexp ']' ';' 
    | TYPE VAR_ID '[' aexp ']' ASSIGN expression ';'
    ;

expression: aexp
| bexp
| call
| VAR_ID
| CHAR_VALUE
| STRING_VALUE
;

func_decl:
    TYPE FUNCTION_ID '(' param_list ')' '{' seq '}' 
    ;

param_list:
    param
    | param_list ',' param
    | /* empty */
    ;

param:
    TYPE VAR_ID 
    | TYPE VAR_ID '[' ']'
    ;

seq: statement ';'
    | seq statement ';'
    ;

statement: assignment
    | condition
    | loop
    | return_statement
    | function_call
    | print_statement
    | typeof_statement
    ;

assignment: VAR_ID ASSIGN expression ';'         
    | TYPE VAR_ID ASSIGN expression ';'            
    | VAR_ID '[' aexp ']' ASSIGN expression ';'
    | TYPE VAR_ID '[' aexp ']' ASSIGN expression ';'
    | CLASS_ID '.' VAR_ID ASSIGN expression ';'
    ;

condition:
      if_statement
    ;

if_statement:
      IF '(' expression ')' seq
    ;

loop:
        WHILE '(' bexp ')' seq
    ;

return_statement:
    RETURN expression ';'
    ;

function_call:
    FUNCTION_ID '(' param_list ')' ';'
    ;

print_statement:
    PRINT '(' expression ')' ';'
    ;

typeof_statement:
    TYPEOF '(' expression ')' ';'
    ;

arithmetic_type:
    | INT
    | FLOAT
    ;
aexp: 
    |arithmetic_type
    |VAR_ID
    |aexp '+' aexp
    |aexp '-' aexp
    |aexp '*' aexp
    |aexp '/' aexp
    | '(' aexp ')'
    |aexp '%' aexp
    | '-' aexp
    ;

bexp:
    | BOOL_VALUE
    | aexp LESS aexp
    | aexp GREATER aexp
    | aexp EQUAL aexp
    | bexp NOT_EQUAL bexp
    | aexp GREATER_EQUAL aexp
    | aexp LESS_EQUAL aexp
    | NOT bexp
    | bexp AND bexp
    | bexp OR bexp
    | aexp LESS aexp
    |'(' bexp ')'
    ;

call: FUNCTION_ID '(' param_list ')'
    ;

TYPE: INT | FLOAT | CHAR | STRING | BOOL | VOID
    ;


%%

void yyerror(const char* s) {
    cout << "error: " << s << " at line: " << yylineno << endl;
}

int main() {
    yyparse();
    return 0;
}
