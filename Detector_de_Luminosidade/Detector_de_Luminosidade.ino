/*
#include <iostream>
#include <cstring>
*/

int ldr=A0;//Set A0(Analog Input) for LDR.
int value=0;
void setup() {
Serial.begin(9600);
pinMode(3,OUTPUT);
}

void loop() {
value=analogRead(ldr);//Reads the Value of LDR(light).
Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
Serial.println(value);
if(value<300)
  {
    digitalWrite(3,HIGH);//Makes the LED glow in Dark.
  }
  else
  {
    digitalWrite(3,LOW);//Turns the LED OFF in Light.
  }
}



/*
int LED1 = 6;
int LED2 = 5;
int LED3 = 4;
int LED4 = 3;
int LED5 = 2;
int ldr = A0;
int value = 0;

int l1 = 0;
int l2 = 0;
int l3 = 0;
int l4 = 0;
int l5 = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  value = analogRead(ldr);
  Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
  Serial.println(value);
  if (value <= 1) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
  } else if (value <= 2) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
  } else if (value <= 3) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
  } else if (value <= 4) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED1, LOW);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED1, HIGH);
  }
}
*/
