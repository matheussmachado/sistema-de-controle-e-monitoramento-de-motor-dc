#ifndef LEDS_H
#define LEDS_H

typedef struct {
  void (*ligar)(void);
  void (*desligar)(void);
} LedLigaDesliga;

LedLigaDesliga led_de_operacao;

typedef struct {
  void (*ligar)(void);
  void (*desligar)(void);
} IDriverLed;

void LedDeOperacao_set_driver(IDriverLed driver);

//====================================================================================

struct LedsDeSentido {
  void (*alterar_sentido)(void);
} leds_de_sentido;

typedef void (*IDriverLedsDeSentido)(void);

void LedsDeSentido_set_driver(IDriverLedsDeSentido driver);

#endif