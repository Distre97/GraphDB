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
#line 1 "Graph.b" /* yacc.c:339  */

#include <stdio.h>
#include "Graph.h"
int yylex();
int yyerror(char*);
_ID vid;
_ID eid;
_IDS ids;
_IDS fids;
_IDS tids;
_IDS vids;
_IDS eids;
_IDS tmp_ids;
_popes tmp_pv;
_lists keys;
bool vert;
Direc  dir;
string name;
string label;
string equation;
std::vector<_IDS> tmp_idsv;
auto& graph = Graph::getInstance();

#line 90 "bison.cpp" /* yacc.c:339  */

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
   by #include "bison.hpp".  */
#ifndef YY_YY_BISON_HPP_INCLUDED
# define YY_YY_BISON_HPP_INCLUDED
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
    OR = 258,
    AND = 259,
    OPERATOR = 260,
    ONE = 261,
    INTEGER = 262,
    INT_STRING = 263,
    DOUBLE = 264,
    DOUBLE_STRING = 265,
    WHITESPACE = 266,
    NEWLINE = 267,
    NODE = 268,
    EDGE = 269,
    ID = 270,
    IDENTIFIER = 271,
    TRUE = 272,
    FALSE = 273,
    GRAPH = 274,
    CREATE = 275,
    MATCH = 276,
    DELETE = 277,
    RETURN = 278,
    WITH = 279,
    SET = 280,
    EXIT = 281,
    BRACKET = 282,
    SBRACKET = 283,
    CAMPARE = 284,
    COLON = 285,
    SEMICOLON = 286,
    COMMA = 287,
    POINT = 288,
    FROM = 289,
    TO = 290,
    ANY = 291,
    OF = 292,
    MAX = 293,
    MIN = 294,
    AVG = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "Graph.b" /* yacc.c:355  */

	int ivar;
	char* cvar;
	double dvar;

#line 177 "bison.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "bison.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    55,    56,    59,    60,    61,    62,    63,
      66,    67,    70,    71,    72,    73,    74,    75,    78,    79,
      80,    83,    90,    99,   101,   103,   110,   111,   114,   119,
     124,   129,   134,   139,   144,   149,   155,   156,   159,   165,
     171,   179,   186,   194,   202,   207,   213,   218,   224,   230,
     235,   243,   250,   260,   268,   273,   286,   299,   312,   326,
     332,   337,   350,   363,   376,   390,   396,   402,   408,   416,
     422,   428,   434,   441,   442,   445,   454,   463,   471,   479,
     487,   492,   501,   511,   513,   514,   515,   516,   517,   518,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     543,   551,   561
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR", "AND", "OPERATOR", "ONE",
  "INTEGER", "INT_STRING", "DOUBLE", "DOUBLE_STRING", "WHITESPACE",
  "NEWLINE", "NODE", "EDGE", "ID", "IDENTIFIER", "TRUE", "FALSE", "GRAPH",
  "CREATE", "MATCH", "DELETE", "RETURN", "WITH", "SET", "EXIT", "BRACKET",
  "SBRACKET", "CAMPARE", "COLON", "SEMICOLON", "COMMA", "POINT", "FROM",
  "TO", "ANY", "OF", "MAX", "MIN", "AVG", "$accept", "Program",
  "Statement", "match", "operate", "STRING", "create_node", "create_edge",
  "edge_from", "edge_to", "ln_dict", "bool", "pv_dict", "id", "match_node",
  "any_edge", "with_edge", "match_edge", "node_logic", "n_logic",
  "edge_logic", "e_logic", "n_logic_fomula", "e_logic_fomula", "property",
  "return", "set", "pp_assign", "fore", "behind", "delete", "quit", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,     2,    17,  -151,  -151,    -1,     6,  -151,    40,    35,
    -151,  -151,  -151,  -151,  -151,    26,    65,    38,    77,  -151,
      72,    36,    81,  -151,    35,    35,    35,    87,   100,    96,
     121,   118,   125,   134,  -151,   134,   132,   136,   137,   154,
    -151,  -151,  -151,   141,   156,   145,   170,   149,   121,   151,
      59,  -151,   170,   152,   125,   155,   153,  -151,  -151,    78,
      79,   164,   166,   168,   157,    80,   158,    13,   169,   159,
      82,   156,  -151,    14,   105,   160,   167,   121,   121,    43,
     110,   162,   161,   125,   125,  -151,  -151,  -151,  -151,  -151,
    -151,    70,   163,  -151,  -151,    74,  -151,    20,   165,   122,
    -151,    83,  -151,   167,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,   121,   121,   174,  -151,  -151,   186,  -151,
    -151,  -151,  -151,  -151,  -151,   125,   125,   -12,   171,   188,
    -151,    22,    24,    34,   138,  -151,  -151,   126,   172,   173,
     175,   142,    75,  -151,  -151,  -151,  -151,   176,  -151,  -151,
      18,   177,   179,    19,   178,   181,   180,  -151,   -10,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,   182,   184,   185,   146,   187,   183,  -151,
    -151,   125,  -151,  -151,    23,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,   187,  -151,   189,  -151,   133,    49,
      68,  -151,  -151,  -151,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     0,   112,     0,     7,
       5,     6,    10,    11,     9,     0,     0,     0,     0,     3,
     110,    76,     0,     8,    14,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,     0,     0,     0,
      17,    15,    16,     0,     0,     0,     0,     0,     0,     0,
      53,    54,     0,     0,     0,     0,    59,    60,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,    74,   111,    75,    77,    78,
      79,     0,     0,    81,    82,     0,    90,    83,     0,     0,
      21,     0,    37,    38,    66,    19,    67,    20,    18,    26,
      27,    68,    65,     0,     0,     0,    41,    43,    56,    55,
      48,    70,    71,    72,    69,     0,     0,     0,     0,    62,
      61,    29,    30,    18,     0,    31,    28,     0,    91,    92,
      93,     0,     0,   100,    25,    29,    30,     0,    40,    42,
      56,    55,     0,    62,    61,     0,     0,    23,     0,    50,
      87,    88,    89,    33,    34,    35,    32,    97,    98,    99,
      94,    95,    96,   101,   102,   103,     0,     0,     0,    58,
      57,     0,    64,    63,     0,    52,    51,    24,   107,   108,
     109,   104,   105,   106,     0,    22,     0,    49,     0,     0,
       0,    46,    47,    44,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,  -151,   135,   -72,  -151,  -151,  -142,  -150,
    -151,   -70,   -37,   190,    -2,    95,    98,  -151,  -151,   -45,
      32,   -53,  -151,  -151,   191,  -151,  -151,  -151,  -151,  -151,
    -151,  -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    23,   135,    10,    11,   128,   159,
      44,   136,    65,    73,   187,   116,   117,    13,    49,    50,
      55,    56,    51,    57,    59,    24,    25,    66,    67,    97,
      26,    14
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    81,   111,    75,   112,   178,   185,    70,   123,   155,
     124,   155,    15,    16,     3,    -2,     1,     4,    95,    17,
      18,   102,    78,    84,   156,   142,   186,   -84,   195,   -85,
     129,   130,   118,   119,   101,    -2,    -2,     5,     6,   -86,
      96,    -2,   103,     7,   155,   179,   182,   143,   202,   -84,
     102,   -85,    19,    29,    27,    34,   201,    20,    21,   197,
      22,   -86,    77,    78,    35,   165,    30,   166,   150,   151,
     155,   120,   153,   154,    36,    37,    38,   131,   105,   132,
     107,   138,   173,   139,   174,   203,   133,   109,   110,   155,
     140,   175,    31,    28,    85,    85,    92,   134,    92,    92,
      33,   141,   176,    43,   204,    32,    86,    87,    93,    39,
     100,   147,   104,   105,   106,   107,    45,   121,   105,   122,
     107,   108,   109,   110,    46,   157,   108,   109,   110,   145,
     105,   146,   107,   163,   105,   164,   107,    47,   108,   109,
     110,    53,   108,   109,   110,   160,    52,   161,    48,   170,
      58,   171,    54,   191,   162,   192,    83,    84,   172,    40,
      41,    42,   193,   113,   114,   125,   126,   199,   200,    61,
      64,    68,    69,    62,    63,   157,    71,    72,    74,    76,
      88,    80,    89,    82,    90,    98,    94,    91,   152,    99,
      78,   115,    84,   137,    17,   127,   144,   157,   148,   167,
     168,   149,   169,     0,   180,   183,   158,   181,   155,   188,
     177,   189,   190,   196,     0,   184,     0,   198,   194,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79
};

static const yytype_int16 yycheck[] =
{
       2,    54,    74,    48,    74,   147,   156,    44,    80,    21,
      80,    21,    13,    14,    12,     0,     1,     0,     5,    13,
      14,     7,     4,     4,    36,     5,    36,     5,   178,     5,
      83,    84,    77,    78,    71,    20,    21,    20,    21,     5,
      27,    26,    28,    26,    21,    27,    27,    27,   198,    27,
       7,    27,    12,    15,    28,    19,   198,    22,    23,    36,
      25,    27,     3,     4,    28,   137,    28,   137,   113,   114,
      21,    28,   125,   126,    38,    39,    40,     7,     8,     9,
      10,     7,     7,     9,     9,    36,    16,    17,    18,    21,
      16,    16,    15,    28,    16,    16,    16,    27,    16,    16,
      28,    27,    27,    16,    36,    28,    28,    28,    28,    28,
      28,    28,     7,     8,     9,    10,    16,     7,     8,     9,
      10,    16,    17,    18,    28,   127,    16,    17,    18,     7,
       8,     9,    10,     7,     8,     9,    10,    16,    16,    17,
      18,    16,    16,    17,    18,     7,    28,     9,    27,     7,
      16,     9,    27,     7,    16,     9,     3,     4,    16,    24,
      25,    26,    16,     3,     4,     3,     4,    34,    35,    37,
      16,    30,    16,    37,    37,   177,    31,     7,    29,    28,
      16,    29,    16,    28,    16,    16,    28,    30,    14,    30,
       4,    24,     4,    30,    13,    34,    31,   199,   103,    27,
      27,   103,    27,    -1,    27,    27,    35,    28,    21,    27,
      34,    27,    27,   181,    -1,    35,    -1,    28,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    42,    12,     0,    20,    21,    26,    43,    44,
      47,    48,    55,    58,    72,    13,    14,    13,    14,    12,
      22,    23,    25,    45,    66,    67,    71,    28,    28,    15,
      28,    15,    28,    28,    19,    28,    38,    39,    40,    28,
      45,    45,    45,    16,    51,    16,    28,    16,    27,    59,
      60,    63,    28,    16,    27,    61,    62,    64,    16,    65,
      65,    37,    37,    37,    16,    53,    68,    69,    30,    16,
      53,    31,     7,    54,    29,    60,    28,     3,     4,    54,
      29,    62,    28,     3,     4,    16,    28,    28,    16,    16,
      16,    30,    16,    28,    28,     5,    27,    70,    16,    30,
      28,    53,     7,    28,     7,     8,     9,    10,    16,    17,
      18,    46,    52,     3,     4,    24,    56,    57,    60,    60,
      28,     7,     9,    46,    52,     3,     4,    34,    49,    62,
      62,     7,     9,    16,    27,    46,    52,    30,     7,     9,
      16,    27,     5,    27,    31,     7,     9,    28,    56,    57,
      60,    60,    14,    62,    62,    21,    36,    55,    35,    50,
       7,     9,    16,     7,     9,    46,    52,    27,    27,    27,
       7,     9,    16,     7,     9,    16,    27,    34,    49,    27,
      27,    28,    27,    27,    35,    50,    36,    55,    27,    27,
      27,     7,     9,    16,    35,    50,    61,    36,    28,    34,
      35,    49,    50,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    45,    46,    46,
      46,    47,    48,    49,    50,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    59,    60,    60,    60,    60,    60,    61,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     6,     9,     2,     2,     4,     1,     1,     3,     3,
       3,     3,     4,     4,     4,     4,     1,     2,     6,     5,
       7,     6,     7,     6,     7,     7,     6,     6,     6,     9,
       7,     8,     8,     1,     1,     3,     3,     5,     5,     1,
       1,     3,     3,     5,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     4,     1,     4,     4,     4,
       2,     4,     4,     2,     3,     3,     3,     4,     4,     4,
       1,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       1,     4,     1
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
        case 4:
#line 56 "Graph.b" /* yacc.c:1646  */
    {yyclearin;yyerrok;}
#line 1423 "bison.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "Graph.b" /* yacc.c:1646  */
    {vert = true;tmp_idsv.clear();}
#line 1429 "bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "Graph.b" /* yacc.c:1646  */
    {vert = false;tmp_idsv.clear();}
#line 1435 "bison.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "Graph.b" /* yacc.c:1646  */
    {
                vid = graph.add_vert(name, label, tmp_pv);
                tmp_pv.clear();
			  	//printf("create_node %s %s\n\n",$4,$5);
			  }
#line 1445 "bison.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 91 "Graph.b" /* yacc.c:1646  */
    {
  			  	auto edge = _edge(*fids.begin(), *tids.begin());
  			  	fids.clear();
                tids.clear();
  			  	eid = graph.add_edge(edge, string((yyvsp[-5].cvar)), tmp_pv);
                tmp_pv.clear();
  			  }
#line 1457 "bison.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 99 "Graph.b" /* yacc.c:1646  */
    {fids = vids;}
#line 1463 "bison.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 101 "Graph.b" /* yacc.c:1646  */
    {tids = vids;}
#line 1469 "bison.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 104 "Graph.b" /* yacc.c:1646  */
    {
			//printf("label:%s	name:%s\n",$1,$3);
			name = (yyvsp[-1].cvar);
			label = (yyvsp[-3].cvar);
		}
#line 1479 "bison.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 115 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:bool\n",$1,$3);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(3, string((yyvsp[0].cvar))))));
		}
#line 1488 "bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:integer\n",$1,$3);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(1, string((yyvsp[0].cvar))))));
		}
#line 1497 "bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 125 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:double\n",$1,$3);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(2, string((yyvsp[0].cvar))))));
		}
#line 1506 "bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 130 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:string\n",$1,$3);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(0, string((yyvsp[0].cvar))))));
		}
#line 1515 "bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 135 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:bool\n",$2,$4);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(3, string((yyvsp[0].cvar))))));
		}
#line 1524 "bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 140 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:integer\n",$2,$4);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(1, string((yyvsp[0].cvar))))));
		}
#line 1533 "bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 145 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:double\n",$2,$4);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(2, string((yyvsp[0].cvar))))));
		}
#line 1542 "bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 150 "Graph.b" /* yacc.c:1646  */
    {
			//printf("property:%s	value:%s type:string\n",$2,$4);
			tmp_pv.emplace_back(_prop(string((yyvsp[-2].cvar)), make_data(_pack(0, string((yyvsp[0].cvar))))));
		}
#line 1551 "bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 155 "Graph.b" /* yacc.c:1646  */
    {/*printf("id:%s\n", $2);*/ids.emplace(atoi((yyvsp[0].cvar)));}
#line 1557 "bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 156 "Graph.b" /* yacc.c:1646  */
    {/*printf("id:%s\n", $2);*/ids.emplace(atoi((yyvsp[0].cvar)));}
#line 1563 "bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 160 "Graph.b" /* yacc.c:1646  */
    {
				//printf("match_id_1\n");
				vids = ids;
				ids.clear();
			}
#line 1573 "bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "Graph.b" /* yacc.c:1646  */
    {
				//printf("match_node_1\n");
				vids = tmp_idsv[(yyvsp[-1].ivar)];
				//cout<< *vids.begin();
			}
#line 1583 "bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 172 "Graph.b" /* yacc.c:1646  */
    {
				//printf("match_id_2\n");
				vids = ids;
				ids.clear();
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			}
#line 1595 "bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 180 "Graph.b" /* yacc.c:1646  */
    {
				//printf("match_node_2\n");
				vids = tmp_idsv[(yyvsp[-2].ivar)];
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			}
#line 1606 "bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 187 "Graph.b" /* yacc.c:1646  */
    {
				//printf("match_id_3\n");
				vids = ids;
				ids.clear();
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			}
#line 1618 "bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 195 "Graph.b" /* yacc.c:1646  */
    {
				//printf("match_node_3\n");
				vids = tmp_idsv[(yyvsp[-2].ivar)];
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			}
#line 1629 "bison.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "Graph.b" /* yacc.c:1646  */
    {
				dir = Direc::TO;
		  		eids = tmp_idsv[(yyvsp[-3].ivar)];
			}
#line 1638 "bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 208 "Graph.b" /* yacc.c:1646  */
    {
		  		dir = Direc::FROM;
		  		eids = tmp_idsv[(yyvsp[-3].ivar)];
		  	}
#line 1647 "bison.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 214 "Graph.b" /* yacc.c:1646  */
    {
				dir = Direc::TO;
		  		eids = tmp_idsv[(yyvsp[-2].ivar)] & graph.inq_edge(fids, Direc::OUT);
			}
#line 1656 "bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 219 "Graph.b" /* yacc.c:1646  */
    {
				dir = Direc::FROM;
		  		eids = tmp_idsv[(yyvsp[-2].ivar)] & graph.inq_edge(tids, Direc::IN);
			}
#line 1665 "bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 225 "Graph.b" /* yacc.c:1646  */
    {
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = ids;
				ids.clear();
			}
#line 1675 "bison.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 231 "Graph.b" /* yacc.c:1646  */
    {
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[(yyvsp[-5].ivar)];
			}
#line 1684 "bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 236 "Graph.b" /* yacc.c:1646  */
    {
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[(yyvsp[-3].ivar)];
				tmp_ids = graph.inq_edge(fids, Direc::OUT) & graph.inq_edge(tids, Direc::IN);
				eids = eids & tmp_ids;

			}
#line 1696 "bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 244 "Graph.b" /* yacc.c:1646  */
    {
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[(yyvsp[-4].ivar)];
				tmp_ids = graph.inq_edge(fids, Direc::OUT);
				eids = eids & tmp_ids;
			}
#line 1707 "bison.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 251 "Graph.b" /* yacc.c:1646  */
    {
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[(yyvsp[-4].ivar)];
				//cout<<*eids.begin()<<endl;
				tmp_ids = graph.inq_edge(tids, Direc::IN);
				eids = eids & tmp_ids;
				//cout<<*tmp_ids.begin()<<endl;
			}
#line 1720 "bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 261 "Graph.b" /* yacc.c:1646  */
    {
				if ((yyvsp[0].ivar)<0)
					(yyval.ivar) = -1*(yyvsp[0].ivar)-1;
				else
					(yyval.ivar)=(yyvsp[0].ivar);
			}
#line 1731 "bison.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 269 "Graph.b" /* yacc.c:1646  */
    {
			//printf("logic %s\n",$1);
			(yyval.ivar) = (yyvsp[0].ivar);
		}
#line 1740 "bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 274 "Graph.b" /* yacc.c:1646  */
    {
			_IDS ids1;
			_IDS ids2;
			//printf("AND %d %d\n",$1,$3);
			if ((yyvsp[-2].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-2].ivar)-1];
			else ids1 = tmp_idsv[(yyvsp[-2].ivar)];
			if ((yyvsp[0].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[0].ivar)-1];
			else ids2 = tmp_idsv[(yyvsp[0].ivar)];
			tmp_ids = ids1 & ids2;
			tmp_idsv.emplace_back(tmp_ids);
			(yyval.ivar) = -1*tmp_idsv.size();
		}
#line 1757 "bison.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 287 "Graph.b" /* yacc.c:1646  */
    {
	   		_IDS ids1;
	   		_IDS ids2;
	   		//printf("OR %d %d\n",$1,$3);
	   		if ((yyvsp[-2].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-2].ivar)-1];
	   		else ids1 = tmp_idsv[(yyvsp[-2].ivar)];
	   		if ((yyvsp[0].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[0].ivar)-1];
	   		else ids2 = tmp_idsv[(yyvsp[0].ivar)];
	   		tmp_ids = ids1 | ids2;
	   		tmp_idsv.emplace_back(tmp_ids);
	   		(yyval.ivar) = -1*tmp_idsv.size();
	   }
#line 1774 "bison.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 300 "Graph.b" /* yacc.c:1646  */
    {
	   		_IDS ids1;
	   		_IDS ids2;
	   		//printf("AND %d %d\n",$2,$4);
	   		if ((yyvsp[-3].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-3].ivar)-1];
	   		else ids1 = tmp_idsv[(yyvsp[-3].ivar)];
	   		if ((yyvsp[-1].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-1].ivar)-1];
	   		else ids2 = tmp_idsv[(yyvsp[-1].ivar)];
	   		tmp_ids = ids1 & ids2;
	   		tmp_idsv.emplace_back(tmp_ids);
	   		(yyval.ivar) = -1*tmp_idsv.size();
	   }
#line 1791 "bison.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 313 "Graph.b" /* yacc.c:1646  */
    {
	   		_IDS ids1;
	   		_IDS ids2;
	   		//printf("OR %d %d\n",$2,$4);
	   		if ((yyvsp[-3].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-3].ivar)-1];
	   		else ids1 = tmp_idsv[(yyvsp[-3].ivar)];
	   		if ((yyvsp[-1].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-1].ivar)-1];
	   		else ids2 = tmp_idsv[(yyvsp[-1].ivar)];
	   		tmp_ids = ids1 | ids2;
	   		tmp_idsv.emplace_back(tmp_ids);
	   		(yyval.ivar) = -1*tmp_idsv.size();
	   }
#line 1808 "bison.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 326 "Graph.b" /* yacc.c:1646  */
    {
	if ((yyvsp[0].ivar)<0)
		(yyval.ivar) = -1*(yyvsp[0].ivar)-1;
	else
		(yyval.ivar)=(yyvsp[0].ivar);
}
#line 1819 "bison.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 333 "Graph.b" /* yacc.c:1646  */
    {
			//printf("logic %s\n",$1);
			(yyval.ivar) = (yyvsp[0].ivar);
		}
#line 1828 "bison.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 338 "Graph.b" /* yacc.c:1646  */
    {
			_IDS ids1;
			_IDS ids2;
			//printf("AND %d %d\n",$1,$3);
			if ((yyvsp[-2].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-2].ivar)-1];
			else ids1 = tmp_idsv[(yyvsp[-2].ivar)];
			if ((yyvsp[0].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[0].ivar)-1];
			else ids2 = tmp_idsv[(yyvsp[0].ivar)];
			tmp_ids = ids1 & ids2;
			tmp_idsv.emplace_back(tmp_ids);
			(yyval.ivar) = -1*tmp_idsv.size();
		}
#line 1845 "bison.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 351 "Graph.b" /* yacc.c:1646  */
    {
			_IDS ids1;
			_IDS ids2;
			//printf("OR %d %d\n",$1,$3);
			if ((yyvsp[-2].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-2].ivar)-1];
			else ids1 = tmp_idsv[(yyvsp[-2].ivar)];
			if ((yyvsp[0].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[0].ivar)-1];
			else ids2 = tmp_idsv[(yyvsp[0].ivar)];
			tmp_ids = ids1 | ids2;
			tmp_idsv.emplace_back(tmp_ids);
			(yyval.ivar) = -1*tmp_idsv.size();
		}
#line 1862 "bison.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 364 "Graph.b" /* yacc.c:1646  */
    {
			_IDS ids1;
			_IDS ids2;
			//printf("AND %d %d\n",$2,$4);
			if ((yyvsp[-3].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-3].ivar)-1];
			else ids1 = tmp_idsv[(yyvsp[-3].ivar)];
			if ((yyvsp[-1].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-1].ivar)-1];
			else ids2 = tmp_idsv[(yyvsp[-1].ivar)];
			tmp_ids = ids1 & ids2;
			tmp_idsv.emplace_back(tmp_ids);
			(yyval.ivar) = -1*tmp_idsv.size();
		}
#line 1879 "bison.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 377 "Graph.b" /* yacc.c:1646  */
    {
			_IDS ids1;
			_IDS ids2;
			//printf("OR %d %d\n",$2,$4);
			if ((yyvsp[-3].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-3].ivar)-1];
			else ids1 = tmp_idsv[(yyvsp[-3].ivar)];
			if ((yyvsp[-1].ivar) < 0) ids1 = tmp_idsv[-1*(yyvsp[-1].ivar)-1];
			else ids2 = tmp_idsv[(yyvsp[-1].ivar)];
			tmp_ids = ids1 | ids2;
			tmp_idsv.emplace_back(tmp_ids);
			(yyval.ivar) = -1*tmp_idsv.size();
		}
#line 1896 "bison.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 391 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(3, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1906 "bison.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 397 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(1, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1916 "bison.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 403 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(2, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1926 "bison.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 409 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(0, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1936 "bison.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 417 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(3, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1946 "bison.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 423 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(1, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1956 "bison.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 429 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(2, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1966 "bison.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 435 "Graph.b" /* yacc.c:1646  */
    {
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string((yyvsp[-1].cvar))),_prop(string((yyvsp[-2].cvar)), make_data(_pack(0, string((yyvsp[0].cvar))))))));
					(yyval.ivar) = tmp_idsv.size() - 1;
				}
#line 1976 "bison.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 441 "Graph.b" /* yacc.c:1646  */
    {/*printf("%s\n",$1);*/keys.emplace_back(string((yyvsp[0].cvar)));}
#line 1982 "bison.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 442 "Graph.b" /* yacc.c:1646  */
    {/*printf("%s\n",$1);*/keys.emplace_back(string((yyvsp[0].cvar)));}
#line 1988 "bison.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 446 "Graph.b" /* yacc.c:1646  */
    {
			//printf("return ok\n\n");
			if (vert)
				graph.show_vert(vids, keys);
			else
				graph.show_edge(eids, keys);
			keys.clear();
		}
#line 2001 "bison.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 455 "Graph.b" /* yacc.c:1646  */
    {
			//printf("return ok\n\n");
			if (vert)
				graph.show_vert(vids,{});
			else
				graph.show_edge(eids,{});
			//cout<<*eids.begin()<<endl;
		}
#line 2014 "bison.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 464 "Graph.b" /* yacc.c:1646  */
    {
			//printf("return %s\n\n",$2);
			if (vert)
				graph.inq_vert(string((yyvsp[0].cvar)), Stats::MAX, vids);
			else
				graph.inq_edge(string((yyvsp[0].cvar)), Stats::MAX, eids);
		}
#line 2026 "bison.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 472 "Graph.b" /* yacc.c:1646  */
    {
			//printf("return %s\n\n",$2);
			if (vert)
				graph.inq_vert(string((yyvsp[0].cvar)), Stats::MIN, vids);
			else
				graph.inq_edge(string((yyvsp[0].cvar)), Stats::MIN, eids);
		}
#line 2038 "bison.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 480 "Graph.b" /* yacc.c:1646  */
    {
			//printf("return %s\n\n",$2);
			if (vert)
				graph.inq_vert(string((yyvsp[0].cvar)), Stats::AVG, vids);
			else
				graph.inq_edge(string((yyvsp[0].cvar)), Stats::AVG, eids);
		}
#line 2050 "bison.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 488 "Graph.b" /* yacc.c:1646  */
    {
			graph.show_graph(vids);
		}
#line 2058 "bison.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 493 "Graph.b" /* yacc.c:1646  */
    {
		//printf("set ok\n\n");
		if (vert)
			for (auto id : vids) graph.add_vert_prop(id, tmp_pv);
		else
			for (auto id : eids) graph.add_edge_prop(id, tmp_pv);
		tmp_pv.clear();
	}
#line 2071 "bison.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 502 "Graph.b" /* yacc.c:1646  */
    {
		//printf("set ok\n\n");cout<<equation;
		if (vert)
				graph.alt_vert(vids, equation);
			else
				graph.alt_edge(eids, equation);
		equation="";
	}
#line 2084 "bison.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 513 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+"="+string((yyvsp[0].cvar));}
#line 2090 "bison.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 514 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+"="+string((yyvsp[0].cvar));}
#line 2096 "bison.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 515 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+"="+string((yyvsp[0].cvar));}
#line 2102 "bison.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 516 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-3].cvar))+"="+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2108 "bison.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 517 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-3].cvar))+"="+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2114 "bison.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 518 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-3].cvar))+"="+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2120 "bison.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 521 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[0].cvar));}
#line 2126 "bison.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 522 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2132 "bison.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 523 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2138 "bison.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 524 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2144 "bison.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 525 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2150 "bison.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 526 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2156 "bison.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 527 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2162 "bison.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 528 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2168 "bison.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 529 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2174 "bison.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 530 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2180 "bison.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 531 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[0].cvar));}
#line 2186 "bison.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 532 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2192 "bison.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 533 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2198 "bison.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 534 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2204 "bison.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 535 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2210 "bison.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 536 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2216 "bison.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 537 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2222 "bison.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 538 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2228 "bison.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 539 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2234 "bison.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 540 "Graph.b" /* yacc.c:1646  */
    {equation = equation+string((yyvsp[-2].cvar))+string((yyvsp[-1].cvar))+string((yyvsp[0].cvar));}
#line 2240 "bison.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 544 "Graph.b" /* yacc.c:1646  */
    {
			//printf("DELETE_ok_1\n\n");
			if (vert)
				graph.del_vert(vids);
			else
				graph.del_edge(eids);
		}
#line 2252 "bison.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 552 "Graph.b" /* yacc.c:1646  */
    {
			//printf("DELETE_ok_2\n\n");
			if (vert)
				graph.del_vert(vids, keys);
			else
				graph.del_edge(eids, keys);
			keys.clear();
		}
#line 2265 "bison.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 562 "Graph.b" /* yacc.c:1646  */
    {
		  graph.save();
		  printf("Graph_db closed\n");
		  exit(0);
	  }
#line 2275 "bison.cpp" /* yacc.c:1646  */
    break;


#line 2279 "bison.cpp" /* yacc.c:1646  */
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
#line 568 "Graph.b" /* yacc.c:1906  */

int yyerror(char *s)
	{
        fprintf(stdout, "%s\n", s);
        return 0;
    }

int main(void)
{
	yyparse();
	return 1;
}
