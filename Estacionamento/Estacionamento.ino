#include <HCSR04.h>

int ledVerde1 = 2;
int ledVerde2 = 3;
int ledVerde3 = 7;
int ledVerde4 = 9;

int ledVermelho1 = 4;
int ledVermelho2 = 5;
int ledVermelho3 = 6;
int ledVermelho4 = 8;

int triggerPin = 12;
int echoPin = 13;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
bool parkingStatus;

double distance;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledVerde3, OUTPUT);
  pinMode(ledVerde4, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  pinMode(ledVermelho3, OUTPUT);
  pinMode(ledVermelho4, OUTPUT);
}

void loop() {
  distance = distanceSensor.measureDistanceCm();
  parkingStatus = distance > 9 ? false : true;
  if (parkingStatus) {
    vagaOcupada();
    Serial.print("Vaga OCUPADA! Distância: ");
  } else {
    vagaLivre();
    Serial.print("Vaga LIVRE! Distância: ");
  }
  Serial.println(distance);
  delay(1000);
}

void vagaOcupada() {
  estadoLedsVerdes(0);
  estadoLedsVermelhos(1);
}

void vagaLivre() {
  estadoLedsVerdes(1);
  estadoLedsVermelhos(0);
}

void estadoLedsVerdes(int estado) {
  digitalWrite(ledVerde1, estado);
  digitalWrite(ledVerde2, estado);
  digitalWrite(ledVerde3, estado);
  digitalWrite(ledVerde4, estado);
}

void estadoLedsVermelhos(int estado) {
  digitalWrite(ledVermelho1, estado);
  digitalWrite(ledVermelho2, estado);
  digitalWrite(ledVermelho3, estado);
  digitalWrite(ledVermelho4, estado);
}
