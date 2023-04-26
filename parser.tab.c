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
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin; 

FILE * IRcode;
FILE * MIPScode;
  
 
void yyerror(const char* s);
char currentScope[50] = "global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks

#line 95 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_ID = 10,                        /* ID  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_SEMICOLON = 12,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_EQUAL = 14,                     /* EQUAL  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 17,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 18,                    /* DIVIDE  */
  YYSYMBOL_LEFTPARENTHESIS = 19,           /* LEFTPARENTHESIS  */
  YYSYMBOL_RIGHTPARENTHESIS = 20,          /* RIGHTPARENTHESIS  */
  YYSYMBOL_LEFTCURLYBRACKET = 21,          /* LEFTCURLYBRACKET  */
  YYSYMBOL_RIGHCURLYBRACKET = 22,          /* RIGHCURLYBRACKET  */
  YYSYMBOL_LEFTBRACKET = 23,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 24,              /* RIGHTBRACKET  */
  YYSYMBOL_UNARYNOT = 25,                  /* UNARYNOT  */
  YYSYMBOL_LOGICALAND = 26,                /* LOGICALAND  */
  YYSYMBOL_LOGICALOR = 27,                 /* LOGICALOR  */
  YYSYMBOL_NUMBER = 28,                    /* NUMBER  */
  YYSYMBOL_WRITE = 29,                     /* WRITE  */
  YYSYMBOL_WRITELN = 30,                   /* WRITELN  */
  YYSYMBOL_FUN = 31,                       /* FUN  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_LESS_THAN = 35,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 36,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN_OR_EQUAL_TO = 37,     /* LESS_THAN_OR_EQUAL_TO  */
  YYSYMBOL_GREATER_THAN_OR_EQUAL_TO = 38,  /* GREATER_THAN_OR_EQUAL_TO  */
  YYSYMBOL_EQUAL_TO = 39,                  /* EQUAL_TO  */
  YYSYMBOL_NOT_EQUAL_TO = 40,              /* NOT_EQUAL_TO  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_DeclList = 43,                  /* DeclList  */
  YYSYMBOL_Decl = 44,                      /* Decl  */
  YYSYMBOL_StmtList = 45,                  /* StmtList  */
  YYSYMBOL_Stmt = 46,                      /* Stmt  */
  YYSYMBOL_Type = 47,                      /* Type  */
  YYSYMBOL_ParamList = 48,                 /* ParamList  */
  YYSYMBOL_Param = 49,                     /* Param  */
  YYSYMBOL_ReturnStmt = 50,                /* ReturnStmt  */
  YYSYMBOL_FunCall = 51,                   /* FunCall  */
  YYSYMBOL_IfStmt = 52,                    /* IfStmt  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_WhileStmt = 54,                 /* WhileStmt  */
  YYSYMBOL_FunDecl = 55,                   /* FunDecl  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_Block = 58,                     /* Block  */
  YYSYMBOL_VarDecl = 59,                   /* VarDecl  */
  YYSYMBOL_Expr = 60                       /* Expr  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    76,    79,    82,    83,    84,    85,    86,
      89,    90,    95,    96,    97,    98,   101,   102,   103,   104,
     105,   106,   109,   110,   113,   118,   119,   120,   123,   144,
     156,   159,   159,   291,   328,   355,   328,   378,   403,   423,
     456,   511,   512,   513,   514,   551,   567,   595,   631,   673,
     719,   765,   818,   878,   930,   983,  1035,  1087,  1139,  1191,
    1246,  1303,  1327
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
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "INT", "FLOAT",
  "CHAR", "BOOL", "STRING", "VOID", "ID", "RETURN", "SEMICOLON", "COMMA",
  "EQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LEFTPARENTHESIS",
  "RIGHTPARENTHESIS", "LEFTCURLYBRACKET", "RIGHCURLYBRACKET",
  "LEFTBRACKET", "RIGHTBRACKET", "UNARYNOT", "LOGICALAND", "LOGICALOR",
  "NUMBER", "WRITE", "WRITELN", "FUN", "IF", "ELSE", "WHILE", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_OR_EQUAL_TO", "GREATER_THAN_OR_EQUAL_TO",
  "EQUAL_TO", "NOT_EQUAL_TO", "$accept", "Program", "DeclList", "Decl",
  "StmtList", "Stmt", "Type", "ParamList", "Param", "ReturnStmt",
  "FunCall", "IfStmt", "$@1", "WhileStmt", "FunDecl", "$@4", "$@5",
  "Block", "VarDecl", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      95,   -92,   -92,   -92,   -92,   -92,   -92,     9,   256,   -92,
     -14,   256,   256,   -92,   256,    -3,    53,     7,    12,    33,
     -92,    95,   -92,   249,    24,    23,    32,   -92,   -92,   -92,
     -92,     3,   256,    53,   256,   -11,   205,   -92,   115,   -92,
     205,    50,    61,   256,   256,   -92,   -92,   -92,    -1,   -92,
     -92,   -92,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   205,    66,    58,   121,   -92,   -92,
     -92,   147,   173,   -92,   256,   256,    -8,    -8,   -92,   -92,
     218,   211,    48,    48,    48,    48,    48,    48,    64,   -92,
      65,    62,   -92,    68,    57,   179,    53,   256,    53,    68,
      95,   -92,   -92,    74,   -92,   205,    77,    71,   -92,   249,
     -92,    96,   -92,    86,    53,    68,   -92,   -92,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,    16,    17,    19,    18,    20,    21,    45,     0,    12,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       2,     4,     7,    10,     0,     0,     0,     8,     9,     5,
       6,     0,     0,    27,     0,    45,    28,    42,     0,    44,
      61,     0,     0,     0,     0,     1,     3,    11,     0,    14,
      15,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,    43,    62,
      34,     0,     0,    38,     0,     0,    49,    50,    51,    52,
      59,    60,    55,    57,    56,    58,    53,    54,    26,    29,
      46,     0,    31,     0,     0,     0,    27,     0,    22,     0,
      10,    33,    39,     0,    25,    48,     0,     0,    32,    10,
      40,    24,    35,     0,    22,     0,    37,    23,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -15,   -92,   -21,   -92,   -16,    -4,    16,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -91,   -92,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,   107,    66,    25,
      26,    27,    99,    28,    29,    91,   115,   101,    30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    36,    47,    32,    38,    39,    46,    40,   108,    54,
      55,    73,    34,    74,    37,    51,    41,    65,    52,    53,
      54,    55,    75,    32,   118,    64,    43,    67,    33,    56,
      57,    44,    34,    45,    48,    49,    71,    72,    58,    59,
      60,    61,    62,    63,    50,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     1,     2,     3,
       4,     5,     6,    52,    53,    54,    55,    94,    95,   102,
      69,    70,    52,    53,    54,    55,    88,    96,    89,    97,
      65,    98,   106,    56,    57,   109,   110,   111,   113,   100,
     105,   112,    58,    59,    60,    61,    62,    63,   106,     1,
       2,     3,     4,     5,     6,     7,     8,     9,   116,   114,
     117,    10,   104,     0,    11,     0,     0,     0,     0,     0,
      12,     0,     0,    13,    14,    15,    16,    17,     0,    18,
      52,    53,    54,    55,     0,    68,    52,    53,    54,    55,
       0,    56,    57,     0,     0,    90,     0,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    58,    59,    60,    61,
      62,    63,    52,    53,    54,    55,     0,    92,     0,     0,
       0,     0,     0,    56,    57,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    52,    53,
      54,    55,     0,    93,    52,    53,    54,    55,     0,    56,
      57,     0,     0,   103,     0,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    58,    59,    60,    61,    62,    63,
      52,    53,    54,    55,     0,     0,    52,    53,    54,    55,
       0,    56,    57,    52,    53,    54,    55,    56,     0,     0,
      58,    59,    60,    61,    62,    63,    58,    59,    60,    61,
      62,    63,     0,    58,    59,    60,    61,    62,    63,     7,
       8,     9,     0,     0,     0,    10,    35,     0,    11,     0,
       0,     0,    10,     0,    12,    11,     0,    13,    14,    15,
       0,    12,     0,     0,    13,    14,    15
};

static const yytype_int8 yycheck[] =
{
      16,     8,    23,    14,    11,    12,    21,    14,    99,    17,
      18,    12,    23,    14,    28,    12,    19,    33,    15,    16,
      17,    18,    23,    14,   115,    32,    19,    34,    19,    26,
      27,    19,    23,     0,    10,    12,    43,    44,    35,    36,
      37,    38,    39,    40,    12,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     4,     5,     6,
       7,     8,     9,    15,    16,    17,    18,    74,    75,    12,
      20,    10,    15,    16,    17,    18,    10,    13,    20,    14,
      96,    19,    98,    26,    27,   100,    12,    10,   109,    21,
      97,    20,    35,    36,    37,    38,    39,    40,   114,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    22,    13,
     114,    16,    96,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    28,    29,    30,    31,    32,    -1,    34,
      15,    16,    17,    18,    -1,    20,    15,    16,    17,    18,
      -1,    26,    27,    -1,    -1,    24,    -1,    26,    27,    -1,
      35,    36,    37,    38,    39,    40,    35,    36,    37,    38,
      39,    40,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    15,    16,
      17,    18,    -1,    20,    15,    16,    17,    18,    -1,    26,
      27,    -1,    -1,    24,    -1,    26,    27,    -1,    35,    36,
      37,    38,    39,    40,    35,    36,    37,    38,    39,    40,
      15,    16,    17,    18,    -1,    -1,    15,    16,    17,    18,
      -1,    26,    27,    15,    16,    17,    18,    26,    -1,    -1,
      35,    36,    37,    38,    39,    40,    35,    36,    37,    38,
      39,    40,    -1,    35,    36,    37,    38,    39,    40,    10,
      11,    12,    -1,    -1,    -1,    16,    10,    -1,    19,    -1,
      -1,    -1,    16,    -1,    25,    19,    -1,    28,    29,    30,
      -1,    25,    -1,    -1,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      16,    19,    25,    28,    29,    30,    31,    32,    34,    42,
      43,    44,    45,    46,    47,    50,    51,    52,    54,    55,
      59,    60,    14,    19,    23,    10,    60,    28,    60,    60,
      60,    19,    47,    19,    19,     0,    43,    45,    10,    12,
      12,    12,    15,    16,    17,    18,    26,    27,    35,    36,
      37,    38,    39,    40,    60,    47,    49,    60,    20,    20,
      10,    60,    60,    12,    14,    23,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    10,    20,
      24,    56,    20,    20,    60,    60,    13,    14,    19,    53,
      21,    58,    12,    24,    49,    60,    47,    48,    58,    43,
      12,    10,    20,    45,    13,    57,    22,    48,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    49,    49,    49,    50,    51,
      51,    53,    52,    54,    56,    57,    55,    58,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     0,     4,     2,     4,     2,     0,     2,     4,
       0,     0,     6,     5,     0,     0,     9,     4,     3,     5,
       6,     1,     2,     3,     2,     1,     4,     3,     6,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3
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
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 52 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 870 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBER: /* NUMBER  */
#line 53 "parser.y"
         { fprintf(yyoutput, "%d", ((*yyvaluep).string)); }
#line 876 "parser.tab.c"
        break;

      default:
        break;
    }
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
  case 2: /* Program: DeclList  */
#line 69 "parser.y"
                   { (yyval.ast) = (yyvsp[0].ast);
					 printf("\n--- Abstract Syntax Tree ---\n\n"); 
					 printAST((yyval.ast),0);
					}
#line 1269 "parser.tab.c"
    break;

  case 3: /* DeclList: Decl DeclList  */
#line 76 "parser.y"
                                { (yyvsp[-1].ast)->left = (yyvsp[0].ast);
							  (yyval.ast) = (yyvsp[-1].ast);
							}
#line 1277 "parser.tab.c"
    break;

  case 4: /* DeclList: Decl  */
#line 79 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 1283 "parser.tab.c"
    break;

  case 11: /* StmtList: Stmt StmtList  */
#line 90 "parser.y"
                        { (yyvsp[-1].ast)->left = (yyvsp[0].ast);
					  (yyval.ast) = (yyvsp[-1].ast);
					}
#line 1291 "parser.tab.c"
    break;

  case 12: /* Stmt: SEMICOLON  */
#line 95 "parser.y"
                        {}
#line 1297 "parser.tab.c"
    break;

  case 13: /* Stmt: Expr SEMICOLON  */
#line 96 "parser.y"
                                {(yyval.ast) = (yyvsp[-1].ast);}
#line 1303 "parser.tab.c"
    break;

  case 14: /* Stmt: ReturnStmt SEMICOLON  */
#line 97 "parser.y"
                               {  }
#line 1309 "parser.tab.c"
    break;

  case 15: /* Stmt: FunCall SEMICOLON  */
#line 98 "parser.y"
                            { }
#line 1315 "parser.tab.c"
    break;

  case 16: /* Type: INT  */
#line 101 "parser.y"
          { strcpy((yyval.ast)->nodeType, "int"); strcpy((yyval.ast)->value, "0");}
#line 1321 "parser.tab.c"
    break;

  case 17: /* Type: FLOAT  */
#line 102 "parser.y"
                { strcpy((yyval.ast)->nodeType, "float"); strcpy((yyval.ast)->value, "0.0");}
#line 1327 "parser.tab.c"
    break;

  case 18: /* Type: BOOL  */
#line 103 "parser.y"
               { strcpy((yyval.ast)->nodeType, "bool"); strcpy((yyval.ast)->value, "0");}
#line 1333 "parser.tab.c"
    break;

  case 19: /* Type: CHAR  */
#line 104 "parser.y"
               { strcpy((yyval.ast)->nodeType, "char"); strcpy((yyval.ast)->value, "");}
#line 1339 "parser.tab.c"
    break;

  case 20: /* Type: STRING  */
#line 105 "parser.y"
                 { strcpy((yyval.ast)->nodeType, "string"); strcpy((yyval.ast)->value, "");}
#line 1345 "parser.tab.c"
    break;

  case 21: /* Type: VOID  */
#line 106 "parser.y"
               { strcpy((yyval.ast)->nodeType, "void"); strcpy((yyval.ast)->value, "");}
#line 1351 "parser.tab.c"
    break;

  case 23: /* ParamList: Type ID COMMA ParamList  */
#line 110 "parser.y"
                                  { printf("\n RECOGNIZED RULE: Parameter list %s\n", (yyvsp[-2].string)); 
	  	emitFunctionParameter(currentScope, (yyvsp[-2].string), (yyvsp[-3].ast));
	}
#line 1359 "parser.tab.c"
    break;

  case 24: /* ParamList: Type ID  */
#line 113 "parser.y"
                  {	printf("\n RECOGNIZED RULE: Parameter %s\n", (yyvsp[0].string)); 
		emitFunctionParameter(currentScope, (yyvsp[0].string), (yyvsp[-1].ast));
	}
#line 1367 "parser.tab.c"
    break;

  case 26: /* Param: Type ID  */
#line 119 "parser.y"
                  { }
#line 1373 "parser.tab.c"
    break;

  case 28: /* ReturnStmt: RETURN Expr  */
#line 123 "parser.y"
                            {
	printf("\n RECOGNIZED RULE: Return statement: %s with value:%s\n", (yyvsp[0].ast), (yyvsp[0].ast)->value);
	// Symbol Table 
	symTabAccess();
	int inSymTab = found((yyvsp[0].ast), currentScope);
	
	// currently this code has a problem, not every Expr will be in the symbol table

	// get value from symbol table if inSymTab
	if(inSymTab != -1) {
		// get the value from the symbol table
		char value[50];
		sprintf(value, "%s", getValue(inSymTab));
		printf("value: %s\n", value);
	}
	else {
		printf("not found %s in symtab - semantic error", (yyvsp[0].ast));
	}
}
#line 1397 "parser.tab.c"
    break;

  case 29: /* FunCall: ID LEFTPARENTHESIS Param RIGHTPARENTHESIS  */
#line 144 "parser.y"
                                                          { 
	printf("\n RECOGNIZED RULE: Function call %s\n", (yyvsp[-3].string));
	// Symbol Table

	// IR GOTO Label

	emitMIPSFunctionCall((yyvsp[-3].string));
	(yyval.ast) = (yyvsp[-3].string); 


 
}
#line 1414 "parser.tab.c"
    break;

  case 31: /* $@1: %empty  */
#line 159 "parser.y"
                                                 {
		printf("\n RECOGNIZED RULE: If statement %s\n", (yyvsp[-1].ast));
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-1].ast)->value, currentScope); 
		// Check if Expr $3's nodeType is a number or a variable
		if(strcmp((yyvsp[-1].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-1].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-1].ast)->value, "%s", getValue(inSymTab1));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-1].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");

			// emit IR code for if statement
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n"); 

			// do not emit IR code for if statement 
		}

		sprintf((yyvsp[-1].ast)->value, "%s", stringVal);
		emitMIPSIfStatement((yyvsp[-1].ast)->LHS, (yyvsp[-1].ast)->condition, (yyvsp[-1].ast)->RHS, stringVal); 
}
#line 1457 "parser.tab.c"
    break;

  case 32: /* IfStmt: IF LEFTPARENTHESIS Expr RIGHTPARENTHESIS $@1 Block  */
#line 197 "parser.y"
      {
		(yyval.ast) = AST_BinaryExpression("if", (yyvsp[0].ast), (yyvsp[-3].ast));  
		// print the AST
		printf("\n--- Abstract Syntax Tree ---\n\n");
		printAST((yyval.ast),0);
		emitMIPSEndIfStatement();

}
#line 1470 "parser.tab.c"
    break;

  case 33: /* WhileStmt: WHILE LEFTPARENTHESIS Expr RIGHTPARENTHESIS Block  */
#line 291 "parser.y"
                                                             { 
	printf("Recognized rule: While statement %s\n", (yyvsp[-2].ast)->value);
	// Check if the variables are in the symbol table
	int inSymTab1 = found((yyvsp[-2].ast)->value, currentScope);
	// Check if Expr $3's nodeType is a number or a variable
	if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
		// Numbers don't exist in the symbol table. Skip this check.
	}
	// Variable is not in the symbol table
	else if(inSymTab1 == -1) { 
		// Variable is not in the symbol table
		printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
		semanticCheckPassed = 0;
	}
	// Variable is in the symbol table 
	else if(inSymTab1 != -1) {
		// Update the value according to the symbol table
		sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
	}

	// Check if the expression is true or false
	char stringVal[50];
	if(atoi((yyvsp[-2].ast)->value)) {
		sprintf(stringVal, "%d", 1);
		printf("TRUE\n");

		// emit IR code for if statement
	}
	else {
		sprintf(stringVal, "%d", 0);
		printf("FALSE\n"); 

		// do not emit IR code for if statement 
	}
}
#line 1510 "parser.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 328 "parser.y"
                            {
printf("\n RECOGNIZED RULE: Function declaration %s\n", (yyvsp[0].string));
																// Symbol Table
																symTabAccess();
																int inSymTab = found((yyvsp[0].string), currentScope);
																//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
																// turn $2 into string
																char funScope[50];
																sprintf(funScope, "%s", (yyvsp[0].string));
																// set current scope to function name
																strcpy(currentScope, funScope);
																
																// print the current scope
																if (inSymTab == -1) 
																	addItem((yyvsp[0].string), "Fun", (yyvsp[-1].ast), "Fun", 0, "global");
																else
																	printf("SEMANTIC ERROR: Fun %s is already in the symbol table", funScope);
																showSymTable();
																emitFunctionDeclaration(currentScope, (yyvsp[0].string), (yyvsp[-1].ast)); 

																// ---- SEMANTIC ACTIONS by PARSER ----	
																// $$ = AST_Fun("Fun", $2, $3);
																
																//printf("-----------> %s", $$->LHS);
																emitMIPSFunctionDeclaration((yyvsp[0].string), (yyvsp[-1].ast));
																
}
#line 1542 "parser.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 355 "parser.y"
                                           {emitFunctionBlockStart();}
#line 1548 "parser.tab.c"
    break;

  case 36: /* FunDecl: FUN Type ID $@4 LEFTPARENTHESIS ParamList RIGHTPARENTHESIS $@5 Block  */
#line 355 "parser.y"
                                                                                {  
											// change current scope back to global 
											
											(yyval.ast) = AST_Fun("Fun", (yyvsp[-7].ast), (yyvsp[-6].string));
											// $$->right = AST_Block("Block", $8, $8); 
											// $$->left = AST_Block("Params", $2, $3);
											// add the block to the right hand side of the function
											// maybe if the scope is not global, don't run the code and update the symbol table
											// the code should really only run on a function call

											// implement emitFunctionDeclaration(char* functionName, char** parameterList, int numParameters)
											
											// print ParamList
											
											// print the entire parameter list 
											// emit function name
											emitFunctionBlockEnd();
											strcpy(currentScope, "global"); 

											emitMIPSEndFunction();  
										}
#line 1574 "parser.tab.c"
    break;

  case 37: /* Block: LEFTCURLYBRACKET DeclList StmtList RIGHCURLYBRACKET  */
#line 378 "parser.y"
                                                           { 
	(yyval.ast) = AST_Block("Block", (yyvsp[-2].ast), (yyvsp[-1].ast)); 
	// print the AST
	printf("\n--- Abstract Syntax Tree 2 ---\n\n");
	printAST((yyval.ast),0);
	while((yyvsp[-2].ast)->left != NULL) {
		printf("DeclList: %s\n", (yyvsp[-2].ast)->left->LHS);
		printf("Value: %s\n", (yyvsp[-2].ast)->left->RHS);  
		 
		(yyvsp[-2].ast) = (yyvsp[-2].ast)->left;
		(yyval.ast) = (yyvsp[-2].ast); 
	}
	while((yyvsp[-1].ast)->left != NULL) {
		printf("StmtList: %s\n", (yyvsp[-1].ast)->left->LHS);
		printf("Value: %s\n", (yyvsp[-1].ast)->left->RHS);
		
		(yyvsp[-1].ast) = (yyvsp[-1].ast)->left;
		(yyval.ast) = (yyvsp[-1].ast);
	} 

	// loop through the statement list and look for return statements
}
#line 1601 "parser.tab.c"
    break;

  case 38: /* VarDecl: Type ID SEMICOLON  */
#line 403 "parser.y"
                                        { printf("\n RECOGNIZED RULE: Variable declaration %s\n", (yyvsp[-1].string));
									// Symbol Table
									symTabAccess();
									int inSymTab = found((yyvsp[-1].string), currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == -1)  
										addItem((yyvsp[-1].string), "Var", (yyvsp[-2].ast)->nodeType, (yyvsp[-2].ast)->value, 0, currentScope);
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[-1].string));
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
									printf("-----------> %s\n", (yyval.ast)->LHS);

									emitVariableDeclaration(currentScope, (yyvsp[-2].ast), (yyvsp[-1].string), "0");

									emitMIPSVariableDeclaration((yyvsp[-1].string), (yyvsp[-2].ast), (yyvsp[-2].ast)->value); 
								    (yyval.ast) = AST_Type("Type", (yyvsp[-2].ast)->nodeType, (yyvsp[-2].ast)->value);
								}
#line 1626 "parser.tab.c"
    break;

  case 39: /* VarDecl: Type ID EQUAL Expr SEMICOLON  */
#line 423 "parser.y"
                               { printf("\n RECOGNIZED RULE: Variable declaration %s\n", (yyvsp[-3].string));
									// Symbol Table 
									symTabAccess();
									int inSymTab = found((yyvsp[-3].string), currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									if (inSymTab == -1)  {
										// If the variable is an int, truncate the value
										addItem((yyvsp[-3].string), "Var", (yyvsp[-4].ast), (yyvsp[-1].ast)->value, 0, currentScope);
										if(!strcmp(getVariableType((yyvsp[-3].string), currentScope), "int")) {
											int trunc = atoi((yyvsp[-1].ast)->value);
											sprintf((yyvsp[-1].ast)->value, "%d", trunc);
										}
										else if(!strcmp(getVariableType((yyvsp[-3].string), currentScope), "float")) {
											float trunc = atof((yyvsp[-1].ast)->value);
											sprintf((yyvsp[-1].ast)->value, "%f", trunc);
										}
										
										updateItem((yyvsp[-3].string), (yyvsp[-1].ast)->value, currentScope);
									}
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[-3].string));
									showSymTable(); 
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    (yyval.ast) = AST_Type("Type",(yyvsp[-4].ast),(yyvsp[-3].string));
									printf("-----------> %s", (yyval.ast)->LHS);

									emitVariableDeclaration(currentScope, (yyvsp[-4].ast), (yyvsp[-3].string), (yyvsp[-1].ast)->value);
									// emitMIPSVariableDeclaration(char* id, char* type, char* value)
									emitMIPSVariableDeclaration((yyvsp[-3].string), (yyvsp[-4].ast), (yyvsp[-1].ast)->value);

								}
#line 1664 "parser.tab.c"
    break;

  case 40: /* VarDecl: Type ID LEFTBRACKET Expr RIGHTBRACKET SEMICOLON  */
#line 456 "parser.y"
                                                  { 
    // Symbol Table
    symTabAccess();
    int inSymTab = found((yyvsp[-4].string), currentScope);
    if (inSymTab == -1) {
        // Add the array name to the symbol table
		// turn $4 into number
        addItem((yyvsp[-4].string), "Arr", (yyvsp[-5].ast), "", atoi((yyvsp[-2].ast)->value), currentScope);
    } else {
        printf("SEMANTIC ERROR: Array %s is already in the symbol table\n", (yyvsp[-4].string));
    }
	// for loop that makes empty entries as many times as the number in $4
	int i;
	char defaultVal[3];
	if(strcmp((yyvsp[-5].ast), "int") == 0)
		strcpy(defaultVal, "0");
	else if(strcmp((yyvsp[-5].ast), "float") == 0)
		strcpy(defaultVal, "0.0");	// if I don't do this, the default value is corrupted (0.!)
	else if(strcmp((yyvsp[-5].ast), "char") == 0)
		strcpy(defaultVal, "");
	
	for (i = 0; i < atoi((yyvsp[-2].ast)->value); i++) {
		// add i char to the end of $2
		char *arrName = malloc(strlen((yyvsp[-4].string)) + 2);
		strcpy(arrName, (yyvsp[-4].string));
		char iChar[2];
		sprintf(iChar, "%d", i);
		strcat(arrName, iChar);
		printf("the value of $$ is %s\n", (yyval.ast)->value);
		addItem((yyvsp[-4].string), "ArrVar", (yyvsp[-5].ast), defaultVal, 0, currentScope);
		(yyval.ast) = AST_Type("[]",(yyvsp[-5].ast),(yyvsp[-4].string));
	}
    showSymTable();

    // ---- SEMANTIC ACTIONS by PARSER ----
    (yyval.ast) = AST_Type("[]", (yyvsp[-5].ast), (yyvsp[-4].string));
    //printf("-----------> %s", $$->LHS);

	// turn number into string
	char arraySize[3];
	sprintf(arraySize, "%d", atoi((yyvsp[-2].ast)->value) * 4);
	emitMIPSArrayDeclaration((yyvsp[-4].string), arraySize); 

}
#line 1713 "parser.tab.c"
    break;

  case 41: /* Expr: NUMBER  */
#line 511 "parser.y"
                        { (yyval.ast) = (yyvsp[0].string); sprintf((yyval.ast)->value, "%s", (yyvsp[0].string)); sprintf((yyval.ast)->nodeType, "%s", "number"); }
#line 1719 "parser.tab.c"
    break;

  case 42: /* Expr: MINUS NUMBER  */
#line 512 "parser.y"
                             { (yyval.ast) = (yyvsp[0].string); sprintf((yyval.ast)->value, "-%s", (yyvsp[0].string)); sprintf((yyval.ast)->nodeType, "%s", "number"); }
#line 1725 "parser.tab.c"
    break;

  case 43: /* Expr: LEFTPARENTHESIS Expr RIGHTPARENTHESIS  */
#line 513 "parser.y"
                                                                 {(yyval.ast) = (yyvsp[-1].ast); sprintf((yyval.ast)->value, "%s", (yyvsp[-1].ast)->value);}
#line 1731 "parser.tab.c"
    break;

  case 44: /* Expr: UNARYNOT Expr  */
#line 514 "parser.y"
                        { (yyval.ast) = (yyvsp[0].ast); 

		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab1));
		}

		char stringVal[50];
		// check if 0 or 1, if so, flip it
		if(strcmp((yyvsp[0].ast)->value, "0") == 0)
			sprintf(stringVal, "%s", "1");
		else if(strcmp((yyvsp[0].ast)->value, "1") == 0)
			sprintf(stringVal, "%s", "0");
		else
			printf("SEMANTIC ERROR: Unary not can only be applied to 0 or 1.\n This was a %s\n", (yyvsp[0].ast)->value);

		// Generate AST for the addition
		// $$ = AST_BinaryExpression("!", NULL, $2); 

		// Perform the addition, and update the value of the expression
		sprintf((yyval.ast)->value, "%s", stringVal);
  
	}
#line 1773 "parser.tab.c"
    break;

  case 45: /* Expr: ID  */
#line 551 "parser.y"
             { (yyval.ast) = (yyvsp[0].string); sprintf((yyval.ast)->value, "%s", (yyvsp[0].string)); 
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[0].string), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyval.ast)->value, "%s", getValue(inSymTab1));
		}
	}
#line 1793 "parser.tab.c"
    break;

  case 46: /* Expr: ID LEFTBRACKET Expr RIGHTBRACKET  */
#line 568 "parser.y"
        {
		int inSymTab = found((yyvsp[-3].string), currentScope);

		if(inSymTab == 1) {
			printf("SEMANTIC ERROR: Array %s is not in the symbol table\n", (yyvsp[-3].string));
		} 
		else {
			int size = getArraySize((yyvsp[-3].string), currentScope);
			int index = atoi((yyvsp[-1].ast)->value);  

				if (index >= size) {
					printf("SEMANTIC ERROR: Index out of bounds for array %s\n", (yyvsp[-3].string));
					semanticCheckPassed = 0;
				} else { 
					// Construct the AST for the array indexing
					// $$ = AST_BinaryExpression($1, $3);
					sprintf((yyval.ast)->value, "%s", getValue(inSymTab + index));
					sprintf((yyval.ast)->nodeType, "%s", "[]"); 
					printf("Setting value of %s to %s" , (yyvsp[-3].string), getValue(inSymTab + index));
					// printf("hey guy, I am actually updating the symbol table here with %s\n", $3->value);
					// updateItemByID(inSymTab + index, $$->value);

					// sprintf($$->nodeType, "%s", "Arr"); 
					// turn $3 into number 
				} 
		} 
	}
#line 1825 "parser.tab.c"
    break;

  case 47: /* Expr: ID EQUAL Expr  */
#line 595 "parser.y"
                      {
        // Update the value of the variable in the symbol table
		int inSymTab = found((yyvsp[-2].string), currentScope);  
		printf("Recoginzed an assignment statement %s = %s\n", (yyvsp[-2].string), (yyvsp[0].ast)->value);
		// check if Expr nodeType is a number
		if((yyvsp[0].ast)->nodeType == "number") { 
			// Numbers don't exist in the symbol table. Skip this check.
			printf("it's a number\n");
		}
		else if (inSymTab == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0;
		} 
		else {
			// print the Expr
			printf( "Expr: %s", (yyvsp[0].ast)->value);

			// If the variable is an int, truncate the value
			if(!strcmp(getVariableType((yyvsp[-2].string), currentScope), "int")) {
				int trunc = atoi((yyvsp[0].ast)->value);
				sprintf((yyvsp[0].ast)->value, "%d", trunc);
			}
			else if(!strcmp(getVariableType((yyvsp[-2].string), currentScope), "float")) {
				float trunc = atof((yyvsp[0].ast)->value);
				sprintf((yyvsp[0].ast)->value, "%f", trunc); 
			}
 
            updateItem((yyvsp[-2].string), (yyvsp[0].ast)->value, currentScope);
            (yyval.ast) = AST_BinaryExpression("=", (yyvsp[-2].string), (yyvsp[0].ast)->value); 
        }

		emitAssignment(currentScope, (yyvsp[-2].string), (yyvsp[0].ast)->value);
		// emitMIPSVariableUpdate(char* id, char* value)
		emitMIPSVariableUpdate((yyvsp[-2].string), (yyvsp[0].ast)->value);
	  
     }
#line 1866 "parser.tab.c"
    break;

  case 48: /* Expr: ID LEFTBRACKET Expr RIGHTBRACKET EQUAL Expr  */
#line 631 "parser.y"
                                                       {
		 // Update the value of the variable in the symbol table
		int inSymTab = found((yyvsp[-5].string), currentScope);  

		// check if Expr nodeType is a number 
		if (inSymTab == -1) {
			printf("SEMANTIC ERROR: Array %s is not in the symbol table\n", (yyvsp[-5].string));
			semanticCheckPassed = 0;
		}
		else {  
			// $1 is an array's index, not the id.

			int size = getArraySize((yyvsp[-5].string), currentScope);
				if (atoi((yyvsp[-3].ast)) >= size) {
					printf("SEMANTIC ERROR: Index out of bounds for array %s\n", (yyvsp[-5].string));
					semanticCheckPassed = 0;
				} else {
					char* value = getValue(inSymTab + atoi((yyvsp[-3].ast)));
					// Create a new node for the array element
					printf("hey guys, I am actually updating the symbol table here with %s\n", (yyvsp[-5].string));
 
					// print the Expr

					if(!strcmp(getVariableType((yyvsp[-5].string), currentScope), "int")) {
						int trunc = atoi((yyvsp[0].ast)->value);
						sprintf((yyvsp[0].ast)->value, "%d", trunc); 
					}
					else if(!strcmp(getVariableType((yyvsp[-5].string), currentScope), "float")) {
						float trunc = atof((yyvsp[0].ast)->value);
						sprintf((yyvsp[0].ast)->value, "%f", trunc); 
					} 
					updateItemByID(inSymTab + atoi((yyvsp[-3].ast)->value), (yyvsp[0].ast)->value);

					(yyval.ast) = AST_BinaryExpression("[]", (yyvsp[-5].string), value); 
				}
		} 
 
		emitAssignment(currentScope, (yyvsp[-5].string), (yyvsp[-3].ast)->value);
		// emitMIPSArrayUpdateValue(char * id, char * index, char * value)
		// emitMIPSArrayUpdateValue($1, $3->value, $6->value);
		
	 }
#line 1913 "parser.tab.c"
    break;

  case 49: /* Expr: Expr PLUS Expr  */
#line 673 "parser.y"
                        {  
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table 
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		} 
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}
		// Generate AST for the addition
		(yyval.ast) = AST_BinaryExpression("+", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value); 

		// Perform the addition, and update the value of the expression
		char stringVal[50];
		sprintf(stringVal, "%d", atoi((yyvsp[-2].ast)->value) + atoi((yyvsp[0].ast)->value));
		sprintf((yyval.ast)->value, "%s", stringVal);

		// IR time
		emitBinaryOperation(currentScope, "+", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		}
#line 1964 "parser.tab.c"
    break;

  case 50: /* Expr: Expr MINUS Expr  */
#line 719 "parser.y"
                        { 
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		}  
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}
		char stringVal[50];
		// Perform the addition
		sprintf(stringVal, "%d", atoi((yyvsp[-2].ast)->value) - atoi((yyvsp[0].ast)->value));
		// Generate AST for the multiplication
		(yyval.ast) = AST_BinaryExpression("-", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value); 
		// Update the value of the expression
		sprintf((yyval.ast)->value, "%s", stringVal);

		// IR time
		emitBinaryOperation(currentScope, "-", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
	 }
#line 2015 "parser.tab.c"
    break;

  case 51: /* Expr: Expr MULTIPLY Expr  */
#line 765 "parser.y"
                           {
		printf("EXPR1 is %s", (yyvsp[-2].ast)->nodeType);
		printf("EXPR2 is %s", (yyvsp[0].ast)->nodeType); 
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);
		
		printf("inSymTab1: %d" , inSymTab1);
		printf("inSymTab2: %d" , inSymTab2);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		} 
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}
 
		char stringVal[50];
		// Perform the addition
		sprintf(stringVal, "%d", atoi((yyvsp[-2].ast)->value) * atoi((yyvsp[0].ast)->value));
		// Generate AST for the multiplication
		(yyval.ast) = AST_BinaryExpression("*", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value); 
		// Update the value of the expression
		sprintf((yyval.ast)->value, "%s", stringVal);

		// IR time
		emitBinaryOperation(currentScope, "*", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);

	 }
#line 2073 "parser.tab.c"
    break;

  case 52: /* Expr: Expr DIVIDE Expr  */
#line 818 "parser.y"
                        { 
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		} 
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Perform the addition, and update the value of the expression
		char stringVal[50];
		if(atoi((yyvsp[0].ast)->value) == 0) {
			printf("SEMANTIC ERROR: Cannot divide by 0!\n");
			exit(1);
			semanticCheckPassed = 0;
		}
		else {
			sprintf(stringVal, "%f", atof((yyvsp[-2].ast)->value) / atof((yyvsp[0].ast)->value));
			// type coercion for floats 
			if(strchr((yyvsp[-2].ast)->nodeType, 'float') != NULL || strchr((yyvsp[0].ast)->nodeType, 'float') != NULL || strchr((yyval.ast)->nodeType, 'float') != NULL) {
			} 
			
			sprintf(stringVal, "%f", atof((yyvsp[-2].ast)->value) / atof((yyvsp[0].ast)->value));


			// Generate AST for the addition
			(yyval.ast) = AST_BinaryExpression("/", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);  
			sprintf((yyval.ast)->value, "%s", stringVal);
		}

		// IR time
		emitBinaryOperation(currentScope, "/", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
     }
#line 2138 "parser.tab.c"
    break;

  case 53: /* Expr: Expr EQUAL_TO Expr  */
#line 878 "parser.y"
                              {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) == atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n"); 
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression("number", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value); 
		sprintf((yyval.ast)->value, "%s", stringVal);
		sprintf((yyval.ast)->condition, "%s", "==");
	 }
#line 2195 "parser.tab.c"
    break;

  case 54: /* Expr: Expr NOT_EQUAL_TO Expr  */
#line 930 "parser.y"
                                  {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) != atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression("number", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		// $$->left->nodeType = "=="; do this for array not string
		sprintf((yyval.ast)->value, "%s", stringVal); 
		sprintf((yyval.ast)->condition, "%s", "!=");
	 }
#line 2253 "parser.tab.c"
    break;

  case 55: /* Expr: Expr LESS_THAN Expr  */
#line 983 "parser.y"
                               {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table  
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) < atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression("number", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		sprintf((yyval.ast)->value, "%s", stringVal);
		sprintf((yyval.ast)->condition, "%s", "<");
	 }
#line 2310 "parser.tab.c"
    break;

  case 56: /* Expr: Expr LESS_THAN_OR_EQUAL_TO Expr  */
#line 1035 "parser.y"
                                           {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) <= atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression("number", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		sprintf((yyval.ast)->value, "%s", stringVal); 
		sprintf((yyval.ast)->condition, "%s", "<=");
	 }
#line 2367 "parser.tab.c"
    break;

  case 57: /* Expr: Expr GREATER_THAN Expr  */
#line 1087 "parser.y"
                                  {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) > atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression(">", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		sprintf((yyval.ast)->value, "%s", stringVal);
		sprintf((yyval.ast)->condition, "%s", ">");
	 }
#line 2424 "parser.tab.c"
    break;

  case 58: /* Expr: Expr GREATER_THAN_OR_EQUAL_TO Expr  */
#line 1139 "parser.y"
                                              {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) >= atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression("number", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		sprintf((yyval.ast)->value, "%s", stringVal);
		sprintf((yyval.ast)->condition, "%s", ">=");
	 }
#line 2481 "parser.tab.c"
    break;

  case 59: /* Expr: Expr LOGICALAND Expr  */
#line 1191 "parser.y"
                                {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);

		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
			printf("NODETYPE: %s\n\n\n\n\n\n\n", (yyvsp[-2].ast)->nodeType);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
						printf("NODETYPE: %s\n\n\n\n\n\n\n", (yyvsp[-2].ast)->nodeType);

			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2));
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) && atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}
				printf("ATTEMPTED: %s && %s", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression("number", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		sprintf((yyval.ast)->value, "%s", stringVal);
	 }
#line 2541 "parser.tab.c"
    break;

  case 60: /* Expr: Expr LOGICALOR Expr  */
#line 1246 "parser.y"
                               {
		// Check if the variables are in the symbol table
		int inSymTab1 = found((yyvsp[-2].ast), currentScope);
		int inSymTab2 = found((yyvsp[0].ast), currentScope);
  
		// Check if Expr $1's nodeType is a number or a variable
		if(strcmp((yyvsp[-2].ast)->nodeType, "number") == 0) {
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if(inSymTab1 == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[-2].ast)->value);
						printf("NODETYPE: %s\n\n\n\n\n\n\n", (yyvsp[-2].ast)->nodeType);

			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab1 != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[-2].ast)->value, "%s", getValue(inSymTab1));
		}

		// check if Expr $3's nodeType is a number
		if(strcmp((yyvsp[0].ast)->nodeType, "number") == 0) { 
			// Numbers don't exist in the symbol table. Skip this check.
		}
		// Variable is not in the symbol table
		else if (inSymTab2 == -1) {
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
						printf("NODETYPE: %s\n\n\n\n\n\n\n", (yyvsp[0].ast)->nodeType);

			semanticCheckPassed = 0; 
		}
		// Variable is in the symbol table
		else if(inSymTab2 != -1) {  
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab2)); 
		}

		// Check if the expression is true or false
		char stringVal[50];
		if(atoi((yyvsp[-2].ast)->value) || atoi((yyvsp[0].ast)->value)) {
			sprintf(stringVal, "%d", 1);
			printf("TRUE\n");
		}
		else {
			sprintf(stringVal, "%d", 0);
			printf("FALSE\n");  
		}

		printf("ATTEMPTED: %s || %s", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);

		// Generate AST for the less than expression
		(yyval.ast) = AST_BinaryExpression("number", (yyvsp[-2].ast)->value, (yyvsp[0].ast)->value);
		sprintf((yyval.ast)->value, "%s", stringVal);
	 }
#line 2603 "parser.tab.c"
    break;

  case 61: /* Expr: WRITE Expr  */
#line 1303 "parser.y"
                       {
		// Check if the variable is in the symbol table
		int inSymTab = found((yyvsp[0].ast), currentScope);
		// Variable is not in the symbol table
		if(inSymTab == -1) {
			// Variable is not in the symbol table
			printf("SEMANTIC ERROR: Variable %s is not in the symbol table\n", (yyvsp[0].ast)->value);
			semanticCheckPassed = 0;
		}
		// Variable is in the symbol table
		else if(inSymTab != -1) {
			// Update the value according to the symbol table
			sprintf((yyvsp[0].ast)->value, "%s", getValue(inSymTab));
		}  

		// Generate AST for the write statement
		(yyval.ast) = AST_Write((yyvsp[0].ast)->nodeType, (yyvsp[0].ast)->value, ""); 
		
		// Generate IR code for the write statement
		// emitWrite($2);

		// Generate MIPS code for the write statement
		emitMIPSWriteId((yyvsp[0].ast)->value);
	 }
#line 2632 "parser.tab.c"
    break;

  case 62: /* Expr: WRITELN LEFTPARENTHESIS RIGHTPARENTHESIS  */
#line 1327 "parser.y"
                                                    {  
		// Generate AST for the writeln statement
		(yyval.ast) = AST_Write("newline", "", "");
		// Generate MIPS code for the write statement
		emitMIPSNewLine();  

	 }
#line 2644 "parser.tab.c"
    break;


#line 2648 "parser.tab.c"

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

#line 1348 "parser.y"


int main(int argc, char**argv)
{
	strcpy(currentScope, "global");
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");
	 
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	} 

	// Initialize IR and MIPS files
	initIRcodeFile(); 
	initAssemblyFile();

	// Start parser
	yyparse();

	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();
	combineMIPSFiles(); 
	 
	showSymTable();
}
  
void yyerror(const char* s) { 
	fprintf(stderr, "Parse error: %s\n", s); 
	exit(1);
}

