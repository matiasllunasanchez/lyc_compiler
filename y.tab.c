
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "libs/tercetos/tercetos.h"
#include "libs/tabla_simbolos/tabla_simbolos.h"
#include "libs/sentencias_control/sentencias_control.h"

simbolo tabla_simbolo[TAM_TABLA];
int fin_tabla = -1;

int varADeclarar1 = 0;
int cantVarsADeclarar = 0;
int tipoDatoADeclarar;

int yystopparser=0;
FILE  *yyin;
int yyparse();
int yylex();
int yyparse();
int yyerror(char* mensaje);
int yyerror();
int contWhile=0;
char * yytext;

terceto vector_tercetos[CANT_MAX_TERCETOS];
int idx_ultimo_terceto = -1;

// Comparadores booleanos
int comp_bool_actual;

// Auxiliares anidamientos
int salto_implicito=NULO;

infoaux_sentencias pila_aux[ANIDACION_MAX];
int tope_pila_aux=NULO;

// Indices
int idx_programa; // ind_bloque
int idx_sentencia;
int idx_dec;
int idx_asignacion;
int idx_iteracion;
int idx_seleccion; // ind_bif
int idx_salida;
int idx_entrada;
int idx_tomar;
int idx_factor;
int idx_condicion;
int idx_comparacion;
int idx_comparacion_izq;
int idx_expresion;
int idx_expresion_izq;
int idx_termino;
int idx_between;
int idx_take;

// Indices sentencias de control van como extern en sentencias de control.c
int idx_if;
int idx_endif;
int idx_else;
int idx_endwhile;


/* Line 189 of yacc.c  */
#line 139 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DECVAR = 258,
     ENDDEC = 259,
     OP_TIPO = 260,
     INTEGER = 261,
     FLOAT = 262,
     STRING = 263,
     IF = 264,
     ELSE = 265,
     ENDIF = 266,
     WHILE = 267,
     ENDWHILE = 268,
     TAKE = 269,
     BETWEEN = 270,
     WRITE = 271,
     READ = 272,
     AND = 273,
     OR = 274,
     NOT = 275,
     OP_ASIG = 276,
     OP_RES = 277,
     OP_SUM = 278,
     OP_MUL = 279,
     OP_DIV = 280,
     OP_MAYOR = 281,
     OP_MAYOR_IGUAL = 282,
     OP_MENOR = 283,
     OP_MENOR_IGUAL = 284,
     OP_IGUAL = 285,
     OP_NO_IGUAL = 286,
     COMA = 287,
     PAR_A = 288,
     PAR_C = 289,
     COR_A = 290,
     COR_C = 291,
     PYC = 292,
     ID = 293,
     CONST_ENT = 294,
     CONST_REAL = 295,
     CONST_STR = 296
   };
#endif
/* Tokens.  */
#define DECVAR 258
#define ENDDEC 259
#define OP_TIPO 260
#define INTEGER 261
#define FLOAT 262
#define STRING 263
#define IF 264
#define ELSE 265
#define ENDIF 266
#define WHILE 267
#define ENDWHILE 268
#define TAKE 269
#define BETWEEN 270
#define WRITE 271
#define READ 272
#define AND 273
#define OR 274
#define NOT 275
#define OP_ASIG 276
#define OP_RES 277
#define OP_SUM 278
#define OP_MUL 279
#define OP_DIV 280
#define OP_MAYOR 281
#define OP_MAYOR_IGUAL 282
#define OP_MENOR 283
#define OP_MENOR_IGUAL 284
#define OP_IGUAL 285
#define OP_NO_IGUAL 286
#define COMA 287
#define PAR_A 288
#define PAR_C 289
#define COR_A 290
#define COR_C 291
#define PYC 292
#define ID 293
#define CONST_ENT 294
#define CONST_REAL 295
#define CONST_STR 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 66 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"

    int int_val;
	float real_val;
    char *str_val;



/* Line 214 of yacc.c  */
#line 265 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 277 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    15,    19,    21,    25,    27,
      29,    31,    33,    36,    37,    39,    41,    43,    45,    47,
      51,    55,    59,    63,    67,    69,    73,    77,    79,    83,
      85,    87,    89,    90,   100,   101,   109,   116,   117,   119,
     122,   123,   128,   132,   136,   137,   142,   144,   146,   148,
     150,   152,   154,   156,   159,   162,   165,   176,   187,   197,
     199,   203,   205,   207,   209
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    48,    -1,     3,    45,     4,    -1,
      45,    46,     5,    47,    -1,    46,     5,    47,    -1,    38,
      -1,    46,    32,    38,    -1,     6,    -1,     7,    -1,     8,
      -1,    49,    -1,    48,    49,    -1,    -1,    50,    -1,    57,
      -1,    54,    -1,    64,    -1,    63,    -1,    38,    21,    51,
      -1,    38,    21,    41,    -1,    38,    21,    66,    -1,    51,
      23,    52,    -1,    51,    22,    52,    -1,    52,    -1,    52,
      24,    53,    -1,    52,    25,    53,    -1,    53,    -1,    33,
      51,    34,    -1,    40,    -1,    38,    -1,    39,    -1,    -1,
       9,    55,    33,    58,    34,    48,    10,    48,    11,    -1,
      -1,     9,    56,    33,    58,    34,    48,    11,    -1,    12,
      33,    58,    34,    48,    13,    -1,    -1,    60,    -1,    20,
      60,    -1,    -1,    58,    59,    18,    60,    -1,    58,    19,
      60,    -1,    33,    58,    34,    -1,    -1,    51,    61,    62,
      51,    -1,    65,    -1,    26,    -1,    28,    -1,    29,    -1,
      27,    -1,    30,    -1,    31,    -1,    17,    38,    -1,    16,
      41,    -1,    16,    38,    -1,    15,    33,    38,    32,    35,
      51,    37,    51,    36,    34,    -1,    14,    33,    68,    37,
      39,    37,    35,    67,    36,    34,    -1,    14,    33,    68,
      37,    39,    37,    35,    36,    34,    -1,    39,    -1,    67,
      37,    39,    -1,    23,    -1,    24,    -1,    25,    -1,    22,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   106,   110,   114,   121,   127,   135,   139,
     143,   151,   155,   161,   162,   166,   170,   174,   178,   186,
     191,   195,   199,   203,   207,   214,   218,   222,   229,   233,
     238,   243,   252,   252,   262,   262,   276,   279,   280,   281,
     284,   283,   293,   298,   302,   302,   306,   313,   317,   321,
     325,   329,   333,   341,   348,   353,   364,   369,   370,   374,
     375,   379,   380,   381,   382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECVAR", "ENDDEC", "OP_TIPO", "INTEGER",
  "FLOAT", "STRING", "IF", "ELSE", "ENDIF", "WHILE", "ENDWHILE", "TAKE",
  "BETWEEN", "WRITE", "READ", "AND", "OR", "NOT", "OP_ASIG", "OP_RES",
  "OP_SUM", "OP_MUL", "OP_DIV", "OP_MAYOR", "OP_MAYOR_IGUAL", "OP_MENOR",
  "OP_MENOR_IGUAL", "OP_IGUAL", "OP_NO_IGUAL", "COMA", "PAR_A", "PAR_C",
  "COR_A", "COR_C", "PYC", "ID", "CONST_ENT", "CONST_REAL", "CONST_STR",
  "$accept", "start", "seccion_declaracion", "bloque_variables",
  "listavar", "tipodato", "programa", "sentencia", "asignacion",
  "expresion", "termino", "factor", "seleccion", "$@1", "$@2", "iteracion",
  "condicion", "$@3", "comparacion", "$@4", "comparador", "entrada",
  "salida", "between", "take", "lista_take_ctes", "operadores_take", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    47,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    51,    51,    51,    52,    52,    52,    53,    53,
      53,    53,    55,    54,    56,    54,    57,    58,    58,    58,
      59,    58,    58,    60,    61,    60,    60,    62,    62,    62,
      62,    62,    62,    63,    64,    64,    65,    66,    66,    67,
      67,    68,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     4,     3,     1,     3,     1,     1,
       1,     1,     2,     0,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     1,     0,     9,     0,     7,     6,     0,     1,     2,
       0,     4,     3,     3,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,    10,    10,     9,     1,
       3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    13,     6,     0,     0,     1,    32,     0,
       0,     0,     0,     2,    11,    14,    16,    15,    18,    17,
       3,     0,     0,     0,     0,     0,    37,    55,    54,    53,
       0,    12,     0,     8,     9,    10,     5,     7,    37,    37,
       0,     0,    37,    30,    31,    29,    44,    24,    27,    40,
      38,    46,     0,     0,    20,    19,    21,     4,    40,    40,
       0,    39,    44,    40,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,    13,    13,     0,    28,    43,    23,
      22,    47,    50,    48,    49,    51,    52,     0,    25,    26,
      42,     0,     0,    64,    61,    62,    63,     0,     0,     0,
       0,    45,    36,    41,     0,    13,    35,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,    59,     0,     0,
      58,     0,     0,    56,    57,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    36,    13,    14,    15,    46,
      47,    48,    16,    24,    25,    17,    49,    71,    50,    66,
      87,    18,    19,    51,    56,   118,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -69
static const yytype_int8 yypact[] =
{
       9,    -4,    42,    55,   -69,     1,    -2,   -69,   -69,    14,
     -28,    13,    35,    55,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,     3,   124,    15,    40,    47,    68,   -69,   -69,   -69,
      36,   -69,   124,   -69,   -69,   -69,   -69,   -69,    68,    68,
      49,    64,    68,   -69,   -69,   -69,    43,    65,   -69,   -10,
     -69,   -69,    67,    78,   -69,    43,   -69,   -69,     4,    12,
      21,   -69,    76,    26,    78,    78,    93,    78,    78,    64,
      55,    50,    90,    76,    55,    55,    77,   -69,   -69,    65,
      65,   -69,   -69,   -69,   -69,   -69,   -69,    78,   -69,   -69,
     -69,     2,    64,   -69,   -69,   -69,   -69,    98,    16,    32,
     101,    43,   -69,   -69,    99,    55,   -69,    78,   100,    46,
      -1,   104,   -69,    78,   -19,    69,   106,   -69,    58,   107,
     -69,   108,   105,   -69,   -69,   -69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   -69,   138,   113,   -68,   -13,   -69,   -26,
      63,    66,   -69,   -69,   -69,   -69,    87,   -69,   -40,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,    61,    91,    22,    55,    20,    98,    99,    32,    69,
      27,     8,     1,    28,     9,   102,    62,   116,    10,    11,
     117,    64,    65,    69,    70,     8,   105,    73,     9,    90,
      23,    69,    10,    11,     4,    23,   113,   109,    74,     4,
      12,     8,     7,   106,     9,    69,    75,    26,    10,    11,
      52,    29,   103,    37,    12,     8,    30,   112,     9,    76,
      78,   101,    10,    11,     8,    64,    65,     9,    92,    53,
      12,    10,    11,    38,    43,    44,    45,    54,    31,    40,
      39,   110,    60,    40,    12,    31,    31,   115,    41,    67,
      68,    64,    65,    12,   121,   122,    31,    42,    64,    65,
      72,    42,    43,    44,    45,   119,    43,    44,    45,   100,
      77,    53,    93,    94,    95,    96,    43,    44,    45,    81,
      82,    83,    84,    85,    86,    58,    59,    79,    80,    63,
      33,    34,    35,    88,    89,   104,   107,   111,   108,   114,
     120,   123,   124,    21,   125,    57
};

static const yytype_uint8 yycheck[] =
{
      13,    41,    70,     5,    30,     4,    74,    75,     5,    19,
      38,     9,     3,    41,    12,    13,    42,    36,    16,    17,
      39,    22,    23,    19,    34,     9,    10,    53,    12,    69,
      32,    19,    16,    17,    38,    32,    37,   105,    34,    38,
      38,     9,     0,    11,    12,    19,    34,    33,    16,    17,
      14,    38,    92,    38,    38,     9,    21,    11,    12,    38,
      34,    87,    16,    17,     9,    22,    23,    12,    18,    33,
      38,    16,    17,    33,    38,    39,    40,    41,    91,    15,
      33,   107,    33,    15,    38,    98,    99,   113,    20,    24,
      25,    22,    23,    38,    36,    37,   109,    33,    22,    23,
      33,    33,    38,    39,    40,    36,    38,    39,    40,    32,
      34,    33,    22,    23,    24,    25,    38,    39,    40,    26,
      27,    28,    29,    30,    31,    38,    39,    64,    65,    42,
       6,     7,     8,    67,    68,    37,    35,    37,    39,    35,
      34,    34,    34,     5,    39,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    44,    38,    45,    46,     0,     9,    12,
      16,    17,    38,    48,    49,    50,    54,    57,    63,    64,
       4,    46,     5,    32,    55,    56,    33,    38,    41,    38,
      21,    49,     5,     6,     7,     8,    47,    38,    33,    33,
      15,    20,    33,    38,    39,    40,    51,    52,    53,    58,
      60,    65,    14,    33,    41,    51,    66,    47,    58,    58,
      33,    60,    51,    58,    22,    23,    61,    24,    25,    19,
      34,    59,    33,    51,    34,    34,    38,    34,    34,    52,
      52,    26,    27,    28,    29,    30,    31,    62,    53,    53,
      60,    48,    18,    22,    23,    24,    25,    68,    48,    48,
      32,    51,    13,    60,    37,    10,    11,    35,    39,    48,
      51,    37,    11,    37,    35,    51,    36,    39,    67,    36,
      34,    36,    37,    34,    34,    39
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 97 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 0: <start> --> <seccion_declaracion> <programa> \n"); 
																				guardar_tabla(); 
																				guardar_tercetos();
																			}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 106 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	printf("\n REGLA 1: <seccion_declaracion> --> DECVAR <bloque_variables> ENDDEC \n"); 	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 110 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 2: <bloque_variables> --> <bloque_variables> <listavar> OP_TIPO <tipodato> \n"); 
																				agregar_tipos_datos_a_tabla();
																			}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 114 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 3: <bloque_variables> --> <listavar> OP_TIPO <tipodato> \n"); 
																				agregar_tipos_datos_a_tabla();
																			}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 121 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 4: <listavar> --> ID  [ID: %s] \n", (yyvsp[(1) - (1)].str_val)); 
																				int idx = agregar_var_a_tabla(yylval.str_val); 
																				varADeclarar1 = fin_tabla; 
																				cantVarsADeclarar = 1; 
																			}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 127 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 5: <listavar> --> <listavar> COMA ID [ID: %s] \n", (yyvsp[(3) - (3)].str_val)); 
																				int idx = agregar_var_a_tabla(yylval.str_val); 
																				cantVarsADeclarar++; 
																			}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 135 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 6: <tipodato> --> INTEGER  \n"); 
																				tipoDatoADeclarar = ENUM_INTEGER; 
																			}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 139 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 7: <tipodato> --> FLOAT \n"); 
																			  	tipoDatoADeclarar = ENUM_FLOAT; 
																			}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 143 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 8: <tipodato> --> STRING \n"); 
																			  	tipoDatoADeclarar = ENUM_STRING; 
																			}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 151 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 9: <programa> --> <sentencia> \n"); 
																				idx_programa = idx_sentencia;
																			}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 155 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 10: <programa> --> <programa> <sentencia> \n"); 
																				idx_programa = crear_terceto(PROG, idx_programa, idx_sentencia);			
																			}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 162 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 11: <sentencia> --> <asignacion> \n"); 
																				idx_sentencia = idx_asignacion; 
																			}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 166 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 12: <sentencia> --> <iteracion> \n");
																				 idx_sentencia = idx_iteracion;
																			}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 170 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 13: <sentencia> --> <seleccion> \n");
																				idx_sentencia = idx_seleccion; 
																			}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 174 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 14: <sentencia> --> <salida> \n");
																				idx_sentencia = idx_salida; 
																			}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 178 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
			    																printf("\n REGLA 15: <sentencia> --> <entrada> \n");
																				idx_sentencia = idx_entrada; 
																			}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 186 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
																				printf("\n REGLA 16: <asignacion> --> ID OP_ASIG <expresion> \n"); 	
																				int idx = buscar_en_tabla((yyvsp[(1) - (3)].str_val));
																				idx_asignacion = crear_terceto(OP_ASIG, idx, idx_expresion);
																			}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 191 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 17: <asignacion> --> ID OP_ASIG CONST_STR \n"); 
																				int idx = agregar_cte_string_a_tabla(yylval.str_val);
																			}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 195 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	printf("\n REGLA 18: <asignacion> --> ID OP_ASIG <take> \n"); 	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 199 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 19: <expresion> --> <expresion> OP_SUM <termino> \n"); 
																				idx_expresion = crear_terceto(OP_SUM, idx_expresion, idx_termino);
																			}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 203 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 20: <expresion> --> <expresion> OP_RES <termino> \n"); 
																				idx_expresion = crear_terceto(OP_RES, idx_expresion, idx_termino);
																			}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 207 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 21: <expresion> --> <termino> \n"); 
																				idx_expresion = idx_termino; 
																			}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 214 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 22: <termino> --> <termino> OP_MUL <factor> \n");
																				idx_termino = crear_terceto(OP_MUL, idx_termino, idx_factor);
																			}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 218 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 23: <termino> --> <termino> OP_DIV <factor> \n");
																				idx_termino = crear_terceto(OP_DIV, idx_termino, idx_factor);
																			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 222 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 24: <termino> --> <factor> \n"); 
																				idx_termino = idx_factor;
																			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 229 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 25: <factor> --> PAR_A <expresion> PAR_C \n"); 
																				idx_factor = idx_expresion;
																			}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 233 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 26: <factor> --> CONST_REAL \n");
																				int idx = agregar_cte_real_a_tabla(yylval.real_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 238 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 27: <factor> --> ID \n"); 
																				int idx = buscar_en_tabla((yyvsp[(1) - (1)].str_val));
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 243 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 28: <factor> --> CONST_ENT \n"); 
																				int idx = agregar_cte_int_a_tabla(yylval.int_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 252 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
		// idx_if=crear_terceto(IF, PARTE_VACIA, PARTE_VACIA);
		// apilar_sentencia();
	}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 255 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
																				printf("\n REGLA 29: <seleccion> --> IF PAR_A <condicion> PAR_C <programa> ELSE <programa> ENDIF\n"); 	
																				idx_endif=crear_terceto(ENDIF,PARTE_VACIA,PARTE_VACIA);
																				salto_a_fin_IF();
																				// desapilar_sentencia();
																				idx_seleccion = idx_if;
																			}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 262 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
			// idx_if=crear_terceto(IF, PARTE_VACIA, PARTE_VACIA);
			// apilar_sentencia();
	}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 265 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
																				printf("\n REGLA 30: <seleccion> --> IF PAR_A <condicion> PAR_C <programa> ENDIF \n");
																				idx_endif=crear_terceto(ENDIF,PARTE_VACIA,PARTE_VACIA);
																				idx_else=idx_endif;
																				//! ponerSaltosElse();
																				// desapilar_sentencia();
																				idx_seleccion = idx_if;
																			}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 276 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	printf("\n REGLA 31: <iteracion> --> WHILE PAR_A <condicion> PAR_C <programa> ENDWHILE\n"); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 280 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	printf("\n REGLA 33: <condicion> --> <comparacion> \n"); 	}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 281 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	printf("\n REGLA 44: <condicion> --> NOT <comparacion> \n"); 	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 284 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
			crear_terceto(obtener_operador_salto(comp_bool_actual),idx_comparacion,PARTE_VACIA);
			idx_comparacion_izq =  idx_comparacion; 
		}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 287 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
																				crear_terceto(obtener_operador_salto(comp_bool_actual),idx_comparacion,PARTE_VACIA);
																				crear_terceto(AND,idx_comparacion_izq,idx_comparacion);
																				
																				printf("\n REGLA 45: <condicion> --> <condicion> AND <comparacion> <c> \n"); 	
																			}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 293 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	printf("\n REGLA 46: <condicion> --> <condicion> OR <comparacion> \n"); 	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 298 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	// REVISAR, deberia estar en condicion
																				printf("\n REGLA 48.bis: <comparacion> --> PAR_A <condicion> PAR_C \n");
																				idx_comparacion = idx_condicion;
																			}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 302 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {idx_expresion_izq = idx_expresion;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 302 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
																				printf("\n REGLA 48: <comparacion> --> <expresion> <comparador> <expresion> \n");
																				idx_comparacion = crear_terceto(CMP,idx_expresion_izq,idx_expresion);
																			}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 306 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
																				printf("\n REGLA 47: <condicion> --> PAR_A <between> PAR_C \n");
																				idx_comparacion = idx_between;
																			}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 313 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 49: <comparador> --> OP_MAYOR \n");
																				comp_bool_actual = OP_MAYOR; 
																			}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 317 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 50: <comparador> --> OP_MENOR \n");
																				comp_bool_actual = OP_MENOR; 
																			}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 321 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 51: <comparador> --> OP_MENOR_IGUAL \n");
																				comp_bool_actual = OP_MENOR_IGUAL; 
																			}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 325 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 52: <comparador> --> OP_MAYOR_IGUAL \n"); 
																				comp_bool_actual = OP_MAYOR_IGUAL; 
																			}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 329 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 53: <comparador> --> OP_IGUAL \n"); 
																				comp_bool_actual = OP_IGUAL; 
																			}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 333 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 54: <comparador> --> OP_NO_IGUAL \n");
																				comp_bool_actual = OP_NO_IGUAL; 
																			}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 341 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 55: <entrada> --> READ ID \n"); 
																				chequear_var_en_tabla(yylval.str_val);
																			}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 348 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 56: <salida> -->  WRITE CONST_STR  \n"); 
																				int idx = agregar_cte_string_a_tabla(yylval.str_val); 
																				idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 353 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n REGLA 57: <salida> -->  WRITE ID  \n"); 
																				chequear_var_en_tabla(yylval.str_val); 
																				int idx = buscar_en_tabla((yyvsp[(2) - (2)].str_val));
																				idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 364 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 58: <between> --> BETWEEN PAR_A ID COMA COR_A <expresion> PYC <expresion> COR_C PAR_C \n"); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 369 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 59: <take> --> TAKE PAR_A <operadores_take> PYC CONST_ENT PYC COR_A <lista_take_ctes> COR_C PAR_C \n"); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 370 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 60: <take> --> TAKE PAR_A <operadores_take> PYC CONST_ENT PYC COR_A COR_C PAR_C \n"); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 374 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 61: <lista_take_ctes> --> CONST_ENT \n"); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 375 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 62: <lista_take_ctes> --> <lista_take_ctes> PYC <factor> \n"); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 379 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 63: <oper> --> OP_SUM \n"); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 380 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 64: <oper> --> OP_MUL \n"); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 381 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 65: <oper> --> OP_DIV \n"); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 382 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { printf("\n REGLA 66: <oper> --> OP_RES \n"); }
    break;



/* Line 1455 of yacc.c  */
#line 2166 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 384 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"


