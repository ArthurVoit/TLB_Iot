#include "lib_TLB.h"

WiFiClientSecure client;
PubSubClient mqtt(client);

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";
const String ID = "TLB_S2";

const int PORT = 8883;
const String URL = "ee5258c8dbff40548769fe4dd31022ab.s1.eu.hivemq.cloud";
const String broker_user = ""; 
const String broker_pass = ""; 
const String S1_ilumi = "S1/ilumi";
const String S2_P1 = "S2/P1";
const String S2_P2 = "S2/P2";

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
  status_connection(); 
  mqtt.subscribe(S1_ilumi.c_str());
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  pinMode(TRIG_PIN_2, OUTPUT); 
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(RGBb, OUTPUT);
  pinMode(RGBg, OUTPUT);  
  pinMode(RGBr, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  float dadoSensor1 = status_ultrassonico(TRIG_PIN, ECHO_PIN);
  mqtt.publish(S2_P1_topic.c_str(), String(dadoSensor1).c_str());

  float dadoSensor2 = status_ultrassonico(TRIG_PIN_2, ECHO_PIN_2);
  mqtt.publish(S2_P2_topic.c_str(), String(dadoSensor2).c_str());

  mqtt.loop();
  delay(1000);

}