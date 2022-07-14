// EXEMPLO DE IMPLEMENTAÇÃO

#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "plataforma/drivers_setup.h"
#include "casos_de_uso/casos_de_uso.h"

#define CEM_PORCENTO 100

static char porcentagem_potenciometro = 0;

int main(void) {	
	DDRD = 0b11111111;
  DDRB = 0b00000001;
  PORTB = 0b00000110;  

  TCCR0B = 0b00000001; //TC0 com prescaler de 64
  TIMSK0 = 0b00000001; //habilita a interrupção do TC0
  TCNT0 = 96; //Inicia a contagem em 96 para gerar a interrupção a cada 10us

  ADMUX = (1 << REFS0);
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1  << ADPS0);

  UBRR0 = 103;
  UCSR0B =  (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);
  UCSR0C =  (1<<UCSZ01) | (1<<UCSZ00);

  sei();
  
  setup_driver_LedDeEstado();
  setup_driver_LedsDeIntensidade();
  setup_driver_BotaoDeEstado();

	while (1) {     
    alterar_estado_ligado_caso_botao_acionado();
    
    ADCSRA |= (1<<ADSC);
    while (ADCSRA & (1<<ADSC));

    porcentagem_potenciometro = (CEM_PORCENTO*(ADC>>1))/511; // 511: RESOLUÇÃO VIÁVEL
    // EXEMPLO DE REQUISIÇÃO FEITA PELA IMPLEMENTAÇÃO AO SISTEMA
    alterar_intensidade_do_sistema(porcentagem_potenciometro);
	}
	return 0;
}