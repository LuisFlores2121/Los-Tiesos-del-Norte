```C++
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("¡Hola Mundo desde Pico W!");
}

void loop() {
  // Realizar alguna acción en el bucle principal
  delay(1000); // Esperar 1 segundo
  Serial.println("¡Hola de nuevo desde Pico W!"); // Imprimir un mensaje adicional
}
```
