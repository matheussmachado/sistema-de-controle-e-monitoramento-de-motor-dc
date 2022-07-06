#include "app/casos_de_uso/casos_de_uso.h"
#include "app/elementos/LedBarGraph.h"
#include "app/elementos/BotaoLimitador.h"

#define PORCENTAGEM_MAX 50

// EXEMPLO DE UM CASO DE USO
void alterar_intensidade_do_sistema(char porcentagem) {  
  // EXEMPLO DE VALIDAÇÃO DE REQUISIÇÃO EXTERNA AO SISTEMA
  if (porcentagem >= PORCENTAGEM_MAX)
    // EXEMPLO DE REQUISIÇÃO DO SISTEMA AO EXTERIOR
    if (botao_limitador.esta_acionado())
      porcentagem = PORCENTAGEM_MAX;
  
  // ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSA INFORMAÇÃO
  led_bargraph.alterar_intensidade(porcentagem);
}