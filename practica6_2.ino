/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: nombre y carnet en display
   alumno:Christian Solorzano
   Fecha: 28/4/2023 de abril
*/


#include <LiquidCrystal.h>

#define RS   12
#define enable 11
#define  D4  5
#define D5  4
#define D6  3
#define D7  2
#define DWH(pin)   digitalWrite(pin, HIGH)
#define DWL(pin)   digitalWrite(pin, LOW)
#define buzzer 8
void  configPinesInput(void);
void  configpinesOutput(void);
int trig = 9;
int echo = 10;
int duracion;
int distancia;
int contador=0;
int dis7;

LiquidCrystal LCD (RS, enable, D4, D5, D6, D7);
  
  void setup(){
    
  LCD.begin(16,2);  
  Serial.begin(9600); 
  configPinesInput();
  configpinesOutput();
  LCD.print("Conteo de "); 
  LCD.setCursor(0,2);
  LCD.print("Personas:  0");


}

void loop (){

  
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
  
  distancia= duracion*0.034/2;    
  Serial.print(String(distancia)); // La variable String guarda tipo de datos en cadenas
  Serial.println(" cm");
  delay(400);                      //la distancia que nos va a estar propocionarno 
                                   // El sensor es en "CM" gracias a la 
                                   //operacion de distancia
            



  if(distancia>=6 && distancia <=10) // Si la distancia es entre 6 y 10 hara lo que esta entre llaves
  {
    
    contador++;
     delay(1000);
      LCD.setCursor(0,0);
      LCD.print("Conteo de "); 
      LCD.setCursor(0,2);
      LCD.print("Personas: ");
      LCD.setCursor(11,2);
      LCD.print(contador);  
    } 
   
    if(contador>=16){

      contador=60;
      tone(buzzer, 659, 1000);     
      LCD.setCursor(0,0);
      LCD.print("AFORO MAXIMO DE ");
      LCD.setCursor(0,1);
      LCD.print("    PERSONAS    ");
      LCD.setCursor(0,0);
      delay(1000);
      LCD.print("                ");
      LCD.setCursor(0,1);
      LCD.print("                ");
      delay(1000);
      LCD.setCursor(0,0);
      tone(buzzer, 659, 1000);
      LCD.print("AFORO MAXIMO DE ");
      LCD.setCursor(0,1);
      LCD.print("    PERSONAS    ");
      delay(1000);
      
      
    }
                          
   }

 void  configPinesInput(void){
  pinMode(echo, INPUT);
  
 }

void  configpinesOutput(void)
{
     pinMode(trig, OUTPUT);  
     
                     
}
