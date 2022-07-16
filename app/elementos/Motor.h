#ifndef MOTOR_H
#define MOTOR_H

struct Motor {
  void (*ligar)(void);
  void (*desligar)(void);
  void (*alterar_intensidade)(char percentual);
  void (*inverter_rotacao)(void);
} motor;

typedef struct {
  void (*ligar)(void);
  void (*desligar)(void);
  void (*alterar_intensidade)(char percentual);
  void (*inverter_rotacao)(void);
} IDriverMotor;

void Motor_set_driver(IDriverMotor driver);

#endif