#include "app/casos_de_uso/casos_de_uso.h"
#include "app/elementos/LedDeEstado.h"

void alterar_estado_ligado(void) {	
	led_de_estado.alterar_estado();
}