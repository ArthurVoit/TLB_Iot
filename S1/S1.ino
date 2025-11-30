#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "lib_TLB.h"
WiFiClientSecure client;
PubSubClient mqtt(client);

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

const int PORT = 8883;
const String URL = "ee5258c8dbff40548769fe4dd31022ab.s1.eu.hivemq.cloud";

const String broker_user = ""; 
const String broker_pass = ""; 

const String S1_ilumi = "S1/ilumi";
const String S1_temp = "S1/temp";
const String S1_umi = "S1/umi";
const String S1_P1_topic = "S1/P1";
  
void setup() {
  Serial.begin(115200);
  status_connection(SSID, PASS, PORT, URL); 
  mqtt.subscribe(S1_ilumi.c_str());
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  pinMode(LED, INPUT);
  pinMode(RGBr, OUTPUT);
  pinMode(RGBg, OUTPUT);
  pinMode(RGBb, OUTPUT);
  pinMode(LDR, INPUT);
  dht.begin();
}

void loop() {
  float dadoSensor1 = ultrassonico();
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  int luminosidade = analogRead(LDR);
  int estadoLED = (luminosidade > NOITE) ? 1 : 0;
  
  mqtt.publish(S1_P1_topic.c_str(), String(dadoSensor1).c_str());
  mqtt.publish(S1_temp.c_str(), String(temperatura).c_str());
  mqtt.publish(S1_umi.c_str(), String(umidade).c_str());
  mqtt.publish(S1_ilumi.c_str(), String(estadoLED).c_str());

  digitalWrite(LED, estadoLED);

  mqtt.loop();
  delay(5000);

}