#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "lib_TLB.h"

WiFiClientSecure client;            
PubSubClient mqtt(client);    

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";
const String ID = "TLB_TREM";

const int PORT = 8883;
const String URL = "81e7fafe091e4b09b0b93bf45fb52950.s1.eu.hivemq.cloud";

const String broker_user = "";
const String broker_pass = "";

const String trem_TLB = "trem_TLB"; 

void setup() {
  status_connection(SSID, PASS, PORT, URL, ID);
  mqtt.subscribe(trem_TLB.c_str());
  mqtt.setCallback(callback);
  pinMode(RGBr, OUTPUT);
  pinMode(RGBg, OUTPUT);
  pinMode(RGBb, OUTPUT);

}

void loop() {
  mqtt.loop();
}

void callback(char* topic, byte* payload, unsigned int length){
  String mensagem = "";
  for(int i = 0; i < length; i++){
    mensagem += (char)payload[i];
  }
  Serial.print("Recebido: ");
  Serial.println(mensagem);

  int msg = mensagem.toInt();

  if (msg > 0){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else if(msg < 0){
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  } else{
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
  }

}