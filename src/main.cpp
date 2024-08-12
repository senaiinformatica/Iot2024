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
 *************************/


#include <Arduino.h>
#include <DHTesp.h>
#include "iot.h"
#include "saidas.h"
#include "entradas.h"
#include "tempo.h"
#include "atuadores.h"

//Definição dos tópicos de publicação
#define mqtt_pub_topic1 "projetoProfessor/DHT/Temperatura"
#define mqtt_pub_topic2 "projetoProfessor/DHT/Umidade"
#define DHTPIN 2

//Criacao de objetos
DHTesp dht; //Objeto do sensor DHT22



//Variáveis globais


void setup()
{
  dht.setup(DHTPIN, DHTesp::DHT22);

  Serial.begin(115200);
  setup_wifi();
  setup_time();
  inicializa_entradas();
  inicializa_saidas();
  inicializa_mqtt();
  inicializa_servos();
}

void loop()
{
  atualiza_time();
  atualiza_saidas();
  atualiza_botoes();
  atualiza_mqtt();

  float umidade = dht.getHumidity();
  float temperatura = dht.getTemperature();

  publica_mqtt(mqtt_pub_topic1, String(temperatura));
  publica_mqtt(mqtt_pub_topic2, String(umidade));
} 


