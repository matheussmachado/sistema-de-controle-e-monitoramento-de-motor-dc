#include <Arduino.h>
#include "plataforma/drivers_setup.h"
#include "elementos/Motor.h"

static unsigned int intensidade = 0;

static void ligar(sentido_t sentido) {
  if (sentido == HORARIO) {            
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }
  else if (sentido == ANTI_HORARIO) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
}

static void desligar(void) {
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

static void alterar_intensidade(unsigned int percentual) {  
  intensidade = (unsigned int)((percentual)*(1023.0/100));
}

void setup_driver_Motor(void) {
  IDriverMotor driver = {
    .ligar = ligar,
    .desligar = desligar,
    .alterar_intensidade = alterar_intensidade
  };

  Motor_set_driver(driver);
}