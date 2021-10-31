int pedVerde = 9;
int pedVermelho = 8;
int carroVerde = 12;
int carroAmarelo = 11;
int carroVermelho = 10;

void setup() {
  pinMode(pedVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);

  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
}

void loop() {
  digitalWrite(pedVermelho, HIGH);
  delay(5000); 
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH); 
  delay(3000); 
  digitalWrite(carroAmarelo, LOW); 
  digitalWrite(carroVermelho, HIGH);
  digitalWrite(pedVermelho, LOW); 
  digitalWrite(pedVerde, HIGH);
  delay(5000);  
  digitalWrite(pedVerde, LOW);
  for(int x = 0; x<5; x++) 
  {
    digitalWrite(pedVermelho, HIGH);
    delay(250);
    digitalWrite(pedVermelho, LOW);
    delay(250);
  }
  digitalWrite(carroVermelho, LOW); 
}
