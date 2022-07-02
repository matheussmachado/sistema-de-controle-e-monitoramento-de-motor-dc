#include <avr/io.h>
#include <avr/interrupt.h>
#include "app/plataforma/HAL/drivers_setup.h"

void setup_plataforma(void) {  
  DDRD = 0b11111111;
  DDRB = 0b00000001;
  PORTB = 0b00000010;
  PORTD |= (1<<PD7);

  ADMUX = (1 << REFS0);
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1  << ADPS0);

  TCCR0B = 0b00000001; //TC0 com prescaler de 1
  TIMSK0 = 0b00000001; //habilita a interrupção do TC0
  TCNT0 = 96; //Inicia a contagem em 96 para gerar a interrupção a cada 10us
  sei();

  setup_driver_LedDeEstado();
  setup_driver_LedsDeIntensidade();
}
