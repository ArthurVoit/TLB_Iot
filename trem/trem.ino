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

void callback(char* topic, byte* payload, unsigned int length){
  String mensagem = "";
  for(int i = 0; i < length; i++){
    mensagem += (char)payload[i];
  }
  Serial.print("Recebido: ");
  Serial.println(mensagem);

  int msg = mensagem.toInt();

  if (msg > 0){
    Desligado();
    Verde();
  } else if(msg < 0){
    Desligado();
    Vermelho();
  } else{
    Desligado();
  }

}

void setup() {
  status_connection();
  mqtt.subscribe(trem_TLB.c_str());
  mqtt.setCallback(callback);
  pinMode(RGBr, OUTPUT);
  pinMode(RGBg, OUTPUT);
  pinMode(RGBb, OUTPUT);

}

void loop() {
  mqtt.loop();
  delay(1000);
}
