#include <dht11.h>
#include <Arduino.h>

#ifndef LIB_TLB_H
#define LIB_TLB_H
#define DHT 4
#define ECHO_PIN 23
#define TRIG_PIN 22
#define LED 19
#define LDR 34
#define RGBr 14
#define RGBg 26
#define RGBb 25
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
void Vermelho();
void Verde();
void Branco();
void Magenta();
void Amarelo();
void Ciano();
void Desligado();
int ultrassonico();
void luz();
void umidade();
void temp();
void status_connection(String SSID, String PASS, String PORT);
#endif