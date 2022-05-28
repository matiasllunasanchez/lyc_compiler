
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
#include "libs/funciones_especiales/funciones_especiales.h"

simbolo tabla_simbolo[TAM_TABLA];
int fin_tabla = -1;

int varADeclarar1 = 0;
int cantVarsADeclarar = 0;
int tipoDatoADeclarar;

int tipo_dato_actual = SIN_TIPO;

int yystopparser=0;
FILE  *yyin;
int yyparse();
int yylex();
int yyparse();
int yyerror(char* mensaje);
int yyerror();
void reset_tipo_dato(){ tipo_dato_actual = SIN_TIPO; };
int contWhile=0;
char * yytext;
int ult_pos_pila;
int idx_terceto_leido;

elemento_terceto pila_tercetos[MAX_ANIDAMIENTOS];
terceto vector_tercetos[CANT_MAX_TERCETOS];

int idx_ultimo_terceto = -1;
// Cosas para comparadores booleanos
int comp_bool_actual;
int idx_programa;
int idx_bloque_if_true;
int idx_sentencia;
int idx_declaracion;
int idx_asignacion;
int idx_condicion_izq;
int idx_condicion_der;
int idx_salto_implicito;
int has_or;

int idx_salida;
int idx_entrada;
int idx_between;
int idx_take;
int idx_factor;

int idx_expresion_general;

int idx_expresion;
int idx_expresion_izq;

int idx_expresion_booleana;

int idx_termino;
int idx_termino_izq;
int idx_termino_booleano;
int idx_termino_booleano_izq;

int idx_iteracion;
int idx_seleccion;

int idx_cota_inferior;
int idx_cota_superior;

// Variables para TAKE
int operador_take;
int cantidad_a_tomar;
int idx_constante_take;
int idx_var_take; // Donde va la variable auxiliar que acumula
int idx_var_take_aux; // Variable auxiliar para asignar valor antes de operar el take
int idx_resultado_take;
// Indices para BETWEEN
int idx_between;
int idx_salto_between;
int idx_valor_a_comparar;
int idx_salto_a_fin_between_cota_inf; // Between falso, cota inferior mayor al valor
int idx_salto_a_fin_between_cota_sup; // Between falso, cota superior menor al valor

// Indices extras para if y while
int idx_while;
int idx_end_while;

int idx_if;
int idx_else;
int idx_end_if;

//////////////////////////////////////////
int idx_then;


/* Line 189 of yacc.c  */
#line 172 "y.tab.c"

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
     OP_ASIG = 258,
     OP_RES = 259,
     OP_SUM = 260,
     OP_DIV = 261,
     OP_MUL = 262,
     OP_MAYOR = 263,
     OP_MAYOR_IGUAL = 264,
     OP_MENOR = 265,
     OP_MENOR_IGUAL = 266,
     OP_IGUAL = 267,
     OP_NO_IGUAL = 268,
     OP_TIPO = 269,
     TAKE = 270,
     BETWEEN = 271,
     WHILE = 272,
     IF = 273,
     THEN = 274,
     INTEGER = 275,
     FLOAT = 276,
     STRING = 277,
     ELSE = 278,
     DECVAR = 279,
     ENDDEC = 280,
     AND = 281,
     OR = 282,
     NOT = 283,
     WRITE = 284,
     READ = 285,
     COMA = 286,
     ENDIF = 287,
     ENDWHILE = 288,
     PAR_A = 289,
     PAR_C = 290,
     COR_A = 291,
     COR_C = 292,
     PYC = 293,
     ID = 294,
     CONST_ENT = 295,
     CONST_REAL = 296,
     CONST_STR = 297
   };
#endif
/* Tokens.  */
#define OP_ASIG 258
#define OP_RES 259
#define OP_SUM 260
#define OP_DIV 261
#define OP_MUL 262
#define OP_MAYOR 263
#define OP_MAYOR_IGUAL 264
#define OP_MENOR 265
#define OP_MENOR_IGUAL 266
#define OP_IGUAL 267
#define OP_NO_IGUAL 268
#define OP_TIPO 269
#define TAKE 270
#define BETWEEN 271
#define WHILE 272
#define IF 273
#define THEN 274
#define INTEGER 275
#define FLOAT 276
#define STRING 277
#define ELSE 278
#define DECVAR 279
#define ENDDEC 280
#define AND 281
#define OR 282
#define NOT 283
#define WRITE 284
#define READ 285
#define COMA 286
#define ENDIF 287
#define ENDWHILE 288
#define PAR_A 289
#define PAR_C 290
#define COR_A 291
#define COR_C 292
#define PYC 293
#define ID 294
#define CONST_ENT 295
#define CONST_REAL 296
#define CONST_STR 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 108 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"

    int int_val;
	float real_val;
    char *str_val;



/* Line 214 of yacc.c  */
#line 300 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 312 "y.tab.c"

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
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    15,    19,    21,    25,    27,
      29,    31,    33,    36,    38,    40,    42,    44,    46,    50,
      52,    54,    58,    62,    64,    68,    72,    74,    78,    80,
      82,    84,    86,    87,    88,    98,   101,   104,   110,   111,
     112,   122,   123,   124,   130,   131,   132,   138,   140,   143,
     145,   149,   150,   155,   157,   159,   161,   163,   165,   167,
     170,   173,   176,   178,   180,   181,   193,   204,   214,   216,
     218,   220,   222,   224,   226
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    49,    -1,    24,    46,    25,    -1,
      46,    47,    14,    48,    -1,    47,    14,    48,    -1,    39,
      -1,    47,    31,    39,    -1,    20,    -1,    21,    -1,    22,
      -1,    50,    -1,    49,    50,    -1,    51,    -1,    56,    -1,
      61,    -1,    73,    -1,    72,    -1,    39,     3,    52,    -1,
      42,    -1,    53,    -1,    53,     5,    54,    -1,    53,     4,
      54,    -1,    54,    -1,    54,     7,    55,    -1,    54,     6,
      55,    -1,    55,    -1,    34,    53,    35,    -1,    41,    -1,
      39,    -1,    40,    -1,    78,    -1,    -1,    -1,    17,    57,
      34,    64,    35,    19,    58,    49,    33,    -1,    18,    34,
      -1,    35,    19,    -1,    59,    64,    60,    49,    32,    -1,
      -1,    -1,    59,    64,    60,    49,    62,    23,    63,    49,
      32,    -1,    -1,    -1,    69,    65,    26,    66,    69,    -1,
      -1,    -1,    69,    67,    27,    68,    69,    -1,    69,    -1,
      28,    69,    -1,    76,    -1,    34,    64,    35,    -1,    -1,
      53,    70,    71,    53,    -1,     8,    -1,    10,    -1,    11,
      -1,     9,    -1,    12,    -1,    13,    -1,    30,    39,    -1,
      29,    42,    -1,    29,    39,    -1,    53,    -1,    53,    -1,
      -1,    16,    34,    39,    77,    31,    36,    74,    38,    75,
      37,    35,    -1,    15,    34,    79,    38,    80,    38,    36,
      81,    37,    35,    -1,    15,    34,    79,    38,    80,    38,
      36,    37,    35,    -1,     5,    -1,     7,    -1,     6,    -1,
       4,    -1,    40,    -1,    40,    -1,    81,    38,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   131,   135,   139,   146,   152,   160,   164,
     168,   176,   180,   187,   191,   195,   199,   203,   211,   219,
     224,   231,   235,   239,   246,   250,   254,   261,   265,   270,
     275,   280,   288,   292,   288,   307,   313,   319,   330,   332,
     328,   348,   351,   348,   357,   359,   357,   365,   370,   375,
     382,   385,   385,   394,   398,   402,   406,   410,   414,   422,
     429,   434,   443,   453,   465,   465,   501,   507,   517,   521,
     525,   529,   536,   548,   564
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OP_ASIG", "OP_RES", "OP_SUM", "OP_DIV",
  "OP_MUL", "OP_MAYOR", "OP_MAYOR_IGUAL", "OP_MENOR", "OP_MENOR_IGUAL",
  "OP_IGUAL", "OP_NO_IGUAL", "OP_TIPO", "TAKE", "BETWEEN", "WHILE", "IF",
  "THEN", "INTEGER", "FLOAT", "STRING", "ELSE", "DECVAR", "ENDDEC", "AND",
  "OR", "NOT", "WRITE", "READ", "COMA", "ENDIF", "ENDWHILE", "PAR_A",
  "PAR_C", "COR_A", "COR_C", "PYC", "ID", "CONST_ENT", "CONST_REAL",
  "CONST_STR", "$accept", "start", "seccion_declaracion",
  "bloque_variables", "listavar", "tipodato", "programa", "sentencia",
  "asignacion", "expresion_general", "expresion", "termino", "factor",
  "iteracion", "$@1", "$@2", "inicio_if", "inicio_then", "seleccion",
  "$@3", "$@4", "expresion_booleana", "$@5", "$@6", "$@7", "$@8",
  "termino_booleano", "$@9", "comparador", "entrada", "salida",
  "funcion_expresion_cota_inferior", "funcion_expresion_cota_superior",
  "between", "$@10", "take", "operador_take", "numeros_a_tomar",
  "lista_take_ctes", 0
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    46,    47,    47,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    50,    51,    52,
      52,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    57,    58,    56,    59,    60,    61,    62,    63,
      61,    65,    66,    64,    67,    68,    64,    64,    64,    64,
      69,    70,    69,    71,    71,    71,    71,    71,    71,    72,
      73,    73,    74,    75,    77,    76,    78,    78,    79,    79,
      79,    79,    80,    81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     4,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     1,     0,     0,     9,     2,     2,     5,     0,     0,
       9,     0,     0,     5,     0,     0,     5,     1,     2,     1,
       3,     0,     4,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     0,    11,    10,     9,     1,     1,
       1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     6,     0,     0,     1,    32,     0,
       0,     0,     0,     2,    11,    13,    14,     0,    15,    17,
      16,     3,     0,     0,     0,     0,    35,    61,    60,    59,
       0,    12,     0,     0,     0,     0,    29,    30,    28,    51,
      23,    26,     0,    41,    49,    31,     0,     8,     9,    10,
       5,     7,     0,     0,    19,    18,    20,     0,     0,    48,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,    71,    68,    70,    69,     0,    64,
      27,    50,    22,    21,    53,    56,    54,    55,    57,    58,
       0,    25,    24,    36,    38,    42,    45,     0,     0,     0,
      52,    37,     0,     0,     0,    33,    72,     0,     0,    39,
      43,    46,     0,     0,     0,     0,     0,     0,    62,     0,
       0,    34,     0,    73,     0,     0,    40,    67,     0,     0,
      63,     0,    66,    74,     0,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    50,    13,    14,    15,    55,
      39,    40,    41,    16,    25,   112,    17,    68,    18,   102,
     115,    42,    69,   103,    70,   104,    43,    64,    90,    19,
      20,   119,   131,    44,    99,    45,    78,   107,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int8 yypact[] =
{
     -10,   -17,    49,    -2,   -66,    31,    -6,   -66,   -66,    28,
     -30,    26,    66,    -2,   -66,   -66,   -66,     2,   -66,   -66,
     -66,   -66,     7,    71,    35,    48,   -66,   -66,   -66,   -66,
      -8,   -66,    52,    68,     5,     2,   -66,   -66,   -66,    73,
      88,   -66,    79,   -16,   -66,   -66,    71,   -66,   -66,   -66,
     -66,   -66,     2,    14,   -66,   -66,    73,    53,    45,   -66,
       0,    80,    14,    14,   100,    14,    14,    87,    -2,    90,
      91,   -66,    82,     0,   -66,   -66,   -66,   -66,    81,   -66,
     -66,   -66,    88,    88,   -66,   -66,   -66,   -66,   -66,   -66,
      14,   -66,   -66,   -66,    34,   -66,   -66,   101,    83,    93,
      73,   -66,    98,     5,     5,   -66,   -66,    84,    89,   -66,
     -66,   -66,    -2,    92,    14,    -2,    50,   -27,    73,    94,
      58,   -66,    95,   -66,    61,    14,   -66,   -66,    96,    86,
      73,    97,   -66,   -66,   102,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   -66,   122,    99,   -65,   -13,   -66,   -66,
     -29,    38,    39,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -12,   -66,   -66,   -66,   -66,   -32,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      31,    56,    59,    94,    62,    63,    60,    32,    23,    27,
     122,   -44,    28,   123,     1,     8,     9,    32,    33,   -47,
      32,    46,     4,    61,    73,    24,    53,    10,    11,    32,
      34,    36,    37,    38,    54,    80,    35,    12,    24,    35,
      72,    36,    37,    38,    36,    37,    38,   116,    53,     7,
     120,     8,     9,    36,    37,    38,    21,    74,    75,    76,
      77,   100,    26,    10,    11,    29,   101,     8,     9,    30,
       4,   110,   111,    12,    51,     8,     9,    62,    63,    10,
      11,    31,    52,   121,    79,   118,    57,    10,    11,    12,
     126,    47,    48,    49,    65,    66,   130,    12,   128,   129,
      82,    83,    58,    31,    91,    92,    93,    31,    84,    85,
      86,    87,    88,    89,    67,    81,    95,    97,    96,    98,
     105,   109,   113,   106,   108,   114,   133,    22,   117,     0,
     127,   132,   125,     0,   134,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,    71
};

static const yytype_int8 yycheck[] =
{
      13,    30,    34,    68,     4,     5,    35,    15,    14,    39,
      37,    27,    42,    40,    24,    17,    18,    15,    16,    35,
      15,    14,    39,    35,    53,    31,    34,    29,    30,    15,
      28,    39,    40,    41,    42,    35,    34,    39,    31,    34,
      52,    39,    40,    41,    39,    40,    41,   112,    34,     0,
     115,    17,    18,    39,    40,    41,    25,     4,     5,     6,
       7,    90,    34,    29,    30,    39,    32,    17,    18,     3,
      39,   103,   104,    39,    39,    17,    18,     4,     5,    29,
      30,    94,    34,    33,    39,   114,    34,    29,    30,    39,
      32,    20,    21,    22,     6,     7,   125,    39,    37,    38,
      62,    63,    34,   116,    65,    66,    19,   120,     8,     9,
      10,    11,    12,    13,    35,    35,    26,    35,    27,    38,
      19,    23,    38,    40,    31,    36,    40,     5,    36,    -1,
      35,    35,    38,    -1,    37,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    44,    45,    39,    46,    47,     0,    17,    18,
      29,    30,    39,    49,    50,    51,    56,    59,    61,    72,
      73,    25,    47,    14,    31,    57,    34,    39,    42,    39,
       3,    50,    15,    16,    28,    34,    39,    40,    41,    53,
      54,    55,    64,    69,    76,    78,    14,    20,    21,    22,
      48,    39,    34,    34,    42,    52,    53,    34,    34,    69,
      53,    64,     4,     5,    70,     6,     7,    35,    60,    65,
      67,    48,    64,    53,     4,     5,     6,     7,    79,    39,
      35,    35,    54,    54,     8,     9,    10,    11,    12,    13,
      71,    55,    55,    19,    49,    26,    27,    35,    38,    77,
      53,    32,    62,    66,    68,    19,    40,    80,    31,    23,
      69,    69,    58,    38,    36,    63,    49,    36,    53,    74,
      49,    33,    37,    40,    81,    38,    32,    35,    37,    38,
      53,    75,    35,    40,    37,    35
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
#line 122 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 0: <start> --> <seccion_declaracion> <programa> \n"); 
																				guardar_tabla(); 
																				guardar_tercetos();
																			}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 131 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	printf("\n Regla 1: <seccion_declaracion> --> DECVAR <bloque_variables> ENDDEC \n"); 	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 135 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 2: <bloque_variables> --> <bloque_variables> <listavar> OP_TIPO <tipodato> \n"); 
																				agregar_tipos_datos_a_tabla();
																			}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 139 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 3: <bloque_variables> --> <listavar> OP_TIPO <tipodato> \n"); 
																				agregar_tipos_datos_a_tabla();
																			}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 146 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 4: <listavar> --> ID  [ID: %s] \n", (yyvsp[(1) - (1)].str_val)); 
																				int idx = agregar_var_declarada_a_tabla(yylval.str_val); 
																				varADeclarar1 = fin_tabla; 
																				cantVarsADeclarar = 1; 
																			}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 152 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 5: <listavar> --> <listavar> COMA ID [ID: %s] \n", (yyvsp[(3) - (3)].str_val)); 
																				int idx = agregar_var_declarada_a_tabla(yylval.str_val); 
																				cantVarsADeclarar++; 
																			}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 160 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 6: <tipodato> --> INTEGER  \n"); 
																				tipoDatoADeclarar = ENUM_INTEGER; 
																			}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 164 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 7: <tipodato> --> FLOAT \n"); 
																			  	tipoDatoADeclarar = ENUM_FLOAT; 
																			}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 168 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 8: <tipodato> --> STRING \n"); 
																			  	tipoDatoADeclarar = ENUM_STRING; 
																			}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 176 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 9: <programa> --> <sentencia> \n"); 
																				idx_programa = idx_sentencia;
																			}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 180 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 10: <programa> --> <programa> <sentencia> \n"); 
																				idx_programa = crear_terceto(PROG, idx_programa, idx_sentencia);			
																			}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 187 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 11: <sentencia> --> <asignacion> \n"); 
																				idx_sentencia = idx_asignacion; 
																			}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 191 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																				printf("\n Regla 12: <sentencia> --> <iteracion> \n");
																				idx_sentencia = idx_iteracion;
																			}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 195 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																				printf("\n Regla 13: <sentencia> --> <seleccion> \n");
																				idx_sentencia = idx_seleccion; 
																			}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 199 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 14: <sentencia> --> <salida> \n");
																				idx_sentencia = idx_salida; 
																			}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 203 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
			    																printf("\n Regla 15: <sentencia> --> <entrada> \n");
																				idx_sentencia = idx_entrada; 
																			}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 211 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
																				printf("\n Regla 16: <asignacion> --> ID OP_ASIG <expresion> \n"); 	
																				int idx = buscar_en_tabla((yyvsp[(1) - (3)].str_val));
																				idx_asignacion = crear_terceto(OP_ASIG, idx, idx_expresion_general);
																			}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 219 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																				printf("\n Regla 17: <expresion_general> --> CTE_STRING \n");
																				int idx = agregar_cte_string_a_tabla(yylval.str_val);
																				idx_expresion_general = crear_terceto(PARTE_VACIA,idx,PARTE_VACIA);
																			}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 224 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																				printf("\n Regla 18: <expresion_general> --> <expresion>\n");
																				idx_expresion_general = idx_expresion;
																			}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 231 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 19: <expresion> --> <expresion> OP_SUM <termino> \n"); 
																				idx_expresion = crear_terceto(OP_SUM, idx_expresion, idx_termino);
																			}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 235 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 20: <expresion> --> <expresion> OP_RES <termino> \n"); 
																				idx_expresion = crear_terceto(OP_RES, idx_expresion, idx_termino);
																			}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 239 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 21: <expresion> --> <termino> \n"); 
																				idx_expresion = idx_termino; 
																			}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 246 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 22: <termino> --> <termino> OP_MUL <factor> \n");
																				idx_termino = crear_terceto(OP_MUL, idx_termino, idx_factor);
																			}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 250 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 23: <termino> --> <termino> OP_DIV <factor> \n");
																				idx_termino = crear_terceto(OP_DIV, idx_termino, idx_factor);
																			}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 254 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 24: <termino> --> <factor> \n"); 
																				idx_termino = idx_factor;
																			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 261 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 25: <factor> --> PAR_A <expresion> PAR_C \n"); 
																				idx_factor = idx_expresion;
																			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 265 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 26: <factor> --> CONST_REAL \n");
																				int idx = agregar_cte_real_a_tabla(yylval.real_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 270 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 27: <factor> --> ID \n"); 
																				int idx = buscar_en_tabla((yyvsp[(1) - (1)].str_val));
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 275 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 28: <factor> --> CONST_ENT \n"); 
																				int idx = agregar_cte_int_a_tabla(yylval.int_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 280 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																				printf("\n Regla 29: <factor> --> <take> \n");
																				// validar_tipo_dato(ENUM_FLOAT);
																				idx_factor = idx_take;
																			}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 288 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
															idx_iteracion = crear_terceto(WHILE, PARTE_VACIA, PARTE_VACIA); 
															apilar_terceto(); 
														}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 292 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {	
															idx_then = crear_terceto(THEN,PARTE_VACIA,PARTE_VACIA); 
															actualizar_terceto_pos_then();
														}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 297 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 30: <iteracion> --> WHILE <expresion_booleana> THEN <programa> ENDWHILE\n");
															idx_salto_implicito = crear_terceto(JMP,idx_iteracion,PARTE_VACIA);
															idx_end_while = crear_terceto(ENDWHILE, PARTE_VACIA, PARTE_VACIA);
															actualizar_terceto_pos_end_while();
															desapilar_terceto();
														}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 307 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															idx_if=crear_terceto(IF, PARTE_VACIA, PARTE_VACIA);
															apilar_terceto();
														}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 313 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {	
															idx_then=crear_terceto(THEN,PARTE_VACIA,PARTE_VACIA);
	  														actualizar_terceto_pos_then();
														}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 320 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 31: <seleccion> --> IF <expresion_booleana> THEN <programa> ENDIF\n");
															idx_end_if=crear_terceto(ENDIF,PARTE_VACIA,PARTE_VACIA);
															idx_else=idx_end_if;
															actualizar_terceto_pos_else();
															desapilar_terceto();
															idx_seleccion=idx_if;
														}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 330 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {	idx_bloque_if_true = idx_programa;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 332 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {	
															idx_salto_implicito = crear_terceto(JMP, PARTE_VACIA, PARTE_VACIA);
	  														idx_else = crear_terceto(ELSE,PARTE_VACIA,PARTE_VACIA);
															actualizar_terceto_pos_else();
														}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 337 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 32:<seleccion> --> IF <expresion_booleana> THEN <programa> ELSE <programa> ENDIF\n"); 
															idx_end_if = crear_terceto(ENDIF,PARTE_VACIA,PARTE_VACIA);
															actualizar_terceto_pos_end_if();
															desapilar_terceto();
															idx_seleccion=idx_if;
														}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 348 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
															idx_termino_booleano_izq = idx_termino_booleano;	
														}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 351 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	idx_condicion_izq = crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 352 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 33: <expresion_booleana> --> <termino_booleano> AND <termino_booleano>\n");
															idx_condicion_der =  crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
															idx_expresion_booleana = crear_terceto(AND, idx_termino_booleano_izq, idx_termino_booleano);
														}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 357 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	
															idx_termino_booleano_izq = idx_termino_booleano;	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 359 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	has_or = crear_terceto(obtener_salto_condicion(comp_bool_actual), idx_termino_booleano, PARTE_VACIA); 	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 360 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 34: <expresion_booleana> --> <termino_booleano> OR <termino_booleano>\n");
															idx_condicion_der =  crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
															idx_expresion_booleana = crear_terceto(OR, idx_termino_booleano_izq, idx_termino_booleano);
														}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 365 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 35: <expresion_booleana> --> <termino_booleano>\n");
															idx_expresion_booleana = idx_termino_booleano;
															idx_condicion_izq = crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
														}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 370 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 36: <expresion_booleana> --> NOT <termino_booleano>\n");
															idx_expresion_booleana = idx_termino_booleano;
															idx_condicion_izq = crear_terceto(obtener_salto_condicion(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
														}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 375 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 37: <expresion_booleana> --> <between>\n");
															idx_expresion_booleana = idx_between;
														}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 382 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 38: <expresion_booleana> --> PAR_A <termino_booleano> PAR_C\n");
														}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 385 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 	idx_expresion_izq = idx_expresion;	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 386 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
															printf("\n Regla 39: <termino_booleano> --> <expresion> <comparador> <expresion>\n");
															reset_tipo_dato();
															idx_termino_booleano = crear_terceto(CMP, idx_expresion_izq, idx_expresion);
														}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 394 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
															printf("\n Regla 40: <comparador> --> OP_MAYOR \n");
															comp_bool_actual = OP_MAYOR; 
														}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 398 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
															printf("\n Regla 41: <comparador> --> OP_MENOR \n");
															comp_bool_actual = OP_MENOR; 
														}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 402 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
															printf("\n Regla 42: <comparador> --> OP_MENOR_IGUAL \n");
															comp_bool_actual = OP_MENOR_IGUAL; 
														}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 406 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
															printf("\n Regla 43: <comparador> --> OP_MAYOR_IGUAL \n"); 
															comp_bool_actual = OP_MAYOR_IGUAL; 
														}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 410 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
															printf("\n Regla 44: <comparador> --> OP_IGUAL \n"); 
															comp_bool_actual = OP_IGUAL; 
														}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 414 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
															printf("\n Regla 45: <comparador> --> OP_NO_IGUAL \n");
															comp_bool_actual = OP_NO_IGUAL; 
														}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 422 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 46: <entrada> --> READ ID \n"); 
																				validar_var_en_tabla(yylval.str_val);
																			}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 429 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 46: <salida> -->  WRITE CONST_STR  \n"); 
																				int idx = agregar_cte_string_a_tabla(yylval.str_val); 
																				idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 434 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																				printf("\n Regla 47: <salida> -->  WRITE ID  \n"); 
																				validar_var_en_tabla(yylval.str_val); 
																				int idx = buscar_en_tabla((yyvsp[(2) - (2)].str_val));
																				idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 443 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																	printf("\n Regla 48: <funcion_expresion_cota_inferior> -->  <expresion>  \n"); 
																	idx_cota_inferior = idx_expresion;
																	comp_bool_actual = OP_MAYOR_IGUAL; // Salta por BLT
																	int idx_aux= crear_terceto(CMP,idx_valor_a_comparar,idx_cota_inferior);
																	idx_salto_a_fin_between_cota_inf=crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_aux, PARTE_VACIA);
																}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 453 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																	printf("\n Regla 49: <funcion_expresion_cota_superior> -->  <expresion>  \n");
																	idx_cota_superior = idx_expresion;	
																	int idx_aux= crear_terceto(CMP,idx_valor_a_comparar,idx_cota_superior);
																	comp_bool_actual = OP_MENOR_IGUAL;  // Salta por BGT
																	idx_salto_a_fin_between_cota_sup=crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_aux, PARTE_VACIA);
																}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 465 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																int tipo_dato = validar_var_en_tabla((yyvsp[(3) - (3)].str_val));
																tipo_dato_actual = validar_tipo_dato(tipo_dato, tipo_dato_actual);
																int idx = buscar_en_tabla((yyvsp[(3) - (3)].str_val));
																idx_valor_a_comparar = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
															}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 473 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																printf("\n Regla 50: <between> --> BETWEEN PAR_A ID COMA COR_A <expresion> PYC <expresion> COR_C PAR_C \n"); 
																// Se debe verificar que el ID que se ingresa sea variable DEL TIPO NUMERICA UNICAMENTE.

																reset_tipo_dato(); // Revisar
																int idx_var_between = buscar_o_insertar_var_en_tabla("@between",ENUM_INTEGER);
																int valor_verdadero = agregar_cte_int_a_tabla(1);
																crear_terceto(OP_ASIG, idx_var_between, valor_verdadero); 

																idx_salto_between=crear_terceto(JMP, PARTE_VACIA, PARTE_VACIA); //Saltea la asignacion de falso
																
																// Flow solo si viene por falso
																int valor_falso = agregar_cte_int_a_tabla(0);
																int idx_terceto_falso = crear_terceto(BETWEEN_FALSE, PARTE_VACIA, PARTE_VACIA);
																crear_terceto(OP_ASIG, idx_var_between, valor_falso); //A este terceto se llega si es verdadero, asigno 1 a @between
																
																// Flow final obligatorio
																idx_between = crear_terceto(BETWEEN_CMP, PARTE_VACIA, PARTE_VACIA); // Aca caigo si algun branch por falso me hizo caer directo aca.
																crear_terceto(CMP, idx_var_between, valor_verdadero); //Comparo @between contra verdadero

																// Relleno tercetos con branches que saltan por casos falsos.
																// Valor a comparar fuera de las cotas
																poner_salto_hacia_fin_between(idx_terceto_falso, idx_salto_between, idx_between, idx_salto_a_fin_between_cota_inf, idx_salto_a_fin_between_cota_sup);
															}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 502 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																					printf("\n Regla 51: <take> --> TAKE PAR_A <operador_take> PYC numeros_a_tomar PYC COR_A <lista_take_ctes> COR_C PAR_C \n"); 
																					idx_take = idx_resultado_take;
																					validar_cantidad_take(cantidad_a_tomar);
																				}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 508 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																					printf("\n Regla 52: <take> --> TAKE PAR_A <operador_take> PYC numeros_a_tomar PYC COR_A COR_C PAR_C \n"); 
																					int valor_cero = agregar_cte_int_a_tabla(0);\
																					int idx_cero = crear_terceto(PARTE_VACIA,valor_cero,PARTE_VACIA);
																					idx_take = crear_terceto(OP_ASIG, idx_var_take, idx_cero);
																				}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 517 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																					printf("\n Regla 53: <operador_take> --> OP_SUM \n"); 
																					operador_take = OP_SUM;
																				}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 521 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																					printf("\n Regla 54: <operador_take> --> OP_MUL \n"); 
																					operador_take = OP_MUL;
																				}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 525 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																					printf("\n Regla 55: <operador_take> --> OP_DIV \n"); 
																					operador_take = OP_DIV;
																				}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 529 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																					printf("\n Regla 56: <operador_take> --> OP_RES \n"); 
																					operador_take = OP_RES;
																				}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 536 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																					printf("\n Regla 57: <numeros_a_tomar> --> CONST_ENT \n"); 
																					// reset_tipo_dato(); // Revisar
																					cantidad_a_tomar = (yyvsp[(1) - (1)].int_val);
																					agregar_cte_int_a_tabla(cantidad_a_tomar);

																					idx_var_take = buscar_o_insertar_var_en_tabla("@take_accu",ENUM_INTEGER);
																					idx_var_take_aux = buscar_o_insertar_var_en_tabla("@take_accu_aux",ENUM_INTEGER);
																				}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 548 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    { 
																					printf("\n Regla 58: <lista_take_ctes> --> CONST_ENT \n");
																					// int idx = agregar_cte_int_a_tabla(yylval.int_val);
																					int idx = agregar_cte_int_a_tabla((yyvsp[(1) - (1)].int_val));
																					if(cantidad_a_tomar > 0) {
																						int idx_primer_constante = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																						idx_resultado_take = crear_terceto(OP_ASIG, idx_var_take, idx_primer_constante);
																						cantidad_a_tomar--;
																					}
																					else {
																						// Por falta de definicion, se considera que se devuelve 0 cuando la cantidad a tomar es 0.
																						int valor_cero = agregar_cte_int_a_tabla(0);\
																						int idx_cero = crear_terceto(PARTE_VACIA,valor_cero,PARTE_VACIA);
																						idx_resultado_take = crear_terceto(OP_ASIG, idx_var_take, idx_cero);
																					}
																				}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 564 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"
    {
																					printf("\n Regla 59: <lista_take_ctes> --> <lista_take_ctes> PYC <factor> \n");
																					int idx = agregar_cte_int_a_tabla((yyvsp[(3) - (3)].int_val));
																					if(cantidad_a_tomar > 0) {
																						int idx_siguiente_constante = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA); // Crea terceto para sig
																						crear_terceto(OP_ASIG, idx_var_take_aux, idx_siguiente_constante); // Crea terceto de igualacion entre var accu aux y var sig
																						int idx_operacion_terceto = crear_terceto(operador_take, idx_var_take, idx_var_take_aux); // Crea un terceto operando los acumuladores con el operador take
																						idx_resultado_take = crear_terceto(OP_ASIG, idx_var_take, idx_operacion_terceto); // Vuelve a asignar al accu
																						cantidad_a_tomar--;
																					}
																				}
    break;



/* Line 1455 of yacc.c  */
#line 2428 "y.tab.c"
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
#line 576 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"


