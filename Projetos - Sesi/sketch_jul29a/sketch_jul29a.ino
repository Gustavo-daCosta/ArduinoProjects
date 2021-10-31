int botao = 7;
int led = 13;
bool estadoLed = 0;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == LOW){
    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);
    while (digitalRead(botao) == LOW);
    delay(100);
  }
}
