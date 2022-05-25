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
#define BA 16   // Branch Always o Salto Incondicional osea salto siempre.


// Partes de un terceto
#define PARTE_A 1 // OPERADOR
#define PARTE_B 2 // OPERANDO A
#define PARTE_C 3 // OPERANDO B

int crear_terceto(int parte_a, int parte_b, int parte_c);
void guardar_tercetos();
void modificar_terceto(int indice, int posicion, int valor);

typedef struct{
  int parte_a; // OPERADOR
  int parte_b; // OPERANDO A
  int parte_c; // OPERANDO B
} terceto;

extern terceto vector_tercetos[CANT_MAX_TERCETOS];
extern int idx_ultimo_terceto; // Indice del ultimo elemento insertado en vector

#endif