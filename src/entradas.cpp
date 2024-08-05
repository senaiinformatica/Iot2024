#include "entradas.h"
#include "saidas.h"
#include <Arduino.h>
#include <Bounce2.h>

//Declaração dos objetos tipo Bounce
Bounce botao_boot = Bounce();

//Função para configurar as entradas
void setup_entradas()
{
    botao_boot.attach(BUTTONBUILTIN, INPUT_PULLUP);
}


//Função para realizar as acões dos botões
void botoes()
{
  botao_boot.update();
  
    if (botao_boot.fell())
    {
      Serial.println("Botao pressionado");
      LedBuiltinState = !LedBuiltinState;
    }
  
    else if (botao_boot.rose())
    {
      Serial.println("Botao solto");;
    }
  
}