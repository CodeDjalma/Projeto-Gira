#include <Arduino.h>
const int tomadaOne = 10;
const int tomadaTwo = 3;
const int tomadaTree = 12;
const int tomadaFour = 13;
const int tomadaFive = 2;
const int tomadaSix = 11;
const int tomadaSeven = 5;
const int tomadaEight = 6;
const int buzzerPin = 4;

unsigned long previousMillis = 0;  // Armazena o último momento em que uma ação foi executada
const long interval = 20;  // Intervalo de 20 milissegundos

void setup() {
  pinMode(tomadaOne, OUTPUT);
  pinMode(tomadaTwo, OUTPUT);
  pinMode(tomadaTree, OUTPUT);
  pinMode(tomadaFour, OUTPUT);
  pinMode(tomadaFive, OUTPUT);
  pinMode(tomadaSix, OUTPUT);
  pinMode(tomadaSeven, OUTPUT);
  pinMode(tomadaEight, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  // Inicializa as tomadas desligadas
  digitalWrite(tomadaOne, HIGH);
  digitalWrite(tomadaTwo, HIGH);
  digitalWrite(tomadaTree, HIGH);
  digitalWrite(tomadaFour, HIGH);
  digitalWrite(tomadaFive, HIGH);
  digitalWrite(tomadaSix, HIGH);
  digitalWrite(tomadaSeven, HIGH);
  digitalWrite(tomadaEight, HIGH);

  noTone(buzzerPin);  // Silencia o buzzer
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'I') {
      Serial.println("Gira");  // PROCURA COMUNICAÇÃO COM O SOFTWARE
    } else {
      processCommand(command);
    }
  }
}

void processCommand(char cmd) {
  unsigned long currentMillis = millis();  // Tempo atual

  switch (cmd) {
    case 'G':
      // Pisca a tomadaTwo com intervalo de 20 ms e aciona o buzzer
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        blinkTomadaTwoWithBuzzer();
      }
      break;

    case 'J':
      digitalWrite(tomadaOne, LOW);  // LIGA TOMADA 1
      break;

    case 'K':
      digitalWrite(tomadaOne, HIGH);  // DESLIGA TOMADA 1
      break;

    case 'C':
      digitalWrite(tomadaTwo, LOW);  // LIGA TOMADA 2
      break;

    case 'D':
      digitalWrite(tomadaTwo, HIGH);  // DESLIGA TOMADA 2
      break;
    case 'N':
      digitalWrite(tomadaTree, LOW);  //LIGA TOMADA 3
      // tone(buzzerPin, 4500, 10);
      break;

    case 'O':
      digitalWrite(tomadaTree, HIGH);  //DESLIGA TOMADA 3
      break;

    case 'P':
      digitalWrite(tomadaFour, LOW);  //LIGA TOMADA 4
      // tone(buzzerPin, 4500, 10);
      break;

    case 'Q':
      digitalWrite(tomadaFour, HIGH);  //DESLIGA TOMADA 4
      break;

    case 'A':
      //tone(buzzerPin, 4500, 10);
      digitalWrite(tomadaFive, LOW);  //LIGA TOMADA 5
      break;

    case 'B':
      digitalWrite(tomadaFive, HIGH);  //DESLIGA TOMADA 5
      break;


    case 'E':
      //tone(buzzerPin, 4500, 10);
      digitalWrite(tomadaSix, LOW);  //LIGA TOMADA 6
      break;

    case 'F':
      digitalWrite(tomadaSix, HIGH);  //DESLIGA TOMADA 6
      break;

    case 'L':
      digitalWrite(tomadaSeven, LOW);  //LIGA TOMADA 7
                                       //tone(buzzerPin, 4500, 10);
      break;

    case 'M':
      digitalWrite(tomadaSeven, HIGH);  //DESLIGA TOMADA 7
      break;

    case 'H':
      digitalWrite(tomadaEight, LOW);  //LIGA TOMADA 8
      // tone(buzzerPin, 4500, 10);
      break;

    case 'R':
      digitalWrite(tomadaEight, HIGH);  //DESLIGA TOMADA 8
      break;

    case 'S':

      //tone(buzzerPin, 2100, 50);
      digitalWrite(tomadaSeven, HIGH);
      delay(5);
      digitalWrite(tomadaTwo, HIGH);
      delay(5);
      digitalWrite(tomadaTree, HIGH);
      delay(5);
      digitalWrite(tomadaFour, HIGH);
      delay(5);
      digitalWrite(tomadaFive, HIGH);
      delay(5);
      digitalWrite(tomadaSix, HIGH);
      delay(5);
      digitalWrite(tomadaOne, HIGH);
      delay(5);
      digitalWrite(tomadaEight, HIGH);
      break;

    case 'T':
      // tone(buzzerPin, 2100, 50);
      digitalWrite(tomadaSeven, LOW);
      delay(5);
      digitalWrite(tomadaTwo, LOW);
      delay(5);
      digitalWrite(tomadaTree, LOW);
      delay(5);
      digitalWrite(tomadaFour, LOW);
      delay(5);
      digitalWrite(tomadaFive, LOW);
      delay(5);
      digitalWrite(tomadaSix, LOW);
      delay(5);
      digitalWrite(tomadaOne, LOW);
      delay(5);
      digitalWrite(tomadaEight, LOW);
      break;

    case 'Z':
      Serial.println("11");
      break;

    default:
     //SE CHEGOU AQUI , RECEBEU COMANDO INVALIDO
           digitalWrite(tomadaSeven, HIGH);
      delay(5);
      digitalWrite(tomadaTwo, HIGH);
      delay(5);
      digitalWrite(tomadaTree, HIGH);
      delay(5);
      digitalWrite(tomadaFour, HIGH);
      delay(5);
      digitalWrite(tomadaFive, HIGH);
      delay(5);
      digitalWrite(tomadaSix, HIGH);
      delay(5);
      digitalWrite(tomadaOne, HIGH);
      delay(5);
      digitalWrite(tomadaEight, HIGH);
      break;
  }
}

// Função para piscar tomadaTwo com o buzzer
void blinkTomadaTwoWithBuzzer() {
  digitalWrite(tomadaTwo, LOW);  // Liga a tomadaTwo
  tone(buzzerPin, 2100, 20);     // Aciona o buzzer
  delay(20);                     // Pausa de 20ms para permitir o buzzer tocar
  digitalWrite(tomadaTwo, HIGH); // Desliga a tomadaTwo
}


