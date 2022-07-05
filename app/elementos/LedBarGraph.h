#define QTD_LEDS 5 // MANTER QTD DIVISOR DE 100

// EXEMPLO DE ELEMENTO
struct LedBarGraph {
  void (*alterar_intensidade)(char porcentagem);
} led_bargraph;

// EXEMPLO DE INTERFACE DE UM DRIVER
struct IDriveLedBarGraph {
  void (*ligar_led)(int led);
  void (*desligar_led)(int led);
  void (*regular_intensidade_do_led)(int led, char nivel_de_intensidade);
} driver_led_bargraph;