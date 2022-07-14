#include "elementos/Botoes.h"

static IDriverBotoes _driver;

void Botoes_init_driver(IDriverBotoes driver) {
  _driver = driver;
}

static bool acionados(botoes_t botao) {
  return _driver.acionados(botao);
}

struct Botoes botoes = {
  .acionados = acionados
};