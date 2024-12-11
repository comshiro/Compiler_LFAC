
{
    
}
%union
{
    char* id_var;
    char* type_var;

    int int_val;
    float float_val;
    double double_val;
    long long_val;
    char char_val;
    char* string_val;
    bool bool_val;
}

%token START STOP RETURN 
%token CLASS PUBLIC PROTECTED PRIVATE STATIC

%token<tip_var> INT FLOAT CHAR STRING BOOL

%token<id_var> CLASS_ID FUNCTION_ID VAR_ID

%token<int_val> INT_VALUE
%token<float_val> FLOAT_VALUE
%token<double_val> DOUBLE_VALUE
%token<long_val> LONG_VALUE
%token<char_val> CHAR_VALUE
%token<string_val> STRING_VALUE
%token<bool_val> BOOL_VALUE

%token IF WHILE
%token ASSIGN 
%token AND OR NOT
%token BOOL_TRUE BOOL_FALSE
%token EQUAL NOT_EQUAL LESS LESS_EQUAL GREATER GREATER_EQUAL

%left OR
%left AND
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL
%left '+' '-'
%left '*' '/' '%'
%left NOT
%left '{' '}' '[' ']' '(' ')'


%start program

%%
program:    
    | classes_section global_var global_func main_body
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

ID:
    | VAR_ID
    | FUNCTION_ID
    | CLASS_ID
    ;

classes_section: 
    | class
    | classes_section class
    ;
global_func: 
    | func_decl
    | global_func func_decl
    ;
global_var: 
    | var_decl
    | global_var var_decl
    ;
class: ACCES_TYPE CLASS CLASS_ID '{' '}' ';'
    | ACCES_TYPE CLASS CLASS_ID '{'
        class_body
    '}'
    | ACCES_TYPE CLASS CLASS_ID ':' ACCES_TYPE CLASS_ID '{' '}' ';'
    | ACCES_TYPE CLASS CLASS_ID ':' ACCES_TYPE CLASS_ID '{'
        class_body
    '}'
    ;

class_body: 
    | var_decl func_decl class_body
    | ACCES_TYPE : var_decl func_decl class_body
    | ACCES_TYPE : var_decl ACCES_TYPE func_decl class_body
    | ACCES_TYPE : var_decl func_decl ACCES_TYPE class_body
    ;

var_decl       :  TYPE ID ';' { 
                              if(!current->existsId($2)) {
                                    current->addVar($1,$2);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
              | TYPE ID  '(' list_param ')' ';'
           ;

var_decl : TYPE ID ';'
         | TYPE ID ASSIGN NR ';'
         | TYPE ID ASSIGN '[' NR ']' ';'
         | TYPE ID '[' NR ']' ASSIGN '{' list_param '}' ';'
         ;
func_decl : TYPE ID '(' list_param ')' '{' seq '}' 
          | TYPE ID '(' ')' '{' seq '}' 
          ;
list_param : param
            | list_param ','  param 
            ;
            
param : TYPE ID 
      ; 
      

seq :  statement ';' 
     | seq statement ';'
     ;

statement: ID ASSIGN ID
         | ID ASSIGN NR  	
         | ID ASSIGN call
         | ID ASSIGN aexp
         | ID ASSIGN bexp	 
         | ID '(' call_list ')'
         ;
        
call_list : NR
           | call_list ',' NR
           ;

arithmetic_type:
    | INT
    | FLOAT
    | DOUBLE
    | LONG
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
    | BOOL_TRUE
    | BOOL_FALSE
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
    ;
%%
void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;