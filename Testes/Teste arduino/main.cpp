#include <Arduino.h>

void setup() {
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop() {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);