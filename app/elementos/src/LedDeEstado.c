#include "app/elementos/LedDeEstado.h"

static void alterar_estado(void) {
  driver_led_de_estado.alterar_estado();
}

struct LedDeEstado led_de_estado = {
  .alterar_estado = alterar_estado
};