// Libs necesarias para el desarrolo del proyecto
#include <DHT.h>
#include <LiquidCrystal.h>

// Config del DHT11
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Config de la pantalla LCD
LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2); // Pines para el LCD: RS, RW, E, D4, D5, D6, D7
// Config de leds
int ledVerde = 11;
int ledRojo = 12;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // Inicia el LCD de 16x2

  // Pantalla de inicio 1
  lcd.setCursor(0, 0);
  lcd.print("TriARG Ltda.");
  lcd.setCursor(0, 1);
  lcd.print("Bahia Blanca");
  delay(1000);
  lcd.clear();
  // Pantalla de inicio 2
  lcd.setCursor(0, 0);
  lcd.print("Automatizacion");
  lcd.setCursor(0, 1);
  lcd.print("Temp / Humd");
  delay(2000);
  lcd.clear();
  // Inicia los pines apagados
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  // Inicializa el sensor DHT11
  dht.begin();
}

void loop() {
  // Variables para almacenar temperatura y humedad
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();
  // Variables para almacenar la diferencia que hay con la temperatura y humedad ideal
  float tempDif = temperatura - 25;
  float humDif = humedad - 40;
  // Config de la pantalla lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.setCursor(0, 1);
  lcd.print("Humd: ");
  lcd.print(humedad);

  // Diferencia de temperatura y humedad print por terminal 
  String tempStr = "La diferencia de temperatura es: " + String(tempDif, 2);
  String humStr = "La diferencia de humedad es: " + String(humDif, 2);
  Serial.println(tempStr);
  Serial.println(humStr);

  // Condiciones para los leds dependiendo de la temp o humedad
  if (temperatura >= 25) {
    digitalWrite(ledVerde, HIGH);
    // aca muestro por terminal si el led esta encendido o apagado dependiendo de la condicion
    Serial.println("Led 1 encendido");
  } else {
    digitalWrite(ledVerde, LOW);
    Serial.println("Led 1 apagado");
  }

  if (humedad <= 40) {
    digitalWrite(ledRojo, HIGH);
    // aca muestro por terminal si el led esta encendido o apagado dependiendo de la condicion
    Serial.println("Led 2 encendido");
  } else {
    digitalWrite(ledRojo, LOW);
    Serial.println("Led 2 apagado");
  }

  delay(2000);
}
