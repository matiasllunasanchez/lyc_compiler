#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define Integer 1
#define Real 2
#define String 3
#define CteInt 4
#define CteReal 5
#define CteString 6

#define TAM_TABLA 500
#define TAM_NOMBRE 30

void agregarVarATabla(char* nombre);
void agregarTiposDatosATabla(void);
void agregarCteStringATabla(char* nombre);
void agregarCteIntATabla(int valor);
void agregarCteRealATabla(float valor);
void chequearVarEnTabla(char* nombre);
int buscarEnTabla(char * name);
void escribirNombreEnTabla(char* nombre, int pos);
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