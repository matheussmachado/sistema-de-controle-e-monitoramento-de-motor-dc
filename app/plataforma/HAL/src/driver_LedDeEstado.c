#include <avr/io.h>
#include "app/plataforma/HAL/drivers_setup.h"
#include "app/elementos/LedDeEstado.h"

static void alterar_estado(void) {
	PORTB ^= (1<<PB0);
}

// VIRAR MACRO OU INLINE?
void setup_driver_LedDeEstado(void) { 
  // EXEMPLO DE IMPLEMENTAÇÃO DE INTERFACE
  led_de_estado.alterar_estado = alterar_estado;
}
