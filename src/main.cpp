#include <Arduino.h>
#include "iot.h"
#include "saidas.h"
#include "entradas.h"
#include "tempo.h"



void setup()
{
  Serial.begin(115200);
  setup_wifi();
  setup_time();
  setup_saidas();
  setup_entradas();
}


void loop()
{
  atualiza_time();
  botoes();
  atualiza_saidas();
  hora_certa();
}

