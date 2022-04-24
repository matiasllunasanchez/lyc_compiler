%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int yystopparser=0;
FILE  *yyin;
int yyparse();
int yylex();
int yyparse();
int yyerror();
int contWhile=0;
char * yytext;

%}

%start start 
%right OP_ASIG 
%left OP_SUMA OP_RESTA
%left OP_MULT OP_DIV

%token OP_MAYOR OP_MAYIGU OP_MENOR OP_MENIGU OP_IGUAL OP_NO_IGUAL OP_TIPO
%token TAKE BETWEEN WHILE IF INTEGER FLOAT STRING ELSE THEN DECVAR ENDDEC AND OR NOT
%token WRITE READ COMA ENDIF ENDWHILE PAR_A PAR_C COR_A COR_C PYC

%token ID CONST_ENT CONST_REAL CONST_STR

%union {
    char *str_val;
}


%%

start: programa                                                             { printf("\n REGLA 0: <start> --> <programa> \n"); }
;
    
programa:
    sentencia                                                               { printf("\n REGLA 1: <programa> --> <sentencia> \n"); }       
    | programa sentencia                                                    { printf("\n REGLA 2: <programa> --> <programa> <sentencia> \n"); }
;              
    
sentencia:
    | declaracion                                                           { printf("\n REGLA 3: <sentencia> --> <declaracion> \n"); }  
    | asignacion                                                            { printf("\n REGLA 4: <sentencia> --> <asignacion> \n"); }   
    | ciclo                                                                 { printf("\n REGLA 5: <sentencia> --> <ciclo> \n"); }   
    | condicional                                                           { printf("\n REGLA 6: <sentencia> --> <condicional> \n"); }   
    | salida                                                                { printf("\n REGLA 7: <sentencia> --> <salida> \n"); }   
    | entrada                                                               { printf("\n REGLA 8: <sentencia> --> <entrada> \n"); } 
    | entre                                                                 { printf("\n REGLA 9: <sentencia> --> <entre> \n"); }  //BETWEEN
    | tomar                                                                 { printf("\n REGLA 10: <sentencia> --> <tomar> \n"); }  // TAKE
;

//BETWEEN
entre:
    BETWEEN PAR_A ID COMA COR_A expresion PYC expresion COR_C PAR_C         { printf("\n REGLA 11: <entre> --> BETWEEN PAR_A ID COMA COR_A <expresion> PYC <expresion> COR_C PAR_C \n"); }
;

//TAKE
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

//FIN TAKE

declaracion:
    DECVAR bloque_variables ENDDEC                                          { printf("\n REGLA 20: <declaracion> --> DECVAR <bloque_variables> ENDDEC \n"); }
;    

listavar:
    ID                                                                      { printf("\n REGLA 21: <listavar> --> ID \n"); }
    | listavar COMA ID                                                      { printf("\n REGLA 22: <listavar> --> <listavar> COMA ID \n"); }
;

tipodato:
    INTEGER                                                                 { printf("\n REGLA 23: <tipodato> --> INTEGER  \n");}
    | FLOAT                                                                 { printf("\n REGLA 24: <tipodato> --> FLOAT \n");}
    | STRING                                                                { printf("\n REGLA 25: <tipodato> --> STRING \n");}
;

condicional:
    IF PAR_A condicion PAR_C programa ELSE programa ENDIF                   { printf("\n REGLA 26: <condicional> --> IF PAR_A <condicion> PAR_C <programa> ELSE <programa> ENDIF\n"); }
    | IF PAR_A condicion PAR_C programa ENDIF                               { printf("\n REGLA 27: <condicional> --> IF PAR_A <condicion> PAR_C <programa> ENDIF \n"); }
;

ciclo:
    WHILE PAR_A condicion PAR_C programa ENDWHILE                           { printf("\n REGLA 28: <ciclo> --> WHILE PAR_A <condicion> PAR_C <programa> ENDWHILE\n"); }
;

entrada:
    READ ID                                                                 { printf("\n REGLA 29: <entrada> --> READ <factor> \n"); }
;

salida:
    WRITE CONST_STR                                                         { printf("\n REGLA 30: <salida> -->  WRITE CONST_STR  \n"); }
    | WRITE ID                                                              { printf("\n REGLA 31: <salida> -->  WRITE ID  \n"); }
;

asignacion:
    ID OP_ASIG expresion                                                    { printf("\n REGLA 32: <asignacion> --> ID OP_ASIG <expresion> \n"); }
    | ID OP_ASIG CONST_STR                                                  { printf("\n REGLA 33: <asignacion> --> ID OP_ASIG CONST_STR \n"); }
;

expresion:
    expresion OP_SUMA termino                                               { printf("\n REGLA 34: <expresion> --> <expresion> OP_SUMA <termino> \n"); }
    | expresion OP_RESTA termino                                            { printf("\n REGLA 35: <expresion> --> <expresion> OP_RESTA <termino> \n"); }
    | termino                                                               { printf("\n REGLA 36: <expresion> --> <termino> \n"); }
;

termino:
    termino OP_MULT factor                                                  { printf("\n REGLA 37: <termino> --> <termino> OP_MULT <factor> \n");}
    | termino OP_DIV factor                                                 { printf("\n REGLA 38: <termino> --> <termino> OP_DIV <factor> \n");}
    | factor                                                                { printf("\n REGLA 39: <termino> --> <factor> \n"); }
;

factor:
    PAR_A expresion PAR_C                                                   { printf("\n REGLA 40: <factor> --> PAR_A <expresion> PAR_C \n"); } 
    | CONST_REAL                                                            { printf("\n REGLA 41: <factor> --> CONST_REAL \n"); }
    | ID                                                                    { printf("\n REGLA 42: <factor> --> ID \n"); } 
    | CONST_ENT                                                             { printf("\n REGLA 43: <factor> --> CONST_ENT \n"); }
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
    OP_MAYOR                                                                { printf("\n REGLA 54: <comparador> --> OP_MAYOR \n"); } 
    | OP_MENOR                                                              { printf("\n REGLA 55: <comparador> --> OP_MENOR \n"); } 
    | OP_MENIGU                                                             { printf("\n REGLA 56: <comparador> --> OP_MENIGU \n"); } 
    | OP_MAYIGU                                                             { printf("\n REGLA 57: <comparador> --> OP_MAYIGU \n"); } 
    | OP_IGUAL                                                              { printf("\n REGLA 58: <comparador> --> OP_IGUAL \n"); } 
    | OP_NO_IGUAL                                                           { printf("\n REGLA 59: <comparador> --> OP_NO_IGUAL \n"); }
;

bloque_variables:
    bloque_variables listavar OP_TIPO tipodato                              { printf("\n REGLA 60: <bloque_variables> --> <bloque_variables> listavar OP_TIPO tipodato \n"); }
    | listavar OP_TIPO tipodato                                             { printf("\n REGLA 61: <bloque_variables> --> listavar OP_TIPO tipodato \n"); }
;

%%