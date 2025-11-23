#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "lib_TLB.h"
#include <dht11.h>
dht11 DHT11;
WiFiClientSecure client;
PubSubClient mqtt(client);

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

const int PORT = 8883;
const String URL = "ee5258c8dbff40548769fe4dd31022ab.s1.eu.hivemq.cloud";

const String broker_user = "Sensor1"; 
const String broker_pass = "Senha321"; 

const String S1_ilumi = "S1/ilumi";
const String S1_temp = "S1/temp";
const String S1_umi = "S1/umi";
const String S2_P1_topic = "S2/P1";
  
void setup() {
  Serial.begin(115200);
  status_connection(SSID, PASS, PORT); 
  mqtt.subscribe(S1_ilumi.c_str());
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  pinMode(LED, INPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  float temperatura = DHT11.temperature;
  float umidade = DHT11.humidity;
  int luminosidade = analogRead(LDR);

  mqtt.publish(S1_temp.c_str(), String(temperatura).c_str());
  mqtt.publish(S1_umi.c_str(), String(umidade).c_str());
  mqtt.publish(S1_ilumi.c_str(), String(luminosidade).c_str());

  mqtt.loop();
  delay(5000);

}