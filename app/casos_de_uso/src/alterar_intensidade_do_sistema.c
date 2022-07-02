#include "app/casos_de_uso/casos_de_uso.h"
#include "app/elementos/LedsDeIntensidade.h"

void alterar_intensidade_do_sistema(char porcentagem) {
  leds_de_intensidade.alterar_intensidade(porcentagem);
}