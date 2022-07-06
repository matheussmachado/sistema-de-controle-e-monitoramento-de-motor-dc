#include <avr/io.h>
#include "app/plataforma/HAL/drivers_setup.h"
#include "app/elementos/LedDeEstado.h"


static void alterar_estado(void) {
	PORTB ^= (1<<PB0);
}

static IDriverLedDeEstado driver = {
  .alterar_estado = alterar_estado
};

void setup_driver_LedDeEstado(void) {  
  LedDeEstado_init_driver(driver);
}