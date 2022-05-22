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
%left OP_SUMA OP_RESTA
%left OP_MULT OP_DIV

%token OP_MAYOR OP_MAYIGU OP_MENOR OP_MENIGU OP_IGUAL OP_NO_IGUAL OP_TIPO
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
start: programa                                                             { 
																				printf("\n REGLA 0: <start> --> <programa> \n"); 
																				guardarTabla(); 
																				guardar_tercetos();
																			}
;
    
programa:
    sentencia                                                               { 
																				printf("\n REGLA 1: <programa> --> <sentencia> \n"); 
																				idx_programa = idx_sentencia;
																			}       
    | programa sentencia                                                    { 
																				printf("\n REGLA 2: <programa> --> <programa> <sentencia> \n"); 
																				idx_programa = crear_terceto(PROG, idx_programa, idx_sentencia);			
																			}
;

sentencia:
    | declaracion                                                           { 
																				printf("\n REGLA 3: <sentencia> --> <declaracion> \n"); 
																				idx_sentencia = idx_dec; 
																			}  
    | asignacion                                                            { 
																				printf("\n REGLA 4: <sentencia> --> <asignacion> \n"); 
																				idx_sentencia = idx_asig; 
																			}    
    | ciclo                                                                 { 
																				printf("\n REGLA 5: <sentencia> --> <ciclo> \n");
																				 idx_sentencia = idx_ciclo;
																			}   
    | condicional                                                           { 
																				printf("\n REGLA 6: <sentencia> --> <condicional> \n");
																				idx_sentencia = idx_cond; 
																			}  
    | salida                                                                { 
																				printf("\n REGLA 7: <sentencia> --> <salida> \n");
																				idx_sentencia = idx_salida; 
																			}    
    | entrada                                                               { 
			    																printf("\n REGLA 8: <sentencia> --> <entrada> \n");
																				idx_sentencia = idx_entrada; 
																			}  
    | entre                                                                 { 
																				printf("\n REGLA 9: <sentencia> --> <entre> \n");
																				idx_sentencia = idx_entre; 
																			}  
    | tomar                                                                 { 
																				printf("\n REGLA 10: <sentencia> --> <tomar> \n");
																				idx_sentencia = idx_tomar; 
																			}  
;

// Declaraciones de Variables
declaracion:
    DECVAR bloque_variables ENDDEC                                          { printf("\n REGLA 20: <declaracion> --> DECVAR <bloque_variables> ENDDEC \n"); }
;    

listavar:
    ID                                                                      { 
																				printf("\n REGLA 21: <listavar> --> ID \n"); 
																				int idx = agregarVarATabla(yylval.str_val); 
																				varADeclarar1 = fin_tabla; 
																				cantVarsADeclarar = 1; 
																			}
    | listavar COMA ID                                                      { 
																				printf("\n REGLA 22: <listavar> --> <listavar> COMA ID \n"); 
																				int idx = agregarVarATabla(yylval.str_val); 
																				cantVarsADeclarar++; 
																			}
;

tipodato:
    INTEGER                                                                 { 
																				printf("\n REGLA 23: <tipodato> --> INTEGER  \n"); 
																				tipoDatoADeclarar = INTEGER; 
																			}
    | FLOAT                                                                 { 
																				printf("\n REGLA 24: <tipodato> --> FLOAT \n"); 
																			  	tipoDatoADeclarar = FLOAT; 
																			}
    | STRING                                                                { 
																				printf("\n REGLA 25: <tipodato> --> STRING \n"); 
																			  	tipoDatoADeclarar = STRING; 
																			}
;

bloque_variables:
    bloque_variables listavar OP_TIPO tipodato                              { 
																				printf("\n REGLA 60: <bloque_variables> --> <bloque_variables> listavar OP_TIPO tipodato \n"); 
																				agregarTiposDatosATabla(); 
																			}
    | listavar OP_TIPO tipodato                                             { 
																				printf("\n REGLA 61: <bloque_variables> --> listavar OP_TIPO tipodato \n"); 
																				agregarTiposDatosATabla(); 
																			}
;

// General
asignacion:
    ID OP_ASIG expresion                                                    { printf("\n REGLA 32: <asignacion> --> ID OP_ASIG <expresion> \n"); }
	| ID OP_ASIG CONST_STR                                                  { 
																				printf("\n REGLA 33: <asignacion> --> ID OP_ASIG CONST_STR \n"); 
																				int idx = agregarCteStringATabla(yylval.str_val);
																			}
;

expresion:
    expresion OP_SUMA termino                                               { 
																			  printf("\n REGLA 34: <expresion> --> <expresion> OP_SUMA <termino> \n"); 
																			  idx_expresion = crear_terceto(OP_SUMA, idx_expresion, idx_termino);
																			}
    | expresion OP_RESTA termino                                            { 
																			  printf("\n REGLA 35: <expresion> --> <expresion> OP_RESTA <termino> \n"); 
																			  idx_expresion = crear_terceto(OP_RESTA, idx_expresion, idx_termino);
																			}
    | termino                                                               { 
																			  printf("\n REGLA 36: <expresion> --> <termino> \n"); 
	 																		  idx_expresion = idx_termino; 
																			}
;

termino:
    termino OP_MULT factor                                                  { 
																				printf("\n REGLA 37: <termino> --> <termino> OP_MULT <factor> \n");
																				idx_termino = crear_terceto(OP_MULT, idx_termino, idx_factor);
																			}
    | termino OP_DIV factor                                                 { 
																				printf("\n REGLA 38: <termino> --> <termino> OP_DIV <factor> \n");
																				idx_termino = crear_terceto(OP_DIV, idx_termino, idx_factor);
																			}
    | factor                                                                { 
																				printf("\n REGLA 39: <termino> --> <factor> \n"); 
																				idx_termino = idx_factor;
																			}
;

factor:
    PAR_A expresion PAR_C                                                   { 
																				printf("\n REGLA 40: <factor> --> PAR_A <expresion> PAR_C \n"); 
																				idx_factor = idx_expresion;
																			} 
    | CONST_REAL                                                            { 
																				printf("\n REGLA 41: <factor> --> CONST_REAL \n");
																				int idx = agregarCteRealATabla(yylval.real_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    | ID                                                                    { 
																				printf("\n REGLA 42: <factor> --> ID \n"); 
																				int idx = buscarEnTabla($1);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			} 
    | CONST_ENT                                                             { 
																				printf("\n REGLA 43: <factor> --> CONST_ENT \n"); 
																				int idx = agregarCteIntATabla(yylval.int_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
;

// Sentencias de control
condicional:
    IF PAR_A condicion PAR_C programa ELSE programa ENDIF                   { printf("\n REGLA 26: <condicional> --> IF PAR_A <condicion> PAR_C <programa> ELSE <programa> ENDIF\n"); }
    | IF PAR_A condicion PAR_C programa ENDIF                               { printf("\n REGLA 27: <condicional> --> IF PAR_A <condicion> PAR_C <programa> ENDIF \n"); }
;

ciclo:
    WHILE PAR_A condicion PAR_C programa ENDWHILE                           { printf("\n REGLA 28: <ciclo> --> WHILE PAR_A <condicion> PAR_C <programa> ENDWHILE\n"); }
;

condicion:
    exp                                                                     { printf("\n REGLA 44: <condicion> --> <exp> \n"); }
    | exp AND exp_izq                                                       { printf("\n REGLA 45: <condicion> --> <exp> AND <exp_izq> \n"); }
    | exp OR exp_izq                                                        { printf("\n REGLA 46: <condicion> --> <exp> OR <exp_izq> \n"); }
;

exp:
    comparacion                                                             { printf("\n REGLA 47: <exp> --> <comparacion> \n"); }
    | PAR_A comparacion PAR_C                                               { printf("\n REGLA 48: <exp> --> PAR_A <comparacion> PAR_C \n"); }
    | expresion                                                             { printf("\n REGLA 49: <exp> --> <expresion> \n"); }
;

exp_izq:
    exp                                                                     { printf("\n REGLA 50: <exp> --> <exp_izq> \n"); }
;

comparacion:
   expresion comparador factor                                              { printf("\n REGLA 51: <comparacion> --> <expresion> <comparador> <factor> \n"); }
   | PAR_A condicion PAR_C                                                  { printf("\n REGLA 52: <comparacion> --> PAR_A <condicion> PAR_C\n"); }
   | NOT condicion                                                          { printf("\n REGLA 53: <condicion> -->  NOT <condicion> \n"); }
;

comparador:
    OP_MAYOR                                                                { 
																				printf("\n REGLA 54: <comparador> --> OP_MAYOR \n");
																				comp_bool_actual = OP_MAYOR; 
																			} 
    | OP_MENOR                                                              { 
																				printf("\n REGLA 55: <comparador> --> OP_MENOR \n");
																				comp_bool_actual = OP_MENOR; 
																			} 
    | OP_MENIGU                                                             { 
																				printf("\n REGLA 56: <comparador> --> OP_MENIGU \n");
																				comp_bool_actual = OP_MENIGU; 
																			} 
    | OP_MAYIGU                                                             { 
																				printf("\n REGLA 57: <comparador> --> OP_MAYIGU \n"); 
																				comp_bool_actual = OP_MAYIGU; 
																			} 
    | OP_IGUAL                                                              { 
																				printf("\n REGLA 58: <comparador> --> OP_IGUAL \n"); 
																				comp_bool_actual = OP_IGUAL; 
																			} 
    | OP_NO_IGUAL                                                           { 
																				printf("\n REGLA 59: <comparador> --> OP_NO_IGUAL \n");
																				comp_bool_actual = OP_NO_IGUAL; 
																			}
;

// Lectura y escritura
entrada:
    READ ID                                                                 { 
																				printf("\n REGLA 29: <entrada> --> READ ID \n"); 
																				chequearVarEnTabla(yylval.str_val);
																			}
;

salida:
    WRITE CONST_STR                                                         { 
																			  printf("\n REGLA 30: <salida> -->  WRITE CONST_STR  \n"); 
																			  int idx = agregarCteStringATabla(yylval.str_val); 
																			  idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
    | WRITE ID                                                              { 
																			  printf("\n REGLA 31: <salida> -->  WRITE ID  \n"); 
																			  chequearVarEnTabla(yylval.str_val); 
																			  int idx = buscarEnTabla($2);
																			  idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
																			}
;

// Funciones Especiales
// BETWEEN
entre:
    BETWEEN PAR_A ID PYC COR_A expresion PYC expresion COR_C PAR_C    { printf("\n REGLA 11: <entre> --> BETWEEN PAR_A ID COMA COR_A <expresion> PYC <expresion> COR_C PAR_C \n"); }
;

// TAKE
tomar:
    TAKE PAR_A oper PYC CONST_ENT PYC COR_A listapyc COR_C PAR_C            { printf("\n REGLA 12: <tomar> --> TAKE PAR_A <oper> PYC CONST_ENT PYC COR_A <listapyc> COR_C PAR_C \n"); }
    | TAKE PAR_A oper PYC CONST_ENT PYC COR_A COR_C PAR_C                   { printf("\n REGLA 13: <tomar> --> TAKE PAR_A <oper> PYC CONST_ENT PYC COR_A COR_C PAR_C \n"); }

;

listapyc:
    factor                                                                  { printf("\n REGLA 14: <listapyc> --> <factor> \n"); }
| listapyc PYC factor                                                       { printf("\n REGLA 15: <listapyc> --> <listapyc> PYC <factor> \n"); }
;

oper:
OP_SUMA                                                                     { printf("\n REGLA 16: <oper> --> OP_SUMA \n"); } 
| OP_MULT                                                                   { printf("\n REGLA 17: <oper> --> OP_MULT \n"); }
| OP_DIV                                                                    { printf("\n REGLA 18: <oper> --> OP_DIV \n"); }
| OP_RESTA                                                                  { printf("\n REGLA 19: <oper> --> OP_RESTA \n"); }
;
%%
