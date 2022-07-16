#include <stdbool.h>
#include "casos_de_uso/casos_de_uso.h"
#include "elementos/LedDeEstado.h"
#include "elementos/Botoes.h"

bool previamente_acionado = false;	
void alterar_estado_ligado(void);

void alterar_estado_ligado_via_botao_de_estado(void) {
	// FUNÇÃO EXISTENTE PARA ESSA ABORDAGEM DE CHECAGEM COM O
	// DE BOTÃO DE ESTADO AO INVÉS DE UTILIZAR POR INTERRUPÇÃO
	if (botao_de_estado.esta_acionado()) {
    if (previamente_acionado == false) {
      alterar_estado_ligado();
      previamente_acionado = true;
  	}
	}
	else
		previamente_acionado = false;
}

void alterar_estado_ligado(void) {
	// ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSE EVENTO
	led_de_estado.alterar_estado();
}