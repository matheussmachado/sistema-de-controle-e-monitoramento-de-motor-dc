#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Leds.h"

static void led_de_operacao_ligar(void) {
  PORTB |= (1<<PB0);
}

static void led_de_operacao_desligar(void) {
  PORTB &= ~(1<<PB0);
}

static void leds_de_sentido_driver(void) {
  PORTB ^= (1<<PB6);
  PORTB ^= (1<<PB7);
}

void setup_driver_Leds(void) {  
  IDriverLed driver = {
    .ligar = led_de_operacao_ligar,
    .desligar = led_de_operacao_desligar
  };
  LedDeOperacao_set_driver(driver);

  LedsDeSentido_set_driver(leds_de_sentido_driver);
}