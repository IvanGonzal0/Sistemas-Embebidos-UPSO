#include <DHT.h>

#define DHTPIN 13        // Pin del sensor DHT11
#define DHTTYPE DHT11   // Tipo del sensor DHT (DHT11)
#define FAN_PIN 6       // Pin para el motor del ventilador
#define PUMP_PIN 7      // Pin para la bomba de agua
#define GREEN_LED 11    // Pin para el LED verde
#define RED_LED 12      // Pin para el LED rojo

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(FAN_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  // Inicializa el sensor DHT11
  dht.begin();
  
  // Apaga el motor del ventilador, la bomba de agua y el LED rojo
  digitalWrite(FAN_PIN, LOW);
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(RED_LED, LOW);
  
  // Enciende el LED verde para indicar que el sistema está funcionando
  digitalWrite(GREEN_LED, HIGH);
}

void loop() {
  // Lee la temperatura y la humedad
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Verifica la temperatura
  if (temperature >= 25.0) {
    // Si la temperatura es igual o superior a 25 grados, enciende el motor del ventilador
    digitalWrite(FAN_PIN, HIGH);
  } else {
    // De lo contrario, apaga el motor del ventilador
    digitalWrite(FAN_PIN, LOW);
  }
  
  // Verifica la humedad
  if (humidity <= 40) {
    // Si la humedad es menor o igual al 40%, enciende la bomba de agua y el LED verde
    digitalWrite(PUMP_PIN, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  } else {
    // De lo contrario, apaga la bomba de agua, el LED verde y enciende el LED rojo
    digitalWrite(PUMP_PIN, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  
  // Realiza una pausa para evitar lecturas demasiado frecuentes
  delay(2000);  // Puedes ajustar el valor de acuerdo a tus necesidades
}

