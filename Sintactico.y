%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "libs/tercetos/tercetos.h"
#include "libs/tabla_simbolos/tabla_simbolos.h"
#include "libs/sentencias_control/sentencias_control.h"
#include "libs/funciones_especiales/funciones_especiales.h"
#include "libs/generacion_assembler/generacion_assembler.h"

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
%}

%start start 
%right OP_ASIG 
%left OP_SUM OP_RES
%left OP_MUL OP_DIV

%token OP_MAYOR OP_MAYOR_IGUAL OP_MENOR OP_MENOR_IGUAL OP_IGUAL OP_NO_IGUAL OP_TIPO
%token TAKE BETWEEN WHILE IF THEN INTEGER FLOAT STRING ELSE DECVAR ENDDEC AND OR NOT
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
																				printf("\n Regla 0: <start> --> <seccion_declaracion> <programa> \n"); 
																				guardar_tabla(); 
																				guardar_tercetos(OPTIMIZAR);
																				genera_assembler();
																			}
;

// Declaraciones de Variables
seccion_declaracion:
    DECVAR bloque_variables ENDDEC                                          { 	printf("\n Regla 1: <seccion_declaracion> --> DECVAR <bloque_variables> ENDDEC \n"); 	}
;    

bloque_variables:
    bloque_variables listavar OP_TIPO tipodato                              { 
																				printf("\n Regla 2: <bloque_variables> --> <bloque_variables> <listavar> OP_TIPO <tipodato> \n"); 
																				agregar_tipos_datos_a_tabla();
																			}
    | listavar OP_TIPO tipodato                                             { 
																				printf("\n Regla 3: <bloque_variables> --> <listavar> OP_TIPO <tipodato> \n"); 
																				agregar_tipos_datos_a_tabla();
																			}
;

listavar:
    ID                                                                      { 
																				printf("\n Regla 4: <listavar> --> ID  [ID: %s] \n", $1); 
																				int idx = agregar_var_declarada_a_tabla(yylval.str_val); 
																				varADeclarar1 = fin_tabla; 
																				cantVarsADeclarar = 1; 
																			}
    | listavar COMA ID                                                      { 
																				printf("\n Regla 5: <listavar> --> <listavar> COMA ID [ID: %s] \n", $3); 
																				int idx = agregar_var_declarada_a_tabla(yylval.str_val); 
																				cantVarsADeclarar++; 
																			}
;

tipodato:
    INTEGER                                                                 { 
																				printf("\n Regla 6: <tipodato> --> INTEGER  \n"); 
																				tipoDatoADeclarar = ENUM_INTEGER; 
																			}
    | FLOAT                                                                 { 
																				printf("\n Regla 7: <tipodato> --> FLOAT \n"); 
																			  	tipoDatoADeclarar = ENUM_FLOAT; 
																			}
    | STRING                                                                { 
																				printf("\n Regla 8: <tipodato> --> STRING \n"); 
																			  	tipoDatoADeclarar = ENUM_STRING; 
																			}
;

// Reglas base
programa:
    sentencia                                                   			{ 
																				printf("\n Regla 9: <programa> --> <sentencia> \n"); 
																				idx_programa = idx_sentencia;
																			}       
    | programa sentencia                                        			{ 
																				printf("\n Regla 10: <programa> --> <programa> <sentencia> \n"); 
																				idx_programa = crear_terceto(PROG, idx_programa, idx_sentencia);			
																			}
;

sentencia:
    asignacion                                                            	{ 
																				printf("\n Regla 11: <sentencia> --> <asignacion> \n"); 
																				idx_sentencia = idx_asignacion; 
																			}    
    | iteracion                                                             {
																				printf("\n Regla 12: <sentencia> --> <iteracion> \n");
																				idx_sentencia = idx_iteracion;
																			}   
    | seleccion                                                           	{
																				printf("\n Regla 13: <sentencia> --> <seleccion> \n");
																				idx_sentencia = idx_seleccion; 
																			}  
    | salida                                                                { 
																				printf("\n Regla 14: <sentencia> --> <salida> \n");
																				idx_sentencia = idx_salida; 
																			}    
    | entrada                                                               { 
			    																printf("\n Regla 15: <sentencia> --> <entrada> \n");
																				idx_sentencia = idx_entrada; 
																			}
;

// General
asignacion:
    ID OP_ASIG expresion_general                                            { 	
																				printf("\n Regla 16: <asignacion> --> ID OP_ASIG <expresion> \n"); 	
																				int idx = buscar_y_validar_en_tabla($1);
																				idx_asignacion = crear_terceto(OP_ASIG, idx, idx_expresion_general);
																			}
;

expresion_general:
	CONST_STR																{
																				printf("\n Regla 17: <expresion_general> --> CTE_STRING \n");
																				int idx = agregar_cte_string_a_tabla(yylval.str_val);
																				idx_expresion_general = crear_terceto(PARTE_VACIA,idx,PARTE_VACIA);
																			}
	| expresion																{
																				printf("\n Regla 18: <expresion_general> --> <expresion>\n");
																				idx_expresion_general = idx_expresion;
																			}
;

expresion:
    expresion OP_SUM termino                                               	{ 
																				printf("\n Regla 19: <expresion> --> <expresion> OP_SUM <termino> \n"); 
																				idx_expresion = crear_terceto(OP_SUM, idx_expresion, idx_termino);
																			}
    | expresion OP_RES termino                                            	{ 
																				printf("\n Regla 20: <expresion> --> <expresion> OP_RES <termino> \n"); 
																				idx_expresion = crear_terceto(OP_RES, idx_expresion, idx_termino);
																			}
    | termino                                                               { 
																				printf("\n Regla 21: <expresion> --> <termino> \n"); 
																				idx_expresion = idx_termino; 
																			}
;

termino:
    termino OP_MUL factor                                                  	{ 
																				printf("\n Regla 22: <termino> --> <termino> OP_MUL <factor> \n");
																				idx_termino = crear_terceto(OP_MUL, idx_termino, idx_factor);
																			}
    | termino OP_DIV factor                                                 { 
																				printf("\n Regla 23: <termino> --> <termino> OP_DIV <factor> \n");
																				idx_termino = crear_terceto(OP_DIV, idx_termino, idx_factor);
																			}
    | factor                                                                { 
																				printf("\n Regla 24: <termino> --> <factor> \n"); 
																				idx_termino = idx_factor;
																			}
;

factor:
    PAR_A expresion PAR_C                                                   { 
																				printf("\n Regla 25: <factor> --> PAR_A <expresion> PAR_C \n"); 
																				idx_factor = idx_expresion;
																			} 
    | CONST_REAL                                                            { 
																				printf("\n Regla 26: <factor> --> CONST_REAL \n");
																				int idx = agregar_cte_real_a_tabla(yylval.real_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
    | ID                                                                    { 
																				printf("\n Regla 27: <factor> --> ID \n"); 
																				int idx = buscar_y_validar_en_tabla($1);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			} 
    | CONST_ENT                                                             { 
																				printf("\n Regla 28: <factor> --> CONST_ENT \n"); 
																				int idx = agregar_cte_int_a_tabla(yylval.int_val);
																				idx_factor = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
																			}
	| take                                           						{
																				printf("\n Regla 29: <factor> --> <take> \n");
																				// validar_tipo_dato(ENUM_FLOAT);
																				idx_factor = idx_take;
																			}
;

iteracion:
	WHILE 												{ 
															idx_iteracion = crear_terceto(WHILE, PARTE_VACIA, PARTE_VACIA); 
															apilar_terceto(); 
														} 
	PAR_A expresion_booleana PAR_C THEN 				{	
															idx_then = crear_terceto(THEN,PARTE_VACIA,PARTE_VACIA); 
															actualizar_terceto_pos_then();
														} 
	programa ENDWHILE
														{
															printf("\n Regla 30: <iteracion> --> WHILE <expresion_booleana> THEN <programa> ENDWHILE\n");
															idx_salto_implicito = crear_terceto(JMP,idx_iteracion,PARTE_VACIA);
															idx_end_while = crear_terceto(ENDWHILE, PARTE_VACIA, PARTE_VACIA);
															actualizar_terceto_pos_end_while();
															desapilar_terceto();
														}
;

inicio_if:
	IF PAR_A											{
															idx_if=crear_terceto(IF, PARTE_VACIA, PARTE_VACIA);
															apilar_terceto();
														};

inicio_then:
	PAR_C THEN											{	
															idx_then=crear_terceto(THEN,PARTE_VACIA,PARTE_VACIA);
	  														actualizar_terceto_pos_then();
														};

seleccion:
    inicio_if expresion_booleana inicio_then
	programa ENDIF 										{
															printf("\n Regla 31: <seleccion> --> IF <expresion_booleana> THEN <programa> ENDIF\n");
															idx_end_if=crear_terceto(ENDIF,PARTE_VACIA,PARTE_VACIA);
															idx_else=idx_end_if;
															actualizar_terceto_pos_else();
															desapilar_terceto();
															idx_seleccion=idx_if;
														}
	| inicio_if expresion_booleana inicio_then	

	programa 											{	idx_bloque_if_true = idx_programa;} 

	ELSE 												{	
															idx_salto_implicito = crear_terceto(JMP, PARTE_VACIA, PARTE_VACIA);
	  														idx_else = crear_terceto(ELSE,PARTE_VACIA,PARTE_VACIA);
															actualizar_terceto_pos_else();
														}
	programa ENDIF 										{
															printf("\n Regla 32:<seleccion> --> IF <expresion_booleana> THEN <programa> ELSE <programa> ENDIF\n"); 
															idx_end_if = crear_terceto(ENDIF,PARTE_VACIA,PARTE_VACIA);
															actualizar_terceto_pos_end_if();
															desapilar_terceto();
															idx_seleccion=idx_if;
														}
														
;

expresion_booleana:
    termino_booleano 									{ 	
															idx_termino_booleano_izq = idx_termino_booleano;	
														} 
	AND 												{ 	idx_condicion_izq = crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);		}
	termino_booleano 									{
															printf("\n Regla 33: <expresion_booleana> --> <termino_booleano> AND <termino_booleano>\n");
															idx_condicion_der =  crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
															idx_expresion_booleana = crear_terceto(AND, idx_termino_booleano_izq, idx_termino_booleano);
														}
	| termino_booleano									{ 	
															idx_termino_booleano_izq = idx_termino_booleano;	} 
	OR 													{ 	has_or = crear_terceto(obtener_salto_condicion(comp_bool_actual), idx_termino_booleano, PARTE_VACIA); 	}
	termino_booleano									{
															printf("\n Regla 34: <expresion_booleana> --> <termino_booleano> OR <termino_booleano>\n");
															idx_condicion_der =  crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
															idx_expresion_booleana = crear_terceto(OR, idx_termino_booleano_izq, idx_termino_booleano);
														}
    | termino_booleano                                  {
															printf("\n Regla 35: <expresion_booleana> --> <termino_booleano>\n");
															idx_expresion_booleana = idx_termino_booleano;
															idx_condicion_izq = crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
														}
    | NOT PAR_A termino_booleano PAR_C                  {
															printf("\n Regla 36: <expresion_booleana> --> NOT <termino_booleano>\n");
															idx_expresion_booleana = idx_termino_booleano;
															idx_condicion_izq = crear_terceto(obtener_salto_condicion(comp_bool_actual), idx_termino_booleano, PARTE_VACIA);
														}
	| between                       			        {
															printf("\n Regla 37: <expresion_booleana> --> <between>\n");
															idx_expresion_booleana = idx_between;
														}
;

termino_booleano:
	PAR_A expresion_booleana PAR_C 						{
															printf("\n Regla 38: <expresion_booleana> --> PAR_A <termino_booleano> PAR_C\n");
														}
    | expresion 										{ 	idx_expresion_izq = idx_expresion;	}
	comparador expresion		 						{
															printf("\n Regla 39: <termino_booleano> --> <expresion> <comparador> <expresion>\n");
															reset_tipo_dato();
															idx_termino_booleano = crear_terceto(CMP, idx_expresion_izq, idx_expresion);
														}
;

comparador:
	OP_MAYOR                                           	{ 
															printf("\n Regla 40: <comparador> --> OP_MAYOR \n");
															comp_bool_actual = OP_MAYOR; 
														} 
	| OP_MENOR                                          { 
															printf("\n Regla 41: <comparador> --> OP_MENOR \n");
															comp_bool_actual = OP_MENOR; 
														} 
	| OP_MENOR_IGUAL                                    { 
															printf("\n Regla 42: <comparador> --> OP_MENOR_IGUAL \n");
															comp_bool_actual = OP_MENOR_IGUAL; 
														} 
	| OP_MAYOR_IGUAL                                    { 
															printf("\n Regla 43: <comparador> --> OP_MAYOR_IGUAL \n"); 
															comp_bool_actual = OP_MAYOR_IGUAL; 
														} 
	| OP_IGUAL                                          { 
															printf("\n Regla 44: <comparador> --> OP_IGUAL \n"); 
															comp_bool_actual = OP_IGUAL; 
														} 
	| OP_NO_IGUAL                                       { 
															printf("\n Regla 45: <comparador> --> OP_NO_IGUAL \n");
															comp_bool_actual = OP_NO_IGUAL; 
														}
;

// Lectura y escritura
entrada:
    READ ID                                             { 
															printf("\n Regla 46: <entrada> --> READ ID \n"); 
															validar_var_en_tabla(yylval.str_val);
														}
;

salida:
    WRITE CONST_STR                                     { 
															printf("\n Regla 46: <salida> -->  WRITE CONST_STR  \n"); 
															int idx = agregar_cte_string_a_tabla(yylval.str_val); 
															idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
														}
	| WRITE ID                                          { 
															printf("\n Regla 47: <salida> -->  WRITE ID  \n"); 
															validar_var_en_tabla(yylval.str_val); 
															int idx = buscar_y_validar_en_tabla($2);
															idx_salida = crear_terceto(WRITE, idx, PARTE_VACIA); 
														}
;

funcion_expresion_cota_inferior:
	expresion											{
															printf("\n Regla 48: <funcion_expresion_cota_inferior> -->  <expresion>  \n"); 
															idx_cota_inferior = idx_expresion;
															comp_bool_actual = OP_MAYOR_IGUAL; // Salta por BLT
															int idx_aux= crear_terceto(CMP,idx_valor_a_comparar,idx_cota_inferior);
															idx_salto_a_fin_between_cota_inf=crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_aux, PARTE_VACIA);
														}
;

funcion_expresion_cota_superior:
	expresion											{
															printf("\n Regla 49: <funcion_expresion_cota_superior> -->  <expresion>  \n");
															idx_cota_superior = idx_expresion;	
															int idx_aux= crear_terceto(CMP,idx_valor_a_comparar,idx_cota_superior);
															comp_bool_actual = OP_MENOR_IGUAL;  // Salta por BGT
															idx_salto_a_fin_between_cota_sup=crear_terceto(obtener_salto_condicion_negada(comp_bool_actual), idx_aux, PARTE_VACIA);
														}
;

// Funciones Especiales
// FUNCION BETWEEN
between:
    BETWEEN PAR_A ID										{ 
																int tipo_dato = validar_var_en_tabla($3);
																tipo_dato_actual = validar_tipo_dato(tipo_dato, tipo_dato_actual);
																int idx = buscar_y_validar_en_tabla($3);
																idx_valor_a_comparar = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA);
															} 
	COMA COR_A funcion_expresion_cota_inferior PYC 
	
	funcion_expresion_cota_superior COR_C PAR_C    			{ 
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
;

// FUNCION TAKE
take:
    TAKE PAR_A operador_take PYC numeros_a_tomar PYC 
	COR_A lista_take_ctes COR_C PAR_C 											{ 
																					printf("\n Regla 51: <take> --> TAKE PAR_A <operador_take> PYC numeros_a_tomar PYC COR_A <lista_take_ctes> COR_C PAR_C \n"); 
																					idx_take = idx_resultado_take;
																					validar_cantidad_take(cantidad_a_tomar);
																				}
    |  TAKE PAR_A operador_take PYC numeros_a_tomar PYC 
	COR_A COR_C PAR_C			  	 											{ 
																					printf("\n Regla 52: <take> --> TAKE PAR_A <operador_take> PYC numeros_a_tomar PYC COR_A COR_C PAR_C \n"); 
																					int valor_cero = agregar_cte_int_a_tabla(0);\
																					int idx_cero = crear_terceto(PARTE_VACIA,valor_cero,PARTE_VACIA);
																					idx_take = crear_terceto(OP_ASIG, idx_var_take, idx_cero);
																				}
;

operador_take:
	OP_SUM                                                                     	{ 
																					printf("\n Regla 53: <operador_take> --> OP_SUM \n"); 
																					operador_take = OP_SUM;
																				} 
	| OP_MUL                                                                   	{ 
																					printf("\n Regla 54: <operador_take> --> OP_MUL \n"); 
																					operador_take = OP_MUL;
																				}
	| OP_DIV                                                                   	{ 
																					printf("\n Regla 55: <operador_take> --> OP_DIV \n"); 
																					operador_take = OP_DIV;
																				}
	| OP_RES                                                                   	{ 
																					printf("\n Regla 56: <operador_take> --> OP_RES \n"); 
																					operador_take = OP_RES;
																				}
;

numeros_a_tomar:
	CONST_ENT																	{
																					printf("\n Regla 57: <numeros_a_tomar> --> CONST_ENT \n"); 
																					// reset_tipo_dato(); // Revisar
																					cantidad_a_tomar = $1;
																					agregar_cte_int_a_tabla(cantidad_a_tomar);

																					idx_var_take = buscar_o_insertar_var_en_tabla("@take_accu",ENUM_INTEGER);
																					idx_var_take_aux = buscar_o_insertar_var_en_tabla("@take_accu_aux",ENUM_INTEGER);
																				}
;

lista_take_ctes:
	CONST_ENT                                                                	{ 
																					printf("\n Regla 58: <lista_take_ctes> --> CONST_ENT \n");
																					// int idx = agregar_cte_int_a_tabla(yylval.int_val);
																					int idx = agregar_cte_int_a_tabla($1);
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
	| lista_take_ctes PYC CONST_ENT                                          	{
																					printf("\n Regla 59: <lista_take_ctes> --> <lista_take_ctes> PYC <factor> \n");
																					int idx = agregar_cte_int_a_tabla($3);
																					if(cantidad_a_tomar > 0) {
																						int idx_siguiente_constante = crear_terceto(PARTE_VACIA, idx, PARTE_VACIA); // Crea terceto para sig
																						crear_terceto(OP_ASIG, idx_var_take_aux, idx_siguiente_constante); // Crea terceto de igualacion entre var accu aux y var sig
																						int idx_operacion_terceto = crear_terceto(operador_take, idx_var_take, idx_var_take_aux); // Crea un terceto operando los acumuladores con el operador take
																						idx_resultado_take = crear_terceto(OP_ASIG, idx_var_take, idx_operacion_terceto); // Vuelve a asignar al accu
																						cantidad_a_tomar--;
																					}
																				}
;
%%
