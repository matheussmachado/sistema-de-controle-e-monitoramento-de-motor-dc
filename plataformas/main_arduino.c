#include <Arduino.h>
#include "plataforma/arduino/drivers_setup.h"
#include "casos_de_uso/casos_de_uso.h"

void setup(void) {
  pinMode(8, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  
  setup_driver_LedDeEstado();
}

static char botao_acionado = 0;

void loop(void) {

  if (!digitalRead(9)) { // TODO: MELHORAR ESSA IMPLEMENTAÇÃO DEVIDO AO DEBOUNCE FÍSICO
    if (!botao_acionado) {
      alterar_estado_ligado();
      botao_acionado = 1;
    }
  }
  else
    botao_acionado = 0;
}