/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto:  cisterna
          alumno:Christian Solorzano 2022323
          Carlos Argueta 2022335
          Carlos Ceballlos 2022337
   Fecha: 12 De mayo
*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
int trig = 11;
int echo = 12;
int duracion;
int distancia;
int contador = 0;
#define LA  2
#define LB  3
#define LC  4
#define LD  5
#define LE  6
#define LF  7
#define LG  8
#define LH  9
#define BUZZER 10
#define LI  A0
#define LJ  A1

void setup()
{
  LCD.init();
  LCD.backlight();
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LC, OUTPUT);
  pinMode(LD, OUTPUT);
  pinMode(LE, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LG, OUTPUT);
  pinMode(LH, OUTPUT);
  pinMode(LI, OUTPUT);
  pinMode(LJ, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{


  // sensor ultrasonico
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor
  delay(10);
  digitalWrite(trig, HIGH);//Enciende el ping Triger del sensor
  delay(10);
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor


  //Encender y apagar el boton triger hace que este mandando pulsos cada
  // Medio segundo para que asi el boton ECHO reciba una onda de señal

  duracion = pulseIn(echo, HIGH); //devuelve un valor en microsegunso lo cual se
  // se envia a la variable duracion
  //Es la duracion de la cual se envia el pulso y se recibe

  distancia = duracion * 0.034 / 2;

  //LCD midiendo el agua
  int cm = distancia - 15;
  int cm2 = cm * -2;
  int cm3 = cm + cm2;
  LCD.setCursor(0, 0);
  LCD.print("  ");
  LCD.setCursor(0, 0);
  LCD.print(cm3);
  LCD.setCursor(2, 0);
  LCD.print("Cm de agua ");
  //LCD.setCursor(0, 1);
  //LCD.print(distancia);

  //Barra LED
  if (cm3 == 0) {
    digitalWrite(LA, LOW);
    digitalWrite(LB, LOW);
    digitalWrite(LC, LOW);
    digitalWrite(LD, LOW);
    digitalWrite(LE, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LG, LOW);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 1) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, LOW);
    digitalWrite(LC, LOW);
    digitalWrite(LD, LOW);
    digitalWrite(LE, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LG, LOW);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 3) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, LOW);
    digitalWrite(LD, LOW);
    digitalWrite(LE, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LG, LOW);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 4) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, LOW);
    digitalWrite(LE, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LG, LOW);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
    
  }
    if(cm3 <=4 && cm3 >=0){
      
      tone(BUZZER, 686, 1000);
      }

       else {
        noTone(BUZZER);
        
        }
  if (cm3 >= 6) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, HIGH);
    digitalWrite(LE, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LG, LOW);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 7) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, HIGH);
    digitalWrite(LE, HIGH);
    digitalWrite(LF, LOW);
    digitalWrite(LG, LOW);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 9) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, HIGH);
    digitalWrite(LE, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(LG, LOW);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 10) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, HIGH);
    digitalWrite(LE, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(LG, HIGH);
    digitalWrite(LH, LOW);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 12) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, HIGH);
    digitalWrite(LE, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(LG, HIGH);
    digitalWrite(LH, HIGH);
    digitalWrite(LI, LOW);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >= 13) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, HIGH);
    digitalWrite(LE, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(LG, HIGH);
    digitalWrite(LH, HIGH);
    digitalWrite(LI, HIGH);
    digitalWrite(LJ, LOW);
  }
  if (cm3 >=14) {
    digitalWrite(LA, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(LC, HIGH);
    digitalWrite(LD, HIGH);
    digitalWrite(LE, HIGH);
    digitalWrite(LF, HIGH);
    digitalWrite(LG, HIGH);
    digitalWrite(LH, HIGH);
    digitalWrite(LI, HIGH);
    digitalWrite(LJ, HIGH);
    tone(BUZZER, 261, 1000);
  }
if (cm3 >=14) {
  tone(BUZZER, 261, 1000);
}
 else {
  noTone(BUZZER);
  }
}
