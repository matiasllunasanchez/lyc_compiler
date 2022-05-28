#include "tercetos.h"
#include "../../y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int crear_terceto(int parte_a, int parte_b, int parte_c) {
    idx_ultimo_terceto++;
    if(idx_ultimo_terceto >= CANT_MAX_TERCETOS){
        printf("ERR- Se superó el espacio máximo para guardar tercetos.\n");
        system("Pause");
        exit(3);
	}
    vector_tercetos[idx_ultimo_terceto].parte_a = parte_a;
	vector_tercetos[idx_ultimo_terceto].parte_b = parte_b;
	vector_tercetos[idx_ultimo_terceto].parte_c = parte_c;
	return idx_ultimo_terceto + OFFSET;
}

void grabar_parte(FILE** arch,int parte){
		fprintf(*arch, ", ");

		if(parte == PARTE_VACIA)
			fprintf(*arch, "_");
		else if(parte < TAM_TABLA){
			// Es una entrada a tabla de simbolos
			fprintf(*arch, "%s", &(tabla_simbolo[parte].nombre) );
		}
		else
			fprintf(*arch, "[%d]", parte); // Indice nuevo elemento
}

void guardar_tercetos() { 
    if(idx_ultimo_terceto == -1){
        printf("ERR- No existen tercetos cargados en el vector");
        exit(1);
    }

	FILE* arch = fopen("intermedia.txt", "w+");
	if(!arch){
		printf("ERR- No se pudo crear el archivo: intermedia.txt\n");
        exit(1);
		return;
	}
    int i;
    for(i = 0; i <= idx_ultimo_terceto; i++) {
		
		// Indice
        // Result: [idx] (
		fprintf(arch, "[%d] (", i + OFFSET); 

        // Escribo PARTE_A
        // Result: [idx] (PARTE_A
		switch(vector_tercetos[i].parte_a) {
            case PARTE_VACIA:
                fprintf(arch, "_");
                break;
            case PROG: // Revisar
                fprintf(arch, "PROGRAMA");
                break;
            case DECVAR:
                fprintf(arch, "DECVAR");
                break;
            case ENDDEC:
                fprintf(arch, "ENDDEC");
                break;
            case IF:
                fprintf(arch, "IF");
                break;
            case THEN:
				fprintf(arch, "THEN");
				break;
            case ELSE:
                fprintf(arch, "ELSE");
                break;
            case ENDIF:
                fprintf(arch, "ENDIF");
                break;
            case WHILE:
                fprintf(arch, "WHILE");
                break;
            case ENDWHILE:
                fprintf(arch, "ENDWHILE");
                break;
            case OP_ASIG:
                fprintf(arch, ":=");
                break;
            case OP_SUM:
                fprintf(arch, "+");
                break;
            case OP_RES:
                fprintf(arch, "-");
                break;
            case OP_MUL:
                fprintf(arch, "*");
                break;
            case OP_DIV:
                fprintf(arch, "/");
                break;
            case AND:
                fprintf(arch, "AND");
                break;
            case OR:
                fprintf(arch, "OR");
                break;
            case NOT:
                fprintf(arch, "NOT");
                break;
            case OP_MENOR:
                fprintf(arch, "<");
                break;
            case OP_MAYOR:
                fprintf(arch, ">");
                break;
            case OP_MENOR_IGUAL:
                fprintf(arch, "<=");
                break;
            case OP_MAYOR_IGUAL:
                fprintf(arch, ">=");
                break;
            case OP_IGUAL:
                fprintf(arch, "==");
                break;
            case OP_NO_IGUAL:
                fprintf(arch, "!=");
                break;
            case BETWEEN:
                fprintf(arch, "BETWEEN");
                break;
            case BETWEEN_FALSE:
                fprintf(arch, "BETWEEN_FALSE");
                break;
            case BETWEEN_CMP:
                fprintf(arch, "BETWEEN_CMP");
                break;
            case TAKE:
                fprintf(arch, "TAKE");
                break;
            case COMA:
                fprintf(arch, "\',\'");
                break;
            case PYC:
                fprintf(arch,  "\';\'");
                break;
            case READ:
                fprintf(arch, "READ");
                break;
            case WRITE:
                fprintf(arch, "WRITE");
                break;
            case CMP:
				fprintf(arch, "CMP");
				break;
			case BNE:
				fprintf(arch, "BNE");
				break;
			case BEQ:
				fprintf(arch, "BEQ");
				break;
			case BGT:
				fprintf(arch, "BGT");
				break;
			case BGE:
				fprintf(arch, "BGE");
				break;
			case BLE:
				fprintf(arch, "BLE");
				break;
			case BLT:
				fprintf(arch, "BLT");
				break;
			case JMP:
				fprintf(arch, "JMP");
				break;
            default:
                fprintf(arch, "Error. Etiqueta u operando no reconocido");
                break;
		}

		// Escribo PARTE_B
        // Result: [idx] (PARTE_A, PARTE_B
		int parte_b = vector_tercetos[i].parte_b;
        grabar_parte(&arch,parte_b);

		// Escribo PARTE_C
        // Result: [idx] (PARTE_A, PARTE_B, PARTE_C
		int parte_c = vector_tercetos[i].parte_c;
        grabar_parte(&arch,parte_c);

        // Result: [idx] (PARTE_A, PARTE_B, PARTE_C)
		fprintf(arch, ")\n");

	}
	
    fclose(arch);
}

void modificar_terceto(int indice, int parte_terceto, int valor) {

	if(indice > (idx_ultimo_terceto + OFFSET)){
		printf("ERR- Se intentó modificar un terceto inexistente.");
		system ("Pause");
		exit (4);
	}

	switch(parte_terceto){
        case PARTE_A:
            vector_tercetos[indice - OFFSET].parte_a = valor;
            break;
        case PARTE_B:
            vector_tercetos[indice - OFFSET].parte_b = valor;
            break;
        case PARTE_C:
            vector_tercetos[indice - OFFSET].parte_c = valor;
            break;
	}
}