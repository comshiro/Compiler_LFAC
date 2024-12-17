%{
#include <iostream>
#include <cstring>
#include <string>
#include "limbaj.tab.h"
using namespace std;

int yylex(void);
%}

%option noyywrap

%%
"begin"         { return START; }
"end"           { return STOP; }
"return"        { return RETURN; }
"class"         { return CLASS; }
"public"        { return PUBLIC; }
"protected"     { return PROTECTED; }
"private"       { return PRIVATE; }
"static"        { return STATIC; }

"int"           { yylval.type_var = strdup(yytext); return INT; }
"float"         { yylval.type_var = strdup(yytext); return FLOAT; }
"char"          { yylval.type_var = strdup(yytext); return CHAR; }
"string"        { yylval.type_var = strdup(yytext); return STRING; }
"bool"          { yylval.type_var = strdup(yytext); return BOOL; }
"void"          { yylval.type_var = strdup(yytext); return VOID; }

"if"            { return IF; }
"while"         { return WHILE; }

"true"          { yylval.bool_val = true; return BOOL_VALUE; }
"false"         { yylval.bool_val = false; return BOOL_VALUE; }

"Print(".*")"   { return PRINT; }
"TypeOf(".*")"  { return TYPEOF; }

":="            { return ASSIGN; }
"="             { return EQUAL; }
"!="            { return NOT_EQUAL; }
"and"           { return AND; }
"or"            { return OR; }
"!"             { return NOT; }
"<"             { return LESS; }
"<="            { return LESS_EQUAL; }
">"             { return GREATER; }
">="            { return GREATER_EQUAL; }

I_[_a-zA-Z][_a-zA-Z0-9]*  { yylval.id_var = strdup(yytext); return I_VAR_ID; }
F_[_a-zA-Z][_a-zA-Z0-9]*  { yylval.id_var = strdup(yytext); return F_VAR_ID; }
B_[_a-zA-Z][_a-zA-Z0-9]*  { yylval.id_var = strdup(yytext); return B_VAR_ID; }
C_[_a-zA-Z][_a-zA-Z0-9]*  { yylval.id_var = strdup(yytext); return C_VAR_ID; }
S_[_a-zA-Z][_a-zA-Z0-9]*  { yylval.id_var = strdup(yytext); return S_VAR_ID; }
@[_a-zA-Z][_a-zA-Z0-9]* { yylval.id_var = strdup(yytext); return FUNCTION_ID; }
&[_a-zA-Z][_a-zA-Z0-9]* { yylval.id_var = strdup(yytext); return CLASS_ID; }

i_(-?[0-9]+)    { 
    yylval.int_val = atoi(yytext + 2); 
    return INT_VALUE; 
}

f_(-?[0-9]+\.[0-9]*)    { 
    char* value = strdup(yytext + 2); 
    yylval.float_val = atof(value); 
    free(value); 
    return FLOAT_VALUE; 
}

s_\"[^\"\n]+\"  {
    char* value = strdup(yytext + 2); 
    yylval.string_val = strdup(value - 1);
    free(value);
    return STRING_VALUE;
}

c_\"[^\"\n]\"  {
    yylval.char_val = yytext[2];
    return CHAR_VALUE;
}

[/\*]([^*]|\*[^/])*\*[/] { }
[ \t\r]         { }
\n              { yylineno++; }
.               { return yytext[0]; }

%%