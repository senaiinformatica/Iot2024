/*************************
 * Projeto IOT com ESP32 
 * Escola SENAI de Informática
 * Curso de Apredizagem industrial 
 * Integrador de soluções em nuvem
 * Data: 01/08/2024
 * 
 * Autor: Thiago Augusto de Oliveira
 * 
 * Descrição: Projeto de automação utilizando ESP32
 * com conexão WiFi e MQTT.
 * 
 * versão: 0.9
 */


#include <Arduino.h>
#include "iot.h"
#include "saidas.h"
#include "entradas.h"
#include "tempo.h"

//Definição dos tópicos de publicação
#define mqtt_topic1 "projetoProfessor/led1"


//Protótipos das funções do main.cpp
void acao_botao_boot();

//Variáveis globais


void setup()
{
  Serial.begin(115200);
  setup_wifi();
  setup_time();
  inicializa_entradas();
  inicializa_saidas();
  inicializa_mqtt();
}

void loop()
{
  atualiza_time();
  atualiza_saidas();
  atualiza_botoes();
  atualiza_mqtt();
  acao_botao_boot();
}


//Função que verifica se o botão foi pressionado e sua ação
void acao_botao_boot()
{
  if (botao_boot_pressionado())
  {
    LedBuiltInState = !LedBuiltInState;
  }
}