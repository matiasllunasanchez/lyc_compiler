#ifndef sentencias_control_h
#define sentencias_control_h

#define MAX_ANIDAMIENTOS 5
#define VALOR_NULO -1

/* Funciones */
// Retorna el comparador contrario al recibido, el cual sirve para saltar al bloque contrario de una condicion. (SINO)
int obtener_salto_condicion_negada(int comparador); 
 // Retorna el equivalente en assembler del comparador recibido
int obtener_salto_condicion(int comparador);
// Apila elementos del tipo 'elemento_terceto'
// Esta pila contiene informacion de los indices usados para realizar saltos / branches en IF y WHILE
// Contempla anidaciones de IF y WHILE
void apilar_terceto();
// Desapila elementos del tipo 'elemento_terceto'
// Esta pila contiene informacion de los indices usados para realizar saltos / branches en IF y WHILE
// Contempla anidaciones de IF y WHILE
void desapilar_terceto();

 // Actualiza el terceto con el indice del inicio del bloque de condicion verdadera para un branch en el que se cumple la condicion de un if
void actualizar_terceto_pos_then();
 // Actualiza el terceto con el indice donde comienza el bloque else o al final del if en caso de no tener un bloque ELSE o de condicion falsa. Se usa para marcar la posicion hacia donde se debe saltar en el caso donde no se cumple la condicion de un if. idx_else va a marcar el inicio de este bloque en cuestion
void actualizar_terceto_pos_else();
// Actualiza el terceto con el indice que apunta al final del if. Se usa en los branchs implicitos, cuando se termina un bloque verdadero y tenes que saltar implicitamente al final.
void actualizar_terceto_pos_end_if(); 
// Actualiza el terceto con el indice que apunta al final del while para el branch implicito al final del bloque por verdadero de una iteracion.
void actualizar_terceto_pos_end_while(); 

int yyerror(char* mensaje);

//Struct tipo pila para almacenar tercetos
typedef struct{
  int idx_terceto; //Indice del terceto apilado
  int idx_condicion_izq; //Indice de la condicion booleana izq para un condicional
  int idx_condicion_der; //Indice de la condicion booleana detecha para un condicional.
  int has_or; //Indica si la condicion contiene un OR
  int idx_salto_implicito; /*Indica el salto implicito correspondiente al terceto por default utilizado para endif y endwhile*/
} elemento_terceto;

/* Variables externas */

/* Indices usados en anidamientos de if y while */
//Indice de la condicion booleana izq para un condicional
extern int idx_condicion_izq;
//Indice de la condicion booleana detecha para un condicional.
extern int idx_condicion_der;
extern int has_or;
// Indica el salto implicito correspondiente al terceto por default utilizado para endif y endwhile
extern int idx_salto_implicito;
// Indice que apunta a terceto de endif
extern int idx_end_if;
// Indice que apunta a terceto de else
extern int idx_else;
// Indice que apunta a terceto then
extern int idx_then;
// Indice que apunta al ultimo terceto leido
extern int idx_terceto_leido;
// Indice que apunta a terceto de endwhile
extern int idx_end_while;
// Pila de tercetos
// Relacionada con los tercetos que representan anidamientos
extern elemento_terceto pila_tercetos[MAX_ANIDAMIENTOS];

// Indica el indice del ultimo elemento insertado en la pila.
// Funciona como tope de la pila de tercetos de anidados.
// Tambien representa la cantidad de elementos existentes en la pila de tercetos de anidamientos
extern int ult_pos_pila;

#endif
