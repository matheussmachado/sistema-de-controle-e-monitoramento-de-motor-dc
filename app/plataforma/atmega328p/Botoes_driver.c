#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Botoes.h"

static bool botao_de_estado_func(void) {
  return (!(PINB & (1<<PB1)));
}

static bool botao_limitador_func(void) {
  return (!(PINB & (1<<PB2)));
}

void setup_driver_Botoes(void) {
  BotaoDeEstado_set_driver(botao_de_estado_func);
  BotaoLimitador_set_driver(botao_limitador_func);
}