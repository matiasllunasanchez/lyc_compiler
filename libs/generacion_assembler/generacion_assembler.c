#include "generacion_assembler.h"

void genera_assembler() {
    FILE* pFinal = fopen("Final.asm", "w");
    if(!pFinal) {
        printf("Error al crear el archivo Final.asm\n");
        return;
    }
    
    imprimir_header_assembler(pFinal);
    imprimir_codigo_assembler(pFinal);
    imprimir_footer_assembler(pFinal);
    fclose(pFinal);
}

void imprimir_header_assembler(FILE* pFile) {
    // Inicio del archivo
    fprintf(pFile, "include macros2.asm\n");
    fprintf(pFile, "include number.asm\n\n");
    fprintf(pFile, ".MODEL LARGE\n"); // Modelo de memoria
    fprintf(pFile, ".386\n"); // Tipo de procesador
    fprintf(pFile, ".STACK 200h\n\n"); // Bytes en el stack

    // Tabla de simbolos
    imprimir_tabla_simbolos(pFile);

    // Inicio del codigo
    fprintf(pFile, ".CODE\n\n");
    fprintf(pFile, "mov AX, @DATA\n"); // Inicializa el segmento de datos
    fprintf(pFile, "mov DS, AX\n");
    fprintf(pFile, "mov es,ax\n\n");
}

void imprimir_footer_assembler(FILE* pFile) {
    fprintf(pFile, "\nmov ax,4c00h\n");
    fprintf(pFile, "Int 21h\n");
    fprintf(pFile, "End\n");
}

void imprimir_tabla_simbolos(FILE* pFile) {

}

void imprimir_codigo_assembler(FILE* pFile) {

}