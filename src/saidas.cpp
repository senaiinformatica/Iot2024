#include "saidas.h"

bool LedBuiltinState;


void setup_saidas()
{
  pinMode(LEDBUILTIN, OUTPUT);
  LedBuiltinState = LOW;
}

void atualiza_saidas()
{
  digitalWrite(LEDBUILTIN, LedBuiltinState);
}
