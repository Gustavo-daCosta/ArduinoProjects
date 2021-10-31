int pinoLed = 11;

void setup() {
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  acendeBrilho(5);
  apagaBrilho(5);
}

void acendeBrilho(int increamento){
  for (byte value = 0; value < 255; value+=increamento){
    analogWrite(pinoLed, value);
    delay(30);
  }
}

void apagaBrilho(int decreamento){
  for (byte value = 255; value > 0; value-=decreamento){
    analogWrite(pinoLed, value);
    delay(30);
  }
}
