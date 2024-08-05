#include <Arduino.h>
#include <Bounce2.h>
#include "entradas.h"
#include "saidas.h"

#define BOTAO_BOOT_PIN 0


Bounce botao_boot = Bounce();

void inicializa_entradas()
{
    botao_boot.attach(BOTAO_BOOT_PIN, INPUT_PULLUP);
}

void botoes()
{
    //atualiza do estado do botao_boot
    botao_boot.update();

    //verifica se o botao_boot foi pressionado
    if(botao_boot.fell())
    {
        Serial.println("botao pressionado");
        LedBuiltInState = !LedBuiltInState;
    }

    //verifica se o botao_boot foi solto
    else if (botao_boot.rose())
    {
        Serial.println("botao solto");
    }
    
}
