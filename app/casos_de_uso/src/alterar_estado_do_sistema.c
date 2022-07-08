#include "casos_de_uso/casos_de_uso.h"
#include "elementos/LedDeEstado.h"

void alterar_estado_ligado(void) {
	// ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSE EVENTO
	led_de_estado.alterar_estado();
}