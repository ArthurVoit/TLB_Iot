#include "libsla.h"
#include <dht11.h>
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
 Serial.begin(115200);
  pinMode(LED, OUTPUT)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,  INPUT);
  pinMode(RGBr, OUTPUT);
  pinMode(RGBg, OUTPUT);
  pinMode(RGBb, OUTPUT);
  dht.begin();
}

  void Vermelho(){
  digitalWrite(RGBr, HIGH);
  };//Função para acionamento na cor vermelha
  void Verde(){ 
    digitalWrite(RGBg, HIGH);};//Função para acionamento na cor verde
  void Azul(){
     digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor azul
  void Branco(){
  digitalWrite(RGBr, HIGH);
  digitalWrite(RGBg, HIGH);
  digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor branca
  void Magenta(){
  digitalWrite(RGBr, HIGH);
  digitalWrite(RGBg, LOW);
  digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor magenta
  void Amarelo(){
  digitalWrite(RGBr, HIGH);
  digitalWrite(RGBg, HIGH);
  digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor amarela
  void Ciano(){
  digitalWrite(RGBg, HIGH);
  digitalWrite(RGBb, HIGH);  
  };//Função para acionamento na cor ciano
  void Desligado(){
  digitalWrite(RGBr, LOW);
  digitalWrite(RGBg, LOW);
  digitalWrite(RGBb, LOW);
  };//desliga o led

 int ultrassonico(){
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration*0.0343)/2;
  if(distance>2){
    return 0;
  } else{ 
    return 1;
  }
}
 void luz(){
  int value = analogRead(LDR);

    Serial.println("Analog  Value: ");
    Serial.println(value);
    
    if (value > 450) {
        digitalWrite(LED, LOW);
    } else {
        digitalWrite(LED,  HIGH);
    }
    
    delay(250);
}

 void umidade(){
  float h = dht.readHumidity();
  if (isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else 
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
   
  }
}
 void temp(){
    float t = dht.readTemperature();
  if (isnan(t)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else 
  {
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
}
}
