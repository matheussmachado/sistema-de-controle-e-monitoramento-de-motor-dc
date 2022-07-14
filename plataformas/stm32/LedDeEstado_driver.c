#include "stm32f1xx_hal.h"
#include "plataforma/drivers_setup.h"
#include "elementos/LedDeEstado.h"

static void alterar_estado(void) {
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_15);
}

static IDriverLedDeEstado driver = {
  .alterar_estado = alterar_estado
};

void setup_driver_LedDeEstado(void) {  
  LedDeEstado_init_driver(driver);
}