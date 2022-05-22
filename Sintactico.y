%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "libs/tercetos/tercetos.h"
#include "libs/tabla_simbolos/tabla_simbolos.h"

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
// Cosas para comparadores booleanos
int comp_bool_actual;
int idx_programa;
int idx_sentencia;
int idx_dec;
int idx_asig;
int idx_ciclo;
int idx_cond;
int idx_salida;
int idx_entrada;
int idx_entre;
int idx_tomar;
int idx_factor;
int idx_expresion;
int idx_termino;
%}

%start start 
%right OP_ASIG 
%left OP_SUM OP_RES
%left OP_MUL OP_DIV

%token OP_MAYOR OP_MAYOR_IGUAL OP_MENOR OP_MENOR_IGUAL OP_IGUAL OP_NO_IGUAL OP_TIPO
%token TAKE BETWEEN WHILE IF INTEGER FLOAT STRING ELSE DECVAR ENDDEC AND OR NOT
%token WRITE READ COMA ENDIF ENDWHILE PAR_A PAR_C COR_A COR_C PYC



%union {
    int int_val;
	float real_val;
    char *str_val;
}

%token <str_val>ID
%token <int_val>CONST_ENT
%token <real_val>CONST_REAL
%token <str_val>CONST_STR



%%

// Reglas base
start: seccion_declaracion programa                                         { 
																				printf("\n REGLA 0: <start> --> <seccion_declaracion> <programa> \n"); 
																				guardarTabla(); 
																				guardar_tercetos();
																			}
;

// Declaraciones de Variables - 8 Shifts + Reduces
seccion_declaracion:
    DECVAR bloque_variables ENDDEC                                          { printf("\n REGLA 1: <seccion_declaracion> --> DECVAR <bloque_variables> ENDDEC \n"); }
;    

bloque_variables:
    bloque_variables listavar OP_TIPO tipodato                              { 
																				printf("\n REGLA 2: <bloque_variables> --> <bloque_variables> <listavar> OP_TIPO <tipodato> \n"); 
																				agregarTiposDatosATabla(); 
																			}
    | listavar OP_TIPO tipodato                                             { 
																				printf("\n REGLA 3: <bloque_variables> --> <listavar> OP_TIPO <tipodato> \n"); 
																				agregarTiposDatosATabla(); 
																			}
;
 
listavar:
    ID                                                                      { 
																				printf("\n REGLA 4: <listavar> --> ID \n"); 
																				int idx = agregarVarATabla(yylval.str_val); 
																				varADeclarar1 = fin_tabla; 
																				cantVarsADeclarar = 1; 
																			}
    | listavar COMA ID                                                      { 
																				printf("\n REGLA 5: <listavar> --> <listavar> COMA ID \n"); 
																				int idx = agregarVarATabla(yylval.str_val); 
																				cantVarsADeclarar++; 
																			}
;

tipodato:
    INTEGER                                                                 { 
																				printf("\n REGLA 6: <tipodato> --> INTEGER  \n"); 
																				tipoDatoADeclarar = ENUM_INTEGER; 
																			}
    | FLOAT                                                                 { 
																				printf("\n REGLA 7: <tipodato> --> FLOAT \n"); 
																			  	tipoDatoADeclarar = ENUM_FLOAT; 
																			}
    | STRING                                                                { 
																				printf("\n REGLA 8: <tipodato> --> STRING \n"); 
																			  	tipoDatoADeclarar = ENUM_STRING; 
																			}
;

// Reglas base
programa:
      sentencia                                                   			{ 
																				printf("\n REGLA 9: <programa> --> <sentencia> \n"); 
																				idx_programa = idx_sentencia;
																			}       
    | programa sentencia                                        			{ 
																				printf("\n REGLA 10: <programa> --> <programa> <sentencia> \n"); 
																				idx_programa = crear_terceto(PROG, idx_programa, idx_sentencia);			
																			}
;

sentencia:
    | asignacion                                                            { 
																				printf("\n REGLA 11: <sentencia> --> <asignacion> \n"); 
																				idx_sentencia = idx_asig; 
																			}    
    | iteracion                                                             { 
																				printf("\n REGLA 12: <sentencia> --> <iteracion> \n");
																				 idx_sentencia = idx_ciclo;
																			}   
    | seleccion                                                           	{ 
																				printf("\n REGLA 13: <sentencia> --> <seleccion> \n");
																				idx_sentencia = idx_cond; 
																			}  
    | salida                                                                { 
																				printf("\n REGLA 14: <sentencia> --> <salida> \n");
																				idx_sentencia = idx_salida; 
																			}    
    | entrada                                                               { 
			    																printf("\n REGLA 15: <sentencia> --> <entrada> \n");
																				idx_sentencia = idx_entrada; 
																			}
;

// General
asignacion:
    ID OP_ASIG expresion                                                    { printf("\n REGLA 16: <asignacion> --> ID OP_ASIG <expresion> \n"); }
	| ID OP_ASIG CONST_STR                                                  { 
																				printf("\n REGLA 17: <asignacion> --> ID OP_ASIG CONST_STR \n"); 
																				int idx = agregarCteStringATabla(yylval.str_val);
																			}
	| ID OP_ASIG take														{ printf("\n REGLA 18: <asignacion> --> ID OP_ASIG <take> \n"); }		
;

expresion:
    expresion OP_SUM termino                                               	{ 
																			  printf("\n REGLA 19: <expresion> --> <expresion> OP_SUM <termino> \n"); 
																			  idx_expresion = crear_terceto(OP_SUM, idx_expresion, idx_termino);
																			}
    | expresion OP_RES termino                                            	{ 
																			  printf("\n REGLA 20: <expresion> --> <expresion> OP_RES <termino> \n"); 
																			  idx_expresion = crear_terceto(OP_RES, idx_expresion, idx_termino);
																			}
    | termino                                                               { 
																			  printf("\n REGLA 21: <expresion> --> <termino> \n"); 
	 																		  idx_expresion = idx_termino; 
																			}
;

termino:
    termino OP_MUL factor                                                  	{ 
																				printf("\n REGLA 22: <termino> --> <termino> OP_MUL <factor> \n");
																				idx_termino = crear_terceto(OP_MUL, idx_termino, idx_factor);
																			}
    | termino OP_DIV factor                                                 { 
																				printf("\n REGLA 23: <termino> --> <termino> OP_DIV <factor> \n");
																				idx_termino = crear_terceto(OP_DIV, idx_termino, idx_factor);
																			}
    | factor                                                                { 
																				printf("\n REGLA 24: <termino> --> <factor> \n"); 
																				idx_termino = idx_factor;
																			}
;

factor:
    PAR_A expresion PAR_C                                                   { 
																				printf("\n REGLA 25: <factor> --> PAR_A <expresion> PAR_C \n"); 
																				idx_factor = idx_expresion;
																			} 
    | CONST_REAL                                                            { 
																				printf("\n REGLA 26: <factor> --> CONST_REAL \n");
																				int idx = agregarCteRealATabla(yylval.real_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    | ID                                                                    { 
																				printf("\n REGLA 27: <factor> --> ID \n"); 
																				int idx = buscarEnTabla($1);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			} 
    | CONST_ENT                                                             { 
																				printf("\n REGLA 28: <factor> --> CONST_ENT \n"); 
																				int idx = agregarCteIntATabla(yylval.int_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
;

// Sentencias de control
seleccion:
    IF PAR_A condicion PAR_C programa ELSE programa ENDIF                   			{ printf("\n REGLA 29: <seleccion> --> IF PAR_A <condicion> PAR_C <programa> ELSE <programa> ENDIF\n"); }
    | IF PAR_A condicion PAR_C programa ENDIF                               			{ printf("\n REGLA 30: <seleccion> --> IF PAR_A <condicion> PAR_C <programa> ENDIF \n"); }
;

iteracion:
    WHILE PAR_A condicion PAR_C programa ENDWHILE                           			{ printf("\n REGLA 31: <iteracion> --> WHILE PAR_A <condicion> PAR_C <programa> ENDWHILE\n"); }
;

condicion:
    | comparacion                                                           { printf("\n REGLA 33: <condicion> --> <comparacion> \n"); }
	| NOT comparacion                                                       { printf("\n REGLA 44: <condicion> --> NOT <comparacion> \n"); }
    | condicion AND comparacion                                             { printf("\n REGLA 45: <condicion> --> <condicion> AND <comparacion> <c> \n"); }
    | condicion OR comparacion                                              { printf("\n REGLA 46: <condicion> --> <condicion> OR <comparacion> \n"); }
	| between																{ printf("\n REGLA 47: <condicion> --> PAR_A <between> PAR_C \n"); }
;

comparacion:
	PAR_A condicion PAR_C													 { printf("\n REGLA 48.bis: <comparacion> --> PAR_A <condicion> PAR_C \n"); }
    | expresion comparador expresion                                         { printf("\n REGLA 48: <comparacion> --> <expresion> <comparador> <expresion> \n"); }
;

comparador:
    OP_MAYOR                                                                { 
																				printf("\n REGLA 49: <comparador> --> OP_MAYOR \n");
																				comp_bool_actual = OP_MAYOR; 
																			} 
    | OP_MENOR                                                              { 
																				printf("\n REGLA 50: <comparador> --> OP_MENOR \n");
																				comp_bool_actual = OP_MENOR; 
																			} 
    | OP_MENOR_IGUAL                                                        { 
																				printf("\n REGLA 51: <comparador> --> OP_MENOR_IGUAL \n");
																				comp_bool_actual = OP_MENOR_IGUAL; 
																			} 
    | OP_MAYOR_IGUAL                                                             { 
																				printf("\n REGLA 52: <comparador> --> OP_MAYOR_IGUAL \n"); 
																				comp_bool_actual = OP_MAYOR_IGUAL; 
																			} 
    | OP_IGUAL                                                              { 
																				printf("\n REGLA 53: <comparador> --> OP_IGUAL \n"); 
																				comp_bool_actual = OP_IGUAL; 
																			} 
    | OP_NO_IGUAL                                                           { 
																				printf("\n REGLA 54: <comparador> --> OP_NO_IGUAL \n");
																				comp_bool_actual = OP_NO_IGUAL; 
																			}
;

// Lectura y escritura
entrada:
    READ ID                                                                 { 
																				printf("\n REGLA 55: <entrada> --> READ ID \n"); 
																				chequearVarEnTabla(yylval.str_val);
																			}
;

salida:
    WRITE CONST_STR                                                         { 
																			  printf("\n REGLA 56: <salida> -->  WRITE CONST_STR  \n"); 
																			  int idx = agregarCteStringATabla(yylval.str_val); 
																			  idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
    | WRITE ID                                                              { 
																			  printf("\n REGLA 57: <salida> -->  WRITE ID  \n"); 
																			  chequearVarEnTabla(yylval.str_val); 
																			  int idx = buscarEnTabla($2);
																			  idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
;

// Funciones Especiales - 8 Shifts + Reduces
// BETWEEN  -- Devuelve un booleano, debe usarse dentro de una condicion
between:
    BETWEEN PAR_A ID COMA COR_A expresion PYC expresion COR_C PAR_C    							{ printf("\n REGLA 58: <between> --> BETWEEN PAR_A ID COMA COR_A <expresion> PYC <expresion> COR_C PAR_C \n"); }
;

// TAKE  --- Devuelve un valor, deberia poder asignarse
// Para mi el take va como factor
take:
     TAKE PAR_A operadores_take PYC CONST_ENT PYC COR_A lista_take_ctes COR_C PAR_C          	{ printf("\n REGLA 59: <take> --> TAKE PAR_A <operadores_take> PYC CONST_ENT PYC COR_A <lista_take_ctes> COR_C PAR_C \n"); }
    |  TAKE PAR_A operadores_take PYC CONST_ENT PYC COR_A COR_C PAR_C                   		{ printf("\n REGLA 60: <take> --> TAKE PAR_A <operadores_take> PYC CONST_ENT PYC COR_A COR_C PAR_C \n"); }
;

lista_take_ctes:
	CONST_ENT                                                                					{ printf("\n REGLA 61: <lista_take_ctes> --> CONST_ENT \n"); }
	| lista_take_ctes PYC CONST_ENT                                          					{ printf("\n REGLA 62: <lista_take_ctes> --> <lista_take_ctes> PYC <factor> \n"); }
;

operadores_take:
OP_SUM                                                                     { printf("\n REGLA 63: <oper> --> OP_SUM \n"); } 
| OP_MUL                                                                   { printf("\n REGLA 64: <oper> --> OP_MUL \n"); }
| OP_DIV                                                                   { printf("\n REGLA 65: <oper> --> OP_DIV \n"); }
| OP_RES                                                                   { printf("\n REGLA 66: <oper> --> OP_RES \n"); }
;
%%
