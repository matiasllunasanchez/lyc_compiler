#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define SIN_TIPO 0
#define ENUM_INTEGER 1
#define ENUM_FLOAT 2
#define ENUM_STRING 3
#define ENUM_CTE_INTEGER 4
#define ENUM_CTE_FLOAT 5
#define ENUM_CTE_STRING 6
#define TAM_TABLA 500
#define TAM_NOMBRE 32

//Funcion que agrega una variable a la tabla de simbolos. En caso de que la variable ya exista tira error por variable duplicada
int agregar_var_declarada_a_tabla(char* nombre);
//Funcion que busca una variable en la tabla de simbolos y en caso de no existir la inserta.
int buscar_o_insertar_var_en_tabla(char* nombre, int tipo);
void agregar_tipos_datos_a_tabla(void);
int agregar_cte_string_a_tabla(char* nombre);
int agregar_cte_int_a_tabla(int valor);
int agregar_cte_real_a_tabla(float valor);
int buscar_en_tabla(char * name);
int buscar_y_validar_en_tabla(char* name);
void escribir_nombre_en_tabla(char* nombre, int pos);
int validar_var_en_tabla(char* nombre);
void guardar_tabla(void);

// Funcion auxiliar Auxiliares
// Valida que los tipos de datos recibidos sean iguales y sino lanza error.
int validar_tipo_dato(int cte_tipo, int cte_tipo_leido);

// Valida que el tipo de dato pasado por parametro NO sea string
// Si lo es, lanza error
int validar_var_numerica(int cte_tipo);

typedef struct {
    char nombre[TAM_NOMBRE];
    int tipo_dato;
    char valor_s[TAM_NOMBRE];
    float valor_f;
    int valor_i;
    int longitud;
} simbolo;

extern simbolo tabla_simbolo[TAM_TABLA];
extern int fin_tabla; // Es un indice o valor numerico que apunta al ultimo registro en la tabla de simbolos. Es una suerte de tope y debe ser incrementado al guardar el siguiente en la tabla.
extern int varADeclarar1;
extern int cantVarsADeclarar; // Refiere a la cantidad de variables declaradas en el bloque del programador
extern int tipoDatoADeclarar; // Maneja / guarda los valores CONSTANTES que refieren a los tipos de datos posibles que puede definir el programador

#endif // PRIMITIVAS_H_INCLUDED