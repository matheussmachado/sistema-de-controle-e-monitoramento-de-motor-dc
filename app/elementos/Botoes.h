#ifndef BOTAO_DE_ESTADO_H
#define BOTAO_DE_ESTADO_H

#include <stdbool.h>

// CASO HAJA MAIS SENSORES DE ESTADO -> FAZER ESTRUTURAS DESSA SEPARADAS 
// OU GENERALIZAR CASO POSSÍVEL

typedef enum BOTOES {
  BOTAO_DE_ESTADO, BOTAO_LIMITADOR, NUM_BOTOES
} botoes_t;

typedef struct {
  bool (*acionados)(botoes_t botoes);
} IDriverBotoes;

struct Botoes {
  bool (*acionados)(botoes_t botoes);
} botoes;

void Botoes_init_driver(IDriverBotoes driver);

#endif