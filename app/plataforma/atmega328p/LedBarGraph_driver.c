#include <avr/io.h>
#include <avr/interrupt.h>
#include "plataforma/drivers_setup.h"
#include "elementos/LedBarGraph.h"

#define CEM_PORCENTO 100
#define MIN_CICLO_ATIVO 10 // VALOR MÍNIMO PARA MELHOR FUNCIONAMENTO

volatile static char leds_pin[QTD_LEDS] = {PD0, PD1, PD2, PD3, PD4};
volatile static int led_regulado = 0;
volatile static char progressao_pwm_led = 0;
volatile static char ciclo_ativo_pwm_led = 0;

ISR(TIMER0_OVF_vect) {
  // IMPLEMENTAÇÃO DE PWM POR SOFTWARE. ESSA OPERAÇÃO DE BAIXO NÍVEL PODE SER   
  // IMPLEMENTADA DE DIFERENTES FORMAS EM UMA PLATAFORMA (INCLUSIVE VIA HARDWARE).
  // OS POSSÍVEIS PROBLEMAS, COMO RESOLUÇÃO, QUE NECESSITAM DE UM TRATAMENTO ESPECÍFICO     
  // DA PLATAFORMA INDICAM QUE ESTE TRECHO DE CÓDIGO NECESSITA ESTAR ISOLADO DO SISTEMA, 
  // PORTANTO AQUI.

  TCNT0 = 96;
  progressao_pwm_led++;

  if (progressao_pwm_led == CEM_PORCENTO) {
    progressao_pwm_led = 0;
    if (ciclo_ativo_pwm_led > MIN_CICLO_ATIVO) // TRATAMENTO DEVIDO A RESOLUÇÃO
      PORTD |= (1<<leds_pin[led_regulado]);
  }
  else if (progressao_pwm_led == ciclo_ativo_pwm_led)
    PORTD &= ~(1<<leds_pin[led_regulado]);
}

static void ligar_led(int led) {
  PORTD |= (1<<leds_pin[led-1]);
}

static void desligar_led(int led) {
  PORTD &= ~(1<<leds_pin[led-1]);
}

static void regular_intensidade_do_led(int led, char nivel_de_intensidade) {
  if (led >= QTD_LEDS)
    led_regulado = QTD_LEDS - 1;
  else
    led_regulado = led - 1;
  ciclo_ativo_pwm_led = nivel_de_intensidade;  
}

// EXEMPLO DE IMPLEMENTAÇÃO DA INTERFACE DE UM DRIVER
static IDriverLedBarGraph driver = {
  .ligar_led = ligar_led,
  .desligar_led = desligar_led,
  .regular_intensidade_do_led = regular_intensidade_do_led
};

void setup_driver_LedsDeIntensidade(void) {
  // EXEMPLO DE CONEXÃO ENTRE A INTERFACE DE DRIVER IMPLEMENTADA E O ELEMENTO QUE A UTILIZA
  LedBarGraph_init_driver(driver);
}