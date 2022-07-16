#ifndef BOTAO_DE_ESTADO_H
#define BOTAO_DE_ESTADO_H

#include <stdbool.h>

typedef struct {
  bool (*esta_acionado)(void);
} Botao;

Botao botao_de_estado;
Botao botao_limitador;

typedef bool (*IDriverBotao)(void);

void BotaoDeEstado_set_driver(IDriverBotao driver);
void BotaoLimitador_set_driver(IDriverBotao driver);

#endif