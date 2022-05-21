#ifndef tercetos_h
#define tercetos_h
#include "../tabla_simbolos/tabla_simbolos.h"
#include "../../y.tab.h"
#include <stdio.h>
#include <stdlib.h>

#define OFFSET TAM_TABLA
// Desde 0 al max de la tabla de simbolos se considera un valor CTE o ID
// Desde el max tabla de simbolos + idx_ultimo_terceto arrancan los tercetos

// -1 NULL o VACIO  > 0, ... OFFSET > TERCETOS
// Inicio de los valores de los indices validos para interpretar a tercetos:  OFFSET + idx_ultimo_terceto

#define PARTE_VACIA -1 // Terceto parte vacia
#define PROG 7 // Revisar
#define CANT_MAX_TERCETOS 512

// Partes de un terceto
#define PARTE_A 1
#define PARTE_B 2
#define PARTE_C 3

int crear_terceto(int parte_a, int parte_b, int parte_c);
void guardar_tercetos();
void modificar_terceto(int indice, int posicion, int valor);

typedef struct{
  int parte_a;
  int parte_b;
  int parte_c;
} terceto;

extern terceto vector_tercetos[CANT_MAX_TERCETOS];
extern int idx_ultimo_terceto = -1; // Indice del ultimo elemento insertado en vector

#endif