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

LiquidCrystal LCD (RS, enable, D4, D5, D6, D7);
  
  void setup(){
    
  LCD.begin(16,2);  
  LCD.print("Christian");
  LCD.setCursor(0,1);
  LCD.print("2022323");

}

void loop (){

}
