#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1); // RX, TX (GPIO0, GPIO1 en la Raspberry Pi Pico)

const int ledPin = 25; // LED interno de la Raspberry Pi Pico W

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200); // Monitor Serie
  BTSerial.begin(9600); // Configura el puerto serie para el módulo Bluetooth
  Serial.println("El dispositivo Bluetooth está listo para emparejarse");
}

void loop() {
  if (BTSerial.available()) {
    char receivedChar = BTSerial.read();
    Serial.print("Recibido: ");
    Serial.println(receivedChar);

    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); // Enciende el LED
      BTSerial.println("LED Encendido");
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW); // Apaga el LED
      BTSerial.println("LED Apagado");
    }
  }
}
