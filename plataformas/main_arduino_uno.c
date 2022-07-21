#include <Arduino.h>
#include "plataforma/drivers_setup.h"
#include "casos_de_uso/casos_de_uso.h"

void setup(void) {
  pinMode(6, INPUT_PULLUP);  // BOTÃO DE OPERAÇÃO
  pinMode(2, INPUT_PULLUP); //BOTÃO DE INVERSÃO

  pinMode(0, OUTPUT);  // LED DE HORÁRIO
  pinMode(1, OUTPUT);  // LED DE ANTI HORÁRIO
  pinMode(5, OUTPUT);  // LED DE ALIMENTAÇÃO
  pinMode(8, OUTPUT);  // LED DE OPERAÇÃO
  pinMode(9, OUTPUT);  // MOTOR AIN
  pinMode(10, OUTPUT); // MOTOR BIN
  pinMode(11, OUTPUT); // MOTOR AOUT
  pinMode(12, OUTPUT); // MOTOR BOUT

  attachInterrupt(
    digitalPinToInterrupt(2), 
    alterar_sentido_do_sistema_quando_botao_inversor_acionado,
    FALLING
  );

  setup_driver_Botoes();
  setup_driver_Leds();
  setup_driver_Motor();
  
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);
}

void loop(void) {
  atualizar_estado_de_operacao_via_botao_de_operacao();
}