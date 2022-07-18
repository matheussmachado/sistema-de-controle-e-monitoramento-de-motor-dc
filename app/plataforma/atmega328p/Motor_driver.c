#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Motor.h"

static unsigned int intensidade = 0;

static void ligar(sentido_t sentido) {
  if (sentido == HORARIO) {
    OCR1B = 1023 - intensidade; // VERIFICAR MELHOR ABORDAGEM E VERIFICAR OS REGISTRADORES PARA O PWM
    OCR1A = intensidade;
    OCR1B = 0;

    PORTB &= ~(1<<PB1);
    PORTB |= (1<<PB2);
    PORTB |= (1<<PB3);
    PORTB &= ~(1<<PB4);
  }
  else if (sentido == ANTI_HORARIO) {
    OCR1A = 1023 - intensidade;
    OCR1B = intensidade;
    OCR1A = 0;

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

static void alterar_intensidade(unsigned int percentual) {  
  intensidade = (unsigned int)((percentual)*(1023.0/100));
}

void setup_driver_Motor(void) {
  IDriverMotor driver = {
    .ligar = ligar,
    .desligar = desligar,
    .alterar_intensidade = alterar_intensidade
  };

  Motor_set_driver(driver);
}