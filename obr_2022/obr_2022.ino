#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor motorDireito(1);
AF_DCMotor motorEsquerdo(2);

const int SENSOR_ESQUERDO = A2;
const int SENSOR_DIREITO = A0;
const int SENSOR_ESQ_EXT = A2;
const int SENSOR_DIR_EXT = A5;

int leitura_esquerdo = 0;
int leitura_direito = 0;
int leitura_esq_ext = 0;
int leitura_dir_ext  = 0;

bool encontrouPreto(int leitura) {
  return leitura < 2000 ? true : false;
}

void definirVelocidade(int velocidadeEsq, int velocidadeDir) {
  motorEsquerdo.setSpeed(velocidadeEsq);
  motorDireito.setSpeed(velocidadeDir);
}

void ligarMotores() {
  motorEsquerdo.run(FORWARD);
  motorDireito.run(FORWARD);
}

void desligarMotores() {
  motorDireito.run(RELEASE);
  motorEsquerdo.run(RELEASE);
}

void acelerarRobo(int velocidadeEsq, int velocidadeDir) {
  definirVelocidade(velocidadeEsq, velocidadeDir);
  ligarMotores();
}

void pararRobo() {
  definirVelocidade(0, 0);
  desligarMotores();
}

void fazerCurva(int velEsq, int velDir, int intervalo) {
  motorEsquerdo.setSpeed(velEsq);
  motorDireito.setSpeed(velDir);
  ligarMotores();
}

bool sensoresMesmaCor(int valor_leitura) {
  if (
    leitura_direito < valor_leitura &&
    leitura_dir_ext < valor_leitura &&
    leitura_esquerdo < valor_leitura &&
    leitura_esq_ext < valor_leitura
  ) {return true;}
  return false;
}

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_ESQUERDO, INPUT);
  pinMode(SENSOR_DIREITO, INPUT);
  pinMode(SENSOR_ESQ_EXT, INPUT);
  pinMode(SENSOR_DIR_EXT, INPUT);
}

void loop() {
  testeSensores();
  if (leitura_esquerdo > 400) {
    acelerarRobo(70, 30);
  }
  if (leitura_direito > 400) {
    acelerarRobo(30, 70);
  }
  //seguirLinha();
}

void testeSensores() {
  leitura_esquerdo = analogRead(SENSOR_ESQUERDO);
  leitura_direito = analogRead(SENSOR_DIREITO);
  leitura_esq_ext = analogRead(SENSOR_ESQ_EXT);
  leitura_dir_ext = analogRead(SENSOR_DIR_EXT);

 
  Serial.print("ESQUERDO: " + leitura_esquerdo);
  // const int SENSOR_DIR_EXT = 3;
  Serial.println(" | DIREITO: " + leitura_direito);
  Serial.print("ESQUERDO_EXTERNO: " + leitura_dir_ext);
  Serial.println(" | DIREITO_EXTERNO " + leitura_dir_ext);

  //delay(100);
}
/*
//MUDAR SEGUIR LINHA
void seguirLinha() {
  acelerarRobo(255);
  if () {
    zigzag();
  } else {
    fimDaLinha();
  }
}

// por favor, essa função precisa de um nome melhor
void zigzag() {
  if (encontrouPreto(leitura_esquerdo)) {
    motores.turn(70, 30);
  }
  // se der problema, testar com "else if"
  if (encontrouPreto(leitura_direito)) {
    motores.turn(30, 70);
  }
}

void fimDaLinha() {
  while (encontrouPreto(leitura_centro)) {
    motores.backward(50);
  }
  // se nao funcionar, armazenar retorno do estaReto() em uma variável
  while (estaReto() == false) {
    zigzag();
  }
}
*/
