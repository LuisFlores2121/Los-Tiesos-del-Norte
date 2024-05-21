#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int ledPin = 25; // LED interno de la Raspberry Pi Pico W

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("PicoW_BT"); // Nombre del dispositivo Bluetooth
  Serial.println("El dispositivo Bluetooth está listo para emparejarse");
}

void loop() {
  if (SerialBT.available()) {
    char receivedChar = SerialBT.read();
    Serial.print("Recibido: ");
    Serial.println(receivedChar);

    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); // Enciende el LED
      SerialBT.println("LED Encendido");
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW); // Apaga el LED
      SerialBT.println("LED Apagado");
    }
  }
}
