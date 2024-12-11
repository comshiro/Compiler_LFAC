%{
    #include <iostream>
    #include <cstring>
    #include "tema.tab.h"
}

%}
%option noyywrap

%%

"start" {return START;}
"stop" {return STOP;}
"return" {return RETURN;}

"class" {return CLASS;}
"public" {return PUBLIC;}
"protected" {return PROTECTED;} //avem nevoie de protected?
"private" {return PRIVATE;}
"static" {return STATIC;}


"int" {yylval.type_var = strdup(yytext); return INT;}
"float" {yylval.type_var = strdup(yytext); return FLOAT;}
"char" {yylval.type_var = strdup(yytext); return CHAR;}
"string" {yylval.type_var = strdup(yytext); return STRING;}
"bool" {yylval.type_var = strdup(yytext); return BOOL;}
"long" {yylval.type_var = strdup(yytext); return LONG;}
"double" {yylval.type_var = strdup(yytext); return DOUBLE;}
"void" {yylval.type_var = strdup(yytext); return VOID;} //chiar avem nevoie de void?

.[_a-zA-Z][_a-zA-Z0-9]* {yylval.id_var = strdup(yytext); return VAR_ID;}
@[_a-zA-Z][_a-zA-Z0-9]* {yylval.id_var = strdup(yytext); return FUNCTION_ID;}
&[_a-zA-Z][_a-zA-Z0-9]* {yylval.id_var = strdup(yytext); return CLASS_ID;}

i_(0|[-]?([1-9][0-9]*)) {yylval.int_val = atoi(yytext); return INT_VALUE;}
f_([-]?0|[-]?([1-9][0-9]*))\.[0-9]* {
                                        char* value = strdup(yytext); 
                                        value = value + 2; 
                                        yylval.float_val = atof(value); 
                                        free(value); 
                                        return FLOAT_VALUE;
                                    }
d_([-]?0|[-]?([1-9][0-9]*))\.[0-9]* {
                                        char* value = strdup(yytext); 
                                        value = value + 2; 
                                        yylval.double_val = atof(value); 
                                        free(value); 
                                        return DOUBLE_VALUE;
                                    }
l_([-]?0|[-]?([1-9][0-9]*)) {yylval.long_val = atol(yytext); return LONG_VALUE;}

"if" {return IF;}
"while" {return WHILE;} 

":=" {return ASSIGN;}
"true"|"false" {yylval.bool_val = true; return BOOL_VAL;}
"=" {return EQUAL;}
"!=" {return NOT_EQUAL;}
"and" {return AND;}
"or" {return OR;}
"!" {return NOT;}
"<" {return LESS;}
"<=" {return LESS_EQUAL;}
">" {return GREATER;}
">=" {return GREATER_EQUAL;}

[/\*]([^*]|\*[^/])*\*[/] {return COMMENT;} 


[ \t] ;
\n {yylineno++;}
. {return yytext[0];}