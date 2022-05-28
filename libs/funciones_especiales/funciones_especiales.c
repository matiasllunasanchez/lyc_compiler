#include "funciones_especiales.h"
#include "../tercetos/tercetos.h"

void poner_salto_hacia_fin_between(int idx_terceto_falso,int idx_salto_between, int idx_between, int idx_salto_a_fin_between_cota_inf, int idx_salto_a_fin_between_cota_sup) {
	// Modifica los tercetos que saltan por falso del between para que vayan a la linea 477 directamente
	modificar_terceto(idx_salto_between, PARTE_B, idx_between);
	modificar_terceto(idx_salto_a_fin_between_cota_inf, PARTE_C, idx_terceto_falso); // Branch que salta al flow final del between debido a error en comparar contra la cota inferior
	modificar_terceto(idx_salto_a_fin_between_cota_sup, PARTE_C, idx_terceto_falso); // Branch que salta al flow final del between debido a error en comparar contra la cota superior
}
