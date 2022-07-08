#ifndef LED_DE_ESTADO_H
#define LED_DE_ESTADO_H

#include "elementos/drivers_interface/drivers_interface.h"

struct LedDeEstado {
  void (*alterar_estado)(void);
} led_de_estado;

void LedDeEstado_init_driver(IDriverLedDeEstado driver);

#endif