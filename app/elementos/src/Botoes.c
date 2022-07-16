#include "elementos/Botoes.h"

void BotaoDeEstado_set_driver(IDriverBotao driver) {
  botao_de_estado.esta_acionado = driver;
}

void BotaoLimitador_set_driver(IDriverBotao driver) {
  botao_limitador.esta_acionado = driver;
}
