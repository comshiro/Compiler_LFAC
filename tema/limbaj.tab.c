/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
extern int yylex();
extern int yylineno;
void yyerror(const char* s);


bool lookup(void* var) {
    printf("Lookup");
    return true;}

bool is_int(int value) {
    return true;
}

bool compare_values(int left, int right, bool op) {
    return true; 
}


#line 97 "limbaj.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STOP = 3,                       /* STOP  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_CLASS = 5,                      /* CLASS  */
  YYSYMBOL_PUBLIC = 6,                     /* PUBLIC  */
  YYSYMBOL_PROTECTED = 7,                  /* PROTECTED  */
  YYSYMBOL_PRIVATE = 8,                    /* PRIVATE  */
  YYSYMBOL_STATIC = 9,                     /* STATIC  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_BOOL = 14,                      /* BOOL  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_I_VAR_ID = 16,                  /* I_VAR_ID  */
  YYSYMBOL_F_VAR_ID = 17,                  /* F_VAR_ID  */
  YYSYMBOL_B_VAR_ID = 18,                  /* B_VAR_ID  */
  YYSYMBOL_S_VAR_ID = 19,                  /* S_VAR_ID  */
  YYSYMBOL_C_VAR_ID = 20,                  /* C_VAR_ID  */
  YYSYMBOL_CLASS_ID = 21,                  /* CLASS_ID  */
  YYSYMBOL_FUNCTION_ID = 22,               /* FUNCTION_ID  */
  YYSYMBOL_START = 23,                     /* START  */
  YYSYMBOL_INT_VALUE = 24,                 /* INT_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 25,               /* FLOAT_VALUE  */
  YYSYMBOL_CHAR_VALUE = 26,                /* CHAR_VALUE  */
  YYSYMBOL_STRING_VALUE = 27,              /* STRING_VALUE  */
  YYSYMBOL_BOOL_VALUE = 28,                /* BOOL_VALUE  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_EQUAL = 35,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 36,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS = 37,                      /* LESS  */
  YYSYMBOL_LESS_EQUAL = 38,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER = 39,                   /* GREATER  */
  YYSYMBOL_GREATER_EQUAL = 40,             /* GREATER_EQUAL  */
  YYSYMBOL_PRINT = 41,                     /* PRINT  */
  YYSYMBOL_TYPEOF = 42,                    /* TYPEOF  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* '%'  */
  YYSYMBOL_48_ = 48,                       /* '{'  */
  YYSYMBOL_49_ = 49,                       /* '}'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_global_section = 59,            /* global_section  */
  YYSYMBOL_main_body = 60,                 /* main_body  */
  YYSYMBOL_seq = 61,                       /* seq  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_assignment = 63,                /* assignment  */
  YYSYMBOL_condition = 64,                 /* condition  */
  YYSYMBOL_if_statement = 65,              /* if_statement  */
  YYSYMBOL_loop = 66,                      /* loop  */
  YYSYMBOL_return_statement = 67,          /* return_statement  */
  YYSYMBOL_function_call = 68,             /* function_call  */
  YYSYMBOL_print_statement = 69,           /* print_statement  */
  YYSYMBOL_TYPEOF_statement = 70,          /* TYPEOF_statement  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_aexp = 72,                      /* aexp  */
  YYSYMBOL_bexp = 73,                      /* bexp  */
  YYSYMBOL_comparison_op = 74,             /* comparison_op  */
  YYSYMBOL_var_decl = 75,                  /* var_decl  */
  YYSYMBOL_func_decl = 76,                 /* func_decl  */
  YYSYMBOL_optional_param_list = 77,       /* optional_param_list  */
  YYSYMBOL_param_list = 78,                /* param_list  */
  YYSYMBOL_param = 79,                     /* param  */
  YYSYMBOL_type = 80,                      /* type  */
  YYSYMBOL_classes_section = 81,           /* classes_section  */
  YYSYMBOL_class = 82,                     /* class  */
  YYSYMBOL_access_modifier = 83,           /* access_modifier  */
  YYSYMBOL_class_body = 84,                /* class_body  */
  YYSYMBOL_class_body_item = 85,           /* class_body_item  */
  YYSYMBOL_global_var = 86,                /* global_var  */
  YYSYMBOL_global_func = 87,               /* global_func  */
  YYSYMBOL_VAR_ID = 88                     /* VAR_ID  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    47,     2,     2,
      52,    53,    45,    43,    56,    44,    55,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    94,    95,    96,    97,    98,    99,   100,
     101,   105,   109,   110,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   126,   131,   136,   144,   148,   159,   171,
     175,   179,   183,   187,   188,   189,   190,   191,   195,   196,
     197,   198,   199,   208,   216,   224,   232,   233,   236,   240,
     241,   242,   244,   245,   246,   247,   251,   252,   253,   254,
     255,   256,   260,   264,   268,   275,   280,   281,   285,   286,
     290,   291,   295,   296,   297,   298,   299,   303,   304,   308,
     309,   313,   314,   315,   318,   319,   323,   324,   325,   326,
     330,   331,   335,   336,   340,   341,   342,   343,   344
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STOP", "RETURN",
  "CLASS", "PUBLIC", "PROTECTED", "PRIVATE", "STATIC", "INT", "FLOAT",
  "CHAR", "STRING", "BOOL", "VOID", "I_VAR_ID", "F_VAR_ID", "B_VAR_ID",
  "S_VAR_ID", "C_VAR_ID", "CLASS_ID", "FUNCTION_ID", "START", "INT_VALUE",
  "FLOAT_VALUE", "CHAR_VALUE", "STRING_VALUE", "BOOL_VALUE", "IF", "WHILE",
  "ASSIGN", "AND", "OR", "NOT", "EQUAL", "NOT_EQUAL", "LESS", "LESS_EQUAL",
  "GREATER", "GREATER_EQUAL", "PRINT", "TYPEOF", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'{'", "'}'", "'['", "']'", "'('", "')'", "';'", "'.'",
  "','", "$accept", "program", "global_section", "main_body", "seq",
  "statement", "assignment", "condition", "if_statement", "loop",
  "return_statement", "function_call", "print_statement",
  "TYPEOF_statement", "expression", "aexp", "bexp", "comparison_op",
  "var_decl", "func_decl", "optional_param_list", "param_list", "param",
  "type", "classes_section", "class", "access_modifier", "class_body",
  "class_body_item", "global_var", "global_func", "VAR_ID", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     306,   -17,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
       7,    -9,   -80,   -80,   320,   306,   -80,    11,   158,   158,
     -36,   -80,   280,   -80,   -80,   -80,   -80,   -80,   -80,   -31,
     -25,   -80,   158,   158,     3,   -80,   158,   -80,     6,   -19,
      41,    -6,    10,    18,    22,    31,    38,   247,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -23,
     158,    41,   160,   -80,   158,    24,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,    64,   160,    64,   -80,    43,
     201,    20,   162,   158,    64,    64,    41,    41,   -80,   -80,
      41,   160,    50,    46,   -80,   162,    53,   160,   227,   158,
     201,   -80,    49,   288,   -22,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   160,   160,   160,   160,   160,   160,    64,    64,
      79,    58,     8,    23,    59,    62,    63,   236,    70,   158,
      72,   -80,   107,    69,   -80,   -80,    75,   158,   -80,   -80,
      49,    49,   -80,   -80,   -80,   260,   -80,    93,    41,    73,
      81,    85,    80,    82,   -80,   104,   280,   -80,    87,   -80,
     -80,   -80,   -80,    86,   -80,   280,   280,   -80,   -80,    41,
     145,   -80,   -80,   179,   213,   119,   -80,   -80,   -80,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    82,    83,    81,    72,    73,    74,    75,    76,
       0,     0,    90,    92,     0,     4,    77,     0,     5,     6,
       0,     1,     0,     2,    94,    95,    96,    97,    98,     0,
       0,    78,     7,     8,     0,    91,     9,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    14,
      15,    26,    16,    17,    18,    19,    20,    21,    22,     0,
      66,     0,     0,    62,    10,     0,    79,    40,    41,    50,
      38,    39,    35,    36,    49,     0,     0,     0,    33,     0,
      34,    37,     0,    66,     0,     0,     0,     0,    11,    13,
       0,     0,     0,    67,    68,     0,     0,     0,     0,    84,
       0,    52,    48,     0,     0,    29,    58,    59,    56,    61,
      57,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    63,     0,     0,    86,    87,     0,    85,    46,    55,
      42,    43,    44,    45,    47,    51,    53,    54,     0,     0,
       0,     0,     0,     0,    23,     0,     0,    69,     0,    64,
      80,    88,    89,     0,    30,     0,     0,    31,    32,     0,
       0,    71,    25,     0,     0,     0,    65,    27,    28,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -79,   -42,   -80,   -80,   -80,   -80,
     -80,   -39,   -80,   -80,   -48,    29,   -40,   -80,     2,     0,
     105,   -80,    74,   -10,   -80,   187,   -80,   -80,   -80,   190,
      28,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    23,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    79,    80,    81,   117,    57,    58,
      92,    93,    94,    14,    15,    16,    17,   136,   137,    18,
      19,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    78,    12,    30,    20,    89,    61,    21,    90,    38,
     118,   119,    39,    96,    22,    13,    34,    12,    13,    37,
      35,    60,    78,    38,    65,    62,    38,    91,    29,    63,
      66,   139,    13,    37,    35,   101,    37,   104,   124,   125,
     118,   119,   126,    33,   122,   123,    36,    78,    78,    82,
      95,    78,   118,   119,    38,   118,   119,    67,    68,    69,
      64,   150,    83,    42,    37,    70,    71,    72,    73,    74,
      84,   120,    99,    95,    85,    75,   151,   170,   146,   147,
      67,    68,    69,    86,   130,    76,   173,   174,    70,    71,
      87,    98,    74,    77,   114,   115,   116,   105,    75,   135,
     163,   134,   129,   128,   100,   102,   103,   131,    76,    78,
     148,   149,   152,   100,   100,   153,    77,   154,   156,    95,
     127,   175,   158,   159,   160,   118,   132,   164,    89,   165,
      78,    89,    89,   166,   167,   169,   168,   162,   171,   161,
     172,   140,   141,   142,   143,   144,   145,   100,   100,    40,
     112,   113,   114,   115,   116,     5,     6,     7,     8,     9,
     138,    24,    25,    26,    27,    28,    41,    42,     5,     6,
       7,     8,     9,   179,    43,    44,    67,    68,    24,    25,
      26,    27,    28,    40,    70,    71,    45,    46,   121,     5,
       6,     7,     8,     9,   176,    24,    25,    26,    27,    28,
      41,    42,    31,   157,    76,    32,     0,     0,    43,    44,
       0,     0,    97,     0,     0,     0,     0,    40,     0,     0,
      45,    46,     0,     5,     6,     7,     8,     9,   177,    24,
      25,    26,    27,    28,    41,    42,   106,   107,   108,   109,
     110,   111,    43,    44,   112,   113,   114,   115,   116,     0,
      88,    40,     0,     0,    45,    46,     0,     5,     6,     7,
       8,     9,   178,    24,    25,    26,    27,    28,    41,    42,
     112,   113,   114,   115,   116,     0,    43,    44,   133,   112,
     113,   114,   115,   116,    40,     0,     0,   155,    45,    46,
       5,     6,     7,     8,     9,     0,    24,    25,    26,    27,
      28,    41,    42,   112,   113,   114,   115,   116,     0,    43,
      44,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       9,    45,    46,   106,   107,   108,   109,   110,   111,     0,
       0,   112,   113,   114,   115,   116,    24,    25,    26,    27,
      28,   138,    29
};

static const yytype_int16 yycheck[] =
{
       0,    40,     0,    14,    21,    47,    31,     0,    31,    19,
      32,    33,    48,    61,    23,    15,     5,    15,    18,    19,
      18,    52,    61,    33,    21,    50,    36,    50,    22,    54,
      49,    53,    32,    33,    32,    75,    36,    77,    86,    87,
      32,    33,    90,    15,    84,    85,    18,    86,    87,    55,
      60,    90,    32,    33,    64,    32,    33,    16,    17,    18,
      32,    53,    52,    22,    64,    24,    25,    26,    27,    28,
      52,    82,    48,    83,    52,    34,    53,   156,   118,   119,
      16,    17,    18,    52,    95,    44,   165,   166,    24,    25,
      52,    62,    28,    52,    45,    46,    47,    54,    34,    99,
     148,    99,    56,    53,    75,    76,    77,    54,    44,   148,
      31,    53,    53,    84,    85,    53,    52,    54,    48,   129,
      91,   169,    50,    54,    49,    32,    97,    54,   170,    48,
     169,   173,   174,    48,    54,    31,    54,   137,    51,   137,
      54,   112,   113,   114,   115,   116,   117,   118,   119,     4,
      43,    44,    45,    46,    47,    10,    11,    12,    13,    14,
      53,    16,    17,    18,    19,    20,    21,    22,    10,    11,
      12,    13,    14,    54,    29,    30,    16,    17,    16,    17,
      18,    19,    20,     4,    24,    25,    41,    42,    83,    10,
      11,    12,    13,    14,    49,    16,    17,    18,    19,    20,
      21,    22,    15,   129,    44,    15,    -1,    -1,    29,    30,
      -1,    -1,    52,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      41,    42,    -1,    10,    11,    12,    13,    14,    49,    16,
      17,    18,    19,    20,    21,    22,    35,    36,    37,    38,
      39,    40,    29,    30,    43,    44,    45,    46,    47,    -1,
       3,     4,    -1,    -1,    41,    42,    -1,    10,    11,    12,
      13,    14,    49,    16,    17,    18,    19,    20,    21,    22,
      43,    44,    45,    46,    47,    -1,    29,    30,    51,    43,
      44,    45,    46,    47,     4,    -1,    -1,    51,    41,    42,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    43,    44,    45,    46,    47,    -1,    29,
      30,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    41,    42,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    19,
      20,    53,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,    10,    11,    12,    13,    14,
      58,    59,    75,    76,    80,    81,    82,    83,    86,    87,
      21,     0,    23,    60,    16,    17,    18,    19,    20,    22,
      88,    82,    86,    87,     5,    75,    87,    76,    80,    48,
       4,    21,    22,    29,    30,    41,    42,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    75,    76,    88,
      52,    31,    50,    54,    87,    21,    49,    16,    17,    18,
      24,    25,    26,    27,    28,    34,    44,    52,    68,    71,
      72,    73,    55,    52,    52,    52,    52,    52,     3,    62,
      31,    50,    77,    78,    79,    80,    71,    52,    72,    48,
      72,    73,    72,    72,    73,    54,    35,    36,    37,    38,
      39,    40,    43,    44,    45,    46,    47,    74,    32,    33,
      88,    77,    73,    73,    71,    71,    71,    72,    53,    56,
      88,    54,    72,    51,    75,    76,    84,    85,    53,    53,
      72,    72,    72,    72,    72,    72,    73,    73,    31,    53,
      53,    53,    53,    53,    54,    51,    48,    79,    50,    54,
      49,    75,    76,    71,    54,    48,    48,    54,    54,    31,
      61,    51,    54,    61,    61,    71,    49,    49,    49,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    83,    83,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     2,     2,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     7,     6,     1,     7,     7,     3,
       5,     5,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     3,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     5,     6,     8,     0,     1,     1,     3,
       2,     4,     1,     1,     1,     1,     1,     1,     2,     4,
       6,     1,     1,     1,     0,     1,     1,     1,     2,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 14: /* statement: assignment  */
#line 114 "limbaj.y"
               { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1327 "limbaj.tab.c"
    break;

  case 15: /* statement: condition  */
#line 115 "limbaj.y"
                { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1333 "limbaj.tab.c"
    break;

  case 16: /* statement: loop  */
#line 116 "limbaj.y"
           { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1339 "limbaj.tab.c"
    break;

  case 17: /* statement: return_statement  */
#line 117 "limbaj.y"
                       { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1345 "limbaj.tab.c"
    break;

  case 18: /* statement: function_call  */
#line 118 "limbaj.y"
                    { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1351 "limbaj.tab.c"
    break;

  case 19: /* statement: print_statement  */
#line 119 "limbaj.y"
                      { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1357 "limbaj.tab.c"
    break;

  case 20: /* statement: TYPEOF_statement  */
#line 120 "limbaj.y"
                       { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1363 "limbaj.tab.c"
    break;

  case 21: /* statement: var_decl  */
#line 121 "limbaj.y"
               { (yyval.generic_val) = (yyvsp[0].id_var); }
#line 1369 "limbaj.tab.c"
    break;

  case 22: /* statement: func_decl  */
#line 122 "limbaj.y"
                { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1375 "limbaj.tab.c"
    break;

  case 23: /* assignment: VAR_ID ASSIGN expression ';'  */
#line 127 "limbaj.y"
    {
        printf("Assignment: %s = expression\n", (yyvsp[-3].id_var));
        (yyval.generic_val) = (yyvsp[-3].id_var); 
    }
#line 1384 "limbaj.tab.c"
    break;

  case 24: /* assignment: VAR_ID '[' aexp ']' ASSIGN expression ';'  */
#line 132 "limbaj.y"
     { 
        printf("Array Assignment: %s[%d] = expression\n", (yyvsp[-6].id_var), (yyvsp[-4].int_val)); 
        (yyval.generic_val) = (yyvsp[-6].id_var); 
    }
#line 1393 "limbaj.tab.c"
    break;

  case 25: /* assignment: CLASS_ID '.' VAR_ID ASSIGN expression ';'  */
#line 137 "limbaj.y"
    { 
        printf("Class Assignment: %s.%s = expression\n", (yyvsp[-5].id_class), (yyvsp[-3].id_var)); 
        (yyval.generic_val) = (yyvsp[-3].id_var); 
    }
#line 1402 "limbaj.tab.c"
    break;

  case 27: /* if_statement: IF '(' bexp ')' '{' seq '}'  */
#line 149 "limbaj.y"
     {
        printf("IF statement");
        if ((yyvsp[-4].bool_val)) {
            (yyval.generic_val) = (yyvsp[-1].generic_val); 
            printf("IF statement body executed\n");
        }
    }
#line 1414 "limbaj.tab.c"
    break;

  case 28: /* loop: WHILE '(' bexp ')' '{' seq '}'  */
#line 159 "limbaj.y"
                                   {
        if ((yyvsp[-4].bool_val)) {
            printf("While condition is true\n");
            (yyval.generic_val) = (yyvsp[-1].generic_val); 
        } else {
            printf("While condition is false, skipping loop body\n");
            (yyval.generic_val) = NULL;  
        }
    }
#line 1428 "limbaj.tab.c"
    break;

  case 29: /* return_statement: RETURN expression ';'  */
#line 171 "limbaj.y"
                          { (yyval.generic_val) = (yyvsp[-1].generic_val); }
#line 1434 "limbaj.tab.c"
    break;

  case 30: /* function_call: FUNCTION_ID '(' optional_param_list ')' ';'  */
#line 175 "limbaj.y"
                                                {(yyval.generic_val) = (yyvsp[-4].id_func); }
#line 1440 "limbaj.tab.c"
    break;

  case 31: /* print_statement: PRINT '(' expression ')' ';'  */
#line 179 "limbaj.y"
                                {printf("print <expression>\n"); }
#line 1446 "limbaj.tab.c"
    break;

  case 32: /* TYPEOF_statement: TYPEOF '(' expression ')' ';'  */
#line 183 "limbaj.y"
                                  {printf("type of <expression>"); }
#line 1452 "limbaj.tab.c"
    break;

  case 33: /* expression: function_call  */
#line 187 "limbaj.y"
                  { (yyval.generic_val) = (yyvsp[0].generic_val); }
#line 1458 "limbaj.tab.c"
    break;

  case 34: /* expression: aexp  */
#line 188 "limbaj.y"
           { (yyval.generic_val) = (void*)(yyvsp[0].int_val); }
#line 1464 "limbaj.tab.c"
    break;

  case 35: /* expression: CHAR_VALUE  */
#line 189 "limbaj.y"
                 { (yyval.generic_val) = (void*)(yyvsp[0].char_val); }
#line 1470 "limbaj.tab.c"
    break;

  case 36: /* expression: STRING_VALUE  */
#line 190 "limbaj.y"
                   { (yyval.generic_val) = (yyvsp[0].string_val); }
#line 1476 "limbaj.tab.c"
    break;

  case 37: /* expression: bexp  */
#line 191 "limbaj.y"
           { (yyval.generic_val) = (void*)(yyvsp[0].bool_val); }
#line 1482 "limbaj.tab.c"
    break;

  case 38: /* aexp: INT_VALUE  */
#line 195 "limbaj.y"
              {(yyval.int_val) = (yyvsp[0].int_val); }
#line 1488 "limbaj.tab.c"
    break;

  case 39: /* aexp: FLOAT_VALUE  */
#line 196 "limbaj.y"
                  {(yyval.int_val) = (yyvsp[0].float_val); }
#line 1494 "limbaj.tab.c"
    break;

  case 40: /* aexp: I_VAR_ID  */
#line 197 "limbaj.y"
               { lookup((yyvsp[0].id_var)); }
#line 1500 "limbaj.tab.c"
    break;

  case 41: /* aexp: F_VAR_ID  */
#line 198 "limbaj.y"
               { lookup((yyvsp[0].id_var)); }
#line 1506 "limbaj.tab.c"
    break;

  case 42: /* aexp: aexp '+' aexp  */
#line 200 "limbaj.y"
    {
          if (is_int((yyvsp[-2].int_val)) && is_int((yyvsp[0].int_val))) {
              (yyval.int_val) = (yyvsp[-2].int_val) + (yyvsp[0].int_val); 
          } else {
              (yyval.int_val) = (float)(yyvsp[-2].int_val) + (float)(yyvsp[0].int_val);  
          }
      }
#line 1518 "limbaj.tab.c"
    break;

  case 43: /* aexp: aexp '-' aexp  */
#line 209 "limbaj.y"
    {
          if (is_int((yyvsp[-2].int_val)) && is_int((yyvsp[0].int_val))) {
              (yyval.int_val) = (yyvsp[-2].int_val) - (yyvsp[0].int_val);  
          } else {
              (yyval.int_val) = (float)(yyvsp[-2].int_val) - (float)(yyvsp[0].int_val);  
          }
      }
#line 1530 "limbaj.tab.c"
    break;

  case 44: /* aexp: aexp '*' aexp  */
#line 217 "limbaj.y"
    {
          if (is_int((yyvsp[-2].int_val)) && is_int((yyvsp[0].int_val))) {
              (yyval.int_val) = (yyvsp[-2].int_val) * (yyvsp[0].int_val); 
          } else {
              (yyval.int_val) = (float)(yyvsp[-2].int_val) * (float)(yyvsp[0].int_val); 
          }
      }
#line 1542 "limbaj.tab.c"
    break;

  case 45: /* aexp: aexp '/' aexp  */
#line 225 "limbaj.y"
    {
          if (is_int((yyvsp[-2].int_val)) && is_int((yyvsp[0].int_val))) {
              (yyval.int_val) = (yyvsp[-2].int_val) / (yyvsp[0].int_val); 
          } else {
              (yyval.int_val) = (float)(yyvsp[-2].int_val) / (float)(yyvsp[0].int_val); 
          }
      }
#line 1554 "limbaj.tab.c"
    break;

  case 46: /* aexp: '(' aexp ')'  */
#line 232 "limbaj.y"
                   { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1560 "limbaj.tab.c"
    break;

  case 47: /* aexp: aexp '%' aexp  */
#line 233 "limbaj.y"
                    {
        if (is_int((yyvsp[-2].int_val)) && is_int((yyvsp[0].int_val))) 
              (yyval.int_val) = (yyvsp[-2].int_val) % (yyvsp[0].int_val);  }
#line 1568 "limbaj.tab.c"
    break;

  case 48: /* aexp: '-' aexp  */
#line 236 "limbaj.y"
               {(yyval.int_val) = -(yyvsp[0].int_val);}
#line 1574 "limbaj.tab.c"
    break;

  case 49: /* bexp: BOOL_VALUE  */
#line 240 "limbaj.y"
               { (yyval.bool_val) = (void*)(yyvsp[0].bool_val); }
#line 1580 "limbaj.tab.c"
    break;

  case 50: /* bexp: B_VAR_ID  */
#line 241 "limbaj.y"
               { (yyval.bool_val) = lookup((yyvsp[0].id_var)); }
#line 1586 "limbaj.tab.c"
    break;

  case 51: /* bexp: aexp comparison_op aexp  */
#line 243 "limbaj.y"
        {(yyval.bool_val) = compare_values((yyvsp[-2].int_val), (yyvsp[0].int_val), (yyvsp[-1].bool_val));}
#line 1592 "limbaj.tab.c"
    break;

  case 52: /* bexp: NOT bexp  */
#line 244 "limbaj.y"
               { (yyval.bool_val) = !((yyvsp[0].bool_val)); }
#line 1598 "limbaj.tab.c"
    break;

  case 53: /* bexp: bexp AND bexp  */
#line 245 "limbaj.y"
                    { (yyval.bool_val) = (yyvsp[-2].bool_val) && (yyvsp[0].bool_val); }
#line 1604 "limbaj.tab.c"
    break;

  case 54: /* bexp: bexp OR bexp  */
#line 246 "limbaj.y"
                   { (yyval.bool_val) = (yyvsp[-2].bool_val) || (yyvsp[0].bool_val); }
#line 1610 "limbaj.tab.c"
    break;

  case 55: /* bexp: '(' bexp ')'  */
#line 247 "limbaj.y"
                   { (yyval.bool_val) = (yyvsp[-1].bool_val); }
#line 1616 "limbaj.tab.c"
    break;

  case 56: /* comparison_op: LESS  */
#line 251 "limbaj.y"
           { (yyval.bool_val) = "<"; }
#line 1622 "limbaj.tab.c"
    break;

  case 57: /* comparison_op: GREATER  */
#line 252 "limbaj.y"
              { (yyval.bool_val) = ">"; }
#line 1628 "limbaj.tab.c"
    break;

  case 58: /* comparison_op: EQUAL  */
#line 253 "limbaj.y"
            { (yyval.bool_val) = "="; }
#line 1634 "limbaj.tab.c"
    break;

  case 59: /* comparison_op: NOT_EQUAL  */
#line 254 "limbaj.y"
                { (yyval.bool_val) = "!="; }
#line 1640 "limbaj.tab.c"
    break;

  case 60: /* comparison_op: GREATER_EQUAL  */
#line 255 "limbaj.y"
                    { (yyval.bool_val) = ">="; }
#line 1646 "limbaj.tab.c"
    break;

  case 61: /* comparison_op: LESS_EQUAL  */
#line 256 "limbaj.y"
                 { (yyval.bool_val) = "<="; }
#line 1652 "limbaj.tab.c"
    break;

  case 62: /* var_decl: type VAR_ID ';'  */
#line 260 "limbaj.y"
                       { 
        printf("Declared variable %s of type %s\n", (yyvsp[-1].id_var), (yyvsp[-2].type_var)); 
        (yyval.id_var) = (yyvsp[-1].id_var); 
    }
#line 1661 "limbaj.tab.c"
    break;

  case 63: /* var_decl: type VAR_ID ASSIGN expression ';'  */
#line 264 "limbaj.y"
                                        { 
        printf("Declared variable %s of type %s and assigned value\n", (yyvsp[-3].id_var), (yyvsp[-4].type_var));
        (yyval.id_var) = (yyvsp[-3].id_var); 
    }
#line 1670 "limbaj.tab.c"
    break;

  case 64: /* var_decl: type VAR_ID '[' aexp ']' ';'  */
#line 268 "limbaj.y"
                                   { 
        printf("Declared array %s of type %s with size %d\n", (yyvsp[-4].id_var), (yyvsp[-5].type_var), (yyvsp[-2].int_val)); 
        (yyval.id_var) = (yyvsp[-4].id_var); 
    }
#line 1679 "limbaj.tab.c"
    break;

  case 65: /* func_decl: type FUNCTION_ID '(' optional_param_list ')' '{' seq '}'  */
#line 276 "limbaj.y"
    {printf("Function call: %s with <parameters>\n ", (yyvsp[-6].id_func)); }
#line 1685 "limbaj.tab.c"
    break;

  case 66: /* optional_param_list: %empty  */
#line 280 "limbaj.y"
                 { (yyval.generic_val) = NULL; }
#line 1691 "limbaj.tab.c"
    break;

  case 67: /* optional_param_list: param_list  */
#line 281 "limbaj.y"
                  { (yyval.generic_val) = (yyvsp[0].id_var); }
#line 1697 "limbaj.tab.c"
    break;

  case 68: /* param_list: param  */
#line 285 "limbaj.y"
          { (yyval.id_var) = (yyvsp[0].id_var); }
#line 1703 "limbaj.tab.c"
    break;

  case 69: /* param_list: param_list ',' param  */
#line 286 "limbaj.y"
                           { (yyval.id_var) = (yyvsp[-2].id_var); }
#line 1709 "limbaj.tab.c"
    break;

  case 70: /* param: type VAR_ID  */
#line 290 "limbaj.y"
                {  printf("Parameter: %s %s\n", (yyvsp[-1].type_var), (yyvsp[0].id_var));}
#line 1715 "limbaj.tab.c"
    break;

  case 71: /* param: type VAR_ID '[' ']'  */
#line 291 "limbaj.y"
                          {printf("Array Parameter: %s %s\n", (yyvsp[-3].type_var), (yyvsp[-2].id_var));}
#line 1721 "limbaj.tab.c"
    break;


#line 1725 "limbaj.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 347 "limbaj.y"


void yyerror(const char* s) {
    cout << "error: " << s << " at line: " << yylineno << endl;
}

int main() {
    yyparse();
    return 0;
}