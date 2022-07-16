#include "elementos/LedDeEstado.h"

void LedDeEstado_set_driver(IDriverLedDeEstado driver) {
  // O DRIVER É INJETADO POIS ASSIM ELE FICA ENCAPSULADO NO ESCOPO DO ELEMENTO,
  // UMA VEZ QUE O O ELEMENTO ACESSA O DRIVER ATRAVÉS DE UMA INTERFACE E O CASO
  // DE USO ACESSA APENAS O ELEMENTO, NÃO O DRIVER DIRETAMENTE
  led_de_estado.alterar_estado = driver;
}
