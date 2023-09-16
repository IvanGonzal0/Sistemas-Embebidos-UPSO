// Definición de pines
const int rojoPin = 13;
const int naranjaPin = 12;
const int verdePin = 11;

void setup() {
  // Configuración de los pines como salidas
  pinMode(rojoPin, OUTPUT);
  pinMode(naranjaPin, OUTPUT);
  pinMode(verdePin, OUTPUT);
}

void loop() {
  // Encendido del LED rojo
  digitalWrite(rojoPin, HIGH);
  delay(3000);  // 3 segundos
  digitalWrite(rojoPin, LOW);
  delay(100);   // 100 ms de espera

  // Encendido del LED naranja
  digitalWrite(naranjaPin, HIGH);
  delay(1000);  // 1 segundo
  digitalWrite(naranjaPin, LOW);
  delay(100);   // 100 ms de espera

  // Encendido del LED verde
  digitalWrite(verdePin, HIGH);
  delay(1500);  // 1.5 segundos
  digitalWrite(verdePin, LOW);
  delay(100);   // 100 ms de espera
}