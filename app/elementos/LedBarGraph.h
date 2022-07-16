#ifndef LED_BAR_GRAPH_H
#define LED_BAR_GRAPH_H
#define QTD_LEDS 5 // MANTER QTD DIVISOR DE 100

// EXEMPLO DE ELEMENTO
struct LedBarGraph {
  void (*alterar_intensidade)(char porcentagem);
} led_bargraph;

// EXEMPLO DE INTERFACE DE UM DRIVER A SER USADO PELO ELEMENTO
typedef struct {
  void (*ligar_led)(int led);
  void (*desligar_led)(int led);
  void (*regular_intensidade_do_led)(int led, char nivel_de_intensidade);
} IDriverLedBarGraph;

// EXEMPLO DE INICIALIZADOR DE DRIVER
void LedBarGraph_set_driver(IDriverLedBarGraph driver);

#endif