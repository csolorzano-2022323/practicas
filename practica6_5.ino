/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: sensor de temperatura
   alumno: Christian Solorzano
   Fecha: 5 de Mayo
*/
#include <LiquidCrystal_I2C.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#define S 2
LiquidCrystal_I2C LCD(0x27, 16, 2);
OneWire ourWire(S);
DallasTemperature sensor(&ourWire);
#define LR 3
#define LA 4
#define LAM 5



void setup() {
  LCD.init();
  LCD.backlight();
  delay(1000);
  sensor.begin();
  pinMode(LR, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(LAM, OUTPUT);

}

void loop() {

  sensor.requestTemperatures();

  LCD.setCursor(0, 0);
  LCD.print("Grados C");
  LCD.setCursor(9, 0);
  LCD.print(sensor.getTempCByIndex(0));
  LCD.setCursor(0, 1);
  LCD.print("Grados F");
  LCD.setCursor(9, 1);
  LCD.print(sensor.getTempFByIndex(0));

  if (sensor.getTempCByIndex(0) >= 30) {
    digitalWrite(LR, HIGH);
  }
  else {
    digitalWrite(LR, LOW);
  }
  if (sensor.getTempCByIndex(0) <= 16) {
    digitalWrite(LA, HIGH);
  }
  else {
    digitalWrite(LA, LOW);
  }
  if (sensor.getTempCByIndex(0) >= 16 && sensor.getTempCByIndex(0) <= 30) {
    digitalWrite(LAM, HIGH);
  }
  else {
    digitalWrite(LAM, LOW);
  }






}
