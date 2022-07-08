#include "casos_de_uso/casos_de_uso.h"
#include "elementos/LedBarGraph.h"
#include "elementos/BotaoLimitador.h"

#define PORCENTAGEM_MAX 50

// EXEMPLO DE UM CASO DE USO
void alterar_intensidade_do_sistema(char porcentagem) {  
  // EXEMPLO DE RESPOSTA INTERNA DO SITEMA -> TRATAMENTO DE REQUISIÇÃO EXTERNA
  if (porcentagem >= PORCENTAGEM_MAX)    
    if (botao_limitador.esta_acionado()) // EXEMPLO DE REQUISIÇÃO DO SISTEMA AO EXTERIOR
      porcentagem = PORCENTAGEM_MAX;
  
  // ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSA INFORMAÇÃO
  led_bargraph.alterar_intensidade(porcentagem);
}