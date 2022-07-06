#ifndef DRIVERS_INTERFACES_H
#define DRIVERS_INTERFACES_H

#include <stdbool.h>

// EXEMPLO DE INTERFACE DE UM DRIVER A SER USADO PELO ELEMENTO
typedef struct {
  void (*ligar_led)(int led);
  void (*desligar_led)(int led);
  void (*regular_intensidade_do_led)(int led, char nivel_de_intensidade);
} IDriverLedBarGraph;

typedef struct {
  void (*alterar_estado)(void);
} IDriverLedDeEstado;

typedef struct {
  bool (*esta_acionado)(void);
} IDriverBotaoLimitador;

#endif