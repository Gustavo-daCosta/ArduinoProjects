#include <Servo.h>

Servo servo;
int ledVermelho = 9;
int ledAzul = 8;
int potenciometro = A0;
int angulo = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(7);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  angulo = analogRead(potenciometro);
  angulo = map(angulo, 0, 1023, 5, 180);
  Serial.println(angulo);
  servo.write(angulo);
  if (angulo > 90) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, HIGH);
  }
  delay(20);
}
