#include <avr/io.h>
#include "app/plataforma/HAL/drivers_setup.h"

void setup_plataforma(void) {  
  DDRD = (1<<PD7) |(1<<PD4) | (1<<PD3) | (1<<PD2) | (1<<PD1) | (1<<PD0);
  DDRB = (1<<PB0);
  PORTB = (1<<PB1);

  ADMUX = (1 << REFS0);
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1  << ADPS0);

  setup_driver_LedDeEstado();  
}
