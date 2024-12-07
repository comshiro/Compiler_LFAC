
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

%token STOP RETURN 
%token CLASS PUBLIC PROTECTED PRIVATE STATIC

%token<tip_var> INT FLOAT DOUBLE LONG CHAR STRING BOOL VOID

%token<id_var> START CLASS_ID FUNCTION_ID VAR_ID

%token<int_val> INT_VALUE
%token<float_val> FLOAT_VALUE
%token<double_val> DOUBLE_VALUE
%token<long_val> LONG_VALUE
%token<char_val> CHAR_VALUE
%token<string_val> STRING_VALUE
%token<bool_val> BOOL_VALUE

%token IF WHILE
%token ASSIGN AND OR NOT
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
program:    classes_section global_var global_func main_body
    | classes_section global_var main_body
    | classes_section global_func main_body
    | classes_section main_body
    | global_var global_func main_body
    | global_var main_body
    | global_func main_body
    | main_body
       ;
main_body:  declarations main {if (errorCount == 0) cout<< "The program is correct!" << endl;} //dc mai intai declarations?
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
class: ACCES_TYPE CLASS CLASS_ID '{' '}' ';'
    | ACCES_TYPE CLASS CLASS_ID '{
        class_body
    }'
    | ACCES_TYPE CLASS CLASS_ID ':' ACCES_TYPE CLASS_ID '{' '}' ';'
    | ACCES_TYPE CLASS CLASS_ID ':' ACCES_TYPE CLASS_ID '{
        class_body
    }'
    ;
class_body: 
    | var_decl func_decl class_body
    | ACCES_TYPE : var_decl func_decl class_body
    | ACCES_TYPE : var_decl ACCES_TYPE func_decl class_body
    | ACCES_TYPE : var_decl func_decl ACCES_TYPE class_body
    ;

main : START list STOP  
     ;

declarations : decl           
	      |  declarations decl    
	      ;

decl       :  TYPE ID ';' { 
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
         | TYPE ID '=' NR ';'
         | TYPE ID '[' NR ']' ';'
         | TYPE ID '[' NR ']' '=' '{' list_param '}' ';'
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

aexp: NR '+' NR
              | NR '-' NR
              | NR '*' NR
              | NR '/' NR
              | '(' NR ')'
              | NR '%' NR
              ;
bexp: NR '>' NR
              | NR '<' NR
              | NR '=' NR
              | NR '!=' NR
              | NR '<=' NR
              | NR '>=' NR
              | '!' NR
              | NR '&&' NR
              | NR '||' NR
              ;
%%
void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;