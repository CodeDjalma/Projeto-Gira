#include <IRremote.h>

IRsend irsend;  // Objeto para transmissão IR

// Definição dos pinos das tomadas em um array
const int tomadas[] = { 10, 9, 12, 13, 2, 11, 5, 6 };
const int numTomadas = sizeof(tomadas) / sizeof(tomadas[0]);
const int irPin = 3;  // Pino para o transmissor IR
const int LDR = A0;             // Pino analógico que o sensor está conectado

int valorsensor ;               // valor que sera armazenado o valor do LDR

void setup() {
  // Configura todos os pinos das tomadas como saída
  for (int i = 0; i < numTomadas; i++) {
    pinMode(tomadas[i], OUTPUT);
    pinMode(LDR, INPUT);          // Coloca a variavel LDR como entrada
    digitalWrite(tomadas[i], HIGH);  // Desliga todas as tomadas inicialmente
  }

  Serial.begin(9600);  // Inicializa a comunicação serial
}


void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'I') {
      Serial.println("Gira");  // PROCURA COMUNICAÇÃO COM O SOFTWARE
    } else {
      if (command == 'x') {
        String hexadecimal = Serial.readStringUntil('\n');
        // Converte a string hexadecimal para um número
        unsigned long irCode = strtoul(hexadecimal.c_str(), NULL, 16);
        // Envia o comando IR
        irsend.sendNEC(irCode, 32);
        Serial.println("Ligar/Desligar a TV");
      } else {
        processCommand(command);
      }
    }
  }
}


// Processa comandos individuais
void processCommand(char cmd) {
  switch (cmd) {

    case 'X':
      valorsensor = analogRead(LDR);
      
      Serial.println(valorsensor);
      break;

    case 'Z':
      Serial.println("7.2");  // Versão do firmware
      break;

    case 'G':
      resetAllTomadas();  // Desliga todas
      delay(5);
      setTomada(1, LOW);  // Liga tomada 2
      delay(5);
      setTomada(1, HIGH);  // Desliga tomada 1
      break;

    case 'J':
      setTomada(0, LOW);  // Liga tomada 1
      break;
    case 'K':
      setTomada(0, HIGH);  // Desliga tomada 1
      break;
    case 'C':
      setTomada(1, LOW);  // Liga tomada 2
      break;
    case 'D':
      setTomada(1, HIGH);  // Desliga tomada 2
      break;
    case 'N':
      resetAllTomadas();  // Desliga todas
      setTomada(2, LOW);  // Liga tomada 3
      break;
    case 'O':
      setTomada(2, HIGH);  // Desliga tomada 3
      break;
    case 'P':
      setTomada(3, LOW);  // Liga tomada 4
      break;
    case 'Q':
      setTomada(3, HIGH);  // Desliga tomada 4
      break;
    case 'A':
      setTomada(4, LOW);  // Liga tomada 5
      break;
    case 'B':
      setTomada(4, HIGH);  // Desliga tomada 5
      break;
    case 'E':
      setTomada(5, LOW);  // Liga tomada 6
      break;
    case 'F':
      setTomada(5, HIGH);  // Desliga tomada 6
      break;
    case 'L':
      resetAllTomadas();  // Desliga todas
      setTomada(6, LOW);  // Liga tomada 7
      break;
    case 'M':
      setTomada(6, HIGH);  // Desliga tomada 7
      break;
    case 'H':
      setTomada(7, LOW);  // Liga tomada 8
      break;
    case 'R':
      setTomada(7, HIGH);  // Desliga tomada 8
      break;
    case 'S':
      resetAllTomadas();  // Desliga todas
      break;
    case 'T':
      setAllTomadas(LOW);  // Liga todas
      break;
    case '1':
      irsend.sendNEC(0x1818D02F, 32);
      Serial.println("Ligar/Desligar a TV");
      break;
    case '2':
      irsend.sendNEC(0x1818D827, 32);
      Serial.println("Volume +");
      break;
    case '3':
      irsend.sendNEC(0x181858A7, 32);
      Serial.println("Volume -");
      break;

    default:
      // Serial.println("Comando inválido");
      break;
  }
}



// Liga ou desliga todas as tomadas para o mesmo estado
void setAllTomadas(int state) {
  for (int i = 0; i < numTomadas; i++) {
    digitalWrite(tomadas[i], state);
  }
}

// Liga ou desliga uma tomada específica
void setTomada(int index, int state) {
  if (index >= 0 && index < numTomadas) {
    digitalWrite(tomadas[index], state);
  }
}

// Desliga todas as tomadas
void resetAllTomadas() {
  setAllTomadas(HIGH);
}
