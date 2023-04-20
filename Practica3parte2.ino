/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: SECUENCIA DE LUCES AUTOMATICAS 
   alumno: Christian Solorzano
   Fecha: 19 de abril
*/


void setup() {
 
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);

}

void loop() {

  for(int i=2;i<=11;i++){
  digitalWrite(i, HIGH);
  delay(100);
  digitalWrite(i, LOW);
 
  }
  for(int i=11;i>=2;i--){
  digitalWrite(i, HIGH);
  delay(100);
  digitalWrite(i, LOW);
  }
  }

  
  
