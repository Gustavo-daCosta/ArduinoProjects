#include <LiquidCrystal.h>
#define JUMP              9
#define BUZZER            8

#define MAX_JUMP_TIME     1200

#define POINTS_SPEED2     400
#define POINTS_SPEED3     900
#define POINTS_SPEED4     1500

#define CACTUS_GEN_CHANCE_THRESHOLD   60
#define CACTUS_GEN_TIME               800
#define CACTUS_STYLE                  3

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, DB4, DB5, DB6, DB7

byte dino[] = {
  B01110,
  B01011,
  B01111,
  B00110,
  B10111,
  B11110,
  B01110,
  B01010
};
byte cactus1[] = {
  B00100,
  B10100,
  B10101,
  B10101,
  B11101,
  B00111,
  B00100,
  B00100
};
byte cactus2[] = {
  B00100,
  B10101,
  B10101,
  B10101,
  B11111,
  B00100,
  B00100,
  B00100
};

byte cactus3[] = {
  B00100,
  B00101,
  B10101,
  B10101,
  B10111,
  B11100,
  B00100,
  B00100
};

byte block[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

bool jumping = false, started = false;
unsigned int playerY = 1;
unsigned long jumpTime = 0, lastDraw = 0, lastGenerated = 0, startTime = 0;
int cacti[16], cactiCount = 0;
int cactiSpeed = 500; //500ms (slow) -> 200ms (fast)

void clearPlayer(){
  lcd.setCursor(4,playerY);
  lcd.print(" ");
}

void gameOver(){
  started = false;
  clearCacti();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("GAMEOVER");
  lcd.setCursor(3,1);
  lcd.print((millis()-startTime)/100);
  tone(BUZZER, 415);
  delay(80);
  tone(BUZZER, 302);
  delay(50);
  noTone(BUZZER);
  delay(400);
}

void allBlocks(){
  for(int i = 0; i < 16; i++)
    for(int j = 0; j < 2; j++){
      lcd.setCursor(i,j);
      lcd.write(byte(4));
    } 
}

void checkSpeed(){
  if((millis()-startTime)/100 >= POINTS_SPEED2 && cactiSpeed > 400){
    cactiSpeed = 400;
    allBlocks();
  }else if((millis()-startTime)/100 >= POINTS_SPEED3 && cactiSpeed > 300){
    cactiSpeed = 300;
    allBlocks();
  }else if((millis()-startTime)/100 >= POINTS_SPEED4 && cactiSpeed > 200){
    cactiSpeed = 200;
    allBlocks();
  }
}

void drawPlayer(int y, bool clean){
  int comp[2] = {1,0};
  if(clean){
    lcd.setCursor(4,comp[y]);
    lcd.print(" ");
  }
  lcd.setCursor(4,y);
  lcd.write(byte(0));
}

void addCactus(){
  for(int i = 0; i < 16; i++){
    if(cacti[i] == -1){
      if(i>0 && cacti[i-1] == 14 && cactiSpeed == 500) break;
      cacti[i] = 15;
      cactiCount++;
      break;
    }
  }
}

void clearCacti(){
  for(int i = 0; i < 16; i++) cacti[i] = -1;
  cactiCount = 0;
}

void removeFirstCactus(){
  for(int i = 0; i < 16; i++){
    cacti[i] = cacti[i+1];
    if(i >= cactiCount){
      cacti[i] = -1;
      break;
    }
  }
  cactiCount--;
}

void drawCacti(){
  bool moved = false;
  for(int i = 0; i < cactiCount; i++){
    if(millis()-lastDraw >= cactiSpeed){
      cacti[i] = cacti[i] - 1;
      moved = true;
    }
    if(cacti[i] == 4 && playerY == 1){
      started = false;
      gameOver();
      break;
    }
    lcd.setCursor(cacti[i], 1);
    if(cacti[i]>-1){
      lcd.write(CACTUS_STYLE);
    }else{
      removeFirstCactus();
      i--;
    }
  }
  if(moved) lastDraw = millis();
}

void generateCactus(){
  if(millis()-lastGenerated < CACTUS_GEN_TIME) return;
  int chance = random(0,cactiSpeed);
  if(chance < CACTUS_GEN_CHANCE_THRESHOLD){
    addCactus();
    lastGenerated = millis();
  }
}

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, dino);
  lcd.createChar(1, cactus1);
  lcd.createChar(2, cactus2);
  lcd.createChar(3, cactus3);
  lcd.createChar(4, block);
  lcd.setCursor(5,0);
  lcd.print("APERTE");
  lcd.setCursor(5,1);
  lcd.print("O PULO");
  pinMode(JUMP, INPUT);
  pinMode(BUZZER, OUTPUT);
  randomSeed(analogRead(0));
  clearCacti();
}

void loop() {
  if(started){
    lcd.clear();
    checkSpeed();
    if(millis()-jumpTime >= MAX_JUMP_TIME*0.1){
      noTone(BUZZER);
    }
    if(digitalRead(JUMP)){
      if(!jumping){
        jumpTime = millis();
        jumping = true;
        drawPlayer(--playerY, true);
        tone(BUZZER, 800);
      }
      if(jumping){
        if(millis()-jumpTime > MAX_JUMP_TIME){
          jumping = false;
          drawPlayer(++playerY, true);
          noTone(BUZZER);
        }
      }
    }else{
      if(jumping){
        jumping = false;
        drawPlayer(++playerY, true);
      }
    }
    generateCactus();
    drawPlayer(playerY, false);
    drawCacti();
    delay(150);
  }else{
    if(digitalRead(JUMP)){
      started = true;
      startTime = millis();
      tone(BUZZER, 1440);
      delay(200);
      noTone(BUZZER);
    }
  }
}
