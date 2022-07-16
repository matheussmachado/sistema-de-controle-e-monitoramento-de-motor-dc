#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Motor.h"

static void ligar(sentido_t sentido) {
  if (sentido == HORARIO) {
    PORTB &= ~(1<<PB1);
    PORTB |= (1<<PB2);
    PORTB |= (1<<PB3);
    PORTB &= ~(1<<PB4);
  }
  else {
    PORTB |= (1<<PB1);
    PORTB &= ~(1<<PB2);
    PORTB &= ~(1<<PB3);
    PORTB |= (1<<PB4);
  }
}

static void desligar(void) {
  PORTB |= (1<<PB1);
  PORTB |= (1<<PB2);
  PORTB &= ~(1<<PB3);
  PORTB &= ~(1<<PB4);
}

void setup_driver_Motor(void) {
  IDriverMotor driver = {
    .ligar = ligar,
    .desligar = desligar
  };

  Motor_set_driver(driver);
}