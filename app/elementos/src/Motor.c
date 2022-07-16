#include "elementos/Motor.h"

void Motor_set_driver(IDriverMotor driver) {
  motor.ligar = driver.ligar;
  motor.desligar = driver.desligar;
  // motor.alterar_intensidade = driver.alterar_intensidade;
  // motor.inverter_rotacao = driver.inverter_rotacao;
}

// ligar deve controlar o sentido atual