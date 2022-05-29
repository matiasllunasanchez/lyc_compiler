#ifndef generacion_assembler_h
#define generacion_assembler_h

#include <stdio.h>
#include "../tercetos/tercetos.h"

// Genera el archivo assembler final.asm
// El recorrido comienza desde el primer terceto
void genera_assembler();
void imprimir_header_assembler(FILE* pFile);
void imprimir_tabla_simbolos(FILE* pFile);
void imprimir_footer_assembler(FILE* pFile);
void imprimir_codigo_assembler(FILE* pFile);
#endif
