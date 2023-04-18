/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: CONTROL DE UN LED RGB POR MEDIO DE BOTONES 
   alumno: Christian Solorzano
   Fecha: 18 de abril
*/
#define BA 2
#define BB 3
#define R 4
#define G 5
#define B 6

  void setup() {

          pinMode(BA,INPUT);
          pinMode(BB,INPUT);
          pinMode(R,OUTPUT);
          pinMode(G,OUTPUT);
          pinMode(B,OUTPUT);
         
}

void loop() {

    if(digitalRead(BA)==LOW && digitalRead(BB)==LOW){

    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    delay(500);
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
    delay(500);
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
    delay(500);
    }

    if(digitalRead(BA)==HIGH){
    
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
    
    }
    
    if(digitalRead(BB)==HIGH){
    
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
    
    }
    
    if(digitalRead(BA)==HIGH & digitalRead(BB)==HIGH){
    
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
    delay(500);
    }
  
}
