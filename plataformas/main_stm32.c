#include "stm32f1xx_hal.h"
#include "plataforma/drivers_setup.h"
#include "casos_de_uso/casos_de_uso.h"

int main(void) {
  HAL_Init();
  
  __HAL_RCC_GPIOB_CLK_ENABLE();  
  
  GPIO_InitTypeDef GPIO_InitStruct;
  
  // SETUP LEDS
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // SETUP BOTÃO
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;  
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  setup_driver_LedDeEstado();
  
  static char botao_acionado = 0;

  while (1) {
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) { // TODO: MELHORAR ESSA IMPLEMENTAÇÃO DEVIDO AO DEBOUNCE FÍSICO
      if (!botao_acionado) {
        alterar_estado_ligado();
        botao_acionado = 1;
      }
    }
    else
      botao_acionado = 0;    
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
}

void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}