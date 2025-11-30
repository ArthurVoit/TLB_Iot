#include <DHT.h>
#include <Arduino.h>

#ifndef LIB_TLB_H
#define LIB_TLB_H
#define DHTPIN 4
#define ECHO_PIN 23
#define TRIG_PIN 22
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
int ultrassonico();
void status_connection(String SSID, String PASS, String PORT, String URL, String ID);
#endif