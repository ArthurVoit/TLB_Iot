#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "lib_TLB.h"
DHT dht(DHTPIN, DHTTYPE);

void Vermelho()
{
  digitalWrite(RGBr, 255);
} 
void Verde()
{
  digitalWrite(RGBg, 255);
} 
void Azul()
{
  digitalWrite(RGBb, 255);
} 
void Desligado()
{
  digitalWrite(RGBr, 0);
  digitalWrite(RGBg, 0);
  digitalWrite(RGBb, 0);
} 

int status_ultrassonico()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration * 0.0343) / 2;
  if (distance > 2)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void status_connection(String SSID,String PASS, String PORT, String URL, String ID)
{
  Serial.println("Conectando ao Wifi");
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(200);
    Azul();
  }
  Desligado();
  Verde();
  delay(5000);
  Serial.println("\nConectado!");
  client.setInsecure();
  Serial.println("Conectando ao Broker...");
  mqtt.setServer(URL.c_str(), PORT.toInt());
  Desligado();
  while (!mqtt.connected())
  {
    ID += String(random(0xffff), HEX);
    mqtt.connect(ID.c_str(), broker_user.c_str(), broker_pass.c_str());
    delay(200);
    Serial.print(".");
    Azul();
  }
  Serial.println("\n Conectado ao broker com sucesso!");
  Verde();
  delay(5000);
  Desliga();
}