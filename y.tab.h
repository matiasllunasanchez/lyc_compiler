
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 66 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"

    int int_val;
	float real_val;
    char *str_val;



/* Line 1676 of yacc.c  */
#line 142 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


