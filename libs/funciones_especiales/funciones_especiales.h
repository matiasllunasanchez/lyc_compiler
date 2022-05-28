#ifndef funciones_especiales_h
#define funciones_especiales_h
#include "../sentencias_control/sentencias_control.h"


// Agrega indices a los tercetos que branchean / saltan al final de la sentencia between. Al flow final.
// Tambien rellena el salto por falso general
void poner_salto_hacia_fin_between(int idx_terceto_falso, int idx_salto_between, int idx_between, int idx_salto_a_fin_between_cota_inf, int idx_salto_a_fin_between_cota_sup);

//Saltos y pila de between
extern int ind_salto_inlist;
extern int ind_inlist;
extern int ind_inlist_a;
extern int between_vector[MAX_ANIDAMIENTOS];
extern int contador_inlist;
#endif
