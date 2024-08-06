#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h> // Baixar a biblioteca PubSubClient
#include "iot.h"
#include "senhas.h"
#include "saidas.h"

#define mqtt_topic1 "projetoProfessor/led1"
#define mqtt_topic2 "projetoProfessor/led2"

const String cliente_id = "ESP32Client" + String(random(0xffff), HEX);

//Definição dos dados de conexão
WiFiClient espClient;
PubSubClient client(espClient);

void tratar_msg(char *topic, String msg);
void callback(char *topic, byte *payload, unsigned int length);
void reconecta_mqtt();

//Inicia a conexão WiFi
void setup_wifi()
{
  Serial.println();
  Serial.print("Conectando-se a Rede WiFi ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Conectado ao WiFi com sucesso com IP: ");
  Serial.println(WiFi.localIP());
}


void inicializa_mqtt()
{
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void atualiza_mqtt()
{ 
  client.loop();
  if (!client.connected())
  {
    reconecta_mqtt();
  }
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.printf("Mensagem recebida [ %s ] \n\r", topic);
  String msg = "";
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
    msg += (char)payload[i];
  }
  Serial.println();

tratar_msg(topic, msg);
}

void reconecta_mqtt()
{
  while (!client.connected())
  {
    Serial.print("Tentando se conectar ao Broker MQTT: ");
    Serial.println(mqtt_server);
    if (client.connect(cliente_id.c_str()))
    {
      Serial.println("Conectado ao Broker MQTT");
      client.subscribe(mqtt_topic1);
      client.subscribe(mqtt_topic2);
    }
    else
    {
      Serial.println("Falha ao conectar ao Broker.");
      Serial.println("Havera nova tentativa de conexao em 2 segundos");
      delay(2000);
    }
  }
}

void publica_mqtt(String topico, String msg)
{
  client.publish(topico.c_str(), msg.c_str());
}

//! NAO ESQUECER DE SE INCREVER NO TOPICO LINHA 78
void tratar_msg(char *topic, String msg)
{
if(strcmp(topic, mqtt_topic1) == 0)
  {
    if(msg == "liga")
    {
      LedBuiltInState = true;
    }
    else if(msg == "desliga")
    {
      LedBuiltInState = false;
    }
    else if(msg == "alterna")
    {
      LedBuiltInState = !LedBuiltInState;
    }
    else
    {
      Serial.println("Comando desconhecido");
    }
  }

  else if(strcmp(topic, mqtt_topic2) == 0)
  {
    if(msg == "liga")
    {
      LedExternoState = true;
    }
    else if(msg == "desliga")
    {
      LedExternoState = false;
    }
    else if(msg == "alterna")
    {
      LedExternoState = !LedExternoState;
    }
    else
    {
      Serial.println("Comando desconhecido");
    }
  }
  else
  {
    Serial.println("Topico desconhecido");
  }
}



