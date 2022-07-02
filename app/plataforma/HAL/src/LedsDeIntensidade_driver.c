#include <avr/io.h>
#include "app/plataforma/HAL/drivers_setup.h"
#include "app/elementos/LedsDeIntensidade.h"

char leds_pin[QTD_LEDS] = {PD0, PD1, PD2, PD3, PD4};

static void ligar_led(int led) {
  PORTD |= (1<<leds_pin[led]);
}

static void desligar_led(int led) {
  PORTD &= ~(1<<leds_pin[led]);
}

void setup_driver_LedsDeIntensidade(void) {
  // EXEMPLO DE IMPLEMENTAÇÃO DA INTERFACE DE UM DRIVER (COMUNICAÇÃO DO SISTEMA)
  driver_leds_de_intensidade.ligar_led = ligar_led;
  driver_leds_de_intensidade.desligar_led = desligar_led;
}
