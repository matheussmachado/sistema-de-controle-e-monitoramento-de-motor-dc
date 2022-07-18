#ifndef MOTOR_H
#define MOTOR_H

struct Motor {
  void (*ligar)(void);
  void (*desligar)(void);
  void (*alterar_intensidade)(unsigned int percentual);
  void (*alterar_sentido)(void);
} motor;

typedef enum {
  HORARIO, ANTI_HORARIO
} sentido_t;

typedef struct {
  void (*ligar)(sentido_t sentido);
  void (*desligar)(void);
  void (*alterar_intensidade)(unsigned int percentual);
} IDriverMotor;

void Motor_set_driver(IDriverMotor driver);

#endif