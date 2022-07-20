#include "elementos/Motor.h"

/*
  REGRAS: 
   
  AO LIGAR DEVERÁ SER LEVADO EM CONTA O SENTIDO ATUAL
  - o motor é pré definido para iniciar no sentido horário (ou antihorário, opcionalmente)
  - ao alterar o sentido do motor desligado, este deverá guardar a informação e permanecer desligado
  - ao ligar o motor, este deverá girar no sentido setado antes de iniciar a operação

  AO RECEBER O VALOR DE INTENSIDADE:
  - precisa ser controlável -> respeitar o valor máximo do caso de uso -> independente do valor do ADC
  - ao alterar o sentido de giro o motor deverá girar para o sentido com a mesma intensidade do regulador
*/

struct Motor motor;
static sentido_t sentido = HORARIO;
static void (*driver_ligar)(sentido_t _sentido); // VARIÁVEL AUXILIAR PARA USAR UMA
                                                 // FUNÇÃO DE DRIVER DE MODO CUSTOMIZADO

static void ligar(void) {
  driver_ligar(sentido);
}

static void alterar_sentido(void) {
  sentido = !sentido;
}

void Motor_set_driver(IDriverMotor driver) {
  // SÓ É POSSÍVEL CONSTRUIR O MOTOR DESSA FORMA FORA DESSA FUNÇÃO 
  // POIS O DRIVER RECEBIDO COMO ARGUMENTO É DELETADO DA MEMÓRIA APÓS 
  // ESSA FUNÇÃO SER EXECUTADA
  motor.desligar = driver.desligar;
  motor.alterar_intensidade = driver.alterar_intensidade;
  motor.alterar_sentido = alterar_sentido;
  // ENVOLVENDO A FUNÇÃO DO DRIVER PARA UTILIZAÇÃO CUSTOMIZADA
  driver_ligar = driver.ligar;
  motor.ligar = ligar; 
}
