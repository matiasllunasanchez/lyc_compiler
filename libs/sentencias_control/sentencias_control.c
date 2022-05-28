#include "sentencias_control.h"
#include "../tercetos/tercetos.h"
#include "../../y.tab.h"

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

void apilar_terceto(){
	ult_pos_pila++;
	if(ult_pos_pila>=MAX_ANIDAMIENTOS){
		yyerror("ERR- Se ha excedido la cantidad de anidamientos.");
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

void desapilar_terceto(){
	elemento_terceto terceto=pila_tercetos[ult_pos_pila];
	ult_pos_pila--;

	idx_terceto_leido=terceto.idx_terceto;
	idx_condicion_izq=terceto.idx_condicion_izq;
	idx_condicion_der=terceto.idx_condicion_der;
	has_or=terceto.has_or;
	idx_salto_implicito=terceto.idx_salto_implicito;
}

//***Revisar***//
void actualizar_terceto_pos_then(){
	if(has_or!=VALOR_NULO){ //Revisa
		modificar_terceto(has_or, PARTE_B, idx_then);
	}
}

void actualizar_terceto_pos_else(){
	if(idx_condicion_izq!=VALOR_NULO){
		modificar_terceto(idx_condicion_izq, PARTE_B, idx_else);
	}
	if(idx_condicion_der!=VALOR_NULO){
		modificar_terceto(idx_condicion_der, PARTE_B, idx_else);
	}
}

void actualizar_terceto_pos_end_if(){
	if(idx_salto_implicito!=VALOR_NULO){
		modificar_terceto(idx_salto_implicito, PARTE_A, idx_end_if);
	}
}

void actualizar_terceto_pos_end_while(){
	if(idx_condicion_izq !=VALOR_NULO){
		modificar_terceto(idx_condicion_izq, PARTE_B, idx_end_while);
	}
	if(idx_condicion_der !=VALOR_NULO){
		modificar_terceto(idx_condicion_der, PARTE_B, idx_end_while);
	}
}
