// EXEMPLO DE UMA REGRA DE ALTO NÍVEL IMPLEMENTADA POR UM ELEMENTO

#include "elementos/LedBarGraph.h"

#define CEM_PORCENTO 100
#define PERCENTUAL_POR_LED (CEM_PORCENTO / QTD_LEDS)


// EXEMPLO DE UM ATRIBUTOS PRIVADOS
static IDriverLedBarGraph _driver;
static char leds_completos = 0;

// EXEMPLO DE MÉTODOS PÚBLICOS DO ELEMENTO
void LedBarGraph_init_driver(IDriverLedBarGraph driver); // MÉTODO DE INICIALIZAÇÃO DE DRIVER
static void alterar_intensidade(char nivel_percentual); // -> PÚBLICO ATRAVÉS DA STRUCT DO ELEMENTO
// EXEMPLO DE MÉTODO PRIVADO DO ELEMENTO
static void tratar_nivel_restante(char nivel_restante);


void LedBarGraph_init_driver(IDriverLedBarGraph driver) {
  _driver = driver;
}


static void alterar_intensidade(char nivel_percentual) {
  static char nivel_alterior = 0;  
  leds_completos = (QTD_LEDS*nivel_percentual)/CEM_PORCENTO;
  char nivel_restante = nivel_percentual - PERCENTUAL_POR_LED*(leds_completos);  
  
  for (int i = 1; i <= QTD_LEDS; i++) {
    if (i <= leds_completos)
      // EXEMPLO DA UTILIZAÇÃO DA INTERFACE DE UM DRIVER (RESPOSTA DO SISTEMA)
      _driver.ligar_led(i);    
    else
      if (nivel_alterior != nivel_percentual)
        _driver.desligar_led(i);   
  }
  
  nivel_alterior = nivel_percentual;
  tratar_nivel_restante(nivel_restante);
}


static void tratar_nivel_restante(char nivel_restante) {
  if (!nivel_restante) 
    return;  
  char intensidade = (CEM_PORCENTO*nivel_restante)/PERCENTUAL_POR_LED;
  char led = leds_completos + 1;
  _driver.regular_intensidade_do_led(led, intensidade);
}


//EXEMPLO DE INICIALIZAÇÃO DE UM ELEMENTO
struct LedBarGraph led_bargraph = {
  .alterar_intensidade = alterar_intensidade
};