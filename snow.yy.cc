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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "snow.y"


#include "parser.hpp"


#line 77 "snow.yy.cc"

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

#include "snow.yy.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_UNKNOW = 3,               /* TOKEN_UNKNOW  */
  YYSYMBOL_TOKEN_WORD = 4,                 /* TOKEN_WORD  */
  YYSYMBOL_TOKEN_STRING = 5,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_DEC = 6,                  /* TOKEN_DEC  */
  YYSYMBOL_TOKEN_HEX = 7,                  /* TOKEN_HEX  */
  YYSYMBOL_TOKEN_FLOAT = 8,                /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_EQUAL = 9,                /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_PLUS = 10,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_SUB = 11,                 /* TOKEN_SUB  */
  YYSYMBOL_TOKEN_TIMES = 12,               /* TOKEN_TIMES  */
  YYSYMBOL_TOKEN_DIVIDE = 13,              /* TOKEN_DIVIDE  */
  YYSYMBOL_TOKEN_LP = 14,                  /* TOKEN_LP  */
  YYSYMBOL_TOKEN_RP = 15,                  /* TOKEN_RP  */
  YYSYMBOL_TOKEN_LS = 16,                  /* TOKEN_LS  */
  YYSYMBOL_TOKEN_RS = 17,                  /* TOKEN_RS  */
  YYSYMBOL_TOKEN_LC = 18,                  /* TOKEN_LC  */
  YYSYMBOL_TOKEN_RC = 19,                  /* TOKEN_RC  */
  YYSYMBOL_TOKEN_LA = 20,                  /* TOKEN_LA  */
  YYSYMBOL_TOKEN_RA = 21,                  /* TOKEN_RA  */
  YYSYMBOL_TOKEN_DOUBLE_AND = 22,          /* TOKEN_DOUBLE_AND  */
  YYSYMBOL_TOKEN_DOUBLE_OR = 23,           /* TOKEN_DOUBLE_OR  */
  YYSYMBOL_TOKEN_DOUBLE_LA = 24,           /* TOKEN_DOUBLE_LA  */
  YYSYMBOL_TOKEN_DOUBLE_RA = 25,           /* TOKEN_DOUBLE_RA  */
  YYSYMBOL_TOKEN_DOUBLE_EQUAL = 26,        /* TOKEN_DOUBLE_EQUAL  */
  YYSYMBOL_TOKEN_LA_EQUAL = 27,            /* TOKEN_LA_EQUAL  */
  YYSYMBOL_TOKEN_RA_EQUAL = 28,            /* TOKEN_RA_EQUAL  */
  YYSYMBOL_TOKEN_NOT_EQUAL = 29,           /* TOKEN_NOT_EQUAL  */
  YYSYMBOL_TOKEN_AND = 30,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 31,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_QUESTION = 32,            /* TOKEN_QUESTION  */
  YYSYMBOL_TOKEN_POINT = 33,               /* TOKEN_POINT  */
  YYSYMBOL_TOKEN_BROKEN_ISSUE = 34,        /* TOKEN_BROKEN_ISSUE  */
  YYSYMBOL_TOKEN_EXCLAMATION = 35,         /* TOKEN_EXCLAMATION  */
  YYSYMBOL_TOKEN_AT = 36,                  /* TOKEN_AT  */
  YYSYMBOL_TOKEN_HASHTAG = 37,             /* TOKEN_HASHTAG  */
  YYSYMBOL_TOKEN_DOLLAR = 38,              /* TOKEN_DOLLAR  */
  YYSYMBOL_TOKEN_PERCENT = 39,             /* TOKEN_PERCENT  */
  YYSYMBOL_TOKEN_XOR = 40,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_COLON = 41,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_SEMICOLON = 42,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_BACKSLASH = 43,           /* TOKEN_BACKSLASH  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_expression = 45,                /* expression  */
  YYSYMBOL_op_logic_or = 46,               /* op_logic_or  */
  YYSYMBOL_op_logic_and = 47,              /* op_logic_and  */
  YYSYMBOL_op_or = 48,                     /* op_or  */
  YYSYMBOL_op_xor = 49,                    /* op_xor  */
  YYSYMBOL_op_and = 50,                    /* op_and  */
  YYSYMBOL_op_equal = 51,                  /* op_equal  */
  YYSYMBOL_op_relation = 52,               /* op_relation  */
  YYSYMBOL_op_bit = 53,                    /* op_bit  */
  YYSYMBOL_op_plus_sub = 54,               /* op_plus_sub  */
  YYSYMBOL_op_times_divide_mod = 55,       /* op_times_divide_mod  */
  YYSYMBOL_op_prefix = 56,                 /* op_prefix  */
  YYSYMBOL_op_suffix = 57,                 /* op_suffix  */
  YYSYMBOL_atom = 58                       /* atom  */
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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   54

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  65

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    42,    44,    51,    53,    60,    62,    69,
      71,    78,    80,    87,    89,    91,    98,   100,   102,   104,
     106,   113,   115,   117,   124,   126,   128,   135,   137,   139,
     141,   148,   150,   152,   154,   156,   163,   170,   172,   174
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_UNKNOW",
  "TOKEN_WORD", "TOKEN_STRING", "TOKEN_DEC", "TOKEN_HEX", "TOKEN_FLOAT",
  "TOKEN_EQUAL", "TOKEN_PLUS", "TOKEN_SUB", "TOKEN_TIMES", "TOKEN_DIVIDE",
  "TOKEN_LP", "TOKEN_RP", "TOKEN_LS", "TOKEN_RS", "TOKEN_LC", "TOKEN_RC",
  "TOKEN_LA", "TOKEN_RA", "TOKEN_DOUBLE_AND", "TOKEN_DOUBLE_OR",
  "TOKEN_DOUBLE_LA", "TOKEN_DOUBLE_RA", "TOKEN_DOUBLE_EQUAL",
  "TOKEN_LA_EQUAL", "TOKEN_RA_EQUAL", "TOKEN_NOT_EQUAL", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_QUESTION", "TOKEN_POINT", "TOKEN_BROKEN_ISSUE",
  "TOKEN_EXCLAMATION", "TOKEN_AT", "TOKEN_HASHTAG", "TOKEN_DOLLAR",
  "TOKEN_PERCENT", "TOKEN_XOR", "TOKEN_COLON", "TOKEN_SEMICOLON",
  "TOKEN_BACKSLASH", "$accept", "expression", "op_logic_or",
  "op_logic_and", "op_or", "op_xor", "op_and", "op_equal", "op_relation",
  "op_bit", "op_plus_sub", "op_times_divide_mod", "op_prefix", "op_suffix",
  "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-23)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -6,   -23,   -23,     5,     5,    -6,     5,     5,    26,    16,
      20,    12,     4,    15,     1,   -14,   -22,    24,    -3,   -23,
     -23,   -23,   -23,   -23,    31,   -23,   -23,   -23,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,   -23,    20,    12,     4,
      15,     1,   -14,   -14,   -22,   -22,   -22,   -22,    24,    24,
      -3,    -3,   -23,   -23,   -23
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    37,    38,     0,     0,     0,     0,     0,     0,     2,
       3,     5,     7,     9,    11,    13,    16,    21,    24,    27,
      31,    36,    32,    33,     0,    35,    34,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     4,     6,     8,
      10,    12,    14,    15,    17,    18,    19,    20,    22,    23,
      25,    26,    28,    29,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,    42,   -23,    21,    19,    22,    23,    18,   -18,   -13,
      -2,    -1,   -12,    14,   -23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       1,     2,    39,    40,     3,     4,    35,    36,     5,    43,
      44,     1,     2,    37,    38,    52,    53,    22,    23,     5,
      25,    26,    54,    55,    56,    57,    27,    33,     6,     7,
      34,    62,    63,    64,    41,    42,    45,    58,    59,    28,
      60,    61,    29,    30,    31,    32,    46,    24,    48,    47,
      51,     0,    49,     0,    50
};

static const yytype_int8 yycheck[] =
{
       6,     7,    24,    25,    10,    11,    20,    21,    14,    12,
      13,     6,     7,    27,    28,    33,    34,     3,     4,    14,
       6,     7,    35,    36,    37,    38,     0,    26,    34,    35,
      29,    43,    44,    45,    10,    11,    39,    39,    40,    23,
      41,    42,    22,    31,    40,    30,    15,     5,    29,    28,
      32,    -1,    30,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    10,    11,    14,    34,    35,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    57,    57,    45,    57,    57,     0,    23,    22,
      31,    40,    30,    26,    29,    20,    21,    27,    28,    24,
      25,    10,    11,    12,    13,    39,    15,    47,    48,    49,
      50,    51,    52,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    57,    58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     2,     1,     1,     1,     3
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
        yyerror (parser, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, parser); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *parser)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parser);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *parser)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parser);
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
                 int yyrule, void *parser)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parser); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *parser)
{
  YY_USE (yyvaluep);
  YY_USE (parser);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *parser)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, yylexer);
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
  case 2: /* expression: op_logic_or  */
#line 35 "snow.y"
            { yyval = yyvsp[0]; }
#line 1171 "snow.yy.cc"
    break;

  case 3: /* op_logic_or: op_logic_and  */
#line 42 "snow.y"
             { yyval = yyvsp[0]; }
#line 1177 "snow.yy.cc"
    break;

  case 4: /* op_logic_or: op_logic_or TOKEN_DOUBLE_OR op_logic_and  */
#line 44 "snow.y"
                                         { yyval = yyvsp[-2] || yyvsp[0]; printf("result: %ld = %ld || %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1183 "snow.yy.cc"
    break;

  case 5: /* op_logic_and: op_or  */
#line 51 "snow.y"
      { yyval = yyvsp[0]; }
#line 1189 "snow.yy.cc"
    break;

  case 6: /* op_logic_and: op_logic_and TOKEN_DOUBLE_AND op_or  */
#line 53 "snow.y"
                                    { yyval = yyvsp[-2] && yyvsp[0]; printf("result: %ld = %ld && %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1195 "snow.yy.cc"
    break;

  case 7: /* op_or: op_xor  */
#line 60 "snow.y"
       { yyval = yyvsp[0]; }
#line 1201 "snow.yy.cc"
    break;

  case 8: /* op_or: op_or TOKEN_OR op_xor  */
#line 62 "snow.y"
                      { yyval = yyvsp[-2] | yyvsp[0]; printf("result: %ld = %ld | %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1207 "snow.yy.cc"
    break;

  case 9: /* op_xor: op_and  */
#line 69 "snow.y"
       { yyval = yyvsp[0]; }
#line 1213 "snow.yy.cc"
    break;

  case 10: /* op_xor: op_xor TOKEN_XOR op_and  */
#line 71 "snow.y"
                        { yyval = yyvsp[-2] ^ yyvsp[0]; printf("result: %ld = %ld ^ %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1219 "snow.yy.cc"
    break;

  case 11: /* op_and: op_equal  */
#line 78 "snow.y"
         { yyval = yyvsp[0]; }
#line 1225 "snow.yy.cc"
    break;

  case 12: /* op_and: op_and TOKEN_AND op_equal  */
#line 80 "snow.y"
                          { yyval = yyvsp[-2] & yyvsp[0]; printf("result: %ld = %ld & %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1231 "snow.yy.cc"
    break;

  case 13: /* op_equal: op_relation  */
#line 87 "snow.y"
            { yyval = yyvsp[0]; }
#line 1237 "snow.yy.cc"
    break;

  case 14: /* op_equal: op_equal TOKEN_DOUBLE_EQUAL op_relation  */
#line 89 "snow.y"
                                        { yyval = yyvsp[-2] == yyvsp[0]; printf("result: %ld = %ld == %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1243 "snow.yy.cc"
    break;

  case 15: /* op_equal: op_equal TOKEN_NOT_EQUAL op_relation  */
#line 91 "snow.y"
                                     { yyval = yyvsp[-2] != yyvsp[0]; printf("result: %ld = %ld != %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1249 "snow.yy.cc"
    break;

  case 16: /* op_relation: op_bit  */
#line 98 "snow.y"
       { yyval = yyvsp[0]; }
#line 1255 "snow.yy.cc"
    break;

  case 17: /* op_relation: op_relation TOKEN_LA op_bit  */
#line 100 "snow.y"
                            { yyval = yyvsp[-2] < yyvsp[0]; printf("result: %ld = %ld < %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1261 "snow.yy.cc"
    break;

  case 18: /* op_relation: op_relation TOKEN_RA op_bit  */
#line 102 "snow.y"
                            { yyval = yyvsp[-2] > yyvsp[0]; printf("result: %ld = %ld > %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1267 "snow.yy.cc"
    break;

  case 19: /* op_relation: op_relation TOKEN_LA_EQUAL op_bit  */
#line 104 "snow.y"
                                  { yyval = yyvsp[-2] <= yyvsp[0]; printf("result: %ld = %ld <= %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1273 "snow.yy.cc"
    break;

  case 20: /* op_relation: op_relation TOKEN_RA_EQUAL op_bit  */
#line 106 "snow.y"
                                  { yyval = yyvsp[-2] >= yyvsp[0]; printf("result: %ld = %ld >= %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1279 "snow.yy.cc"
    break;

  case 21: /* op_bit: op_plus_sub  */
#line 113 "snow.y"
            { yyval = yyvsp[0]; }
#line 1285 "snow.yy.cc"
    break;

  case 22: /* op_bit: op_bit TOKEN_DOUBLE_LA op_plus_sub  */
#line 115 "snow.y"
                                   { yyval = yyvsp[-2] << yyvsp[0]; printf("result: %ld = %ld << %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1291 "snow.yy.cc"
    break;

  case 23: /* op_bit: op_bit TOKEN_DOUBLE_RA op_plus_sub  */
#line 117 "snow.y"
                                   { yyval = yyvsp[-2] >> yyvsp[0]; printf("result: %ld = %ld >> %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1297 "snow.yy.cc"
    break;

  case 24: /* op_plus_sub: op_times_divide_mod  */
#line 124 "snow.y"
                    { yyval = yyvsp[0]; }
#line 1303 "snow.yy.cc"
    break;

  case 25: /* op_plus_sub: op_plus_sub TOKEN_PLUS op_times_divide_mod  */
#line 126 "snow.y"
                                           { yyval = yyvsp[-2] + yyvsp[0]; printf("result: %ld = %ld + %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1309 "snow.yy.cc"
    break;

  case 26: /* op_plus_sub: op_plus_sub TOKEN_SUB op_times_divide_mod  */
#line 128 "snow.y"
                                          { yyval = yyvsp[-2] - yyvsp[0]; printf("result: %ld = %ld - %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1315 "snow.yy.cc"
    break;

  case 27: /* op_times_divide_mod: op_prefix  */
#line 135 "snow.y"
          { yyval = yyvsp[0]; }
#line 1321 "snow.yy.cc"
    break;

  case 28: /* op_times_divide_mod: op_times_divide_mod TOKEN_TIMES op_prefix  */
#line 137 "snow.y"
                                          { yyval = yyvsp[-2] * yyvsp[0]; printf("result: %ld = %ld * %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1327 "snow.yy.cc"
    break;

  case 29: /* op_times_divide_mod: op_times_divide_mod TOKEN_DIVIDE op_prefix  */
#line 139 "snow.y"
                                           { yyval = yyvsp[-2] / yyvsp[0]; printf("result: %ld = %ld / %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1333 "snow.yy.cc"
    break;

  case 30: /* op_times_divide_mod: op_times_divide_mod TOKEN_PERCENT op_prefix  */
#line 141 "snow.y"
                                            { yyval = yyvsp[-2] % yyvsp[0]; printf("result: %ld = %ld mod %ld\n", yyval, yyvsp[-2], yyvsp[0]); }
#line 1339 "snow.yy.cc"
    break;

  case 31: /* op_prefix: op_suffix  */
#line 148 "snow.y"
          { yyval = yyvsp[0]; }
#line 1345 "snow.yy.cc"
    break;

  case 32: /* op_prefix: TOKEN_PLUS op_suffix  */
#line 150 "snow.y"
                     { yyval = +(yyvsp[0]); printf("result: %ld = + %ld\n", yyval, yyvsp[0]); }
#line 1351 "snow.yy.cc"
    break;

  case 33: /* op_prefix: TOKEN_SUB op_suffix  */
#line 152 "snow.y"
                    { yyval = -(yyvsp[0]); printf("result: %ld = - %ld\n", yyval, yyvsp[0]); }
#line 1357 "snow.yy.cc"
    break;

  case 34: /* op_prefix: TOKEN_EXCLAMATION op_suffix  */
#line 154 "snow.y"
                            { yyval = !(yyvsp[0]); printf("result: %ld = ! %ld\n", yyval, yyvsp[0]); }
#line 1363 "snow.yy.cc"
    break;

  case 35: /* op_prefix: TOKEN_BROKEN_ISSUE op_suffix  */
#line 156 "snow.y"
                             { yyval = ~(yyvsp[0]); printf("result: %ld = ~ %ld\n", yyval, yyvsp[0]); }
#line 1369 "snow.yy.cc"
    break;

  case 36: /* op_suffix: atom  */
#line 163 "snow.y"
     { yyval = yyvsp[0]; }
#line 1375 "snow.yy.cc"
    break;

  case 37: /* atom: TOKEN_DEC  */
#line 170 "snow.y"
          { yyval = strtol(yyget_text(yylexer), NULL, 10); }
#line 1381 "snow.yy.cc"
    break;

  case 38: /* atom: TOKEN_HEX  */
#line 172 "snow.y"
          { yyval = strtol(yyget_text(yylexer), NULL, 16); }
#line 1387 "snow.yy.cc"
    break;

  case 39: /* atom: TOKEN_LP expression TOKEN_RP  */
#line 174 "snow.y"
                             { yyval = yyvsp[-1]; }
#line 1393 "snow.yy.cc"
    break;


#line 1397 "snow.yy.cc"

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
      yyerror (parser, YY_("syntax error"));
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
                      yytoken, &yylval, parser);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parser);
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
  yyerror (parser, YY_("memory exhausted"));
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
                  yytoken, &yylval, parser);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parser);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 177 "snow.y"

