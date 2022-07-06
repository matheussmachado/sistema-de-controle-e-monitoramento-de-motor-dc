#include "app/elementos/LedDeEstado.h"

static IDriverLedDeEstado _driver;

void LedDeEstado_init_driver(IDriverLedDeEstado driver) {
  _driver = driver;
}

static void alterar_estado(void) {
  _driver.alterar_estado();
}

struct LedDeEstado led_de_estado = {
  .alterar_estado = alterar_estado
};