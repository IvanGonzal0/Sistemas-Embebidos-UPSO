#include <SoftwareSerial.h>

// Definimos los pines para los LEDs y los motores
const int plantaBajaLED = 13;
const int plantaAltaLED = 12;
const int patioLED = 11;
const int alarmaLED = 8;
const int motorCochera = 10;
const int motorPorton = 9;
const int motorRiego = 7;

void setup() {
  // Inicializamos la comunicación serial
  Serial.begin(9600);

  // Inicializamos los pines de salida para LEDs y motores
  pinMode(plantaBajaLED, OUTPUT);
  pinMode(plantaAltaLED, OUTPUT);
  pinMode(patioLED, OUTPUT);
  pinMode(alarmaLED, OUTPUT);
  pinMode(motorCochera, OUTPUT);
  pinMode(motorPorton, OUTPUT);
  pinMode(motorRiego, OUTPUT);

  // Mensajes de inicio
  Serial.println("Bienvenido");
  delay(200);
  Serial.println("Inicializando el sistema");
  delay(200);
  Serial.println("Espere....");
  delay(2000);
  Serial.println("Sistema activo");
}

void loop() {
  // Leemos la entrada serial(lo que ingrese el usuario)
  if (Serial.available()) {
    char comando = Serial.read();
    // Convertimos a minúscula lo ingresado por el usuario antes de ejecutar el comando (con esto manejamos que sea indiferente si el caracter ingresado es una mayuscula)
    char comandoMinuscula = tolower(comando);
    ejecutarComando(comandoMinuscula);
  }
}

void ejecutarComando(char comando) {
  // Ejecutamos la acción correspondiente según el comando recibido para eso utilizamos un switch case
  switch (comando) {
    case 'a':
      encenderLED(plantaBajaLED, "Iluminacion de la planta baja encendida");
      break;
    case 'b':
      apagarLED(plantaBajaLED, "Iluminacion de la planta baja apagada");
      break;
    case 'c':
      encenderLED(plantaAltaLED, "Iluminacion de la planta alta encendida");
      break;
    case 'd':
      apagarLED(plantaAltaLED, "Iluminacion de la planta alta apagada");
      break;
    case 'e':
      encenderLED(patioLED, "Iluminacion del patio encendida");
      break;
    case 'f':
      apagarLED(patioLED, "Iluminacion del patio apagada");
      break;
    case '1':
      encenderLED(alarmaLED, "Alarma encendida");
      break;
    case '0':
      apagarLED(alarmaLED, "Alarma apagada");
      break;
    case '2':
      ejecutarMotor(motorCochera, "Aperturando cochera...", "Cochera aperturada");
      break;
    case '3':
      ejecutarMotor(motorCochera, "Cerrando cochera...", "Cochera cerrada");
      break;
    case '4':
      ejecutarMotor(motorPorton, "Aperturando porton...", "Porton aperturado");
      break;
    case '5':
      ejecutarMotor(motorPorton, "Cerrando porton...", "Porton cerrado");
      break;
    case '6':
      prenderMotor(motorRiego, "Encendiendo sistema de riego...", "Sistema de riego encendido");
      break;
    case '7':
      apagarMotor(motorRiego, "Apagando sistema de riego...", "Sistema de riego apagado");
      break;
    default:
      Serial.println("Comando no reconocido");
  }
}

// Realizamos funciones para encender y apagar los leds
// Esto nos permite una mejor lectura del código de programación
// Tuvimos que considerar el numero de pin de cada led y el comando elejido por el usuario, para encender las luces de la zona correcta(el comando que ingresa el usuario)
void encenderLED(int pinLED, const char* mensaje) {
  digitalWrite(pinLED, HIGH);
  Serial.println(mensaje);
}
// Funcion para apagar los leds
void apagarLED(int pinLED, const char* mensaje) {
  digitalWrite(pinLED, LOW);
  Serial.println(mensaje);
}
// Realizamos una función para ejecutar los motores de porton y cochera
// Esto lo pudimos lograr teniendo en cuenta el numero de pin del motor, para encender el motor correcto(el comando que ingresa el usuario)
void ejecutarMotor(int pinMotor, const char* mensajeInicio, const char* mensajeFin) {

  Serial.println(mensajeInicio);
  digitalWrite(pinMotor, HIGH);
  // Simulamos el tiempo de movimiento del motor (2 segundos)
  delay(2000);
  // Apagamos el motor
  digitalWrite(pinMotor, LOW);
  Serial.println(mensajeFin);
}

void prenderMotor(int pinMotor, const char* mensajeInicio, const char* mensajeFin) {
  Serial.println(mensajeInicio);
  digitalWrite(pinMotor, HIGH);
  Serial.println(mensajeFin);
}

void apagarMotor(int pinMotor, const char* mensajeInicio, const char* mensajeFin) {
  Serial.println(mensajeInicio);
  digitalWrite(pinMotor, LOW);
  Serial.println(mensajeFin);
}

//C:\Users\Ivan\AppData\Local\Temp\arduino\sketches\D12BC29DEC565D8EDEBAE845B41B5B74