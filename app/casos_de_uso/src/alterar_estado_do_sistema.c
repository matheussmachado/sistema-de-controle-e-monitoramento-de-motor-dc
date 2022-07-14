#include <stdbool.h>
#include "casos_de_uso/casos_de_uso.h"
#include "elementos/LedDeEstado.h"
#include "elementos/Botoes.h"

bool ainda_acionado = false;	
void alterar_estado_ligado(void);

void alterar_estado_ligado_caso_botao_acionado(void) {
	if (botoes.acionados(BOTAO_DE_ESTADO)) {
    if (ainda_acionado == false) {
      alterar_estado_ligado();
      ainda_acionado = true;
  	}
	}
	else
		ainda_acionado = false;
}


void alterar_estado_ligado(void) {
	// ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSE EVENTO
	led_de_estado.alterar_estado();
}