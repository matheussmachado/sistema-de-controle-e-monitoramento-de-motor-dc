#include <avr/io.h>
#include "app/casos_de_uso/casos_de_uso.h"

volatile static char botao_acionado = 0;

void executar_programa(void) {
  if (!(PINB & (1 << 1))) {
    if (!botao_acionado) {
      alterar_estado_ligado();
      botao_acionado = 1;
    }
  }
  else
    botao_acionado = 0;  
}