#ifndef tercetos_h
#define tercetos_h
#include "../tabla_simbolos/tabla_simbolos.h"

#define OFFSET TAM_TABLA
// Desde 0 al max de la tabla de simbolos se considera un valor CTE o ID
// Desde el max tabla de simbolos + idx_ultimo_terceto arrancan los tercetos

// -1 NULL o VACIO  > 0, ... OFFSET > TERCETOS
// Inicio de los valores de los indices validos para interpretar a tercetos:  OFFSET + idx_ultimo_terceto

#define PARTE_VACIA -1 // Terceto parte vacia
#define PROG 7 // Revisar
#define CANT_MAX_TERCETOS 512
#define CMP 21  // Comparador de assembler
// Recordar que los branches son siempre por la condicion contraria a la que evalua el condicional, la verdadera no salta / branchea, sino que sigue.
#define BNE 2   // =  - Salto por NOT EQUAL cuando es igual
#define BGE 4   // <  Salto por MAYOR IGUAL cuando es menor
#define BLT 6   // >= Salto por MENOR QUE cuando es mayor igual
#define BLE 10  // >  Salto por MENOR IGUAL cuadno es mayor
#define BEQ 14  // != Salto por IGUAL QUE cuando es distinto
#define BGT 8   // <= Salto por MAYOR QUE cuando es menor igual
#define JMP 16   // Branch Always o Salto Incondicional osea salto siempre.


// Partes de un terceto
#define PARTE_A 1 // Generalmente el operador (+,*,-,/,etc)
#define PARTE_B 2 // Generalmente el operando 1. (Num o algo)
#define PARTE_C 3 // Generalmente el operando 2. (Num o algo)

// Agrega terceto a vector.
// Tratar de respetar la PARTE_A para los OPERANDOS UNICAMENTE.
// Mandar PARTE_VACIA en PARTE_A y PARTE_C para guardar CTE o ID en la PARTE_B.
// Operadores se manda token, operandos se manda el idx en la tabla de simbolos o de otro terceto.
int crear_terceto(int parte_a, int parte_b, int parte_c); 
// Guarda tercetos en archivo en archivo intermedia.txt
// Esto lo hace recorriendo el vector de tercetos e identificando cada variable DEFINE / CONSTANTE definida en tercetos.h
// Forma final de un terceto: [idx] (PARTE_A, PARTE_B, PARTE_C)
// Nota: Arrancan del indice 500
void guardar_tercetos(); 

// Modificar terceto mediante idx que tiene en el vector y la PARTE que se quiere modificar
// El idx recibido debe tener offset
// La parte debe ser alguna de las CONSTANTES definidas en tercetos.h (PARTE_A o PARTE_B o PARTE_C)
void modificar_terceto(int indice, int parte_terceto, int valor);

typedef struct{
  int parte_a;  // Generalmente el operador (+,*,-,/,etc)
  int parte_b;  // Generalmente el operando 1. (Num o algo)
  int parte_c;  // Generalmente el operando 2. (Num o algo)
} terceto;

extern terceto vector_tercetos[CANT_MAX_TERCETOS]; // Vector que va apilando tercetos
extern int idx_ultimo_terceto; // Indice del ultimo elemento insertado en vector.

#endif