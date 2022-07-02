#include "app/elementos/LedsDeIntensidade.h"

static void alterar_intensidade(char porcentagem) {
  char intensidade_atual = porcentagem*5/100;

  for (int i = 0; i < QTD_LEDS; i++) {
    if (i < intensidade_atual)
      // EXEMPLO DA UTILIZAÇÃO DA INTERFACE DE UM DRIVER
      driver_leds_de_intensidade.ligar_led(i);
    else
      driver_leds_de_intensidade.desligar_led(i);
  }
}

//EXEMPLO DE INICALIZAÇÃO DE UM ELEMENTO
struct LedsDeIntensidade leds_de_intensidade = {
  .alterar_intensidade = alterar_intensidade
};