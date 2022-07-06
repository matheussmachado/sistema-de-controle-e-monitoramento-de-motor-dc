// EXEMPLO DE IMPLEMENTAÇÃO

#include <avr/io.h>
#include <avr/interrupt.h>
#include "app/casos_de_uso/casos_de_uso.h"

#define CEM_PORCENTO 100

static char botao_acionado = 0;
static char porcentagem_potenciometro = 0;

void executar_programa(void) {
  if (!(PINB & (1 << 1))) { // TODO: MELHORAR ESSA IMPLEMENTAÇÃO DEVIDO AO DEBOUNCE FÍSICO
    if (!botao_acionado) {
      alterar_estado_ligado();
      botao_acionado = 1;
    }
  }
  else
    botao_acionado = 0;
  
  ADCSRA |= (1<<ADSC);
  while (ADCSRA & (1<<ADSC));

  porcentagem_potenciometro = (CEM_PORCENTO*(ADC>>1))/511; // 511: RESOLUÇÃO VIÁVEL
  // EXEMPLO DE REQUISIÇÃO FEITA PELA IMPLEMENTAÇÃO AO SISTEMA
  alterar_intensidade_do_sistema(porcentagem_potenciometro);
}