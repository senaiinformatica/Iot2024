#include <Arduino.h>
#include "saidas.h"
#define LedBuiltInPin 2
#define LedExterno 25


bool LedBuiltInState = LOW;
bool LedExternoState = LOW;

void inicializa_saidas()
{
    pinMode(LedBuiltInPin, OUTPUT);
    pinMode(LedExterno, OUTPUT);
}

void atualiza_saidas()
{
    digitalWrite(LedBuiltInPin, LedBuiltInState);
    digitalWrite(LedExterno, LedExternoState);
}