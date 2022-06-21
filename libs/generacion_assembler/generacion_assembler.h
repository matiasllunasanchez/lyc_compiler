#ifndef generacion_assembler_h
#define generacion_assembler_h

#include <stdio.h>
#include "../tercetos/tercetos.h"

// Genera el archivo assembler Final.asm
// El recorrido comienza desde el primer terceto
void genera_assembler();
void imprimir_header_assembler(FILE* pFile);
void imprimir_tabla_simbolos(FILE* pFile);
void imprimir_footer_assembler(FILE* pFile);
void imprimir_codigo_assembler(FILE* pFile);

void escribirEtiqueta(FILE* arch, char* etiqueta, int n);
void escribirSalto(FILE* arch, char* salto, int tercetoDestino);
void asignacion(FILE* arch, int terceto);
void comparacion(FILE* arch, int terceto);
void suma(FILE* arch, int terceto);
void resta(FILE* arch, int terceto);
void multiplicacion(FILE* arch, int terceto);
void division(FILE* arch, int terceto);
void levantarEnPila(FILE* arch, const int ind);
void write(FILE* arch, int ind);
void read(FILE* arch, int ind);

extern simbolo tabla_simbolo[TAM_TABLA];
extern int fin_tabla;
extern terceto vector_tercetos[CANT_MAX_TERCETOS];
extern int idx_ultimo_terceto;

#endif
