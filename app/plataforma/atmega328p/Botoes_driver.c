#include <avr/io.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Botoes.h"

static int botoes_v[NUM_BOTOES];

static bool acionados(botoes_t botao) {
  return (~(PINB & botoes_v[botao]) & botoes_v[botao]);
}

static IDriverBotoes driver = {
  .acionados = acionados
};

void setup_driver_BotaoDeEstado(void) {
  botoes_v[BOTAO_DE_ESTADO] = (1<<PB1);
  botoes_v[BOTAO_LIMITADOR] = (1<<PB2);

  Botoes_init_driver(driver);
}