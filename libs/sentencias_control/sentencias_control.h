#ifndef sentencias_control_h
#define sentencias_control_h

#define MAX_ANIDAMIENTOS 5
#define VALOR_NULO -1

/* Funciones */
//Devuelve el comparador contrario que hace saltar un bloque para un comparador especifico.
int obtener_salto_condicion_negada(int comparador);
//Devuelve el comparador enviado pasado al valor en assembler
int obtener_salto_condicion(int comparador);
void apilar_terceto();
void desapilar_terceto();

void actualizar_terceto_pos_then();
void actualizar_terceto_pos_else();
void actualizar_terceto_pos_end_if();
void actualizar_terceto_pos_end_while();

int yyerror(char* mensaje);

/* Struct tipo pila para almacenar tercetos */
typedef struct{
  int idx_terceto; //Indice del terceto apilado
  int idx_condicion_izq; //Indice de la condicion booleana izq para un condicional
  int idx_condicion_der; //Indice de la condicion booleana detecha para un condicional.
  int has_or; //Indica si la condicion contiene un OR
  int idx_salto_implicito; /*Indica el salto implicito correspondiente al terceto por default utilizado para endif y endwhile*/
} elemento_terceto;

/* Variables externas */

/* Indices utilizados anidamientos de if y while */
//Indice de la condicion booleana izq para un condicional
extern int idx_condicion_izq;
//Indice de la condicion booleana detecha para un condicional.
extern int idx_condicion_der;
extern int has_or;
/*Indica el salto implicito correspondiente al terceto por default utilizado para endif y endwhile*/
extern int idx_salto_implicito;
/* Indice que apunta a terceto de endif */
extern int idx_end_if;
/* Indice que apunta a terceto de else */
extern int idx_else;
/* Indice que apunta a terceto then */
extern int idx_then;
/* Indice que apunta al ultimo terceto leido */
extern int idx_terceto_leido;
/* Indice que apunta a terceto de endwhile */
extern int idx_end_while;
/* Pila de tercetos*/
extern elemento_terceto pila_tercetos[MAX_ANIDAMIENTOS];
/* cantidad de elementos existentes en la pila de tercetos*/
extern int ult_pos_pila;

#endif
