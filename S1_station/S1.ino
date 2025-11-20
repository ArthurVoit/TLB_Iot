#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "lib_TLB.h"
#include <dht11.h>
dht11 DHT11;
WiFiClientSecure client;
PubSubClient mqtt(client);

//conexão wifi
const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

//conexão himeMQ
const int PORT = 8883;
const String URL = "ee5258c8dbff40548769fe4dd31022ab.s1.eu.hivemq.cloud";

//broker
const String broker_user = "Sensor1"; 
const String broker_pass = "Senha321"; 

//Tópicos
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
  String mensagem = "Franca: ";
  if(Serial.available()>0){
    mensagem += Serial.readStringUntil('\n');
    mqtt.publish(OtherTopic.c_str(), mensagem.c_str());

  }

  mqtt.loop();
  delay(200);

}

void callback(char *topic, byte* payload, unsigned int length) {
  String mensagem = "";
  for(int i = 0; i < length; i++){
    mensagem += (char)payload[i];
  }
  Serial.print("Recebidos: ");
  Serial.println(mensagem);
  if(mensagem != "ligar"){
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2,LOW);
  }
}