#include "elementos/Motor.h"

/*
   REGRAS: AO LIGAR DEVERÁ SER LEVADO EM CONTA O SENTIDO ATUAL

- o motor é pré definido para iniciar no sentido horário
- ao alterar o sentido do motor desligado, este deverá guardar a informação e permanecer desligado
- ao ligar o motor, este deverá girar no sentido setado antes de iniciar a operação
*/

struct Motor motor;
static sentido_t sentido = HORARIO;
static IDriverMotor _driver;

static void ligar(void) {
  _driver.ligar(sentido);
}

static void inverter_rotacao(void) {
  sentido = !sentido;
}

void Motor_set_driver(IDriverMotor driver) {
  motor.desligar = driver.desligar;
  motor.alterar_intensidade = driver.alterar_intensidade;
  motor.inverter_rotacao = inverter_rotacao;
  // HACKING
  _driver = driver;
  motor.ligar = ligar; 
}
