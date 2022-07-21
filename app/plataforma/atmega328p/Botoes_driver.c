#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Botoes.h"

static bool botao_de_operacao_driver(void) {
  return (!(PIND & (1<<PD6)));
}

static bool botao_limitador_driver(void) {
  return (!(PIND & (1<<PD7)));
}

// static bool botao_inversor_driver(void) {
//   return (!(PINB & (1<<PB5)));
// }

void setup_driver_Botoes(void) {
  BotaoDeOperacao_set_driver(botao_de_operacao_driver);
  BotaoLimitador_set_driver(botao_limitador_driver);
  //BotaoInversor_set_driver(botao_inversor_driver);
}