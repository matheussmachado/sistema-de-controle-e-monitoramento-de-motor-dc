#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Potenciometro.h"

static char percentual(void) {
  ADCSRA |= (1<<ADSC);
  while (ADCSRA & (1<<ADSC));

  return (CEM_PORCENTO*(ADC>>1))/511; // 511: RESOLUÇÃO VIÁVEL -> DEVE SER TRATADO AQUI
}

void setup_driver_Potenciometro(void) {
  Potenciometro_set_driver(percentual);
}