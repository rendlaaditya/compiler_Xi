/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "calc.y" /* yacc.c:339  */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include "calc.h"  /* Contains definition of `symrec'        */
int  yylex(void);
void yyerror (char  *);
int b=0,n=1;
int r=7;
int labels=0;
int count=0;
int labelcount=0;
FILE *fp;
struct StmtsNode *final;
struct node *afinal;
void StmtsTrav(stmtsptr ptr);
void StmtTrav(stmtptr ptr);
void mipscodeprinter(struct node* root,int b);
int max(int a,int b);
int min(int a,int b);
void doer(struct node* ptr);
void makeershov(struct node* root);

#line 90 "calc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "calc.tab.h".  */
#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    RELOP = 259,
    WHILE = 260,
    MAIN = 261,
    IF = 262,
    ELSE = 263,
    INT = 264,
    BOOL = 265,
    VAR = 266
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "calc.y" /* yacc.c:355  */

int   val;  /* For returning numbers.                   */
char *str;/*for returning strings*/
struct symrec  *tptr;   /* For returning symbol-table pointers      */
char c[1000];
char nData[100];
struct node *e;
struct StmtNode *stmtptr;
struct StmtsNode *stmtsptr;

#line 153 "calc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "calc.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  32
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  86

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   266

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      18,    19,    15,    14,     2,    13,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,    23,
       2,    12,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,    21,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    63,    65,    70,    71,    74,    75,    76,
      77,    91,   103,   109,   114,   121,   125,   127,   131,   134,
     137,   140,   144,   146,   148,   151,   153,   157,   160,   163,
     167,   172,   173
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "RELOP", "WHILE", "MAIN", "IF",
  "ELSE", "INT", "BOOL", "VAR", "'='", "'-'", "'+'", "'*'", "'/'", "'\\n'",
  "'('", "')'", "'{'", "'}'", "':'", "';'", "'['", "']'", "$accept",
  "prog", "stmts", "stmt", "exp", "bexp", "elsestmt", "x", "digits", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,    61,    45,    43,    42,    47,    10,    40,    41,
     123,   125,    58,    59,    91,    93
};
# endif

#define YYPACT_NINF -26

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-26)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,   -26,   -15,   -10,    -5,     0,   -26,    25,   -26,    46,
       3,    11,     3,    20,    18,    51,   -26,   -26,   -26,    39,
      47,    58,    78,    63,    59,    42,    20,    21,   -26,   -26,
      32,    68,    60,    67,    62,   -26,    75,    83,     4,    76,
      73,    74,    20,    20,    20,    20,   -26,   -26,    36,   -26,
      85,    86,   -26,   -26,     4,   -26,    79,     4,    77,    80,
     -26,    65,    65,   -26,   -26,    81,    20,    20,    82,   -26,
      87,   -26,   -26,    84,    45,    56,   -26,    91,   -26,   -26,
     -26,    89,   -26,     4,    90,   -26
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,     0,     0,     0,     0,     5,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     1,     4,    32,     0,
       0,     0,     0,     0,     0,    28,     0,     0,    16,    27,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     7,     0,     8,
       0,     0,    22,    24,     0,    23,     0,     0,     0,     0,
      21,    18,    17,    19,    20,     0,     0,     0,     0,     6,
       0,    30,    29,     0,     0,     0,    11,    25,     9,    14,
      13,     0,    10,     0,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,    -9,   -26,   -25,    92,   -26,   -26,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    27,    21,    82,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    41,    22,    10,    22,     1,    18,    33,    11,     2,
       3,     4,    13,    12,    19,     5,    20,    61,    62,    63,
      64,     6,    14,    18,    15,    16,    53,    30,    31,    56,
      23,    25,    59,    20,    42,    43,    44,    45,    26,    18,
      65,    74,    75,    34,    46,    68,    -3,     1,    70,    20,
      35,     2,     3,     4,    18,    47,    48,     5,    42,    43,
      44,    45,    32,     6,    20,    18,    40,    -3,    79,    42,
      43,    44,    45,    52,    84,    20,    18,    36,    39,    80,
      44,    45,    37,    38,    58,    50,    20,    42,    43,    44,
      45,    49,    51,    60,    55,    54,    57,    66,    67,    81,
      69,     0,    71,    76,    24,    72,    73,    78,    77,    83,
       0,    85
};

static const yytype_int8 yycheck[] =
{
       9,    26,    10,    18,    12,     1,     3,    15,    18,     5,
       6,     7,    12,    18,    11,    11,    13,    42,    43,    44,
      45,    17,    22,     3,    24,     0,    34,     9,    10,    38,
      19,    11,    40,    13,    13,    14,    15,    16,    18,     3,
      48,    66,    67,     4,    23,    54,     0,     1,    57,    13,
       3,     5,     6,     7,     3,    23,    24,    11,    13,    14,
      15,    16,    11,    17,    13,     3,    24,    21,    23,    13,
      14,    15,    16,    11,    83,    13,     3,    19,    19,    23,
      15,    16,     4,    20,    11,    25,    13,    13,    14,    15,
      16,    23,    25,    19,    11,    20,    20,    12,    12,     8,
      21,    -1,    25,    21,    12,    25,    25,    23,    21,    20,
      -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,     6,     7,    11,    17,    27,    28,    29,
      18,    18,    18,    12,    22,    24,     0,    28,     3,    11,
      13,    31,    34,    19,    31,    11,    18,    30,    33,    34,
       9,    10,    11,    34,     4,     3,    19,     4,    20,    19,
      24,    30,    13,    14,    15,    16,    23,    23,    24,    23,
      25,    25,    11,    34,    20,    11,    28,    20,    11,    34,
      19,    30,    30,    30,    30,    34,    12,    12,    28,    21,
      28,    25,    25,    25,    30,    30,    21,    21,    23,    23,
      23,     8,    32,    20,    28,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    28,    28,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    30,    30,    30,    30,
      30,    30,    31,    31,    31,    32,    32,    33,    33,    33,
      33,    34,    34
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     6,     4,     4,     7,
       8,     7,     4,     7,     7,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     4,     1,     1,     4,
       4,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 62 "calc.y" /* yacc.c:1646  */
    {final=(yyvsp[0].stmtsptr);}
#line 1295 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 63 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtsptr)=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
   (yyval.stmtsptr)->singl=1;(yyval.stmtsptr)->left=(yyvsp[0].stmtptr),(yyval.stmtsptr)->right=NULL;}
#line 1302 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtsptr)=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
   (yyval.stmtsptr)->singl=0;(yyval.stmtsptr)->left=(yyvsp[-1].stmtptr),(yyval.stmtsptr)->right=(yyvsp[0].stmtsptr);}
#line 1309 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=NULL;}
#line 1315 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));(yyval.stmtptr)->ismain=1;
		(yyval.stmtptr)->downstmts=(yyvsp[-1].stmtsptr);
		}
#line 1323 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "calc.y" /* yacc.c:1646  */
    {printf("1\n");symrec *s;s=getsym((yyvsp[-3].str));if (s==0) s=putsym((yyvsp[-3].str),VAR,4);(yyval.stmtptr)=NULL;printf("2\n");}
#line 1329 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "calc.y" /* yacc.c:1646  */
    {symrec *s;s=getsym((yyvsp[-3].str));if (s==0) s=putsym((yyvsp[-3].str),VAR,4);(yyval.stmtptr)=NULL;}
#line 1335 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "calc.y" /* yacc.c:1646  */
    {symrec *s=getsym((yyvsp[-6].str));if (s==0) s=putsym((yyvsp[-6].str),VAR,4*(yyvsp[-2].val));(yyval.stmtptr)=NULL;}
#line 1341 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
				if ((yyvsp[0].stmtsptr)!=NULL){
						(yyval.stmtptr)->isif=0;(yyval.stmtptr)->isWhile=0;(yyval.stmtptr)->iselse=1;}
				else{(yyval.stmtptr)->isif=1;(yyval.stmtptr)->isWhile=0;(yyval.stmtptr)->iselse=0;}
						sprintf((yyval.stmtptr)->initCode,"%s", (yyvsp[-5].stmtptr)->initCode);
					    int rr=(yyvsp[-5].stmtptr)->relop;
					    if (rr==0){sprintf((yyval.stmtptr)->initJumpCode,"bne $t0, $t1, ");}
					    else if (rr==1){sprintf((yyval.stmtptr)->initJumpCode,"beq $t0, $t1, ");}
					    else if (rr==2){sprintf((yyval.stmtptr)->initJumpCode,"bge $t0, $t1, ");}
					    else if (rr==3){sprintf((yyval.stmtptr)->initJumpCode,"ble $t0, $t1, ");}
					    else if (rr==4){sprintf((yyval.stmtptr)->initJumpCode,"bgt $t0, $t1, ");}
					    else if (rr==5){sprintf((yyval.stmtptr)->initJumpCode,"blt $t0, $t1, ");}
					    (yyval.stmtptr)->downstmts=(yyvsp[-2].stmtsptr);(yyval.stmtptr)->downelse=(yyvsp[0].stmtsptr);			
				}
#line 1360 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 91 "calc.y" /* yacc.c:1646  */
    {printf("while1\n");(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    (yyval.stmtptr)->isWhile=1;(yyval.stmtptr)->isif=0;(yyval.stmtptr)->iselse=0;
	    sprintf((yyval.stmtptr)->initCode,"%s", (yyvsp[-4].stmtptr)->initCode);
	    int rr=(yyvsp[-4].stmtptr)->relop;
	    if (rr==0){sprintf((yyval.stmtptr)->initJumpCode,"bne $t0, $t1, ");}
	    else if (rr==1){sprintf((yyval.stmtptr)->initJumpCode,"beq $t0, $t1, ");}
	    else if (rr==2){sprintf((yyval.stmtptr)->initJumpCode,"bge $t0, $t1, ");}
	    else if (rr==3){sprintf((yyval.stmtptr)->initJumpCode,"ble $t0, $t1, ");}
	    else if (rr==4){sprintf((yyval.stmtptr)->initJumpCode,"bgt $t0, $t1, ");}
	    else if (rr==5){sprintf((yyval.stmtptr)->initJumpCode,"blt $t0, $t1, ");}
	    (yyval.stmtptr)->downstmts=(yyvsp[-1].stmtsptr);
	  }
#line 1377 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    (yyval.stmtptr)->isWhile=0;(yyval.stmtptr)->isif=0;(yyval.stmtptr)->iselse=0;symrec *s=getsym((yyvsp[-3].str));
	    /*sprintf($$->bodyCode,"%s\nsw $t0,%s($t8)\n", $3, $1->addr);*/
	    sprintf((yyval.stmtptr)->tostore,"%d",atoi(s->addr));
	    (yyval.stmtptr)->down=(yyvsp[-1].e);
	    /*printf("%s\n",$1->addr);*/}
#line 1388 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "calc.y" /* yacc.c:1646  */
    {printf("entered arr assgn\n");(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    (yyval.stmtptr)->isWhile=0;(yyval.stmtptr)->isif=0;(yyval.stmtptr)->iselse=0;symrec *s=getsym((yyvsp[-6].str));(yyval.stmtptr)->isarray=2;
	    sprintf((yyval.stmtptr)->tostore,"%d",atoi(s->addr)+4*(yyvsp[-4].val));
	    (yyval.stmtptr)->down=(yyvsp[-1].e);printf("exit arr assgn\n");
	}
#line 1398 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 114 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    (yyval.stmtptr)->isWhile=0;(yyval.stmtptr)->isif=0;(yyval.stmtptr)->iselse=0;symrec *s=getsym((yyvsp[-6].str));symrec *s1=getsym((yyvsp[-4].str));
		(yyval.stmtptr)->isarray=1;
	    sprintf((yyval.stmtptr)->tostore,"%s",s->addr);
	    sprintf((yyval.stmtptr)->index,"%s",s1->addr);
	    (yyval.stmtptr)->down=(yyvsp[-1].e);
	}
#line 1410 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 121 "calc.y" /* yacc.c:1646  */
    { yyerrok; }
#line 1416 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 125 "calc.y" /* yacc.c:1646  */
    { (yyval.e)=(struct node *) malloc(sizeof(struct node));
			(yyval.e)=(yyvsp[0].e);}
#line 1423 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));
			(yyval.e)->left=(yyvsp[-2].e);(yyval.e)->right=(yyvsp[0].e);(yyval.e)->leafbool=0;(yyval.e)->op='+';
				}
#line 1431 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));
				(yyval.e)->left=(yyvsp[-2].e);(yyval.e)->right=(yyvsp[0].e);(yyval.e)->leafbool=0;(yyval.e)->op='-';
			}
#line 1439 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));
				 (yyval.e)->left=(yyvsp[-2].e);(yyval.e)->right=(yyvsp[0].e);(yyval.e)->leafbool=0;(yyval.e)->op='*';
			}
#line 1447 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 137 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));
				(yyval.e)->left=(yyvsp[-2].e);(yyval.e)->right=(yyvsp[0].e);(yyval.e)->leafbool=0;(yyval.e)->op='/';
			}
#line 1455 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));
				 (yyval.e)=(yyvsp[-1].e);
			}
#line 1463 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 144 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode)); symrec *s=getsym((yyvsp[-2].str));symrec *s2=getsym((yyvsp[0].str));
		        sprintf((yyval.stmtptr)->initCode,"lw $t0, %s($t%d)\nlw $t1, %s($t%d)\n",s->addr,r+1,s2->addr,r+1);(yyval.stmtptr)->relop=(yyvsp[-1].val);}
#line 1470 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));symrec *s=getsym((yyvsp[0].str));
                        sprintf((yyval.stmtptr)->initCode,"li $t0, %d\nlw $t1, %s($t%d)\n", (yyvsp[-2].val),s->addr,r+1);(yyval.stmtptr)->relop=(yyvsp[-1].val);}
#line 1477 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 148 "calc.y" /* yacc.c:1646  */
    {printf("enterred relop bexp\n");(yyval.stmtptr)=(struct StmtNode *) malloc(sizeof(struct StmtNode));symrec *s=getsym((yyvsp[-2].str));
		        sprintf((yyval.stmtptr)->initCode,"lw $t0, %s($t%d)\nli $t1, %d\n", s->addr,r+1,(yyvsp[0].val));(yyval.stmtptr)->relop=(yyvsp[-1].val);printf("exit relop bexp\n");}
#line 1484 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtsptr)=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
				(yyval.stmtsptr)=NULL;}
#line 1491 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 153 "calc.y" /* yacc.c:1646  */
    {(yyval.stmtsptr)=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
				(yyval.stmtsptr)=(yyvsp[-1].stmtsptr);
				}
#line 1499 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 157 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));
		(yyval.e)->left=NULL;(yyval.e)->right=NULL;(yyval.e)->leafbool=1;(yyval.e)->isnum=1;
		sprintf((yyval.e)->address,"%d",(yyvsp[0].val));}
#line 1507 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 160 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));
		(yyval.e)->left=NULL;(yyval.e)->right=NULL;(yyval.e)->leafbool=1;(yyval.e)->isnum=0;symrec *s=getsym((yyvsp[0].str));
		sprintf((yyval.e)->address,"%s",s->addr);/*printf("%s this is number value",$$->address);*/}
#line 1515 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 163 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));symrec *s=getsym((yyvsp[-3].str));
			(yyval.e)->left=NULL;(yyval.e)->right=NULL;(yyval.e)->leafbool=1;(yyval.e)->isnum=0;(yyval.e)->isarray=1;(yyval.e)->arrind=(yyvsp[-1].val);
					sprintf((yyval.e)->address,"%s",s->addr);
			}
#line 1524 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 167 "calc.y" /* yacc.c:1646  */
    {(yyval.e)=(struct node *) malloc(sizeof(struct node));(yyval.e)->isarray=2;symrec *a=getsym((yyvsp[-3].str));symrec *b=getsym((yyvsp[-1].str));
			(yyval.e)->left=NULL;(yyval.e)->right=NULL;(yyval.e)->leafbool=1;(yyval.e)->isnum=0;
		sprintf((yyval.e)->aind,"%s",b->addr);sprintf((yyval.e)->address,"%s",a->addr);
		}
#line 1533 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "calc.y" /* yacc.c:1646  */
    {(yyval.val)=-(yyvsp[0].val);}
#line 1539 "calc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 173 "calc.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1545 "calc.tab.c" /* yacc.c:1646  */
    break;


#line 1549 "calc.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 176 "calc.y" /* yacc.c:1906  */


void StmtsTrav(stmtsptr ptr){
	  //printf("%d\n",ptr->singl);
	  if(ptr->singl==1)StmtTrav(ptr->left);
	  else{
	  	StmtTrav(ptr->left);
	  	StmtsTrav(ptr->right);
	  }
}
void doer(e ptr){
	makeershov(ptr);
	//printf("ershov %d",ptr->ershov);
	mipscodeprinter(ptr,1);
}
void StmtTrav(stmtptr ptr){
	if (ptr!=NULL){
		//printf("iswhile %d\n",ptr->isWhile);
	  	if(ptr->isif==1){
			fprintf(fp,"Lbl%d:\n",labelcount);
			fprintf(fp,"%s",ptr->initCode);
			fprintf(fp,"%s",ptr->initJumpCode);
			fprintf(fp,"Lbl%d\n",labelcount+1);
			StmtsTrav(ptr->downstmts);
			fprintf(fp,"j Lbl%d\n",labelcount+1);
			labelcount=labelcount+2;
		}
		else if (ptr->iselse==1){
			fprintf(fp,"Lbl%d:\n",labelcount);
			fprintf(fp,"%s",ptr->initCode);
			fprintf(fp,"%s",ptr->initJumpCode);
			fprintf(fp,"Lbl%d\n",labelcount+1);
			StmtsTrav(ptr->downstmts);
			fprintf(fp,"j Lbl%d\n",labelcount+2);
			fprintf(fp,"Lbl%d:\n",labelcount+1);
			StmtsTrav(ptr->downelse);
			fprintf(fp,"Lbl%d:\n",labelcount+2);
			labelcount=labelcount+2;
		}
	  	else if (ptr->isWhile==1){	
			fprintf(fp,"\nLbl%d:\n",labelcount);
			fprintf(fp,"%s",ptr->initCode);
			fprintf(fp,"%s",ptr->initJumpCode);
			fprintf(fp,"Lbl%d\n",labelcount+1);
			StmtsTrav(ptr->downstmts);
			fprintf(fp,"j Lbl%d\n",labelcount);
			fprintf(fp,"\nLbl%d:\n",labelcount+1);
			labelcount=labelcount+1;		
		}
		else if (ptr->isarray==1){
			int offs=atoi(ptr->tostore);
			doer(ptr->down);
			fprintf(fp,"li $t%d, %s($t%d) \n",ptr->down->ershov-1,ptr->index,r+1);
			fprintf(fp,"muli $t%d, $t%d, 4 \n",ptr->down->ershov-1,ptr->down->ershov-1);
			fprintf(fp,"addi $t%d, $t%d, %s\n",ptr->down->ershov-1,ptr->down->ershov-1,ptr->tostore);
			fprintf(fp,"add  $t%d, $t%d, $t%d\n",ptr->down->ershov-1,ptr->down->ershov-1,r+1);
			fprintf(fp,"sw $t%d, 0($t%d)\n",ptr->down->ershov,ptr->down->ershov-1);
		}
		else if (ptr->ismain==1){
			fprintf(fp,"\n main:\n");
			StmtsTrav(ptr->downstmts);
		}
		else{
		fprintf(fp,"%s",ptr->bodyCode);doer(ptr->down);fprintf(fp,"sw t%d %s($t%d)\n",ptr->down->ershov,
			ptr->tostore,r+1);
		}
	}
	else{
		//makeershov(ptr);
		//mipscodeprinter(ptr,1);	
	}
}
void makeershov(struct node*root){
	if (root==NULL)	root->ershov=0;
	else if(root->leafbool==1) {root->ershov=1;}
	else {
		makeershov(root->left);
		makeershov(root->right);
		int b=root->left->ershov;
		int c=root->right->ershov;
		if (b==c){
			root->ershov=b+1;
		}
		else if(b>c) root->ershov=b;
		else root->ershov=c;
	}
	//printf("printing ershov %d\n",root->ershov);
}
int max(int a,int b){
	if (a>=b) return a;
	return b;
}
int min(int a,int b){
	if (a>b) return b;
	return a;
}
void mipscodeprinter(struct node* root,int b){
	int genr;
	if (root->leafbool==1){
		if (root->isnum==1){
			//printf("root->address=%s\n",root->address);
			fprintf(fp,"li $t%d %s\n",b,root->address);
		}
		else if(root->isarray==1){ fprintf(fp,"lw $t%d %d($t%d)\n",b,atoi(root->address)+4*root->arrind,r+1);
		}
		else if(root->isarray=2){ fprintf(fp,"lw $t%d, %s($t%d)\n",b,root->aind,r+1);
				fprintf(fp,"muli $t%d, $t%d ,4\n",b,b);
				fprintf(fp,"add  $t%d, $t%d, %s\n",b,b,root->address);
				fprintf(fp,"add  $t%d, $t%d, $t%d\n",b,b,r+1);
				fprintf(fp,"lw   $t%d, 0($t%d)\n",b,b);
		}
		else{
			fprintf(fp,"lw $t%d %s($t%d)\n",b,root->address,r+1);
		}
	}
	else {
		int kr=root->right->ershov;
		int kl=root->left->ershov;
		if (max(kr,kl)<=r){
			if (kr==kl){
				mipscodeprinter(root->right,b+1);
				mipscodeprinter(root->left,b);
				if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
				else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
				else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
				else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
			}
			else{
				if (kr>kl) genr=1;
				else genr=0;
				if (genr==1){
					mipscodeprinter(root->right,b);
					mipscodeprinter(root->left,b);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
				}
				else {
					mipscodeprinter(root->right,b);
					mipscodeprinter(root->left,b);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",b+kl-1,b+kr-1,b+kl-1);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",b+kl-1,b+kl-1,b+kr-1);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",b+kl-1,b+kl-1,b+kr-1);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",b+kl-1,b+kl-1,b+kr-1);
				}
			}
		}
		else{
				if (kr>kl) genr=1;
				else genr=0;
				if (genr==1){
					mipscodeprinter(root->right,1);
					fprintf(fp,"sw $r0, $t%d\n",r);
					if (kl>r){mipscodeprinter(root->left,1);}
					else{mipscodeprinter(root->left,r-root->left->ershov+1);}
					fprintf(fp,"lw $t%d $r0",r-1);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",r,r,r-1);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",r,r,r-1);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",r,r,r-1);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",r,r,r-1);
				}
				else{
					mipscodeprinter(root->left,1);
					fprintf(fp,"sw $r0, $t%d\n",r);
					if (kr>r){mipscodeprinter(root->right,1);}
					else{mipscodeprinter(root->right,r-root->right->ershov+1);}
					fprintf(fp,"lw $t%d $r0",r-1);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",r,r-1,r);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",r,r-1,r);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",r,r-1,r);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",r,r-1,r);
				}
		}
	}
}

int main ()
{
   fp=fopen("asmb.asm","w");
   fprintf(fp,".data\n\n.text\nli $t%d,268500992\n",r+1);
   yyparse ();
	//makerershov();
   StmtsTrav(final);
   fprintf(fp,"\nli $v0,1\nmove $a0,$t0\nsyscall\n");
   fclose(fp);
}

void yyerror (char *s)  /* Called by yyparse on error */
{
  printf ("%s\n", s);
}


