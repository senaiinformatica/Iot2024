#pragma once

#include <Arduino.h>

#define LEDBUILTIN 2

//o comando extern indica que a variável é declarada em outro arquivo
//neste caso, a variável LedBuiltinState é declarada em saidas.cpp
extern bool LedBuiltinState;

void setup_saidas();
void atualiza_saidas();