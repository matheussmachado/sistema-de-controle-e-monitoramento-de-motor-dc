#include "elementos/Potenciometro.h"

void Potenciometro_set_driver(IDriverPotenciometro driver) {
  potenciometro.percentual = driver;
}