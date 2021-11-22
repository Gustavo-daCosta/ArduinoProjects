#include <Servo.h>
#define limiar 260     // 250, 260, 300
#define unpress_angle 90 
#define press_angle 45     

Servo myservo;
bool trig=true;

void setup() {    
  myservo.attach(2);
  myservo.write(unpress_angle);   
}

void loop() {
 myservo.write(unpress_angle);              // Parar de apertar a barra de espaço
 delay(1);
 if(analogRead(A0)< limiar)
 {
    myservo.write(press_angle);          // Apertar a barra de espaço
    delay(100);                   
 }
}
