#include <SoftwareSerial.h>
// Config del bluetooth
SoftwareSerial bluetooth(0, 1); // RX, TX

// Definicion de LEDs
const int plantaBaja = 13;
const int plantaAlta = 12;
const int patio = 11;
const int garage = 10;
const int porton = 9;
const int alarma = 8;

// Funcion de inicio
void setup() {
  // Serial SETUP
  Serial.begin(9600);
  //LEDS configuracion todo apagado
  pinMode(plantaBaja, OUTPUT);
  pinMode(plantaAlta, OUTPUT);
  pinMode(patio, OUTPUT);
  pinMode(alarma, OUTPUT);

  // RELAYS todo apagado
  pinMode(garage, OUTPUT);
  pinMode(porton, OUTPUT);
  
  // Bluetooth
  bluetooth.begin(9600);
}

// Funcion bucle
void loop() {
  // Aca voy a hacer una validación para ver si el Serial esta funcionando y cuando el usuario toque una tecla la voy a capturar en la variable char command
  // ese char capturado se lo voy a pasar a la función processCommand, la cual tiene el switch para evaluar el caso y hacer lo que ingrese el usuario
  if (Serial.available()) {
    char command = Serial.read();
    processCommand(command);
  }
}
// Funcion processCommand recibe el caracter ingresado por el usuario, y luego evalua el caso dentro de un switch
// entonces dependendiendo de lo ingresado por el usuario sera la accion que realizara
void processCommand(char command) {
  switch (command) {
    case 'A':
    case 'a':
      digitalWrite(plantaBaja, HIGH); //enciende planta baja
      break;
    case 'B':
    case 'b':
      digitalWrite(plantaBaja, LOW);  //apaga planta baja
      break;
    case 'C':
    case 'c':
      digitalWrite(plantaAlta, HIGH); //enciende planta alta
      break;
    case 'D':
    case 'd':
      digitalWrite(plantaAlta, LOW);  //apaga planta baja
      break;
    case 'E':
    case 'e':
      digitalWrite(patio, HIGH);  //enciende patio
      break;
    case 'F':
    case 'f':
      digitalWrite(patio, LOW);   //apaga patio
      break;
    case '1':
      digitalWrite(alarma, HIGH); //enciende alarma
      break;
    case '0':
      digitalWrite(alarma, LOW);  //apaga alarma
      break;
    case '2':
      digitalWrite(garage, HIGH); //activa garage
      break;
    case '3':
      digitalWrite(garage, LOW);  //desactiva garage
      break;
    case '4':
      digitalWrite(porton, HIGH); //activa porton
      break;
    case '5':
      digitalWrite(porton, LOW);  //desactiva porton
      break;
  }
}

