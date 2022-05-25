#include "sentencias_control.h"
#include "../tercetos/tercetos.h"
#include "../../y.tab.h"

// A partir del token comparador recibdo que se acaba de leer, se devuelve el operador de assembler para saltar al bloque falso / contrario.
// Si recibo > devuelvo MENOR IGUAL. Si recibo MAYOR IGUAL devuelvo MENOR.
int obtener_operador_salto(int comp){
	switch(comp) {
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

// Inserta idx del fin de la seleccion en el branch obligatorio al final del bloque por verdadero.
void  salto_a_fin_IF() {
    if(salto_implicito!=NULO){
		modificar_terceto(salto_implicito, PARTE_B, idx_endif);
	}
}

// Se apilan sentencias del tipo IF y WHILE
// Maneja sus anidamientos
//! Sabe donde tiene que rellenar un branch y resetea variables globales.
void apilar_sentencia() {
	tope_pila_aux++;
	if(tope_pila_aux>=ANIDACION_MAX){
		yyerror("Anidamientos máximos superados. Anidamientos maximos: 5.");
	}

	infoaux_sentencias vAux;
	// aux.ind_bloque=ind_bloque;
	// aux.ind_bwhile=ind_bwhile;
	// aux.falseIzq=falseIzq;
	// aux.falseDer=falseDer;
	// aux.verdadero=verdadero;
	vAux.salto_implicito=salto_implicito;

	pila_aux[tope_pila_aux] = vAux;

	// falseIzq=VALOR_NULO;
	// falseDer=VALOR_NULO;
	// verdadero=VALOR_NULO;
	idx_salto_implicito=NULO;
}

void desapilar_sentencia() {
	infoaux_sentencias vAux = pila_aux[tope_pila_aux];
	tope_pila_aux--;

	// ind_bloque=aux.ind_bloque;
	// ind_bwhile=aux.ind_bwhile;
	// falseIzq=aux.falseIzq;
	// falseDer=aux.falseDer;
	// verdadero=aux.verdadero;
	salto_implicito = vAux.salto_implicito;
}
