const int LVermelho = 2; 
const int LVerde = 3;
const int buzzerPin = 4; 
const int tomadaOne = 10;  // Pino onde o relé está conectado
const int tomadaTwo = 11;
const int tomadaTree = 12;
const int tomadaFour = 13;


void setup() {
  pinMode(LVermelho, OUTPUT);
  pinMode(LVerde, OUTPUT);
  pinMode(tomadaOne, OUTPUT);  // Configura o pino do relé como saída
  pinMode(tomadaTwo, OUTPUT);
  pinMode(tomadaTree, OUTPUT);
  pinMode(tomadaFour, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  digitalWrite(LVermelho, HIGH);
  digitalWrite(LVerde, HIGH); 
  digitalWrite(tomadaOne, HIGH);  // Mantém o relé desligado inicialmente
  digitalWrite(tomadaTwo, HIGH);  // Mantém o relé desligado inicialmente
  digitalWrite(tomadaTree, HIGH);  // Mantém o relé desligado inicialmente
  digitalWrite(tomadaFour, HIGH);

  noTone(buzzerPin);

}

void loop() {  

  if (Serial.available() > 0) { // Verifica se há dados disponíveis na serial
    char command = Serial.read(); // Lê um caractere da serial

    if (command == 'I') {
      Serial.println("Gira");
    } else {
      processCommand(command); // Processa o comando recebido
    }
  }


}

void processCommand(char cmd) {
  switch (cmd) {
    case 'A':
      tone(buzzerPin, 4500, 400);
      digitalWrite(LVermelho, LOW);   // Acende vermelho
      break;

    case 'B':
      digitalWrite(LVermelho, HIGH);   // APAGA vermelho
      break;         

    case 'C':
        // seria para acender amarelo
      break;

    case 'D':
        // seria para apagar amarelo
      break;

    case 'E':
        digitalWrite(LVerde, LOW);  //acende Verde
      break;

    case 'F':
        digitalWrite(LVerde, HIGH);  //APAGA Verde
      break;

    case 'G':  //pisca
        tone(buzzerPin, 4500, 50);
        digitalWrite(tomadaOne, LOW);  //ACENDE Verde
        delay(50);
        
        digitalWrite(tomadaOne, HIGH);  //APAGA Verde
      break;

    case 'J':
       digitalWrite(tomadaOne, LOW);  //ACENDE
         tone(buzzerPin, 4500, 400);
     //  Serial.println("Tomada ligada");
       break;

     case 'K':
       digitalWrite(tomadaOne, HIGH);  // DESLIGA A TOMADA
     // Serial.println("Tomada desligada");
       break;   

    case 'L':
     digitalWrite(tomadaTwo, LOW);  //ACENDE
       tone(buzzerPin, 4500, 400);
       break;

    case 'M':
     digitalWrite(tomadaTwo, HIGH);  // DESLIGA A TOMADA
       break;

   case 'N':
     digitalWrite(tomadaTree, LOW);  // ACENDE
       tone(buzzerPin, 4500, 400);
       break;

   case 'O':
     digitalWrite(tomadaTree, HIGH);  // DESLIGA A TOMADA
     break; 

   
   case 'P':
     digitalWrite(tomadaFour, LOW);  // ACENDE
       tone(buzzerPin, 4500, 400);
     break;   


   case 'Q':
     digitalWrite(tomadaFour, HIGH);  // DESLIGA A TOMADA
     break; 

    
  

    default:
      Serial.println("Comando inválido"); // Mensagem de erro para comandos inválidos
      break;
  }
}

