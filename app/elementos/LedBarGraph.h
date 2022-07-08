#ifndef LED_BAR_GRAPH_H
#define LED_BAR_GRAPH_H

#include "elementos/drivers_interface/drivers_interface.h"

#define QTD_LEDS 5 // MANTER QTD DIVISOR DE 100

// EXEMPLO DE ELEMENTO
struct LedBarGraph {
  void (*alterar_intensidade)(char porcentagem);
} led_bargraph;

void LedBarGraph_init_driver(IDriverLedBarGraph driver);

#endif