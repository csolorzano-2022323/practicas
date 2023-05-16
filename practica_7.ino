/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto:  Sensores y sus aplicaciones
   alumno:Christian Solorzano
   Fecha: 12 De mayo
*/
#include <Adafruit_NeoPixel.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
byte FA[8] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B01010,
  B01010,
  B01110
};
byte FE[8] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110
};
byte P[8] = {
  B01110,
  B01010,
  B01110,
  B00100,
  B01110,
  B10101,
  B01010,
  B10001
};
byte PC[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11101,
  B11111,
  B11111,
  B11111
};
byte PA[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
void  configPinesInput(void);
void  configpinesOutput(void);
#define radar 2
#define PIN  4
#define SM 3
#define NPIXEL 7
#define BUZZER 11 
#define RA 5
#define RB 6
#define BA 7
#define BB 8
#define BS 10
#define S  9
#define R 12
#define G A2
#define B A3
int contadorA = 0;
int contadorB = 0;
int contadorBS = 0;
int posicion = 0;
LiquidCrystal_I2C LCD(0x27, 16, 2);
Adafruit_NeoPixel led (NPIXEL, PIN, NEO_RGB + NEO_KHZ800);
Servo SERVO;
OneWire ourWire(S);
DallasTemperature sensor(&ourWire);

void setup() {
  LCD.init();
  LCD.backlight();
  led.begin();
  led.clear();
  LCD.createChar(0, P);
  LCD.createChar(1, FA);
  LCD.createChar(2, FE);
  LCD.createChar(3, PC);
  LCD.createChar(4, PA);
  configpinesOutput();
  configpinesOutput();
  LCD.setCursor(2, 0);
  LCD.write(1);
  LCD.setCursor(2, 1);
  LCD.write(1);
  SERVO.attach(3);
  LCD.setCursor(3, 0);
  LCD.print("PuertaCerrada");
  LCD.setCursor(1, 0);
  LCD.write(3);
  LCD.setCursor(1, 1);
  LCD.write(3);
  sensor.begin();
}

void loop() {
  sensor.requestTemperatures();
  int LEC = digitalRead(radar);
  
  if (LEC == HIGH) {
    led.setPixelColor(0, led.Color(193, 25, 27));
    led.setPixelColor(1, led.Color(193, 25, 27));
    led.setPixelColor(2, led.Color(193, 25, 27));
    led.setPixelColor(3, led.Color(193, 25, 27));
    led.setPixelColor(4, led.Color(193, 25, 27));
    led.setPixelColor(5, led.Color(193, 25, 27));
    led.setPixelColor(6, led.Color(193, 25, 27));
    led.show();
    LCD.setCursor(0, 0);
    LCD.write(0);
    LCD.setCursor(0, 1);
    LCD.write(0);
    LCD.setCursor(1, 0);
    LCD.write(4);
    tone(BUZZER, 523, 100);
  }
  
  else {
    led.setPixelColor(0, led.Color(27, 193, 25));
    led.setPixelColor(1, led.Color(27, 193, 25));
    led.setPixelColor(2, led.Color(27, 193, 25));
    led.setPixelColor(3, led.Color(27, 193, 25));
    led.setPixelColor(4, led.Color(27, 193, 25));
    led.setPixelColor(5, led.Color(27, 193, 25));
    led.setPixelColor(6, led.Color(27, 193, 25));
    led.show();
    LCD.setCursor(0, 0);
    LCD.print(" ");
    LCD.setCursor(0, 1);
    LCD.print(" ");
  }
  //RELE A
  if (digitalRead(BA) == HIGH) {
    contadorA++;
    LCD.setCursor(2, 0);
    LCD.write(1);
    delay(500);

  }
  switch (contadorA) {
    case (1):
      digitalWrite(RA, HIGH);
      LCD.setCursor(2, 0);
      LCD.write(2);
      break;
    case (2):
      digitalWrite(RA, LOW);
      contadorA = contadorA - 2;
      LCD.setCursor(2, 0);
      LCD.write(1);
      break;
  }

  // RELE B
  if (digitalRead(BB) == HIGH) {
    contadorB++;
    LCD.setCursor(2, 1);
    LCD.write(1);
    delay(500);
  }
  
  switch (contadorB) {
    case (1):
      digitalWrite(RB, HIGH);
      LCD.setCursor(2, 1);
      LCD.write(2);
      break;
    case (2):
      digitalWrite(RB, LOW);
      contadorB = contadorB - 2;
      LCD.setCursor(2, 1);
      LCD.write(1);
      break;
  }

   //SERVO
  if (digitalRead(BS) == HIGH) {
    contadorBS++;
    delay(500);
  }
  switch (contadorBS) {
    case (1):
      LCD.setCursor(3, 0);
      LCD.print("PuertaAbierta");
      SERVO.write(90);
      LCD.setCursor(1, 0);
      LCD.write(4);
      LCD.setCursor(1, 1);
      LCD.write(4);
      break;

    case (2):
      contadorBS =contadorBS- 2;
      LCD.setCursor(3, 0);
      LCD.print("PuertaCerrada");
      SERVO.write(0);
      LCD.setCursor(1, 0);
      LCD.write(3);
      LCD.setCursor(1, 1);
      LCD.write(3);
      break;
  }
//  temperatura
  LCD.setCursor(3, 1);
  LCD.print("GradosC");
  LCD.setCursor(12, 1);
  LCD.print(sensor.getTempCByIndex(0));

  //LED MORADO
  if (sensor.getTempCByIndex(0) >= 15 && sensor.getTempCByIndex(0) <= 21) {
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  }
  else {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
  //LED VERDE
  if (sensor.getTempCByIndex(0) >= 21 && sensor.getTempCByIndex(0) <= 25) {
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  }
  else {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
  //LED ROJO
  if (sensor.getTempCByIndex(0) >= 26 && sensor.getTempCByIndex(0) <= 45) {
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
  else {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }





}

void  configPinesInput(void) {
  pinMode(radar, INPUT);
  pinMode(BA, INPUT);
  pinMode(BB, INPUT);
}
void  configpinesOutput(void) {

  pinMode(RA, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);


}
