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

int agregarVarATabla(char* nombre){
	 if(fin_tabla >= TAM_TABLA - 1){
		 printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		 system("Pause");
		 exit(2);
	 }

	 if(buscarEnTabla(nombre) == -1){     
		 int idx = ++fin_tabla;
		 escribirNombreEnTabla(nombre, fin_tabla);
		 return idx;
	 }
	 else{
         printf("ERR- Se encontraron dos declaraciones identicas."); 
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
		printf("ERR- No se encontró la tabla de simbolos");
	FILE* arch = fopen("ts.txt", "w+");
	if(!arch){
		printf("ERR- No se ha podido crear el archivo ts.txt\n");
		return;
	}
    int i;
    fprintf(arch, "%-30s%-40s%-30s%-30s\n", "NOMBRE", "TIPO", "VALOR", "LONGITUD");
	for(i = 0; i <= fin_tabla; i++) {
		fprintf(arch, "%-30s", &(tabla_simbolo[i].nombre) );
		switch (tabla_simbolo[i].tipo_dato){
			case ENUM_FLOAT:
				fprintf(arch,"%-40s", "FLOAT");
				break;
			case ENUM_INTEGER:
				fprintf(arch,"%-40s", "INTEGER");
				break;
			case ENUM_STRING:
				fprintf(arch,"%-40s", "STRING");
				break;
			case ENUM_CTE_FLOAT:
				fprintf(arch,"%-40s%-30f", "CONST_REAL", tabla_simbolo[i].valor_f);
				break;
			case ENUM_CTE_INTEGER:
				fprintf(arch,"%-40s%-30d", "CONST_ENT", tabla_simbolo[i].valor_i);
				break;
			case ENUM_CTE_STRING:
				fprintf(arch,"%-40s%-30s%-30d", "CONST_STR", &(tabla_simbolo[i].valor_s), tabla_simbolo[i].longitud);
				break;
		}

		fprintf(arch, "\n");
	}
	fclose(arch);
}

int agregarCteStringATabla(char* nombre){
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}
	int idx = buscarEnTabla(nombre);
	if( idx == -1){
		idx = ++fin_tabla;
		escribirNombreEnTabla(nombre, fin_tabla);
		tabla_simbolo[fin_tabla].tipo_dato = ENUM_CTE_STRING;		
		strcpy(tabla_simbolo[fin_tabla].valor_s, nombre+1); 		
		tabla_simbolo[fin_tabla].longitud = strlen(nombre) - 1;
	}

	return idx;
}

int agregarCteRealATabla(float valor){
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}
	
	char nombre[15];
	sprintf(nombre, "_%f", valor);
	int idx = buscarEnTabla(nombre);

	if(idx == -1) {
		idx = ++fin_tabla;
		escribirNombreEnTabla(nombre, fin_tabla);
		tabla_simbolo[fin_tabla].tipo_dato = ENUM_CTE_FLOAT;
		tabla_simbolo[fin_tabla].valor_f = valor;
	}
	return idx;
}

int agregarCteIntATabla(int valor){
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}

	char nombre[30];
	sprintf(nombre, "_%d", valor);

	int idx = buscarEnTabla(nombre);
	if(idx == -1){
		idx = ++fin_tabla;
		escribirNombreEnTabla(nombre, fin_tabla);
    	tabla_simbolo[fin_tabla].tipo_dato = ENUM_CTE_INTEGER;
		tabla_simbolo[fin_tabla].valor_i = valor;
	}
	return idx;
}

void chequearVarEnTabla(char* nombre){
	if( buscarEnTabla(nombre) == -1){
		char msg[100];
		sprintf(msg,"%s? ERR-Variable declarada fuera del bloque de declaracion", nombre);
		printf(msg);
	}
}