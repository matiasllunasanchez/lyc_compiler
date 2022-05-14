%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

#define Integer 1
#define Real 2
#define String 3
#define CteInt 4
#define CteReal 5
#define CteString 6

#define TAM_TABLA 500
#define TAM_NOMBRE 30

/* Funciones necesarias */
int yyerror(char* mensaje);
void agregarVarATabla(char* nombre);
void agregarTiposDatosATabla(void);
void agregarCteStringATabla(char* nombre);
void agregarCteIntATabla(int valor);
void agregarCteRealATabla(float valor);
void chequearVarEnTabla(char* nombre);
int buscarEnTabla(char * name);
void escribirNombreEnTabla(char* nombre, int pos);
void guardarTabla(void);


typedef struct {
    char nombre[TAM_NOMBRE];
    int tipo_dato;
    char valor_s[TAM_NOMBRE];
    float valor_f;
    int valor_i;
    int longitud;
} simbolo;

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

start: programa                                                             { printf("\n REGLA 0: <start> --> <programa> \n"); guardarTabla(); }
;
    
programa:
    sentencia                                                               { printf("\n REGLA 1: <programa> --> <sentencia> \n"); }       
    | programa sentencia                                                    { printf("\n REGLA 2: <programa> --> <programa> <sentencia> \n"); }
;              
    
sentencia:
    | declaracion                                                           { printf("\n REGLA 3: <sentencia> --> <declaracion> \n"); }  
    | asignacion                                                            { printf("\n REGLA 4: <sentencia> --> <asignacion> \n"); }   
    | iteracion                                                                 { printf("\n REGLA 5: <sentencia> --> <iteracion> \n"); }   
    | seleccion                                                           { printf("\n REGLA 6: <sentencia> --> <seleccion> \n"); }   
    | salida                                                                { printf("\n REGLA 7: <sentencia> --> <salida> \n"); }   
    | entrada                                                               { printf("\n REGLA 8: <sentencia> --> <entrada> \n"); } 
    | entre                                                                 { printf("\n REGLA 9: <sentencia> --> <entre> \n"); }  //BETWEEN
    | tomar                                                                 { printf("\n REGLA 10: <sentencia> --> <tomar> \n"); }  // TAKE
;

// Declaraciones de variables
declaracion:
    DECVAR bloque_variables ENDDEC                                          { printf("\n REGLA 20: <declaracion> --> DECVAR <bloque_variables> ENDDEC \n"); }
;    

listavar:
    ID                                                                      { printf("\n REGLA 21: <listavar> --> ID \n"); agregarVarATabla(yylval.str_val); varADeclarar1 = fin_tabla; cantVarsADeclarar = 1; }
    | listavar COMA ID                                                      { printf("\n REGLA 22: <listavar> --> <listavar> COMA ID \n"); agregarVarATabla(yylval.str_val); cantVarsADeclarar++; }
;

tipodato:
    INTEGER                                                                 { printf("\n REGLA 23: <tipodato> --> INTEGER  \n"); tipoDatoADeclarar = INTEGER;}
    | FLOAT                                                                 { printf("\n REGLA 24: <tipodato> --> FLOAT \n"); tipoDatoADeclarar = FLOAT;}
    | STRING                                                                { printf("\n REGLA 25: <tipodato> --> STRING \n"); tipoDatoADeclarar = STRING;}
;

bloque_variables:
    bloque_variables listavar OP_TIPO tipodato                              { printf("\n REGLA 60: <bloque_variables> --> <bloque_variables> listavar OP_TIPO tipodato \n");agregarTiposDatosATabla(); }
    | listavar OP_TIPO tipodato                                             { printf("\n REGLA 61: <bloque_variables> --> listavar OP_TIPO tipodato \n");agregarTiposDatosATabla(); }
;

// General
seleccion:
    IF condicion programa ELSE programa ENDIF                   { printf("\n REGLA 26: <seleccion> --> IF <condicion> <programa> ELSE <programa> ENDIF\n"); }
    | IF condicion programa ENDIF                               { printf("\n REGLA 27: <seleccion> --> IF <condicion> <programa> ENDIF \n"); }
;

iteracion:
    WHILE condicion programa ENDWHILE                           { printf("\n REGLA 28: <iteracion> --> WHILE <condicion> <programa> ENDWHILE\n"); }
;

asignacion:
    ID OP_ASIG expresion                                                    { printf("\n REGLA 32: <asignacion> --> ID OP_ASIG <expresion> \n"); }
;

condicion:
    comparacion                                                                     { printf("\n REGLA 44: <condicion> --> <comparacion> \n"); }
    | condicion AND comparacion                                                       { printf("\n REGLA 45: <condicion> --> <condicion> AND <comparacion> \n"); }
    | condicion OR comparacion                                                        { printf("\n REGLA 46: <condicion> --> <condicion> OR <comparacion> \n"); }
;

comparacion:
   expresion comparador expresion                                              { printf("\n REGLA 51: <comparacion> --> <expresion> <comparador> <expresion> \n"); }
;

comparador:
    OP_MAYOR                                                                { printf("\n REGLA 54: <comparador> --> OP_MAYOR \n"); } 
    | OP_MENOR                                                              { printf("\n REGLA 55: <comparador> --> OP_MENOR \n"); } 
    | OP_MENIGU                                                             { printf("\n REGLA 56: <comparador> --> OP_MENIGU \n"); } 
    | OP_MAYIGU                                                             { printf("\n REGLA 57: <comparador> --> OP_MAYIGU \n"); } 
    | OP_IGUAL                                                              { printf("\n REGLA 58: <comparador> --> OP_IGUAL \n"); } 
    | OP_NO_IGUAL                                                           { printf("\n REGLA 59: <comparador> --> OP_NO_IGUAL \n"); }
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
    | CONST_REAL                                                            { printf("\n REGLA 41: <factor> --> CONST_REAL \n"); agregarCteRealATabla(yylval.real_val);}
    | ID                                                                    { printf("\n REGLA 42: <factor> --> ID \n"); } 
    | CONST_ENT                                                             { printf("\n REGLA 43: <factor> --> CONST_ENT \n"); agregarCteIntATabla(yylval.int_val);}
;

// Lectura y escritura
entrada:
    READ ID                                                                 { printf("\n REGLA 29: <entrada> --> READ ID \n"); chequearVarEnTabla(yylval.str_val);}
;

salida:
    WRITE CONST_STR                                                         { printf("\n REGLA 30: <salida> -->  WRITE CONST_STR  \n");agregarCteStringATabla(yylval.str_val); }
    | WRITE ID                                                              { printf("\n REGLA 31: <salida> -->  WRITE ID  \n"); chequearVarEnTabla(yylval.str_val); }
;


//  Funcion especial BETWEEN
entre:
    BETWEEN PAR_A ID COMA COR_A expresion PYC expresion COR_C PAR_C         { printf("\n REGLA 11: <entre> --> BETWEEN PAR_A ID COMA COR_A <expresion> PYC <expresion> COR_C PAR_C \n"); }
;

// Funcion especial TAKE
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







int buscarEnTabla(char * name){
   int i=0;
   while(i<=fin_tabla){
	   if(strcmp(tabla_simbolo[i].nombre,name) == 0){
		   return i;
	   }
	   i++;
   }
   return -1;
}



void escribirNombreEnTabla(char* nombre, int pos){
	strcpy(tabla_simbolo[pos].nombre, nombre);
}

 void agregarVarATabla(char* nombre){
	 if(fin_tabla >= TAM_TABLA - 1){
		 printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		 system("Pause");
		 exit(2);
	 }
	 if(buscarEnTabla(nombre) == -1){     
		 fin_tabla++;
		 escribirNombreEnTabla(nombre, fin_tabla);
	 }
	 else{
         yyerror("Encontre dos declaraciones de variables con el mismo nombre. Decidite."); 
     } 

 }


void agregarTiposDatosATabla(){
	for(int i = 0; i < cantVarsADeclarar; i++){
		tabla_simbolo[varADeclarar1 + i].tipo_dato = tipoDatoADeclarar;
	}
}

void guardarTabla(){
	if(fin_tabla == -1)
		yyerror("No encontre la tabla de simbolos");
	FILE* arch = fopen("ts.txt", "w+");
	if(!arch){
		printf("No pude crear el archivo ts.txt\n");
		return;
	}

	for(int i = 0; i <= fin_tabla; i++){
		fprintf(arch, "%s\t", &(tabla_simbolo[i].nombre) );
		switch (tabla_simbolo[i].tipo_dato){
		case Real:
			fprintf(arch, "REAL");
			break;
		case Integer:
			fprintf(arch, "INTEGER");
			break;
		case String:
			fprintf(arch, "STRING");
			break;
		case CteReal:
			fprintf(arch, "CONST_REAL\t%f", tabla_simbolo[i].valor_f);
			break;
		case CteInt:
			fprintf(arch, "CONST_ENT\t%d", tabla_simbolo[i].valor_i);
			break;
		case CteString:
			fprintf(arch, "CONST_STR\t%s\t%d", &(tabla_simbolo[i].valor_s), tabla_simbolo[i].longitud);
			break;
		}
		fprintf(arch, "\n");
	}
	fclose(arch);
}


void agregarCteStringATabla(char* nombre){
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}
	if(buscarEnTabla(nombre) == -1){
		fin_tabla++;
		escribirNombreEnTabla(nombre, fin_tabla);
		tabla_simbolo[fin_tabla].tipo_dato = CteString;		
		strcpy(tabla_simbolo[fin_tabla].valor_s, nombre+1); 		
		tabla_simbolo[fin_tabla].longitud = strlen(nombre) - 1;
	}
}

void agregarCteRealATabla(float valor){
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}
	char nombre[12];
	sprintf(nombre, "_%f", valor);
	if(buscarEnTabla(nombre) == -1){
		fin_tabla++;
		escribirNombreEnTabla(nombre, fin_tabla);
		tabla_simbolo[fin_tabla].tipo_dato = CteReal;
		tabla_simbolo[fin_tabla].valor_f = valor;
	}
}

void agregarCteIntATabla(int valor){
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}
	char nombre[30];
	sprintf(nombre, "_%d", valor);
	if(buscarEnTabla(nombre) == -1){
		fin_tabla++;
		escribirNombreEnTabla(nombre, fin_tabla);
    	tabla_simbolo[fin_tabla].tipo_dato = CteInt;
		tabla_simbolo[fin_tabla].valor_i = valor;
	}
}

void chequearVarEnTabla(char* nombre){
	if( buscarEnTabla(nombre) == -1){
		char msg[100];
		sprintf(msg,"%s? ERR-Variable declarada fuera del bloque de declaracion", nombre);
		yyerror(msg);
	}
}
