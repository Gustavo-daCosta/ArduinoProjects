#include <HCSR04.h>

int ledVerde1 = 2;
int ledVerde2 = 4;
int ledVerde3 = 7;
int ledVerde4 = 9;

int ledVermelho1 = 3;
int ledVermelho2 = 5;
int ledVermelho3 = 6;
int ledVermelho4 = 8;

int leds[8] = {2, 3, 4, 6, 9, 8, 7, 5};
int wantedValue;
int wantedPosition;
int ledAnterior;
int ledPosterior;

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

void atualizarDistancia() {distance = distanceSensor.measureDistanceCm();}

void loop() {
  atualizarDistancia();
  parkingStatus = distance > 9 ? false : true;
  if (distance > 20) {  
    animacao();
  } else {
    if (parkingStatus) {
      vagaOcupada();
      Serial.print("Vaga OCUPADA! Distância: ");
    } else {
      vagaLivre();
      Serial.print("Vaga LIVRE! Distância: ");
    }
  }
  Serial.println(distance);
  delay(1000);
}

void animacao() {
  while (distance > 20) {
    for (int led : leds) {
      estadoTodosLeds(0);
      digitalWrite(led, HIGH);

      for (int i = 0; i < 8; i++) {
        if (wantedValue == leds[i]) {
          wantedPosition = i;
          break;
        }
      }
      
      delay(150);
      atualizarDistancia();
      if (distance < 20) {break;}
    }
  }
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

void estadoTodosLeds(int estado) {
  estadoLedsVerdes(estado);
  estadoLedsVermelhos(estado);
}
