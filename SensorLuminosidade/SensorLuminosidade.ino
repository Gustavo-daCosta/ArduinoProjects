#include <Arduino.h>

const int SENSOR_ESQUERDO = A2;
const int SENSOR_DIREITO = A0;
const int SENSOR_ESQ_EXT = A2;
const int SENSOR_DIR_EXT = A5;

int leitura_esquerdo = 0;
int leitura_direito = 0;
int leitura_esq_ext = 0;
int leitura_dir_ext  = 0;

void setup() {
  Serial.begin(4800);
  pinMode(SENSOR_ESQUERDO, INPUT);
  pinMode(SENSOR_DIREITO, INPUT);
  pinMode(SENSOR_ESQ_EXT, INPUT);
  pinMode(SENSOR_DIR_EXT, INPUT);
}

void loop() {
  leitura_esquerdo = analogRead(SENSOR_ESQUERDO);
  leitura_direito = analogRead(SENSOR_DIREITO);
  leitura_esq_ext = analogRead(SENSOR_ESQ_EXT);
  leitura_dir_ext = analogRead(SENSOR_DIR_EXT);
 
  Serial.print("ESQUERDO: " + leitura_esquerdo);
  Serial.println(" | DIREITO: " + leitura_direito);
  Serial.print("ESQUERDO_EXTERNO: " + leitura_dir_ext);
  Serial.println(" | DIREITO_EXTERNO " + leitura_dir_ext);
}
