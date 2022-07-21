#include <Arduino.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Leds.h"

static void led_de_operacao_ligar(void) {
  digitalWrite(8, HIGH);
}

static void led_de_operacao_desligar(void) {
  digitalWrite(8, LOW);
}

static void leds_de_sentido_driver(void) {
  digitalWrite(0, !digitalRead(0));
  digitalWrite(1, !digitalRead(1));
}

void setup_driver_Leds(void) {  
  IDriverLed driver = {
    .ligar = led_de_operacao_ligar,
    .desligar = led_de_operacao_desligar
  };
  LedDeOperacao_set_driver(driver);

  LedsDeSentido_set_driver(leds_de_sentido_driver);
}