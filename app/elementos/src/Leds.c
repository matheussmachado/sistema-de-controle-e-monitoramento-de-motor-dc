#include "elementos/Leds.h"

// O DRIVER É INJETADO POIS ASSIM ELE FICA ENCAPSULADO NO ESCOPO DO ELEMENTO,
// UMA VEZ QUE O ELEMENTO ACESSA O DRIVER ATRAVÉS DE UMA INTERFACE E O CASO
// DE USO ACESSA APENAS O ELEMENTO, NÃO O DRIVER DIRETAMENTE

void LedDeOperacao_set_driver(IDriverLed driver) {
  led_de_operacao.ligar = driver.ligar;
  led_de_operacao.desligar = driver.desligar;
}

void LedsDeSentido_set_driver(IDriverLedsDeSentido driver) {
  leds_de_sentido.alterar_sentido = driver;
}