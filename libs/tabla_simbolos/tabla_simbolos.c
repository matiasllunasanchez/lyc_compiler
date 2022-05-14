#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

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
    int i;
	for( i = 0; i < cantVarsADeclarar; i++){
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
    int i;
	for(i = 0; i <= fin_tabla; i++){
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