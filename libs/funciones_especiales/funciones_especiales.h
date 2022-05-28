#ifndef funciones_especiales_h
#define funciones_especiales_h
#include "../sentencias_control/sentencias_control.h"


// BETWEEN
// Agrega indices a los tercetos que branchean / saltan al final de la sentencia between. Al flow final.
// Tambien rellena el salto por falso general
void poner_salto_hacia_fin_between(int idx_terceto_falso, int idx_salto_between, int idx_between, int idx_salto_a_fin_between_cota_inf, int idx_salto_a_fin_between_cota_sup);

// TAKE

#endif
