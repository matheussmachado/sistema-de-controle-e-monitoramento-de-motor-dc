#include "elementos/Botoes.h"

void BotaoDeOperacao_set_driver(IDriverBotao driver) {
  botao_de_operacao.esta_acionado = driver;
}

void BotaoLimitador_set_driver(IDriverBotao driver) {
  botao_limitador.esta_acionado = driver;
}

void BotaoInversor_set_driver(IDriverBotao driver) {
  botao_inversor.esta_acionado = driver;
}
