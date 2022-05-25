#ifndef sentencias_control_h
#define sentencias_control_h

#define ANIDACION_MAX 5
#define NULO -1

void  salto_a_fin_IF();
int  obtener_operador_salto();
void apilar_sentencia();
void desapilar_sentencia();
// Variables
extern int salto_implicito;

// Indices
extern int idx_endif;

// Pila de sentencias
typedef struct{
  // int ind_bloque; //Apilamos el bloque actual

  // int falseIzq; //Si se pasa por false el bool izquierdo
  // int falseDer; //Si se pasa por false el bool derecho
  // int verdadero; //Si hay un OR, el lado izq
  // int always; //Para los else, y los endwhile
  int salto_implicito; // ELSE ENDWHILE
} infoaux_sentencias;

extern infoaux_sentencias pila_aux[ANIDACION_MAX];
extern int tope_pila_aux;

#endif