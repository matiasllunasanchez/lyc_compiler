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
    for(int i=0; i<=fin_tabla; i++){
        fprintf(pFile, "%s ", tabla_simbolo[i].nombre);
        switch(tabla_simbolo[i].tipo_dato){
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
    // Los tercetos deben estar optimizados
    // Cantidad de tercetos  es igual a la cantidad de variables @aux -1 a escribir.
    // SI tengo 7 tercetos, necesito 6 auxiliares ooo...
    // Las variables auxiliares para ir guardando los resultados operados en los registros
    
  for(int i=0; i<= idx_ultimo_terceto; i++){
    switch(vector_tercetos[i].parte_a){
      case OP_ASIG:
	  	asignacion(pFile, i);
        break;
      case CMP:
		comparacion(pFile, i);
        break;

      case BGT:
        escribirSalto(pFile, "JA", vector_tercetos[i].parte_b);
        break;
      case BGE:
        escribirSalto(pFile, "JAE", vector_tercetos[i].parte_b);
        break;
      case BLT:
        escribirSalto(pFile, "JB", vector_tercetos[i].parte_b);
        break;
      case BLE:
        escribirSalto(pFile, "JBE", vector_tercetos[i].parte_b);
        break;
      case BNE:
        escribirSalto(pFile, "JNE", vector_tercetos[i].parte_b);
        break;
      case BEQ:
        escribirSalto(pFile, "JE", vector_tercetos[i].parte_b);
        break;
      case JMP:
        escribirSalto(pFile, "JMP", vector_tercetos[i].parte_b);
        break;

      case THEN:
        escribirEtiqueta(pFile, "then", i);
        break;
      case ELSE:
        escribirEtiqueta(pFile, "else", i);
        break;
      case ENDIF:
        escribirEtiqueta(pFile, "endif", i);
        break;

      case WHILE:
        escribirEtiqueta(pFile, "while", i);
        break;

      case ENDWHILE:
        escribirEtiqueta(pFile, "endwhile", i);
        break;

	
    case TAKE:
		escribirEtiqueta(pFile, "TAKE", i);
		break;

	case BETWEEN:
		escribirEtiqueta(pFile, "BETWEEN", i);
		break;

      case OP_SUM:
		suma(pFile,i);
        break;
      case OP_RES:
		resta(pFile,i);
        break;
      case OP_MUL:
		multiplicacion(pFile,i);
        break;
      case OP_DIV:
		division(pFile,i);
        break;

      case READ: read (pFile,i);
        break;
      case WRITE:
	  	write(pFile, i);
        break;
    }
  }

}

void escribirEtiqueta(FILE* pFile, char* etiqueta, int n){
    fprintf(pFile, "%s%d:\n", etiqueta, n+OFFSET);
}

void escribirSalto(FILE* pFile, char* salto, int tercetoDestino){
    fprintf(pFile, "%s ", salto);

    //Por si nos olvidamos de rellenar un salto
    if(tercetoDestino == PARTE_VACIA){
        printf("Ups. Parece que me olvide de rellenar un salto en los tercetos y ahora no se como seguir.\n");
        system("Pause");
        exit(10);
    }

    switch( vector_tercetos[tercetoDestino - OFFSET].parte_a){
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

void asignacion(FILE* pFile, int ind){
	int destino = vector_tercetos[ind].parte_b;
	int origen = vector_tercetos[ind].parte_c;

	//Ver tipo de dato
	switch(tabla_simbolo[destino].tipo_dato){
	case ENUM_INTEGER:
		// Si es un int de tabla de simbolos, primero hay que traerlo de memoria a st(0)
		// Sino es el resultado de una expresion anterior y ya esta en st(0)
		if(origen < OFFSET) //Es un int en tabla de simbolos
			fprintf(pFile, "FILD %s\n", tabla_simbolo[origen].nombre);
		else //El valor ya esta en el copro, puede que haga falta redondear
			fprintf(pFile, "FSTCW CWprevio ;Guardo Control Word del copro\nOR CWprevio, 0400h ;Preparo Control Word seteando RC con redondeo hacia abajo\nFLDCW CWprevio ;Cargo nueva Control Word\n");
		fprintf(pFile, "FISTP %s", tabla_simbolo[destino].nombre);
		break;
	case ENUM_FLOAT:
		// Si es un float de tabla de simbolos, primero hay que traerlo de memoria a st(0)
		// Sino es el resultado de una expresion anterior y ya esta en st(0)
		if(origen < OFFSET) //Es un float en tabla de simbolos
			fprintf(pFile, "FLD %s\n", tabla_simbolo[origen].nombre);
		fprintf(pFile, "FSTP %s", tabla_simbolo[destino].nombre);
		break;
	case ENUM_STRING:
		//destino y origen son entradas a tabla de simbolos
		//Cargo direccion del origen y pongo esa direccion en la variable en memoria. La variable sera puntero a string.
		fprintf(pFile, "LEA EAX, %s\nMOV %s, EAX", tabla_simbolo[origen].nombre, tabla_simbolo[destino].nombre);
	}

	fprintf(pFile, "\n");
}

/** Levanta, da vuelta los elementos y compara */
void comparacion(FILE* pFile, int ind){
	levantarEnPila(pFile, ind);
	fprintf(pFile, "FXCH\nFCOMP\nFSTSW AX\nSAHF\n");

}
/** Levanta, suma, y deja en pila */
void suma(FILE* pFile, int ind){
	levantarEnPila(pFile, ind);
	fprintf(pFile, "FADD\n");
}
/** Levanta, revisa si hay dos operadores: Si hay uno, calcula el negativo. Si hay dos, resta y deja en pila*/
void resta(FILE* pFile, int ind){
	if(vector_tercetos[ind].parte_c==PARTE_VACIA){
		int aux;
		if((aux = vector_tercetos[ind].parte_b) < OFFSET){ //Es decir si está en la tabla
			switch(tabla_simbolo[aux].tipo_dato){
				case ENUM_INTEGER:
					//FILD n; Donde n es el numero integer en memoria
					fprintf(pFile, "FILD %s\n", tabla_simbolo[aux].nombre);
					break;
				case ENUM_FLOAT:
					//FLD n; Donde n es el numero float en memoria
					fprintf(pFile, "FLD %s\n", tabla_simbolo[aux].nombre);
					break;
				case ENUM_CTE_INTEGER:
					//FILD n;Donde n es el numero integer en tabla
					fprintf(pFile, "FILD %s\n", tabla_simbolo[aux].nombre);
					break;
				case ENUM_CTE_FLOAT:
					//FLD n;Donde n es el numero float en tabla
					fprintf(pFile, "FLD %s\n", tabla_simbolo[aux].nombre);
					break;
			}
		}
		fprintf(pFile, "FCHS\n");
	}
	else{
		levantarEnPila(pFile, ind);
		fprintf(pFile, "FSUB\n");
	}
}
/** Levanta, multiplica, y deja en pila */
void multiplicacion(FILE* pFile, int ind){
	levantarEnPila(pFile, ind);
	fprintf(pFile, "FMUL\n");
}
/** Levanta, divide, si la cuenta era de enteros se asegura de truncar y deja en pila */
void division(FILE* pFile, int ind){ //Mañana reviso, seguro acá distinguimos operación integer de flotante
	levantarEnPila(pFile, ind);
	fprintf(pFile, "FDIV\n");
}

/** Asegura que el elemento de la izquierda esté en st1, y el de la derecha en st0 */
void levantarEnPila(FILE* pFile, const int ind){
	int elemIzq = vector_tercetos[ind].parte_b;
	int elemDer = vector_tercetos[ind].parte_c;
	int izqLevantado = 0;
	/* Si el elemento no está en pila lo levanta */
	if(elemIzq < OFFSET){
		switch(tabla_simbolo[elemIzq].tipo_dato){
		case ENUM_INTEGER:
			//FILD n; Donde n es el numero integer en memoria
			fprintf(pFile, "FILD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		case ENUM_FLOAT:
			//FLD n; Donde n es el numero float en memoria
			fprintf(pFile, "FLD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		case ENUM_CTE_INTEGER:
			//FILD n;Donde n es el numero integer en tabla
			fprintf(pFile, "FILD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		case ENUM_CTE_FLOAT:
			//FLD n;Donde n es el numero float en tabla
			fprintf(pFile, "FLD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		}
		izqLevantado=1;
	}
	if(elemDer < OFFSET){
		switch(tabla_simbolo[elemDer].tipo_dato){
		case ENUM_INTEGER:
			//FILD n; Donde n es el numero integer en memoria
			fprintf(pFile, "FILD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		case ENUM_FLOAT:
			//FLD n; Donde n es el numero float en memoria
			fprintf(pFile, "FLD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		case ENUM_CTE_INTEGER:
			//FILD n;Donde n es el numero integer en tabla
			fprintf(pFile, "FILD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		case ENUM_CTE_FLOAT:
			//FLD n;Donde n es el numero float en tabla
			fprintf(pFile, "FLD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		}
		izqLevantado=0;
	}
	if(izqLevantado){
		fprintf(pFile, "FXCH\n");
	}
}

void write(FILE* pFile, int terceto){
	int ind = vector_tercetos[terceto].parte_b; //Indice de entrada a tabla de simbolos del mensaje a mostrar
	switch(tabla_simbolo[ind].tipo_dato){
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

void read(FILE* pFile, int terceto){
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
