#include <IRremote.h>
#include <LiquidCrystal_I2C.h>

// Pino do receptor IR
const int recvPin = 11;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(recvPin, ENABLE_LED_FEEDBACK);
  


  delay(100);
}

void loop() {
  if (IrReceiver.decode()) {

    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println("Protocolo: UNKNOWN");
      IrReceiver.resume(); // libera logo para evitar travamento
      return;
    }

    uint32_t codigo = IrReceiver.decodedIRData.decodedRawData;
    uint8_t bits = IrReceiver.decodedIRData.numberOfBits;

    if (codigo == 0x0 || codigo == 0xFFFFFFFF || bits < 12) {
      Serial.println("Sinal ignorado: dados incompletos ou inválidos.");
      IrReceiver.resume();
      return;
    }

    // Exibe no Serial
    Serial.print("Protocolo: ");
    Serial.println(IrReceiver.getProtocolString());
    Serial.print("Codigo    : 0x");
    Serial.println(codigo, HEX);
    Serial.print("Bits      : ");
    Serial.println(bits);

    // Exibe no LCD
    lcd.clear();
    delay(10);
    lcd.setCursor(0, 0);
    lcd.print("0x");
    lcd.print(codigo, HEX);
    lcd.setCursor(0, 1);
    lcd.print("Bits: ");
    lcd.print(bits);

    IrReceiver.resume();  


    // Volta para mensagem padrão
    lcd.clear();
    delay(10);
    lcd.setCursor(2, 0);
    lcd.print("Direcione");
    lcd.setCursor(2, 1);
    lcd.print("O controle :)");
  }
}
