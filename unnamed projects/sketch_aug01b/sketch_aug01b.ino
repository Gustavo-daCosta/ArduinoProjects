//Programa : Relogio com Arduino, DS1307 e Display 7 Seg
//Autor : FILIPEFLOP
 
#include "Wire.h"
#include "SevSeg.h"
 
//Create an instance of the object.
SevSeg display7seg;
 
int valor = 0;
 
byte zero = 0x00; 
unsigned long timer;
void setup()
{
  Wire.begin();
  //A linha abaixo pode ser retirada apos setar a data e hora
  // SelecionaDataeHora(); 
  
  //Selecao tipo de display anodo comum
  int displayType = COMMON_ANODE; 
     
  //Definicao dos pinos dos digitos
  int digit1 = 7; //Pino Digito1 do display
  int digit2 = 9; //Pino Digito2 do display
  int digit3 = 10; //Pino Digito3 do display
  int digit4 = 13; //Pino Digito4 do display
 
  //Pinos ligados aos segmentos A - H
  int segA = 12; //Pino segmento A  
  int segB = 8; //Pino segmento B
  int segC = 5; //Pino segmento C
  int segD = 3; //Pino segmento D
  int segE = 2; //Pino segmento E
  int segF = 11; //Pino segmento F
  int segG = 6; //Pino segmento G
  int segDP= 4; //Pino segmento H
   
  //Define o numero de digitos do display
  int numberOfDigits = 4;
 
  //Inicializa o display
  display7seg.begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);
   
  //Nivel de brilho do display
  display7seg.SetBrightness(50);
  timer = millis();
}
 
void loop()
{
  char tempString[10]; //Used for sprintf
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  int segundos = ConverteparaDecimal(Wire.read());
  int minutos = ConverteparaDecimal(Wire.read());
  int horas = ConverteparaDecimal(Wire.read() & 0b111111); 
  sprintf(tempString, "%02d%02d", horas, minutos);
  display7seg.DisplayString(tempString, 3);
}
 
void SelecionaDataeHora()   //Seta a data e a hora do DS1307
{
  byte segundos = 10; //Valores de 0 a 59
  byte minutos = 32; //Valores de 0 a 59
  byte horas = 19; //Valores de 0 a 23
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //Stop no CI para que o mesmo possa receber os dados
 
  //As linhas abaixo escrevem no CI os valores de 
  //data e hora que foram colocados nas variaveis acima
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(zero);
  Wire.endTransmission(); 
}
 
byte ConverteParaBCD(byte val)
{ 
  //Converte o número de decimal para BCD
  return ( (val/10*16) + (val%10) );
}
 
byte ConverteparaDecimal(byte val)  
{ 
  //Converte de BCD para decimal
  return ( (val/16*10) + (val%16) );
}
