/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEIRO = 258,
     PROGRAM = 259,
     ABRE_PARENTESES = 260,
     FECHA_PARENTESES = 261,
     VIRGULA = 262,
     PONTO_E_VIRGULA = 263,
     DOIS_PONTOS = 264,
     PONTO = 265,
     NUMERO = 266,
     T_BEGIN = 267,
     T_END = 268,
     VAR = 269,
     IDENT = 270,
     ATRIBUICAO = 271,
     ABRE_COLCHETES = 272,
     FECHA_COLCHETES = 273,
     ABRE_CHAVES = 274,
     FECHA_CHAVES = 275,
     LABEL = 276,
     TYPE = 277,
     ARRAY = 278,
     PROCEDURE = 279,
     FUNCTION = 280,
     GOTO = 281,
     WHILE = 282,
     DO = 283,
     DIV = 284,
     AND = 285,
     NOT = 286,
     OR = 287,
     MENOR = 288,
     MAIOR = 289,
     DIFERENTE = 290,
     MAIOR_OU_IGUAL = 291,
     MENOR_OU_IGUAL = 292,
     IGUAL = 293,
     MENOS = 294,
     MAIS = 295,
     VEZES = 296,
     READ = 297,
     WRITE = 298,
     FALSE_TOKEN = 299,
     TRUE_TOKEN = 300
   };
#endif
/* Tokens.  */
#define INTEIRO 258
#define PROGRAM 259
#define ABRE_PARENTESES 260
#define FECHA_PARENTESES 261
#define VIRGULA 262
#define PONTO_E_VIRGULA 263
#define DOIS_PONTOS 264
#define PONTO 265
#define NUMERO 266
#define T_BEGIN 267
#define T_END 268
#define VAR 269
#define IDENT 270
#define ATRIBUICAO 271
#define ABRE_COLCHETES 272
#define FECHA_COLCHETES 273
#define ABRE_CHAVES 274
#define FECHA_CHAVES 275
#define LABEL 276
#define TYPE 277
#define ARRAY 278
#define PROCEDURE 279
#define FUNCTION 280
#define GOTO 281
#define WHILE 282
#define DO 283
#define DIV 284
#define AND 285
#define NOT 286
#define OR 287
#define MENOR 288
#define MAIOR 289
#define DIFERENTE 290
#define MAIOR_OU_IGUAL 291
#define MENOR_OU_IGUAL 292
#define IGUAL 293
#define MENOS 294
#define MAIS 295
#define VEZES 296
#define READ 297
#define WRITE 298
#define FALSE_TOKEN 299
#define TRUE_TOKEN 300




/* Copy the first part of user declarations.  */
#line 6 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "symbolTable/symbolTable.h"
#include "stringStack/stringStack.h"
#include "genericStack/genericStack.h"
#include "labelsStack/labelsStack.h"

#define SYMBOL_TABLE_CAPACITY 500
#define OPERATORS_STACK_CAPACITY 500
#define LABELS_STACK_CAPACITY 500
#define TYPES_STACK_CAPACITY 500
#define FALSE 0
#define TRUE 1

int num_vars;
int numberOfLabels = 0;

int callingProcedure = FALSE;

char* currentLabel;
typeType* currentType;
char* auxLabel;

symbolTableType* compilerSymbolTable;
int currentLexicalLevel = 0;
int offset = -1;
symbolType* currentSymbol;
stringStackType* operatorsStack;
LabelsStackType* labelsStack;
genericStackType typesStack;


// For some reason I'd to put this function prototype here.
// TODO: think of a better place to put it on
char* getOperatorInstruction(char *operator);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "compilador.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    14,    15,    19,    21,    22,    26,
      27,    30,    32,    33,    34,    41,    43,    47,    49,    53,
      55,    56,    60,    63,    64,    69,    70,    75,    76,    81,
      82,    87,    88,    93,    95,    96,   101,   102,   107,   108,
     113,   115,   116,   121,   122,   127,   128,   133,   135,   136,
     140,   143,   145,   147,   149,   150,   154,   156,   157,   158,
     165,   169,   171,   172,   176,   178,   180,   182,   184,   186,
     191,   196,   197,   201,   203,   207,   209,   213,   215
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    -1,    48,     4,    15,     5,    60,     6,
       8,    49,    10,    -1,    -1,    51,    50,    84,    -1,    52,
      -1,    -1,    53,    14,    54,    -1,    -1,    54,    55,    -1,
      55,    -1,    -1,    -1,    56,    59,     9,    58,    57,     8,
      -1,    15,    -1,    59,     7,    15,    -1,    15,    -1,    60,
       7,    15,    -1,    15,    -1,    -1,    15,    62,    63,    -1,
      16,    64,    -1,    -1,    64,    65,    34,    70,    -1,    -1,
      64,    66,    36,    70,    -1,    -1,    64,    67,    33,    70,
      -1,    -1,    64,    68,    37,    70,    -1,    -1,    64,    69,
      38,    70,    -1,    70,    -1,    -1,    70,    71,    40,    74,
      -1,    -1,    70,    72,    39,    74,    -1,    -1,    70,    73,
      32,    74,    -1,    74,    -1,    -1,    74,    75,    41,    78,
      -1,    -1,    74,    76,    29,    78,    -1,    -1,    74,    77,
      30,    78,    -1,    78,    -1,    -1,     5,    64,     6,    -1,
      31,    78,    -1,    80,    -1,    11,    -1,    45,    -1,    -1,
      44,    79,    91,    -1,    15,    -1,    -1,    -1,    27,    82,
      64,    83,    28,    87,    -1,    12,    85,    13,    -1,    86,
      -1,    -1,    86,     8,    87,    -1,    87,    -1,    88,    -1,
      61,    -1,    84,    -1,    81,    -1,    42,     5,    89,     6,
      -1,    43,     5,    90,     6,    -1,    -1,    89,     7,    91,
      -1,    91,    -1,    90,     7,    91,    -1,    91,    -1,    90,
       7,    11,    -1,    11,    -1,    15,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    58,    72,    72,    74,    78,    78,    79,
      82,    83,    86,    87,    86,   102,   104,   115,   128,   129,
     133,   133,   137,   153,   153,   156,   156,   159,   159,   162,
     162,   165,   165,   168,   171,   171,   174,   174,   177,   177,
     180,   184,   184,   187,   187,   190,   190,   193,   197,   197,
     198,   201,   209,   212,   215,   215,   223,   229,   233,   229,
     249,   251,   251,   253,   253,   255,   258,   259,   260,   261,
     262,   263,   266,   270,   277,   281,   285,   288,   293
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEIRO", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "NUMERO", "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO",
  "ABRE_COLCHETES", "FECHA_COLCHETES", "ABRE_CHAVES", "FECHA_CHAVES",
  "LABEL", "TYPE", "ARRAY", "PROCEDURE", "FUNCTION", "GOTO", "WHILE", "DO",
  "DIV", "AND", "NOT", "OR", "MENOR", "MAIOR", "DIFERENTE",
  "MAIOR_OU_IGUAL", "MENOR_OU_IGUAL", "IGUAL", "MENOS", "MAIS", "VEZES",
  "READ", "WRITE", "FALSE_TOKEN", "TRUE_TOKEN", "$accept", "programa",
  "@1", "bloco", "@2", "parte_declara_vars", "var", "@3", "declara_vars",
  "declara_var", "@4", "@5", "tipo", "lista_id_var", "lista_idents",
  "atribuicao", "@6", "atribui_variavel", "expressao", "@7", "@8", "@9",
  "@10", "@11", "expressao_simples", "@12", "@13", "@14", "termo", "@15",
  "@16", "@17", "fator", "@18", "variavel", "repeticao", "@19", "@20",
  "comando_composto", "comandos_ou_vazio", "comandos", "comando",
  "comando_sem_rotulo", "lista_leitura", "lista_impressao",
  "identificador", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    48,    47,    50,    49,    51,    53,    52,    52,
      54,    54,    56,    57,    55,    58,    59,    59,    60,    60,
      62,    61,    63,    65,    64,    66,    64,    67,    64,    68,
      64,    69,    64,    64,    71,    70,    72,    70,    73,    70,
      70,    75,    74,    76,    74,    77,    74,    74,    78,    78,
      78,    78,    78,    78,    79,    78,    80,    82,    83,    81,
      84,    85,    85,    86,    86,    87,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    90,    90,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     0,     3,     1,     0,     3,     0,
       2,     1,     0,     0,     6,     1,     3,     1,     3,     1,
       0,     3,     2,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     0,     4,
       1,     0,     4,     0,     4,     0,     4,     1,     0,     3,
       2,     1,     1,     1,     0,     3,     1,     0,     0,     6,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     4,
       4,     0,     3,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    19,     0,     0,
       0,     7,    18,     0,     4,     6,     0,     3,     0,    12,
      62,     5,     8,    11,     0,    20,    57,     0,     0,    66,
      68,    67,     0,    61,    64,    65,    10,    17,     0,     0,
      48,     0,     0,    60,    71,     0,     0,    48,    21,    48,
      52,    56,    48,    54,    53,    23,    33,    40,    47,    51,
      78,     0,    73,    77,     0,    75,    63,    16,    15,    13,
      22,    23,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    70,     0,
       0,    49,    55,    48,    48,    48,    48,    48,    71,    48,
      48,    48,    48,    48,    48,    72,    76,    74,    14,    24,
      26,    28,    30,    32,    59,    35,    37,    39,    42,    44,
      46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    13,    18,    14,    15,    16,    22,    23,
      24,    90,    69,    38,     8,    29,    39,    48,    55,    74,
      75,    76,    77,    78,    56,    80,    81,    82,    57,    83,
      84,    85,    58,    73,    59,    30,    40,    79,    31,    32,
      33,    34,    35,    61,    64,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int8 yypact[] =
{
     -52,     7,    10,   -52,    19,    39,    33,   -52,    34,    68,
      60,    65,   -52,    69,   -52,   -52,    64,   -52,    70,   -52,
      -4,   -52,    66,   -52,    71,   -52,   -52,    75,    78,   -52,
     -52,   -52,    72,    76,   -52,   -52,   -52,   -52,    62,    73,
      -2,    77,    -5,   -52,     3,    79,    80,    -2,   -52,    -2,
     -52,   -52,    -2,   -52,   -52,    22,   -20,   -13,   -52,   -52,
     -52,    50,   -52,   -52,    67,   -52,   -52,   -52,   -52,   -52,
     -12,    -1,   -52,    77,    53,    52,    57,    54,    55,    74,
      56,    58,    81,    59,    82,    84,   -52,    77,   -52,    16,
      90,   -52,   -52,    -2,    -2,    -2,    -2,    -2,     3,    -2,
      -2,    -2,    -2,    -2,    -2,   -52,   -52,   -52,   -52,   -20,
     -20,   -20,   -20,   -20,   -52,   -13,   -13,   -13,   -52,   -52,
     -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,    83,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,    23,   -52,
     -52,   -52,   -52,   -52,   -32,   -52,   -52,   -52,   -33,   -52,
     -52,   -52,   -51,   -52,   -52,   -52,   -52,   -52,    85,   -52,
     -52,   -44,   -52,   -52,   -52,   -40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int8 yytable[] =
{
      66,    72,    65,    49,   -71,    91,    63,     3,    20,    50,
      60,    25,   -38,    51,     4,    20,   -43,   -45,    25,   -36,
     -34,   -27,   -23,    26,   -25,   -29,   -31,   106,   -41,    52,
      26,    60,   -27,    92,     5,   -25,   -29,   -31,    27,    28,
       9,    10,    53,    54,     6,    27,    28,   105,     7,   107,
     -58,   118,   119,   120,   114,   -27,    86,    87,   -25,   -29,
     -31,   109,   110,   111,   112,   113,   115,   116,   117,    45,
      70,    46,    71,    88,    89,    12,    11,    -9,    19,    17,
      41,   -12,    20,    42,    44,    43,    37,    93,    94,    47,
      95,    96,    60,    97,    67,    68,    99,   100,   108,     0,
     102,     0,    98,    21,     0,    36,     0,     0,     0,     0,
       0,   103,     0,   101,   104
};

static const yytype_int8 yycheck[] =
{
      44,    52,    42,     5,     8,     6,    11,     0,    12,    11,
      15,    15,    32,    15,     4,    12,    29,    30,    15,    39,
      40,    33,    34,    27,    36,    37,    38,    11,    41,    31,
      27,    15,    33,    73,    15,    36,    37,    38,    42,    43,
       6,     7,    44,    45,     5,    42,    43,    87,    15,    89,
      28,   102,   103,   104,    98,    33,     6,     7,    36,    37,
      38,    93,    94,    95,    96,    97,    99,   100,   101,     7,
      47,     9,    49,     6,     7,    15,     8,    12,    14,    10,
       5,    15,    12,     5,     8,    13,    15,    34,    36,    16,
      33,    37,    15,    38,    15,    15,    40,    39,     8,    -1,
      41,    -1,    28,    18,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    32,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,     4,    15,     5,    15,    60,     6,
       7,     8,    15,    49,    51,    52,    53,    10,    50,    14,
      12,    84,    54,    55,    56,    15,    27,    42,    43,    61,
      81,    84,    85,    86,    87,    88,    55,    15,    59,    62,
      82,     5,     5,    13,     8,     7,     9,    16,    63,     5,
      11,    15,    31,    44,    45,    64,    70,    74,    78,    80,
      15,    89,    91,    11,    90,    91,    87,    15,    15,    58,
      64,    64,    78,    79,    65,    66,    67,    68,    69,    83,
      71,    72,    73,    75,    76,    77,     6,     7,     6,     7,
      57,     6,    91,    34,    36,    33,    37,    38,    28,    40,
      39,    32,    41,    29,    30,    91,    11,    91,     8,    70,
      70,    70,    70,    70,    87,    74,    74,    74,    78,    78,
      78
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 58 "compilador.y"
    { geraCodigo(NULL, "INPP");;}
    break;

  case 3:
#line 59 "compilador.y"
    {
		// DMEM
		int numberOfAllocatedVariables = compilerSymbolTable->top + 1;
		int numberOfDigits = getNumberOfDigits(numberOfAllocatedVariables );
		char dmemString[5 + numberOfDigits];
		sprintf(dmemString, "DMEN %d", numberOfAllocatedVariables );
		geraCodigo(NULL, dmemString);

		// PARA
		geraCodigo(NULL, "PARA");
		printSymbolTable(compilerSymbolTable);
	;}
    break;

  case 4:
#line 72 "compilador.y"
    { ;}
    break;

  case 7:
#line 78 "compilador.y"
    { ;}
    break;

  case 12:
#line 86 "compilador.y"
    { ;}
    break;

  case 13:
#line 87 "compilador.y"
    {
		/* AMEM */
		int numberOfDigits = getNumberOfDigits(num_vars);
		char amemString[5 + numberOfDigits];
              	sprintf(amemString, "AMEM %d", num_vars);
              	geraCodigo(NULL, amemString);


		// Here we should update the last num_vars symbols with the correct type
		int type = getTypeBasedOnToken(token);
		updateLastSymbolsTypes(compilerSymbolTable, num_vars, type);

		num_vars = 0;
	;}
    break;

  case 16:
#line 104 "compilador.y"
    {
		/* Insert the last variable of the list into the Symbol Table */
		num_vars++;
		offset++;

		int type = 0; // temporary, will be updated later
		int lexicalLevel = currentLexicalLevel;
		int category = simpleVariable;

		symbolType* newVariable = createSymbol(token, type, lexicalLevel, offset, category, 0, 0, 0);
		pushToSymbolTable(compilerSymbolTable, newVariable);
	;}
    break;

  case 17:
#line 115 "compilador.y"
    {
            	/* insere vars na tabela de símbolos */
		num_vars++;
		offset++;

                int type = 0; // temporary, will be updated later
		int lexicalLevel = currentLexicalLevel;
		int category = simpleVariable;

		symbolType* newVariable = createSymbol(token, type, lexicalLevel, offset, category, 0, 0, 0);
		pushToSymbolTable(compilerSymbolTable, newVariable);
	;}
    break;

  case 20:
#line 133 "compilador.y"
    {
		currentSymbol = searchIntoSymbolTable(compilerSymbolTable, token);
	;}
    break;

  case 22:
#line 137 "compilador.y"
    {
		int lexicalLevelNumberOfDigits = getNumberOfDigits(currentSymbol->lexicalAddress->lexicalLevel);
		int offsetNumberOfDigits = getNumberOfDigits(currentSymbol->lexicalAddress->offset);
		char armzString[6 + lexicalLevelNumberOfDigits + offsetNumberOfDigits];
		sprintf(
			armzString, "ARMZ %d,%d",
			currentSymbol->lexicalAddress->lexicalLevel,
			currentSymbol->lexicalAddress->offset
		);
		geraCodigo(NULL, armzString);
	;}
    break;

  case 23:
#line 153 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 24:
#line 153 "compilador.y"
    {
		checkTypes(&typesStack, comparison);
		geraCodigo(NULL, "CMMA");
	;}
    break;

  case 25:
#line 156 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 26:
#line 156 "compilador.y"
    {
		checkTypes(&typesStack, comparison);
		geraCodigo(NULL, "CMAG");
	;}
    break;

  case 27:
#line 159 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 28:
#line 159 "compilador.y"
    {
		checkTypes(&typesStack, comparison);
		geraCodigo(NULL, "CMME");
	;}
    break;

  case 29:
#line 162 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 30:
#line 162 "compilador.y"
    {
		checkTypes(&typesStack, comparison);
		geraCodigo(NULL, "CMEG");
	;}
    break;

  case 31:
#line 165 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 32:
#line 165 "compilador.y"
    {
		checkTypes(&typesStack, comparison);
		geraCodigo(NULL, "CMIG");
	;}
    break;

  case 34:
#line 171 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 35:
#line 171 "compilador.y"
    {
			//checkTypes(&typesStack, mathematicalExpression);
			geraCodigo(NULL, "SOMA");
		;}
    break;

  case 36:
#line 174 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 37:
#line 174 "compilador.y"
    {
			checkTypes(&typesStack, mathematicalExpression);
			geraCodigo(NULL, "SUBT");
		 ;}
    break;

  case 38:
#line 177 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 39:
#line 177 "compilador.y"
    {
			checkTypes (&typesStack, comparison);
			geraCodigo(NULL, "DISJ");
		;}
    break;

  case 41:
#line 184 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 42:
#line 184 "compilador.y"
    {
		checkTypes(&typesStack, mathematicalExpression);
		geraCodigo(NULL, "MULT");
	;}
    break;

  case 43:
#line 187 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 44:
#line 187 "compilador.y"
    {
		checkTypes(&typesStack, mathematicalExpression);
		geraCodigo(NULL, "DIVI");
	;}
    break;

  case 45:
#line 190 "compilador.y"
    { callingProcedure = FALSE; ;}
    break;

  case 46:
#line 190 "compilador.y"
    {
		checkTypes(&typesStack, comparison);
		geraCodigo(NULL, "CONJ");
	;}
    break;

  case 50:
#line 198 "compilador.y"
    {
		checkTypes(&typesStack, comparison);
		geraCodigo(NULL, "NEGA")
	;}
    break;

  case 51:
#line 201 "compilador.y"
    {
		symbolType* variable = searchIntoSymbolTable(compilerSymbolTable, token);
 		generateCodeWithArguments(
 			NULL,
		 	"CRVL %d,%d",
			variable->lexicalAddress->lexicalLevel,
			variable->lexicalAddress->offset
		);
	;}
    break;

  case 52:
#line 209 "compilador.y"
    {
		generateCodeWithArguments(NULL, "CRCT %s", token);
		pushType(&typesStack, integerType);
	;}
    break;

  case 53:
#line 212 "compilador.y"
    {
		geraCodigo(NULL, "CRCT 1");
		pushType(&typesStack, booleanType);
	;}
    break;

  case 54:
#line 215 "compilador.y"
    {
		geraCodigo(NULL, "CRCT 0");
        	pushType(&typesStack, booleanType);
	;}
    break;

  case 55:
#line 218 "compilador.y"
    {
		pushType(&typesStack, currentSymbol->type);
		generateCRVLCode(currentSymbol);
	;}
    break;

  case 57:
#line 229 "compilador.y"
    {
		/* Generate the start label */
		generateLabel(&labelsStack, &currentLabel, &numberOfLabels);
		geraCodigo(currentLabel, "NADA");
	;}
    break;

  case 58:
#line 233 "compilador.y"
    {
		/* Generate the end label */
		generateLabel(&labelsStack, &currentLabel, &numberOfLabels);
		currentType = (typeType *) popFromGenericStack(&typesStack);
		if (*currentType != booleanType) {
			puts("\nSyntax error: operation is not boolean\n");
			exit(-1);
		}
		generateCodeWithArguments(NULL, "DSVF %s", currentLabel);
	;}
    break;

  case 59:
#line 242 "compilador.y"
    {
		auxLabel = popFromLabelsStack(&labelsStack);
		currentLabel = popFromLabelsStack(&labelsStack);
		generateCodeWithArguments(NULL, "DSVS %s", currentLabel);
		geraCodigo(auxLabel, "NADA");
	;}
    break;

  case 72:
#line 266 "compilador.y"
    {
		geraCodigo(NULL, "LEIT");
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateARMZCode(currentSymbol);
	;}
    break;

  case 73:
#line 270 "compilador.y"
    {
		geraCodigo(NULL, "LEIT");
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateARMZCode(symbol);
	;}
    break;

  case 74:
#line 277 "compilador.y"
    {
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateCRVLCode(symbol);
		geraCodigo(NULL, "IMPR");
	;}
    break;

  case 75:
#line 281 "compilador.y"
    {
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateCRVLCode(symbol);
		geraCodigo(NULL, "IMPR");
	;}
    break;

  case 76:
#line 285 "compilador.y"
    {
		generateCRCTCode(token);
                geraCodigo(NULL, "IMPR");
	;}
    break;

  case 77:
#line 288 "compilador.y"
    {
		generateCRCTCode(token);
                geraCodigo(NULL, "IMPR");
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 1944 "compilador.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 295 "compilador.y"


main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
   compilerSymbolTable = createSymbolTable(SYMBOL_TABLE_CAPACITY);
   operatorsStack = createStringStack(OPERATORS_STACK_CAPACITY);
   createLabelsStack(&labelsStack);
   createGenericStack(&typesStack);
   yyin=fp;
   yyparse();

   return 0;
}


