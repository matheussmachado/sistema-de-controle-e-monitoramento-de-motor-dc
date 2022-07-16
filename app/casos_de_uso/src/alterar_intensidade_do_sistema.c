// EXEMPLO DE UM CASO DE USO

#include "casos_de_uso/casos_de_uso.h"
#include "elementos/LedBarGraph.h"
#include "elementos/Botoes.h"
#include "elementos/Potenciometro.h"

#define PERCENTUAL_MAX 50

void alterar_intensidade_do_sistema(char percentual);

// API DE ENTRADA ATUAL
void atualizar_intensidade_do_sistema_via_potenciometro(void) {
  /*ESSA FUNÇÃO EXISTE POIS ESSE VALOR DO POTÊNCIOMETRO
    PODE SER OBTIDO ATRAVÉS DE INTERRUPÇÃO. NESSE CASO
    A API DE ENTRADA SERÁ A FUNÇÃO ABAIXO QUE RECEBERÁ
    O VALOR DO AD VIA INTERRUPÇÃO*/
  alterar_intensidade_do_sistema(potenciometro.percentual());
}

void alterar_intensidade_do_sistema(char percentual) {
  // EXEMPLO DE RESPOSTA INTERNA DO SISTEMA -> TRATAMENTO DE REQUISIÇÃO EXTERNA
  if (percentual >= PERCENTUAL_MAX)
    if (botao_limitador.esta_acionado())
      percentual = PERCENTUAL_MAX;
  
  // ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSA INFORMAÇÃO
  led_bargraph.alterar_intensidade(percentual);
}