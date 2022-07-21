// EXEMPLO DE IMPLEMENTAÇÃO

#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "plataforma/drivers_setup.h"
#include "casos_de_uso/casos_de_uso.h"

ISR(PCINT0_vect) {
  if (!(PINB & (1<<PB5)))
    alterar_sentido_do_sistema_quando_botao_inversor_acionado();
}

int main(void) {	
  DDRB = 0b11011111;
  PORTB = 0b01100000;
	DDRD = 0b00111111;
  PORTD = 0b11100000;

  TCCR0B = 0b00000001; //TC0 com prescaler de 64
  TIMSK0 = 0b00000001; //habilita a interrupção do TC0
  TCNT0 = 96; //Inicia a contagem em 96 para gerar a interrupção a cada 10us

  TCCR1A = (1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11) | (1<<WGM10); // Fast PWM 10-bits com saída não invertida
  TCCR1B = (1<<WGM12) | (1<<CS11) | (1<<CS10); // Prescaler de 64  

  ADMUX = (1 << REFS0);
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1  << ADPS0);

  PCICR = (1<<PCIE0);
  PCMSK0 = (1<<PCINT5);

  sei();
  
  setup_driver_LedBarGraph();
  setup_driver_Botoes();
  setup_driver_Potenciometro();
  setup_driver_Leds();
  setup_driver_Motor();

	while (1) {
    atualizar_estado_de_operacao_via_botao_de_operacao();
    atualizar_intensidade_do_sistema_via_potenciometro();
	}
	return 0;
}