/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STOP = 258,                    /* STOP  */
    RETURN = 259,                  /* RETURN  */
    CLASS = 260,                   /* CLASS  */
    PUBLIC = 261,                  /* PUBLIC  */
    PROTECTED = 262,               /* PROTECTED  */
    PRIVATE = 263,                 /* PRIVATE  */
    STATIC = 264,                  /* STATIC  */
    INT = 265,                     /* INT  */
    FLOAT = 266,                   /* FLOAT  */
    CHAR = 267,                    /* CHAR  */
    STRING = 268,                  /* STRING  */
    BOOL = 269,                    /* BOOL  */
    VOID = 270,                    /* VOID  */
    I_VAR_ID = 271,                /* I_VAR_ID  */
    F_VAR_ID = 272,                /* F_VAR_ID  */
    B_VAR_ID = 273,                /* B_VAR_ID  */
    S_VAR_ID = 274,                /* S_VAR_ID  */
    C_VAR_ID = 275,                /* C_VAR_ID  */
    CLASS_ID = 276,                /* CLASS_ID  */
    FUNCTION_ID = 277,             /* FUNCTION_ID  */
    START = 278,                   /* START  */
    INT_VALUE = 279,               /* INT_VALUE  */
    FLOAT_VALUE = 280,             /* FLOAT_VALUE  */
    CHAR_VALUE = 281,              /* CHAR_VALUE  */
    STRING_VALUE = 282,            /* STRING_VALUE  */
    BOOL_VALUE = 283,              /* BOOL_VALUE  */
    IF = 284,                      /* IF  */
    WHILE = 285,                   /* WHILE  */
    ASSIGN = 286,                  /* ASSIGN  */
    AND = 287,                     /* AND  */
    OR = 288,                      /* OR  */
    NOT = 289,                     /* NOT  */
    EQUAL = 290,                   /* EQUAL  */
    NOT_EQUAL = 291,               /* NOT_EQUAL  */
    LESS = 292,                    /* LESS  */
    LESS_EQUAL = 293,              /* LESS_EQUAL  */
    GREATER = 294,                 /* GREATER  */
    GREATER_EQUAL = 295,           /* GREATER_EQUAL  */
    PRINT = 296,                   /* PRINT  */
    TYPEOF = 297                   /* TYPEOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "limbaj.y"

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

#line 119 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */
