#include <Arduino.h>
#include "plataforma/drivers_setup.h"
#include "elementos/LedDeEstado.h"

static void alterar_estado(void) {
	digitalWrite(8, !digitalRead(8));
}

static IDriverLedDeEstado driver = {
  .alterar_estado = alterar_estado
};

void setup_driver_LedDeEstado(void) {  
  LedDeEstado_init_driver(driver);
}