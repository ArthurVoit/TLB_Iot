#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "lib_TLB.h"

WiFiClientSecure client;
PubSubClient mqtt(client);

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

const int PORT = 8883;
const String URL = "test.mosquitto.org";
const String broker_user = ""; 
const String broker_pass = ""; 
const String S1_ilumi = "S1/ilumi";
const String S2_P1_topic = "S2/P1";
const String S2_P2_topic = "S2/P2";

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
  float dadoSensor1 = ultrassonico();
  String mensagem = "S2/P1: "  + String(dadoSensor1, 2);
  mqtt.publish(S2_P1_topic.c_str(), mensagem.c_str());

  float dadoSensor2 = ultrassonico();
  mensagem = "S2/P1: "  + String(dadoSensor2, 2);
  mqtt.publish(S2_P2_topic.c_str(), mensagem.c_str());

  mqtt.loop();
  delay(1000);

}