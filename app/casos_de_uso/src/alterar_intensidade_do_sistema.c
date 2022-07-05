#include "app/casos_de_uso/casos_de_uso.h"
#include "app/elementos/LedBarGraph.h"

#define PORCENTAGEM_MAX 80

// EXEMPLO DE UM CASO DE USO
void alterar_intensidade_do_sistema(char porcentagem) {
  // EXEMPLO DE VALIDAÇÃO DE REQUISIÇÃO EXTERNA
  static char porcentagem_anterior = 0;
  if (porcentagem_anterior == porcentagem)
    return;
  porcentagem_anterior = porcentagem;  
  
  // ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSA INFORMAÇÃO
  led_bargraph.alterar_intensidade(porcentagem);
}