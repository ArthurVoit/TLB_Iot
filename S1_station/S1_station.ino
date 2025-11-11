#include <WiFiClientSecure.h>
#include <PubSubClient.h>
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
const String MyTopic = "S1";
const String OtherTopic = "chat";

//sensores

  //ultrassonico(P1)

  //Temperatura & umidade

  //luminosidade
    const int LED    = 19;
    const int ldrPin = 34;
  

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,  INPUT);

  Serial.begin(115200);
  Serial.println("Conectando ao Wifi");
  WiFi.begin(SSID, PASS);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("\nConectado!");
  client.setInsecure();
  Serial.println("Conectando ao Broker...");
  mqtt.setServer(URL.c_str(), PORT);
  while(!mqtt.connected()){
    String ID = "S1-";
    ID += String(random(0xffff), HEX);
    mqtt.connect(ID.c_str(), broker_user.c_str(), broker_pass.c_str());
    delay(200);
    Serial.print(".");
  }
  mqtt.subscribe(MyTopic.c_str());
  mqtt.setCallback(callback);
  Serial.println("\n Conectado ao broker com sucesso!");
  pinMode(2, OUTPUT);
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