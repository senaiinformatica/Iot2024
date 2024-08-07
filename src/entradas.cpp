#include <Arduino.h>
#include <Bounce2.h>
#include "entradas.h"
#include "saidas.h"

//Definição dos pinos dos botões
#define BOTAO_BOOT_PIN 0

//Criação dos objetos para debouncing
Bounce botao_boot = Bounce();

//Inicializa as entradas digitais
void inicializa_entradas()
{
    botao_boot.attach(BOTAO_BOOT_PIN, INPUT_PULLUP);
}

//Atualiza o estado do botão
void atualiza_botoes()
{
    //atualiza do estado do botao_boot
    botao_boot.update();
}

//Retorna se o botão boot foi pressionado
bool botao_boot_pressionado()
{
    return botao_boot.fell();
}