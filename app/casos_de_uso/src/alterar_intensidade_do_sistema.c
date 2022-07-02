#include "app/casos_de_uso/casos_de_uso.h"
#include "app/elementos/LedsDeIntensidade.h"

// EXEMPLO DE UM CASO DE USO
void alterar_intensidade_do_sistema(char porcentagem) {
  leds_de_intensidade.alterar_intensidade(porcentagem);
}