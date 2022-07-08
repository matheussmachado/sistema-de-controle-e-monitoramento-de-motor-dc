#include "elementos/BotaoLimitador.h"

static IDriverBotaoLimitador _driver;

void BotaoLimitador_init_driver(IDriverBotaoLimitador driver) {
  _driver = driver;
}

bool esta_acionado(void) {
  return (_driver.esta_acionado());
}

struct BotaoLimitador botao_limitador = {
  .esta_acionado = esta_acionado
};