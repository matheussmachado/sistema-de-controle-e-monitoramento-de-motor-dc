#include "stm32f1xx_hal.h"
#include "plataforma/drivers_setup.h"
#include "elementos/Botoes.h"

static bool botao_de_operacao_driver(void) {
  return (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == GPIO_PIN_SET));
}

void setup_driver_Botoes(void) {
  BotaoDeOperacao_set_driver(botao_de_operacao_driver);
}