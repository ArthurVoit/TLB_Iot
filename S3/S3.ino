#include <WiFi.h>
#include <PubSubClient.h>
#include "lib_TLB.h"

WiFiClient client;
PubSubClient mqtt(client);

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

const int PORT           = 1883;
const String URL         = "test.mosquitto.org";
const String S1_ilumi = "S1/ilumi";
const String S2_P1_topic = "S2/P1";
const String S2_P2_topic = "S2/P2";
const String S3_P1_topic = "S3/P1";
const String broker_user = "";
const String broker_pass = "";

void setup() {
  Serial.begin(115200);
  status_connection(SSID, PASS, PORT);
  mqtt.subscribe(S2_P1_topic.c_str());
  mqtt.subscribe(S2_P2_topic.c_str());
  mqtt.subscribe(S1_ilumi.c_str());
  mqtt.subscribe(S3_P1_topic.c_str());
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  pinMode(LED, INPUT);
  pinMode(LDR, INPUT);
  pinMode(DHT, INPUT);
  
}

void loop() {
  float dadoSensor1 = ultrassonico();
  mqtt.publish(S3_P1_topic.c_str(), String(dadoSensor1).c_str());

  mqtt.loop();
  delay(1000);
}







