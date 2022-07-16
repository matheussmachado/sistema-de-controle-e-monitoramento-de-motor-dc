#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/LedDeEstado.h"


static void alterar_estado(void) {
	PORTB ^= (1<<PB0);
}

void setup_driver_LedDeEstado(void) {  
  LedDeEstado_set_driver(alterar_estado);
}