#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define ENUM_INTEGER 1
#define ENUM_FLOAT 2
#define ENUM_STRING 3
#define ENUM_CTE_INTEGER 4
#define ENUM_CTE_FLOAT 5
#define ENUM_CTE_STRING 6

#define TAM_TABLA 500
#define TAM_NOMBRE 32

int agregar_var_a_tabla(char* nombre);
void agregar_tipos_datos_a_tabla(void);
int agregar_cte_string_a_tabla(char* nombre);
int agregar_cte_int_a_tabla(int valor);
int agregar_cte_real_a_tabla(float valor);
int buscar_en_tabla(char * name);
void escribir_nombre_en_tabla(char* nombre, int pos);
void chequear_var_en_tabla(char* nombre);
void guardar_tabla(void);

typedef struct {
    char nombre[TAM_NOMBRE];
    int tipo_dato;
    char valor_s[TAM_NOMBRE];
    float valor_f;
    int valor_i;
    int longitud;
} simbolo;

extern simbolo tabla_simbolo[TAM_TABLA];
extern int fin_tabla; /* Apunta al ultimo registro en la tabla de simbolos. Incrementarlo para guardar el siguiente. */
extern int varADeclarar1;
extern int cantVarsADeclarar;
extern int tipoDatoADeclarar;

#endif // PRIMITIVAS_H_INCLUDED