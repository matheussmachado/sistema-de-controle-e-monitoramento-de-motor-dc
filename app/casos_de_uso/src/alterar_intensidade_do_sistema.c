#include "casos_de_uso/casos_de_uso.h"
#include "elementos/LedBarGraph.h"
#include "elementos/Botoes.h"

#define PORCENTAGEM_MAX 50

// EXEMPLO DE UM CASO DE USO
void alterar_intensidade_do_sistema(char porcentagem) {  
  // EXEMPLO DE RESPOSTA INTERNA DO SISTEMA -> TRATAMENTO DE REQUISIÇÃO EXTERNA
  if (porcentagem >= PORCENTAGEM_MAX)
    if (botoes.acionados(BOTAO_LIMITADOR))
      porcentagem = PORCENTAGEM_MAX;
  
  // ABAIXO VÃO CHAMADAS PARA DISPOSITIVOS QUE PRECISAM SER ATUALIZADOS COM ESSA INFORMAÇÃO
  led_bargraph.alterar_intensidade(porcentagem);
}