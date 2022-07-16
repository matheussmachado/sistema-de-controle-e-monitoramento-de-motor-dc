#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

#define CEM_PORCENTO 100

struct Potenciometro {
  char (*percentual)(void);
} potenciometro;

typedef char (*IDriverPotenciometro)(void);

void Potenciometro_set_driver(IDriverPotenciometro driver);

#endif