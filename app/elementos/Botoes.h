#ifndef BOTAO_DE_ESTADO_H
#define BOTAO_DE_ESTADO_H

#include <stdbool.h>

typedef struct {
  bool (*esta_acionado)(void);
} Botao;

Botao botao_de_operacao;
Botao botao_limitador;
//Botao botao_inversor;

typedef bool (*IDriverBotao)(void);

void BotaoDeOperacao_set_driver(IDriverBotao driver);
void BotaoLimitador_set_driver(IDriverBotao driver);
//void BotaoInversor_set_driver(IDriverBotao driver);

#endif