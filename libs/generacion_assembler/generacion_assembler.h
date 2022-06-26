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

void imprimir_etiqueta(FILE* arch, char* etiqueta, int n);
void imprimir_salto(FILE* arch, char* salto, int tercetoDestino);
void realizar_asignacion(FILE* arch, int terceto);
void realizar_comparacion(FILE* arch, int terceto);
void realizar_suma(FILE* arch, int terceto);
void realizar_resta(FILE* arch, int terceto);
void realizar_multiplicacion(FILE* arch, int terceto);
void realizar_division(FILE* arch, int terceto);
void levantar_en_pila(FILE* arch, const int ind);
void realizar_escritura(FILE* arch, int ind);
void realizar_lectura(FILE* arch, int ind);

extern simbolo tabla_simbolo[TAM_TABLA];
extern int fin_tabla;
extern terceto vector_tercetos[CANT_MAX_TERCETOS];
extern int idx_ultimo_terceto;

#endif
