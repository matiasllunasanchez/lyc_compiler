
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

/* Line 1676 of yacc.c  */
#line 114 "E:\\COMPILADORES\\TP\\lyc_compiler\\Sintactico.y"

    int int_val;
	float real_val;
    char *str_val;



/* Line 1676 of yacc.c  */
#line 144 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


