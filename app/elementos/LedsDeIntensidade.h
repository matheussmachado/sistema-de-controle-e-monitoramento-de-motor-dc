#define QTD_LEDS 5

// EXEMPLO DE ELEMENTO
struct LedsDeIntensidade {
  void (*alterar_intensidade)(char porcentagem);
} leds_de_intensidade;

// EXEMPLO DE INTERFACE DE UM DRIVER
struct IDriveLedsDeIntensidade {
  void (*ligar_led)(int led);
  void (*desligar_led)(int led);
} driver_leds_de_intensidade;