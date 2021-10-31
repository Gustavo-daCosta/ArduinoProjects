int led = 11, velo1 = 0, velo2 = 0, del = 200
;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for (int x=0; x<3; x++){
    if (x == 0){
      velo1 = 150;
      velo2 = 100;
    }
    else if (x == 1){
      velo1 = 450;
      velo2 = 150;
    }
    else {
      velo1 = 150;
      velo2 = 100;
      del = 100;
    }
    for (int x=0; x<3; x++){
      digitalWrite(led, HIGH);
      delay(velo1);
      digitalWrite(led, LOW);
      delay(velo2);
    }
    delay(del);
  }
  delay(5000);
}
