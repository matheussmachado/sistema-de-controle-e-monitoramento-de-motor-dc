#ifndef BOTAO_LIMITADOR_H
#define BOTAO_LIMITADOR_H

#include <stdbool.h>
#include "app/elementos/drivers_interface/drivers_interface.h"

struct BotaoLimitador {
  bool (*esta_acionado)(void);
} botao_limitador;

void BotaoLimitador_init_driver(IDriverBotaoLimitador driver);

#endif
