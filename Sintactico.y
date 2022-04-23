%{
#include "y.tab.h"

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
%token WHILE IF INTEGER FLOAT STRING ELSE THEN DECVAR ENDDEC AND OR NOT
%token WRITE READ COMA ENDIF ENDWHILE PAR_A PAR_C COR_A COR_C PYC

%token ID CONST_ENT CONST_REAL CONST_STR

%union {
    char *str_val;
}


%%

start: programa                                         { printf("\n REGLA 0: <start> --> <programa> \n"); }
    
programa:
    sentencia                                           { printf("\n REGLA 1: <programa> --> <sentencia> \n"); }       
    | programa sentencia                                { printf("\n REGLA 2: <programa> --> <programa> <sentencia> \n"); };              
    
sentencia:
     declaracion                                        { printf("\n REGLA 3: <sentencia> --> <declaracion> \n"); }  
    | asignacion                                        { printf("\n REGLA 4: <sentencia> --> <asignacion> \n"); }   
    | ciclo                                             { printf("\n REGLA 5: <sentencia> --> <ciclo> \n"); }   
    | condicional                                       { printf("\n REGLA 6: <sentencia> --> <condicional> \n"); }   
    | salida                                            { printf("\n REGLA 7: <sentencia> --> <salida> \n"); }   
    | entrada                                           { printf("\n REGLA 8: <sentencia> --> <entrada> \n"); } 
    | entre                                             { printf("\n REGLA 81: <sentencia> --> <entre> \n"); }  //BETWEEN
    | llevar                                            { printf("\n REGLA 82: <sentencia> --> <llevar> \n"); }  // TAKE

entre:
    BETWEEN PAR_A ID COMA COR_A expresion PYC expresion COR_C PAR_C     { printf("\n REGLA 82: <sentencia> --> <llevar> \n"); }

llevar:
    TAKE PAR_A OPER PYC CTE PYC COR_A lista COR_C PAR_C                 { printf("\n REGLA 82: <sentencia> --> <llevar> \n"); }

declaracion:
    DECVAR dec ENDDEC                                   { printf("\n REGLA 10: <declaracion> --> DECVAR <dec> ENDDEC \n"); };    

listavar:
    ID                                                  { printf("\n REGLA 11: <listavar> --> ID \n"); }
    | listavar COMA ID                                  { printf("\n REGLA 12: <listavar> --> <listavar> COMA ID \n"); };

tipodato:
    INTEGER                                             { printf("\n REGLA 13: <tipodato> --> INTEGER  \n");}
    | FLOAT                                             { printf("\n REGLA 14: <tipodato> --> FLOAT \n");}
    | STRING                                            { printf("\n REGLA 15: <tipodato> --> STRING \n");};

condicional:
    IF condicion programa ELSE programa ENDIF           { printf("\n REGLA 16: <condicional> --> IF <condicion> <programa> ELSE <programa> ENDIF\n"); }
    | IF condicion programa ENDIF                       { printf("\n REGLA 17: <condicional> --> IF <condicion> <programa> ENDIF \n"); };

ciclo:
    WHILE PAR_A condicion PAR_C programa ENDWHILE       { printf("\n REGLA 18: <ciclo> --> WHILE ID <sentencia> ENDWHILE\n"); };

entrada:
    READ ID                                             { printf("\n REGLA 19: <entrada> --> READ <factor> \n"); };

salida:
    WRITE CONST_STR                                     { printf("\n REGLA 20: <salida> -->  WRITE CONST_STR  \n"); };

asignacion:
    ID OP_ASIG expresion                                { printf("\n REGLA 21: <asignacion> --> ID OP_ASIG <expresion> \n"); };

condicion:
    PAR_A comparacion PAR_C                             { printf("\n REGLA 22: <condicion> --> PAR_A <comparacion> PAR_C \n"); }
    | PAR_A condicion AND comparacion PAR_C             { printf("\n REGLA 23: <condicion> --> PAR_A <condicion> AND <comparacion> PAR_C \n"); }
    | PAR_A condicion OR comparacion PAR_C              { printf("\n REGLA 24: <condicion> --> PAR_A <condicion> OR <comparacion> PAR_C \n"); }
    | PAR_A NOT condicion PAR_C AND comparacion         { printf("\n REGLA 25: <condicion> --> PAR_A NOT <condicion> PAR_C <comparacion> \n"); }
    | PAR_A NOT condicion PAR_C OR comparacion          { printf("\n REGLA 26: <condicion> --> PAR_A NOT <condicion> PAR_C <comparacion> \n"); };

comparacion:
    expresion comparador expresion                      { printf("\n REGLA 27: <comparacion> --> <expresion> <comparador> <expresion> \n"); };

expresion:
    expresion OP_SUMA termino                           { printf("\n REGLA 28: <expresion> --> <expresion> OP_SUMA <termino> \n"); }
    | expresion OP_RESTA termino                        { printf("\n REGLA 29: <expresion> --> <expresion> OP_RESTA <termino> \n"); }
    | termino                                           { printf("\n REGLA 30: <expresion> --> <termino> \n"); }

termino:
    termino OP_MULT factor                              { printf("\n REGLA 32: <termino> --> <termino> OP_MULT <factor> \n");}
    | termino OP_DIV factor                             { printf("\n REGLA 33: <termino> --> <termino> OP_DIV <factor> \n");}
    | factor                                            { printf("\n REGLA 34: <termino> --> <factor> \n"); };

lista:
    factor                                              { printf("\n REGLA 35: <lista> --> <factor> \n"); }
    | lista COMA factor                                 { printf("\n REGLA 36: <lista> --> <lista> COMA <factor> \n"); };

factor:
    PAR_A expresion PAR_C                               { printf("\n REGLA 37: <factor> --> PAR_A <expresion> PAR_C \n"); } 
    | CONST_REAL                                        { printf("\n REGLA 38: <factor> --> CONST_REAL \n"); }
    | ID                                                { printf("\n REGLA 39: <factor> --> ID \n"); } 
    | CONST_ENT                                         { printf("\n REGLA 40: <factor> --> CONST_ENT \n"); };

comparador:
    OP_MAYOR                                            { printf("\n REGLA 41: <comparador> --> OP_MAYOR \n"); } 
    | OP_MENOR                                          { printf("\n REGLA 42: <comparador> --> OP_MENOR \n"); } 
    | OP_MENIGU                                         { printf("\n REGLA 43: <comparador> --> OP_MENIGU \n"); } 
    | OP_MAYIGU                                         { printf("\n REGLA 44: <comparador> --> OP_MAYIGU \n"); } 
    | OP_IGUAL                                          { printf("\n REGLA 45: <comparador> --> OP_IGUAL \n"); } 
    | OP_NO_IGUAL                                       { printf("\n REGLA 46: <comparador> --> OP_NO_IGUAL \n"); };

dec:
    dec listavar OP_TIPO tipodato                       { printf("\n REGLA 47: <dec> --> <dec> listavar OP_TIPO COR_A tipodato \n"); } 
    | listavar OP_TIPO tipodato                         { printf("\n REGLA 48: <dec> --> <dec> listavar OP_TIPO COR_A tipodato \n"); };

%%