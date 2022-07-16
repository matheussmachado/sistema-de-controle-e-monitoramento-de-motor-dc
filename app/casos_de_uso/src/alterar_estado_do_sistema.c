#include <stdbool.h>
#include "casos_de_uso/casos_de_uso.h"
//#include "elementos/LedDeEstado.h"
#include "elementos/Leds.h"
#include "elementos/Botoes.h"
#include "elementos/Motor.h"

bool previamente_acionado = false;	
void alterar_estado_ligado(void);
void iniciar_operacao_do_sistema(void);
void finalizar_operacao_do_sistema(void);

void atualizar_estado_de_operacao_via_botao_de_operacao(void) {
	if (botao_de_operacao.esta_acionado())
		iniciar_operacao_do_sistema();
	else
	  finalizar_operacao_do_sistema();
	
	// FUNÇÃO EXISTENTE PARA ESSA ABORDAGEM DE CHECAGEM COM O
	// DE BOTÃO DE ESTADO QUE PODERIA SER SUBSTITUIDA POR INTERRUPÇÃO
	if (botao_inversor.esta_acionado()) {
		if (!previamente_acionado) {
			leds_de_sentido.alterar_sentido();
			//motor.alterar_sentido();
			previamente_acionado = true;
		}
	}
	else
		previamente_acionado = false;	
}

void iniciar_operacao_do_sistema(void) {
	motor.ligar();
	led_de_operacao.ligar();	
}

void finalizar_operacao_do_sistema(void) {
	motor.desligar();
	led_de_operacao.desligar();	
}
