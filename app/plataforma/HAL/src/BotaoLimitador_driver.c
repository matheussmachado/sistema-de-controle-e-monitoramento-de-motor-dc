#include <avr/io.h>
#include "app/plataforma/HAL/drivers_setup.h"
#include "app/elementos/BotaoLimitador.h"

static bool esta_acionado(void) {
  if (!(PINB & (1<<PB2)))
    return true;
  return false;
}

static IDriverBotaoLimitador driver = {
  .esta_acionado = esta_acionado
};

void setup_driver_BotaoLimitador(void) {
  BotaoLimitador_init_driver(driver);
}