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
void Branco()
{
  digitalWrite(RGBr, 255);
  digitalWrite(RGBg, 255);
  digitalWrite(RGBb, 255);
} 
void Magenta()
{
  digitalWrite(RGBr, 255);
  digitalWrite(RGBb, 255);
} 
void Amarelo()
{
  digitalWrite(RGBr, 255);
  digitalWrite(RGBg, 255);
  digitalWrite(RGBb, 255);
}
void Ciano()
{
  digitalWrite(RGBg, 255);
  digitalWrite(RGBb, 255);
}
void Desligado()
{
  digitalWrite(RGBr, 0);
  digitalWrite(RGBg, 0);
  digitalWrite(RGBb, 0);
} 

int ultrassonico()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
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
void luz()
{
  int value = analogRead(LDR);

  Serial.println("Analog  Value: ");
  Serial.println(value);

  if (value > 450)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }

  delay(250);
}

void umidade()
{
  float h = dht.readHumidity();
  if (isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
  }
}
void temp()
{
  float t = dht.readTemperature();
  if (isnan(t))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
}

void status_connection(String SSID,String PASS, String PORT)
{
  Serial.println("Conectando ao Wifi");
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(200);
    Azul();
  }
  Verde();
  delay(5000);
  Serial.println("\nConectado!");
  client.setInsecure();
  Serial.println("Conectando ao Broker...");
  mqtt.setServer(URL.c_str(), PORT);
  Desliga();
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