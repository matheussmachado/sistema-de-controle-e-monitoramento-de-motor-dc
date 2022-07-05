// EXEMPLO DE UMA REGRA DE ALTO NÍVEL IMPLEMENTADA POR UM ELEMENTO

#include "app/elementos/LedBarGraph.h"

#define CEM_PORCENTO 100
#define PERCENTUAL_POR_LED (CEM_PORCENTO / QTD_LEDS)

// EXEMPLO DE UM ATRIBUTO PRIVADO
static char leds_completos = 0; 

// EXEMPLO DE MÉTODO PRIVADO DO ELEMENTO
static void tratar_nivel_restante(char nivel_restante) {
  if (!nivel_restante) 
    return;  
  char intensidade = (CEM_PORCENTO*nivel_restante)/PERCENTUAL_POR_LED;
  char led = leds_completos + 1;
  driver_led_bargraph.regular_intensidade_do_led(led, intensidade);
}

// EXEMPLO DE MÉTODO "PÚBLICO" DO ELEMENTO
static void alterar_intensidade(char nivel_percentual) {  
  leds_completos = (QTD_LEDS*nivel_percentual)/CEM_PORCENTO;
  char nivel_restante = nivel_percentual - PERCENTUAL_POR_LED*(leds_completos);  
  
  for (int i = 1; i <= QTD_LEDS; i++) {
    if (i <= leds_completos)
      // EXEMPLO DA UTILIZAÇÃO DA INTERFACE DE UM DRIVER (RESPOSTA DO SISTEMA)
      driver_led_bargraph.ligar_led(i);    
    else
      driver_led_bargraph.desligar_led(i);   
  }
  
  tratar_nivel_restante(nivel_restante);
}

//EXEMPLO DE INICIALIZAÇÃO DE UM ELEMENTO
struct LedBarGraph led_bargraph = {
  .alterar_intensidade = alterar_intensidade // MÉTODO PÚBLICO DO ELEMENTO
};