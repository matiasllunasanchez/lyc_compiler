#include "sentencias_control.h"
#include "../tercetos/tercetos.h"
#include "../../y.tab.h"

/**Devuelve el comparador contrario que hace saltar un bloque para un comparador especifico.
*/
int obtener_salto_condicion_negada(int comp){
	switch(comp){
	case OP_MAYOR:
		return BLE;
	case OP_MAYOR_IGUAL:
		return BLT;
	case OP_MENOR:
		return BGE;
	case OP_MENOR_IGUAL:
		return BGT;
	case OP_IGUAL:
		return BNE;
	case OP_NO_IGUAL:
		return BEQ;
	}
	return PARTE_VACIA;
}

/**Devuelve el comparador enviado pasado al valor en assembler
*/
int obtener_salto_condicion(int comp){
	switch(comp){
	case OP_MAYOR:
		return BGT;
	case OP_MAYOR_IGUAL:
		return BGE;
	case OP_MENOR:
		return BLT;
	case OP_MENOR_IGUAL:
		return BLE;
	case OP_IGUAL:
		return BEQ;
	case OP_NO_IGUAL:
		return BNE;
	}
	return PARTE_VACIA;
}

/** Apila struct elemento_terceto utilizado para if y while que contiene info de los indices de branch. Contempla anidaciones de if y whiles.
*/
void apilar_terceto(){
	ult_pos_pila++;
	if(ult_pos_pila>=MAX_ANIDAMIENTOS){
		yyerror("Se ha excedido la cantidad de anidamientos.");
	}

	elemento_terceto terceto;
	terceto.idx_terceto=idx_terceto_leido;
	terceto.idx_condicion_izq=idx_condicion_izq;
	terceto.idx_condicion_der=idx_condicion_der;
	terceto.has_or=has_or;
	terceto.idx_salto_implicito=idx_salto_implicito;

	pila_tercetos[ult_pos_pila] = terceto;

	idx_condicion_izq=VALOR_NULO;
	idx_condicion_der=VALOR_NULO;
	has_or=VALOR_NULO;
	idx_salto_implicito=VALOR_NULO;
}

/** Desapila struct elemento_tercetoun elemento de la pila que contiene info de los indices utilizados para if y while necesarios para realizar branches.
* pensado para cuando habia if y whiles anidados y vuelvo al padre.
*/
void desapilar_terceto(){
	elemento_terceto terceto=pila_tercetos[ult_pos_pila];
	ult_pos_pila--;

	idx_terceto_leido=terceto.idx_terceto;
	idx_condicion_izq=terceto.idx_condicion_izq;
	idx_condicion_der=terceto.idx_condicion_der;
	has_or=terceto.has_or;
	idx_salto_implicito=terceto.idx_salto_implicito;
}

/** Actualiza el terceto con el indice del inicio del bloque de condicion verdadera para un branch en el que se cumple la condicion de un if
*/
//***Revisar si es necesario***
void actualizar_terceto_pos_then(){
	if(has_or!=VALOR_NULO){ //Me di cuenta tarde de que ind_branch_pendiente y compania no hacen falta, soy un boludo
		modificar_terceto(has_or, PARTE_B, idx_then);
	}
}

/** Actualiza el terceto con el indice donde comienza el bloque else para un branch en el que no se cumple la condicion de un if.
* ind_else deberia apuntar al inicio del bloque else o al final del if en caso de no tener la condicion falsa.
*/
void actualizar_terceto_pos_else(){
	if(idx_condicion_izq!=VALOR_NULO){
		modificar_terceto(idx_condicion_izq, PARTE_B, idx_else);
	}
	if(idx_condicion_der!=VALOR_NULO){
		modificar_terceto(idx_condicion_der, PARTE_B, idx_else);
	}
}

/**  Actualiza el terceto con el indice que apunta al final del if para el branch implicito al final del bloque por verdadero de una condicion.
*/
void actualizar_terceto_pos_end_if(){
	if(idx_salto_implicito!=VALOR_NULO){
		modificar_terceto(idx_salto_implicito, PARTE_A, idx_end_if);
	}
}

/**
Actualiza el terceto con el indice que apunta al final del while para el branch implicito al final del bloque por verdadero de una iteracion.
*/
void actualizar_terceto_pos_end_while(){
	if(idx_condicion_izq !=VALOR_NULO){
		modificar_terceto(idx_condicion_izq, PARTE_B, idx_end_while);
	}
	if(idx_condicion_der !=VALOR_NULO){
		modificar_terceto(idx_condicion_der, PARTE_B, idx_end_while);
	}
}
