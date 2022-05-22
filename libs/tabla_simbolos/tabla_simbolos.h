#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define ENUM_INTEGER 1
#define ENUM_FLOAT 2
#define ENUM_STRING 3
#define ENUM_CTE_INTEGER 4
#define ENUM_CTE_FLOAT 5
#define ENUM_CTE_STRING 6

#define TAM_TABLA 500
#define TAM_NOMBRE 30

int agregarVarATabla(char* nombre);
void agregarTiposDatosATabla(void);
int agregarCteStringATabla(char* nombre);
int agregarCteIntATabla(int valor);
int agregarCteRealATabla(float valor);
int buscarEnTabla(char * name);
void escribirNombreEnTabla(char* nombre, int pos);
void chequearVarEnTabla(char* nombre);
void guardarTabla(void);

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
///OTRAS FUNCIONES

#endif // PRIMITIVAS_H_INCLUDED