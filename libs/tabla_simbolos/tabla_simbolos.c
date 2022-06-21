#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"
int contador_cadenas=1;

int buscar_en_tabla(char * name) {
	int i=0;
	while(i<=fin_tabla){
		if(strcmp(tabla_simbolo[i].nombre,name) == 0){
			return i;
		}
		i++;
	}
	return -1;
}

int buscar_y_validar_en_tabla(char *name){
	int i=0;
	while(i<=fin_tabla){
		if(strcmp(tabla_simbolo[i].nombre,name) == 0){
			return i;
		}
		i++;
	}
	printf("ERR- No se encontró declarada la variable'%s'\n",name); 
	system("Pause");
	exit(2);
}

void escribir_nombre_en_tabla(char* nombre, int pos) {
	strcpy(tabla_simbolo[pos].nombre, nombre);
}

int agregar_var_declarada_a_tabla(char* nombre) {
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}

	if(buscar_en_tabla(nombre) == -1){     
		int idx = ++fin_tabla;
		escribir_nombre_en_tabla(nombre, fin_tabla);
		return idx;
	}
	else {
		printf("ERR- Se encontraron dos declaraciones de variables identicas\n"); 
		system("Pause");
		exit(2);
	} 
}

int buscar_o_insertar_var_en_tabla(char* nombre, int tipo) {
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}

	int pos = buscar_en_tabla(nombre);
	if(pos == -1){     
		int idx = ++fin_tabla;
		escribir_nombre_en_tabla(nombre, fin_tabla);
		tabla_simbolo[fin_tabla].tipo_dato = tipo;
		return fin_tabla;
	}
	return pos;
}

void agregar_tipos_datos_a_tabla() {
    int i;
	for( i = 0; i < cantVarsADeclarar; i++){
		tabla_simbolo[varADeclarar1 + i].tipo_dato = tipoDatoADeclarar;
	}
}

void guardar_tabla() {
	if(fin_tabla == -1){
		printf("ERR- No se encontró la tabla de simbolos");
		system("Pause");
		exit(2);
	}
	FILE* arch = fopen("ts.txt", "w+");
	if(!arch){
		printf("ERR- No se ha podido crear el archivo ts.txt\n");
		system("Pause");
		exit(2);
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

int agregar_cte_string_a_tabla(char* nombre) {
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}
	char nuevoNombre[10]={'\0'}; //10 porque EL maximo tamaño que puede tener está dado por "StringXXX" mas el fin de linea
	sprintf(nuevoNombre, "_cadena_%d", contador_cadenas);
	contador_cadenas++;

	int idx = buscar_en_tabla(nombre);
	if( idx == -1){
		idx = ++fin_tabla;
		escribir_nombre_en_tabla(nuevoNombre, fin_tabla);
		tabla_simbolo[fin_tabla].tipo_dato = ENUM_CTE_STRING;		
		strcpy(tabla_simbolo[fin_tabla].valor_s, nombre+1); 		
		tabla_simbolo[fin_tabla].longitud = strlen(nombre) - 1;
		idx=fin_tabla;
	}

	return idx;
}

int agregar_cte_real_a_tabla(float valor) {
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}
	
	char nombre[15];
	sprintf(nombre, "_%f", valor);
	int idx = buscar_en_tabla(nombre);

	if(idx == -1) {
		idx = ++fin_tabla;
		escribir_nombre_en_tabla(nombre, fin_tabla);
		tabla_simbolo[fin_tabla].tipo_dato = ENUM_CTE_FLOAT;
		tabla_simbolo[fin_tabla].valor_f = valor;
		idx=fin_tabla;
	}
	return idx;
}

int agregar_cte_int_a_tabla(int valor) {
	if(fin_tabla >= TAM_TABLA - 1){
		printf("ERR- Tamanio max de tabla de simbolos alcanzado\n");
		system("Pause");
		exit(2);
	}

	char nombre[30];
	sprintf(nombre, "_%d", valor);

	int idx = buscar_en_tabla(nombre);
	if(idx == -1){
		idx = ++fin_tabla;
		escribir_nombre_en_tabla(nombre, fin_tabla);
    	tabla_simbolo[fin_tabla].tipo_dato = ENUM_CTE_INTEGER;
		tabla_simbolo[fin_tabla].valor_i = valor;
		idx=fin_tabla;
	}
	return idx;
}

int validar_var_en_tabla(char* nombre) {
	int variable = buscar_en_tabla(nombre);
	if( variable== -1){
		char msg[100];
		sprintf(msg,"%s? ERR-Variable declarada fuera del bloque de declaracion", nombre);
		printf(msg);
		system("Pause");
		exit(2);
	}
	return tabla_simbolo[variable].tipo_dato;
}

int validar_tipo_dato(int cte_tipo, int cte_tipo_leido){
	if(cte_tipo_leido == SIN_TIPO){
		return cte_tipo;
	}
	if(cte_tipo_leido != cte_tipo)
	{
		printf("ERR- Tipo de dato asignado incompatible. Asegurarse de que los tipos de datos son correctos.");
		system("Pause");
		exit(2);
	}
	return -1;
}

int validar_var_numerica(int cte_tipo_leido){
	if(cte_tipo_leido == ENUM_STRING){
		printf("ERR- Tipo de dato incompatible para operar. Verficar el uso correcto de strings.");
		system("Pause");
		exit(2);
	}
}

char* reemplazar_espacios(char* str) {
	char find = ' ';
	char replace = '_';
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}
