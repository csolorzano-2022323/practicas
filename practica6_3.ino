#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
#define DWH(pin)   digitalWrite(pin, HIGH)
#define DWL(pin)   digitalWrite(pin, LOW)
#define buzzer A1
#define L1 2
#define L2 3
#define L3 4
#define L4 5
#define L5 6
#define L6 7
#define L7 8
#define L8 9
#define L9 10
#define L10 A0

void  configPinesInput(void);
void  configpinesOutput(void);
int trig = 11;
int echo = 12;
int duracion;
int distancia;
int contador = 0;

void setup()
{
  LCD.init();
  LCD.backlight();
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  configpinesOutput();
}
void loop()
{
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
  Serial.print(String(distancia)); // La variable String guarda tipo de datos en cadenas
  Serial.println(" cm");
  delay(400);
  if (distancia >= 30 && distancia <= 45)
  {
    LCD.setCursor(0, 0);
    LCD.print("Persona/objeto  ");
    LCD.setCursor(0, 1);
    LCD.print("Acercandose     ");  


          if (distancia >= 46 && distancia <= 50) {
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, LOW);
            digitalWrite(L4, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);
          }
    if (distancia >= 40 && distancia <= 45) {
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, LOW);
            digitalWrite(L4, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);
          }
          if (distancia >= 35 && distancia <= 39) {
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);
          }
          if (distancia >= 30 && distancia <= 34) {
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);

    }
  }

  if (distancia >= 15 && distancia <= 29) {
    LCD.setCursor(0, 0);
    LCD.print("    Cuidado     ");
    LCD.setCursor(0, 1);
    LCD.print("Espacio Privado ");
    
    if (distancia >= 25 && distancia <= 29) {
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, HIGH);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);
          }
          if (distancia >= 20 && distancia <= 24) {
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, HIGH);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);
    }
          if (distancia >= 15 && distancia <= 19) {
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, HIGH);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, HIGH);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);
    }
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    delay(1000);
   
  }
      
  if (distancia >= 0 && distancia <= 14) {
  LCD.setCursor(0, 0);
    LCD.print("   Invadiendo   ");
    LCD.setCursor(0, 1);
    LCD.print("Espacio Privado ");
    
    if (distancia >= 10 && distancia <= 14) {
          digitalWrite(L1, HIGH);
          digitalWrite(L2, HIGH);
          digitalWrite(L3, HIGH);
          digitalWrite(L4, HIGH);
          digitalWrite(L5, HIGH);
          digitalWrite(L6, HIGH);
          digitalWrite(L7, HIGH);
          digitalWrite(L8, HIGH);
          digitalWrite(L9, LOW);
          digitalWrite(L10, LOW);
        }
        if (distancia >= 5 && distancia <= 9) {
          digitalWrite(L1, HIGH);
          digitalWrite(L2, HIGH);
          digitalWrite(L3, HIGH);
          digitalWrite(L4, HIGH);
          digitalWrite(L5, HIGH);
          digitalWrite(L6, HIGH);
          digitalWrite(L7, HIGH);
          digitalWrite(L8, HIGH);
          digitalWrite(L9, HIGH);
          digitalWrite(L10, LOW);
        }
        if (distancia >= 0 && distancia <= 5) {
          digitalWrite(L1, HIGH);
          digitalWrite(L2, HIGH);
          digitalWrite(L3, HIGH);
          digitalWrite(L4, HIGH);
          digitalWrite(L5, HIGH);
          digitalWrite(L6, HIGH);
          digitalWrite(L7, HIGH);
          digitalWrite(L8, HIGH);
          digitalWrite(L9, HIGH);
          digitalWrite(L10, HIGH);
        }
    
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);;
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    delay(1000);
  }
    
    if (distancia >= 46) {
      LCD.setCursor(0, 0);
      LCD.print("Fuera de alcanze");
      LCD.setCursor(0, 1);
      LCD.print("Fuera de alcanze");
            digitalWrite(L1, LOW);
            digitalWrite(L2, LOW);
            digitalWrite(L3, LOW);
            digitalWrite(L4, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L9, LOW);
            digitalWrite(L10, LOW);
    }
  
          
          

        
}

void  configpinesOutput(void) {

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
  pinMode(L9, OUTPUT);
  pinMode(L10, OUTPUT);

}
  
 
