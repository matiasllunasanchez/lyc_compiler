#include "generacion_assembler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tercetos/tercetos.h"
#include "../../y.tab.h"

void genera_assembler() {
    FILE* pFile = fopen("./assembler/Final.asm", "w");
    if(!pFile) {
        printf("Error al crear el archivo Final.asm\n");
        return;
    }
    
    imprimir_header_assembler(pFile);
    imprimir_codigo_assembler(pFile);
    imprimir_footer_assembler(pFile);
    fclose(pFile);
}

void imprimir_header_assembler(FILE* pFile) {
    // Inicio del archivo
    fprintf(pFile, "include macros2.asm\n");
    fprintf(pFile, "include number.asm\n\n");
    fprintf(pFile, ".MODEL LARGE\n"); // Modelo de memoria
    fprintf(pFile, ".386\n"); // Tipo de procesador
    fprintf(pFile, ".STACK 200h\n\n"); // Bytes en el stack

    // Tabla de simbolos
    imprimir_tabla_simbolos(pFile);

    // Inicio del codigo
    fprintf(pFile, ".CODE\n");
    fprintf(pFile, "mov AX,@DATA\n"); // Inicializa el segmento de datos
    fprintf(pFile, "mov DS,AX\n");
    fprintf(pFile, "mov es,ax\n\n");
}

void imprimir_footer_assembler(FILE* pFile) {
    fprintf(pFile, "\nmov ax,4c00h\n");
    fprintf(pFile, "Int 21h\n");
    fprintf(pFile, "End\n");
}

void imprimir_tabla_simbolos(FILE* pFile) {
    fprintf(pFile, ".DATA\n");
    for(int i=0; i<=fin_tabla; i++) {
        fprintf(pFile, "%s ", tabla_simbolo[i].nombre);
        switch(tabla_simbolo[i].tipo_dato) {
            case ENUM_CTE_INTEGER:
                fprintf(pFile, "dd %d\n", tabla_simbolo[i].valor_i);
                break;
            case ENUM_CTE_FLOAT:
                fprintf(pFile, "dd %f\n", tabla_simbolo[i].valor_f);
                break;
            case ENUM_CTE_STRING:
                fprintf(pFile, "db \"%s\", '$'\n", tabla_simbolo[i].valor_s);
                break;
            default: // Variable
                fprintf(pFile, "dd ?\n");
        }
    }

    fprintf(pFile, "\n");
}

void imprimir_codigo_assembler(FILE* pFile) {

    for(int i=0; i<= idx_ultimo_terceto; i++) {
        switch(vector_tercetos[i].parte_a){
            // ASIG & COMP
            case OP_ASIG:
                realizar_asignacion(pFile, i);
                break;
            case CMP:
                realizar_comparacion(pFile, i);
                break;

            // BRANCHES
            case BGT:
                imprimir_salto(pFile, "JA", vector_tercetos[i].parte_b);
                break;
            case BGE:
                imprimir_salto(pFile, "JAE", vector_tercetos[i].parte_b);
                break;
            case BLT:
                imprimir_salto(pFile, "JB", vector_tercetos[i].parte_b);
                break;
            case BLE:
                imprimir_salto(pFile, "JBE", vector_tercetos[i].parte_b);
                break;
            case BNE:
                imprimir_salto(pFile, "JNE", vector_tercetos[i].parte_b);
                break;
            case BEQ:
                imprimir_salto(pFile, "JE", vector_tercetos[i].parte_b);
                break;
            case JMP:
                imprimir_salto(pFile, "JMP", vector_tercetos[i].parte_b);
                break;

            // ETIQUETAS
            case THEN:
                imprimir_etiqueta(pFile, "then", i);
                break;
            case ELSE:
                imprimir_etiqueta(pFile, "else", i);
                break;
            case ENDIF:
                imprimir_etiqueta(pFile, "endif", i);
                break;
            case WHILE:
                imprimir_etiqueta(pFile, "while", i);
                break;
            case ENDWHILE:
                imprimir_etiqueta(pFile, "endwhile", i);
                break;

            // ETIQUETAS ESPECIALES
            case TAKE:
                imprimir_etiqueta(pFile, "TAKE", i);
                break;
            case BETWEEN:
                imprimir_etiqueta(pFile, "BETWEEN", i);
                break;

            // OPERADORES
            case OP_SUM:
                realizar_suma(pFile,i);
                break;
            case OP_RES:
                realizar_resta(pFile,i);
                break;
            case OP_MUL:
                realizar_multiplicacion(pFile,i);
                break;
            case OP_DIV:
                realizar_division(pFile,i);
                break;

            // READ & WRITE
            case READ: 
                realizar_lectura(pFile,i);
                break;
            case WRITE:
                realizar_escritura(pFile, i);
                break;
        }
    }

}

void imprimir_etiqueta(FILE* pFile, char* etiqueta, int n){
    fprintf(pFile, "%s%d:\n", etiqueta, n+OFFSET);
}

void imprimir_salto(FILE* pFile, char* salto, int tercetoDestino){
    fprintf(pFile, "%s ", salto);

    if(tercetoDestino == PARTE_VACIA){
        printf("Error - Falta salto.\n");
        system("Pause");
        exit(10);
    }

    switch( vector_tercetos[tercetoDestino - OFFSET].parte_a) {
        case THEN:
            fprintf(pFile, "then");
            break;
        case ELSE:
            fprintf(pFile, "else");
            break;
        case ENDIF:
            fprintf(pFile, "endif");
            break;
        case WHILE:
            fprintf(pFile, "while");
            break;
        case ENDWHILE:
            fprintf(pFile, "endwhile");
            break;
        case BETWEEN_FALSE:
            fprintf(pFile, "between_false");
            break;
        case BETWEEN_CMP:
            fprintf(pFile, "between_cmp");
    }

    fprintf(pFile, "%d\n", tercetoDestino);
}

void realizar_asignacion(FILE* pFile, int ind){
	int destino = vector_tercetos[ind].parte_b;
	int origen = vector_tercetos[ind].parte_c;
	switch(tabla_simbolo[destino].tipo_dato) {
        case ENUM_INTEGER:
            if(origen < OFFSET) 
                fprintf(pFile, "FILD %s\n", tabla_simbolo[origen].nombre);
            else 
                fprintf(pFile, "FSTCW CWanterior\nOR CWanterior, 0400h\nFLDCW CWanterior \n");
            fprintf(pFile, "FISTP %s", tabla_simbolo[destino].nombre);
            break;
        case ENUM_FLOAT:
            fprintf(pFile, "FLD %s\n", tabla_simbolo[origen].nombre);
            fprintf(pFile, "FSTP %s", tabla_simbolo[destino].nombre);
            break;
        case ENUM_STRING:
            fprintf(pFile, "LEA EAX, %s\nMOV %s, EAX", tabla_simbolo[origen].nombre, tabla_simbolo[destino].nombre);
	}

	fprintf(pFile, "\n");
}

void realizar_comparacion(FILE* pFile, int ind){
	levantar_en_pila(pFile, ind);
	fprintf(pFile, "FXCH\nFCOMP\nFSTSW AX\nSAHF\n");

}

void realizar_suma(FILE* pFile, int ind){
	levantar_en_pila(pFile, ind);
	fprintf(pFile, "FADD\n");
}

void realizar_resta(FILE* pFile, int ind){
	if(vector_tercetos[ind].parte_c==PARTE_VACIA){
		int aux;
		if((aux = vector_tercetos[ind].parte_b) < OFFSET){ 
			switch(tabla_simbolo[aux].tipo_dato){
				case ENUM_INTEGER:
					fprintf(pFile, "FILD %s\n", tabla_simbolo[aux].nombre);
					break;
				case ENUM_FLOAT:
					fprintf(pFile, "FLD %s\n", tabla_simbolo[aux].nombre);
					break;
				case ENUM_CTE_INTEGER:
					fprintf(pFile, "FILD %s\n", tabla_simbolo[aux].nombre);
					break;
				case ENUM_CTE_FLOAT:
					fprintf(pFile, "FLD %s\n", tabla_simbolo[aux].nombre);
					break;
			}
		}
		fprintf(pFile, "FCHS\n");
	}
	else{
		levantar_en_pila(pFile, ind);
		fprintf(pFile, "FSUB\n");
	}
}

void realizar_multiplicacion(FILE* pFile, int ind){
	levantar_en_pila(pFile, ind);
	fprintf(pFile, "FMUL\n");
}

void realizar_division(FILE* pFile, int ind){ 
	levantar_en_pila(pFile, ind);
	fprintf(pFile, "FDIV\n");
}

void levantar_en_pila(FILE* pFile, const int ind){
	int elemento_izquierdo = vector_tercetos[ind].parte_b;
	int elemento_derecho = vector_tercetos[ind].parte_c;
	int izq_up = 0;

	if(elemento_izquierdo < OFFSET) {
		switch(tabla_simbolo[elemento_izquierdo].tipo_dato) {
            case ENUM_INTEGER:
                fprintf(pFile, "FILD %s\n", tabla_simbolo[elemento_izquierdo].nombre);
                break;
            case ENUM_FLOAT:
                fprintf(pFile, "FLD %s\n", tabla_simbolo[elemento_izquierdo].nombre);
                break;
            case ENUM_CTE_INTEGER:
                fprintf(pFile, "FILD %s\n", tabla_simbolo[elemento_izquierdo].nombre);
                break;
            case ENUM_CTE_FLOAT:
                fprintf(pFile, "FLD %s\n", tabla_simbolo[elemento_izquierdo].nombre);
                break;
		}
		izq_up=1;
	}

	if(elemento_derecho < OFFSET) {
        
		switch(tabla_simbolo[elemento_derecho].tipo_dato) {
            case ENUM_INTEGER:
                fprintf(pFile, "FILD %s\n", tabla_simbolo[elemento_derecho].nombre);
                break;
            case ENUM_FLOAT:
                fprintf(pFile, "FLD %s\n", tabla_simbolo[elemento_derecho].nombre);
                break;
            case ENUM_CTE_INTEGER:
                fprintf(pFile, "FILD %s\n", tabla_simbolo[elemento_derecho].nombre);
                break;
            case ENUM_CTE_FLOAT:
                fprintf(pFile, "FLD %s\n", tabla_simbolo[elemento_derecho].nombre);
                break;
		}

		izq_up=0;
	}

	if(izq_up) {
		fprintf(pFile, "FXCH\n");
	}
}

void realizar_escritura(FILE* pFile, int terceto){
	int ind = vector_tercetos[terceto].parte_b; 
	switch(tabla_simbolo[ind].tipo_dato) {
        case ENUM_INTEGER:
            fprintf(pFile, "DisplayInteger %s\n", tabla_simbolo[ind].nombre);
            fprintf(pFile, "displayString NEW_LINE\n");
            break;
        case ENUM_FLOAT:
            fprintf(pFile, "DisplayFloat %s,2\n", tabla_simbolo[ind].nombre);
            fprintf(pFile, "displayString NEW_LINE\n");
            break;
        case ENUM_STRING:
            fprintf(pFile, "MOV EBX, %s\ndisplayString [EBX]\n", tabla_simbolo[ind].nombre);
            fprintf(pFile, "displayString NEW_LINE\n");
            break;
        case ENUM_CTE_STRING:
            fprintf(pFile, "displayString %s\n", tabla_simbolo[ind].nombre);
            fprintf(pFile, "displayString NEW_LINE\n");
            break;
	}
	fprintf(pFile, "\n");
}

void realizar_lectura(FILE* pFile, int terceto){
	int ind = vector_tercetos[terceto].parte_b;
	switch(tabla_simbolo[ind].tipo_dato){
	case ENUM_INTEGER:
		fprintf(pFile, "getInteger %s\n", tabla_simbolo[ind].nombre);

		break;
	case ENUM_FLOAT:
		fprintf(pFile, "getFloat %s\n", tabla_simbolo[ind].nombre);

		break;
	case ENUM_STRING:
		fprintf(pFile, "getString %s\n", tabla_simbolo[ind].nombre);

	}
	fprintf(pFile, "\n");
}
