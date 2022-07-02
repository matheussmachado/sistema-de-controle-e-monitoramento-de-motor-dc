#include "app/elementos/LedsDeIntensidade.h"

static void alterar_intensidade(char porcentagem) {
  char nivel_de_intensidade = (QTD_LEDS*porcentagem)/100;

  // EXEMPLO DE UMA REGRA IMPLEMENTADA POR UM ELEMENTO
  for (int i = 0; i < QTD_LEDS; i++) {
    if (i < nivel_de_intensidade)
      // EXEMPLO DA UTILIZAÇÃO DA INTERFACE DE UM DRIVER (RESPOSTA DO SISTEMA)
      driver_leds_de_intensidade.ligar_led(i);
    else
      driver_leds_de_intensidade.desligar_led(i);
  }
}

//EXEMPLO DE INICALIZAÇÃO DE UM ELEMENTO
struct LedsDeIntensidade leds_de_intensidade = {
  .alterar_intensidade = alterar_intensidade
};