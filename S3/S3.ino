#include <WiFi.h>
#include <PubSubClient.h>
#include "lib_TLB.h"

WiFiClient client;
PubSubClient mqtt(client);

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";
const String ID = "TLB_S3";

const int PORT           = 1883;
const String URL         = "ee5258c8dbff40548769fe4dd31022ab.s1.eu.hivemq.cloud";
const String S1_ilumi = "S1/ilumi";
const String S2_P1_topic = "S2/P1";
const String S2_P2_topic = "S2/P2";
const String S3_P1_topic = "S3/P1";
const String broker_user = "";
const String broker_pass = "";

void callback(char* topic, byte* payload, unsigned int length){
  String mensagem = "";
  for(int i = 0; i < length; i++){
    mensagem += (char)payload[i];
  }
  if (String(topic) == S1_ilumi) {
    int estado = mensagem.toInt();
    digitalWrite(LED, estado); 
  }
}

void setup() {
  Serial.begin(115200);
  mqtt.setCallback(callback);
  status_connection(SSID, PASS, PORT, URL, ID);
  mqtt.subscribe(S2_P1_topic.c_str());
  mqtt.subscribe(S2_P2_topic.c_str());
  mqtt.subscribe(S1_ilumi.c_str());
  mqtt.subscribe(S3_P1_topic.c_str());
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  pinMode(LED, INPUT);
  pinMode(LDR, INPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  float dadoSensor1 = ultrassonico();
  mqtt.publish(S3_P1_topic.c_str(), String(dadoSensor1).c_str());

  mqtt.loop();
  delay(1000);
}







