#include <Arduino.h>
#include <Bounce2.h>
#include "entradas.h"

#define BOTAO_BOOT_PIN 0

Bounce botao_boot = Bounce();

void inicializa_entradas()
{
    botao_boot.attach(BOTAO_BOOT_PIN, INPUT_PULLUP);
}
