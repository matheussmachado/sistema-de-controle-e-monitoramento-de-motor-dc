#ifndef LED_DE_ESTADO_H
#define LED_DE_ESTADO_H

struct LedDeEstado {
  void (*alterar_estado)(void);
} led_de_estado;

typedef void (*IDriverLedDeEstado)(void);

void LedDeEstado_set_driver(IDriverLedDeEstado driver);

#endif