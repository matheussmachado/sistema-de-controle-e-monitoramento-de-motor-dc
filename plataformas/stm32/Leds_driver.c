#include "stm32f1xx_hal.h"
#include "plataforma/drivers_setup.h"
#include "elementos/Leds.h"

static void led_de_operacao_ligar(void) {
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

static void led_de_operacao_desligar(void) {
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
}

static void leds_de_sentido_driver(void) {
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
}

void setup_driver_Leds(void) {  
  IDriverLed driver = {
    .ligar = led_de_operacao_ligar,
    .desligar = led_de_operacao_desligar
  };
  LedDeOperacao_set_driver(driver);

  LedsDeSentido_set_driver(leds_de_sentido_driver);
}