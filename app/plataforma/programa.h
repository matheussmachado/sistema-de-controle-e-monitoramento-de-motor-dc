#include <avr/io.h>
#include "app/casos_de_uso/casos_de_uso.h"

#define CEM_PORCENTO 100

static char botao_acionado = 0;


void executar_programa(void) {
  if (!(PINB & (1 << 1))) {
    if (!botao_acionado) {
      alterar_estado_ligado();
      botao_acionado = 1;
    }
  }
  else
    botao_acionado = 0;
  
  ADCSRA |= (1<<ADSC);
  while (ADCSRA & (1<<ADSC));

  char porcentagem_potenciometro = (ADC>>1)*100/511;
  alterar_intensidade_do_sistema(porcentagem_potenciometro);
}