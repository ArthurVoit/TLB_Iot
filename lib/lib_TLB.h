#ifndef LIB_TLB_H
#define LIB_TLB_H

#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define DHTPIN 4
#define ECHO_PIN 23
#define TRIG_PIN 22
#define ECHO_PIN_2 13
#define TRIG_PIN_2 12
#define LED 19
#define LDR 34
#define RGBr 14
#define RGBg 26
#define RGBb 25
#define DHTTYPE DHT11
#define NOITE 1000
#define DIA 500

void Vermelho();
void Verde();
void Azul();
void Desligado();
int status_ultrassonico(const int trigPin, const int echoPin);
void status_connection();
#endif