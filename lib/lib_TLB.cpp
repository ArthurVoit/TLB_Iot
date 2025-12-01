#include "lib_TLB.h"
#include <DHT.h>
DHT dht(DHTPIN, DHTTYPE);

void Vermelho()
{
  analogWrite(RGBr, 255);
} 
void Verde()
{
  analogWrite(RGBg, 255);
} 
void Azul()
{
  analogWrite(RGBb, 255);
} 
void Desligado()
{
  analogWrite(RGBr, 0);
  analogWrite(RGBg, 0);
  analogWrite(RGBb, 0);
} 

int status_ultrassonico(const int trigPin, const int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2;
  if (distance >= 5)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void status_connection()
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
  delay(1000);
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