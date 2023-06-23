// inclui as bibliotecas do sensor ultrassônico e do servomotor
#include <HCSR04.h>
#include <Servo.h>

// Declaração das variáveis que contém a porta dos LEDS
int ledVerde;
int ledLaranja;
int ledVermelho;

// Declaração das variáveis que contém as portas do sensor ultrassônico
int triggerPin = 11;
int echoPin = 12;

// Declaração do sensor ultrassônico
UltraSonicDistanceSensor sensorUltrassonico(triggerPin, echoPin);
// Declaração do servomotor
Servo servo;

double distancia;
double angulo;

void setup() {
  // Configura as portas dos LEDS como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledLaranja, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  // configura a porta do servomotor
  servo.attach(8);
}

// Função para calcular a distância medida pelo sensor ultrassônico
void atualizarDistancia() {
  distancia = sensorUltrassonico.measureDistanceCm();
  // condições para reduzir o alcance do sensor
  if (distancia > 30) {
    distancia == 30;
  } else if (distancia < 0) {
    distancia = 0;
  }
};

// Função para atualizar o ângulo da posição do servomotor
void atualizarPosicaoServo() {
  atualizarDistancia();
  // mapeia o ângulo que o servomotor deve ir
  angulo = map(distancia, 0, 30, 178, 2);
  // move o servomotor para o ângulo indicado
  servo.write(angulo);
}

void loop() {
  atualizarPosicaoServo();
  delay(200);
}
