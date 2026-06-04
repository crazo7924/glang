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
#line 1 "src/parser.y"

#include "ast.hpp"
#include <iostream>
#include <vector>

extern int yylex();
extern int yylineno;
void yyerror(const char *s) {
    std::cerr << "Error at line " << yylineno << ": " << s << std::endl;
}

extern std::unique_ptr<ProgramNode> programBlock;

#line 85 "src/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_IDENTIFIER = 3,               /* T_IDENTIFIER  */
  YYSYMBOL_T_INTEGER = 4,                  /* T_INTEGER  */
  YYSYMBOL_T_FLOAT = 5,                    /* T_FLOAT  */
  YYSYMBOL_T_TYPE_INT = 6,                 /* T_TYPE_INT  */
  YYSYMBOL_T_TYPE_FLOAT = 7,               /* T_TYPE_FLOAT  */
  YYSYMBOL_T_IF = 8,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 9,                     /* T_ELSE  */
  YYSYMBOL_T_WHILE = 10,                   /* T_WHILE  */
  YYSYMBOL_T_RETURN = 11,                  /* T_RETURN  */
  YYSYMBOL_T_DELIMITER = 12,               /* T_DELIMITER  */
  YYSYMBOL_T_ASSIGN = 13,                  /* T_ASSIGN  */
  YYSYMBOL_T_EQ = 14,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 15,                     /* T_NEQ  */
  YYSYMBOL_T_LT = 16,                      /* T_LT  */
  YYSYMBOL_T_LTE = 17,                     /* T_LTE  */
  YYSYMBOL_T_GT = 18,                      /* T_GT  */
  YYSYMBOL_T_GTE = 19,                     /* T_GTE  */
  YYSYMBOL_T_PLUS = 20,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 21,                   /* T_MINUS  */
  YYSYMBOL_T_MUL = 22,                     /* T_MUL  */
  YYSYMBOL_T_DIV = 23,                     /* T_DIV  */
  YYSYMBOL_T_LPAREN = 24,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 25,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACE = 26,                  /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 27,                  /* T_RBRACE  */
  YYSYMBOL_T_COMMA = 28,                   /* T_COMMA  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_program = 30,                   /* program  */
  YYSYMBOL_func_decl = 31,                 /* func_decl  */
  YYSYMBOL_type_spec = 32,                 /* type_spec  */
  YYSYMBOL_func_args = 33,                 /* func_args  */
  YYSYMBOL_func_args_list = 34,            /* func_args_list  */
  YYSYMBOL_block = 35,                     /* block  */
  YYSYMBOL_stmts = 36,                     /* stmts  */
  YYSYMBOL_stmt = 37,                      /* stmt  */
  YYSYMBOL_expr = 38,                      /* expr  */
  YYSYMBOL_call_args = 39                  /* call_args  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  86

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    50,    51,    55,    59,    66,    67,    71,
      72,    76,    81,    89,    94,   100,   104,   111,   115,   119,
     122,   125,   128,   131,   134,   137,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   164,   165,   169
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
  "\"end of file\"", "error", "\"invalid token\"", "T_IDENTIFIER",
  "T_INTEGER", "T_FLOAT", "T_TYPE_INT", "T_TYPE_FLOAT", "T_IF", "T_ELSE",
  "T_WHILE", "T_RETURN", "T_DELIMITER", "T_ASSIGN", "T_EQ", "T_NEQ",
  "T_LT", "T_LTE", "T_GT", "T_GTE", "T_PLUS", "T_MINUS", "T_MUL", "T_DIV",
  "T_LPAREN", "T_RPAREN", "T_LBRACE", "T_RBRACE", "T_COMMA", "$accept",
  "program", "func_decl", "type_spec", "func_args", "func_args_list",
  "block", "stmts", "stmt", "expr", "call_args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,     9,   -26,   -18,   -26,   -26,   -26,   -26,    -1,    17,
     -14,    32,    18,    22,    17,   -26,    28,    17,    54,    34,
     -26,    77,    28,    -6,   -26,   -26,    48,    33,    44,   -26,
      48,   -26,    78,    59,   -26,    86,   -26,   -26,    48,    48,
      58,    73,    48,   -26,    98,   108,    72,   -26,   -26,   -26,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
     120,   142,   -17,    76,   130,   -26,   -26,   -26,    53,    53,
      53,    53,    53,    53,    55,    55,   -26,   -26,   -26,   -26,
      48,    28,    28,   142,   -26,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     1,     0,     7,     8,     3,     2,     0,     9,
       0,     0,     0,    10,     9,    11,     0,     0,     0,     0,
       6,     0,     0,    26,    27,    28,     0,     0,     0,    25,
       0,    14,     0,     0,    15,     0,    12,     5,     0,    41,
      26,     0,     0,    23,     0,     0,     0,    13,    16,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    19,     0,    22,    39,    17,    33,    34,
      35,    36,    37,    38,    29,    30,    31,    32,    18,    40,
       0,     0,     0,    43,    20,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -26,     3,    83,   -26,   -22,   -26,   121,   -25,
     -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     7,    11,    12,    13,    20,    33,    34,    35,
      62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    41,    10,    44,     8,    45,     9,    38,    79,     2,
      14,    80,     3,    60,    61,     4,     5,    64,    39,    63,
      21,     6,    32,     4,     5,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    15,    32,    23,    24,    25,
       4,     5,    26,    16,    27,    28,    29,    40,    24,    25,
      17,    40,    24,    25,    19,    83,    43,    42,    30,    84,
      85,    31,    23,    24,    25,     4,     5,    26,    30,    27,
      28,    29,    30,    56,    57,    58,    59,    58,    59,    22,
      36,    46,    39,    30,    67,    81,    47,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    18,    49,    19,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      65,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    78,    66,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    48,    82,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59
};

static const yytype_int8 yycheck[] =
{
      22,    26,     3,    28,     1,    30,    24,    13,    25,     0,
      24,    28,     3,    38,    39,     6,     7,    42,    24,    41,
      17,    12,    19,     6,     7,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     3,    33,     3,     4,     5,
       6,     7,     8,    25,    10,    11,    12,     3,     4,     5,
      28,     3,     4,     5,    26,    80,    12,    24,    24,    81,
      82,    27,     3,     4,     5,     6,     7,     8,    24,    10,
      11,    12,    24,    20,    21,    22,    23,    22,    23,    25,
       3,     3,    24,    24,    12,     9,    27,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    14,    12,    26,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    12,    25,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    33,    25,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,     0,     3,     6,     7,    12,    31,    32,    24,
       3,    32,    33,    34,    24,     3,    25,    28,    33,    26,
      35,    32,    25,     3,     4,     5,     8,    10,    11,    12,
      24,    27,    32,    36,    37,    38,     3,    35,    13,    24,
       3,    38,    24,    12,    38,    38,     3,    27,    37,    12,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      38,    38,    39,    35,    38,    12,    25,    12,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    12,    25,
      28,     9,    25,    38,    35,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    30,    30,    31,    31,    32,    32,    33,
      33,    34,    34,    35,    35,    36,    36,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     5,     1,     1,     0,
       1,     2,     4,     3,     2,     1,     2,     3,     4,     3,
       5,     5,     3,     2,     2,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     0,     1,     3
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
  case 2: /* program: program func_decl  */
#line 49 "src/parser.y"
                        { programBlock->functions.push_back(std::unique_ptr<FunctionNode>((yyvsp[0].func))); }
#line 1175 "src/parser.cpp"
    break;

  case 4: /* program: %empty  */
#line 51 "src/parser.y"
                  { programBlock = std::make_unique<ProgramNode>(); }
#line 1181 "src/parser.cpp"
    break;

  case 5: /* func_decl: type_spec T_IDENTIFIER T_LPAREN func_args T_RPAREN block  */
#line 55 "src/parser.y"
                                                               {
          (yyval.func) = new FunctionNode(*(yyvsp[-5].string), *(yyvsp[-4].string), *(yyvsp[-2].arg_vec), std::unique_ptr<BlockNode>((yyvsp[0].block)));
          delete (yyvsp[-5].string); delete (yyvsp[-4].string); delete (yyvsp[-2].arg_vec);
      }
#line 1190 "src/parser.cpp"
    break;

  case 6: /* func_decl: T_IDENTIFIER T_LPAREN func_args T_RPAREN block  */
#line 59 "src/parser.y"
                                                     {
          (yyval.func) = new FunctionNode("void", *(yyvsp[-4].string), *(yyvsp[-2].arg_vec), std::unique_ptr<BlockNode>((yyvsp[0].block)));
          delete (yyvsp[-4].string); delete (yyvsp[-2].arg_vec);
      }
#line 1199 "src/parser.cpp"
    break;

  case 7: /* type_spec: T_TYPE_INT  */
#line 66 "src/parser.y"
                 { (yyval.string) = new std::string("int"); }
#line 1205 "src/parser.cpp"
    break;

  case 8: /* type_spec: T_TYPE_FLOAT  */
#line 67 "src/parser.y"
                   { (yyval.string) = new std::string("float"); }
#line 1211 "src/parser.cpp"
    break;

  case 9: /* func_args: %empty  */
#line 71 "src/parser.y"
                  { (yyval.arg_vec) = new std::vector<std::pair<std::string, std::string>>(); }
#line 1217 "src/parser.cpp"
    break;

  case 10: /* func_args: func_args_list  */
#line 72 "src/parser.y"
                     { (yyval.arg_vec) = (yyvsp[0].arg_vec); }
#line 1223 "src/parser.cpp"
    break;

  case 11: /* func_args_list: type_spec T_IDENTIFIER  */
#line 76 "src/parser.y"
                             {
          (yyval.arg_vec) = new std::vector<std::pair<std::string, std::string>>();
          (yyval.arg_vec)->push_back({*(yyvsp[-1].string), *(yyvsp[0].string)});
          delete (yyvsp[-1].string); delete (yyvsp[0].string);
      }
#line 1233 "src/parser.cpp"
    break;

  case 12: /* func_args_list: func_args_list T_COMMA type_spec T_IDENTIFIER  */
#line 81 "src/parser.y"
                                                    {
          (yyvsp[-3].arg_vec)->push_back({*(yyvsp[-1].string), *(yyvsp[0].string)});
          (yyval.arg_vec) = (yyvsp[-3].arg_vec);
          delete (yyvsp[-1].string); delete (yyvsp[0].string);
      }
#line 1243 "src/parser.cpp"
    break;

  case 13: /* block: T_LBRACE stmts T_RBRACE  */
#line 89 "src/parser.y"
                              {
          (yyval.block) = new BlockNode();
          (yyval.block)->statements = std::move(*(yyvsp[-1].stmt_vec));
          delete (yyvsp[-1].stmt_vec);
      }
#line 1253 "src/parser.cpp"
    break;

  case 14: /* block: T_LBRACE T_RBRACE  */
#line 94 "src/parser.y"
                        {
          (yyval.block) = new BlockNode();
      }
#line 1261 "src/parser.cpp"
    break;

  case 15: /* stmts: stmt  */
#line 100 "src/parser.y"
           {
          (yyval.stmt_vec) = new std::vector<std::unique_ptr<StmtNode>>();
          if ((yyvsp[0].stmt)) (yyval.stmt_vec)->push_back(std::unique_ptr<StmtNode>((yyvsp[0].stmt)));
      }
#line 1270 "src/parser.cpp"
    break;

  case 16: /* stmts: stmts stmt  */
#line 104 "src/parser.y"
                 {
          if ((yyvsp[0].stmt)) (yyvsp[-1].stmt_vec)->push_back(std::unique_ptr<StmtNode>((yyvsp[0].stmt)));
          (yyval.stmt_vec) = (yyvsp[-1].stmt_vec);
      }
#line 1279 "src/parser.cpp"
    break;

  case 17: /* stmt: type_spec T_IDENTIFIER T_DELIMITER  */
#line 111 "src/parser.y"
                                         {
          (yyval.stmt) = new VarDeclNode(*(yyvsp[-2].string), *(yyvsp[-1].string));
          delete (yyvsp[-2].string); delete (yyvsp[-1].string);
      }
#line 1288 "src/parser.cpp"
    break;

  case 18: /* stmt: T_IDENTIFIER T_ASSIGN expr T_DELIMITER  */
#line 115 "src/parser.y"
                                             {
          (yyval.stmt) = new AssignmentNode(*(yyvsp[-3].string), std::unique_ptr<ExprNode>((yyvsp[-1].expr)));
          delete (yyvsp[-3].string);
      }
#line 1297 "src/parser.cpp"
    break;

  case 19: /* stmt: T_IF expr block  */
#line 119 "src/parser.y"
                      {
          (yyval.stmt) = new IfNode(std::unique_ptr<ExprNode>((yyvsp[-1].expr)), std::unique_ptr<BlockNode>((yyvsp[0].block)), nullptr);
      }
#line 1305 "src/parser.cpp"
    break;

  case 20: /* stmt: T_IF expr block T_ELSE block  */
#line 122 "src/parser.y"
                                   {
          (yyval.stmt) = new IfNode(std::unique_ptr<ExprNode>((yyvsp[-3].expr)), std::unique_ptr<BlockNode>((yyvsp[-2].block)), std::unique_ptr<BlockNode>((yyvsp[0].block)));
      }
#line 1313 "src/parser.cpp"
    break;

  case 21: /* stmt: T_WHILE T_LPAREN expr T_RPAREN block  */
#line 125 "src/parser.y"
                                           {
          (yyval.stmt) = new WhileNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), std::unique_ptr<BlockNode>((yyvsp[0].block)));
      }
#line 1321 "src/parser.cpp"
    break;

  case 22: /* stmt: T_RETURN expr T_DELIMITER  */
#line 128 "src/parser.y"
                                {
          (yyval.stmt) = new ReturnNode(std::unique_ptr<ExprNode>((yyvsp[-1].expr)));
      }
#line 1329 "src/parser.cpp"
    break;

  case 23: /* stmt: T_RETURN T_DELIMITER  */
#line 131 "src/parser.y"
                           {
          (yyval.stmt) = new ReturnNode(nullptr);
      }
#line 1337 "src/parser.cpp"
    break;

  case 24: /* stmt: expr T_DELIMITER  */
#line 134 "src/parser.y"
                       {
          (yyval.stmt) = new ExprStmtNode(std::unique_ptr<ExprNode>((yyvsp[-1].expr)));
      }
#line 1345 "src/parser.cpp"
    break;

  case 25: /* stmt: T_DELIMITER  */
#line 137 "src/parser.y"
                  {
          (yyval.stmt) = nullptr;
      }
#line 1353 "src/parser.cpp"
    break;

  case 26: /* expr: T_IDENTIFIER  */
#line 143 "src/parser.y"
                   { (yyval.expr) = new IdentifierNode(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1359 "src/parser.cpp"
    break;

  case 27: /* expr: T_INTEGER  */
#line 144 "src/parser.y"
                { (yyval.expr) = new IntNode(std::stoll(*(yyvsp[0].string))); delete (yyvsp[0].string); }
#line 1365 "src/parser.cpp"
    break;

  case 28: /* expr: T_FLOAT  */
#line 145 "src/parser.y"
              { (yyval.expr) = new FloatNode(std::stod(*(yyvsp[0].string))); delete (yyvsp[0].string); }
#line 1371 "src/parser.cpp"
    break;

  case 29: /* expr: expr T_PLUS expr  */
#line 146 "src/parser.y"
                       { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_PLUS, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1377 "src/parser.cpp"
    break;

  case 30: /* expr: expr T_MINUS expr  */
#line 147 "src/parser.y"
                        { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_MINUS, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1383 "src/parser.cpp"
    break;

  case 31: /* expr: expr T_MUL expr  */
#line 148 "src/parser.y"
                      { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_MUL, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1389 "src/parser.cpp"
    break;

  case 32: /* expr: expr T_DIV expr  */
#line 149 "src/parser.y"
                      { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_DIV, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1395 "src/parser.cpp"
    break;

  case 33: /* expr: expr T_EQ expr  */
#line 150 "src/parser.y"
                     { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_EQ, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1401 "src/parser.cpp"
    break;

  case 34: /* expr: expr T_NEQ expr  */
#line 151 "src/parser.y"
                      { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_NEQ, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1407 "src/parser.cpp"
    break;

  case 35: /* expr: expr T_LT expr  */
#line 152 "src/parser.y"
                     { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_LT, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1413 "src/parser.cpp"
    break;

  case 36: /* expr: expr T_LTE expr  */
#line 153 "src/parser.y"
                      { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_LTE, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1419 "src/parser.cpp"
    break;

  case 37: /* expr: expr T_GT expr  */
#line 154 "src/parser.y"
                     { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_GT, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1425 "src/parser.cpp"
    break;

  case 38: /* expr: expr T_GTE expr  */
#line 155 "src/parser.y"
                      { (yyval.expr) = new BinaryOpNode(std::unique_ptr<ExprNode>((yyvsp[-2].expr)), T_GTE, std::unique_ptr<ExprNode>((yyvsp[0].expr))); }
#line 1431 "src/parser.cpp"
    break;

  case 39: /* expr: T_LPAREN expr T_RPAREN  */
#line 156 "src/parser.y"
                             { (yyval.expr) = (yyvsp[-1].expr); }
#line 1437 "src/parser.cpp"
    break;

  case 40: /* expr: T_IDENTIFIER T_LPAREN call_args T_RPAREN  */
#line 157 "src/parser.y"
                                               {
          (yyval.expr) = new CallNode(*(yyvsp[-3].string), std::move(*(yyvsp[-1].expr_vec)));
          delete (yyvsp[-3].string); delete (yyvsp[-1].expr_vec);
      }
#line 1446 "src/parser.cpp"
    break;

  case 41: /* call_args: %empty  */
#line 164 "src/parser.y"
                  { (yyval.expr_vec) = new std::vector<std::unique_ptr<ExprNode>>(); }
#line 1452 "src/parser.cpp"
    break;

  case 42: /* call_args: expr  */
#line 165 "src/parser.y"
           {
          (yyval.expr_vec) = new std::vector<std::unique_ptr<ExprNode>>();
          (yyval.expr_vec)->push_back(std::unique_ptr<ExprNode>((yyvsp[0].expr)));
      }
#line 1461 "src/parser.cpp"
    break;

  case 43: /* call_args: call_args T_COMMA expr  */
#line 169 "src/parser.y"
                             {
          (yyvsp[-2].expr_vec)->push_back(std::unique_ptr<ExprNode>((yyvsp[0].expr)));
          (yyval.expr_vec) = (yyvsp[-2].expr_vec);
      }
#line 1470 "src/parser.cpp"
    break;


#line 1474 "src/parser.cpp"

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

#line 175 "src/parser.y"
