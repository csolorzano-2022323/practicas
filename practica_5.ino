 /*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: thimer
   alumno:Christian Solorzano
   Fecha: 27 de abril
*/

#define DWH(pin)   digitalWrite(pin, HIGH)
#define DWL(pin)   digitalWrite(pin, LOW)
void  configPinesInput(void);
void  configpinesOutput(void);
int trig = 11;
int echo = 12;
int duracion;
int distancia;
int buzzer = 2;
#define NDO 523
#define NRE 587
#define NMI 659
#define NFA 698
#define NSOL 783
#define NLA 880
#define NSI 900

void setup() {
  Serial.begin(9600); 
  configPinesInput();
  configpinesOutput();
}

void loop() {
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
  Serial.println("cm");
  delay(400);                      //la distancia que nos va a estar propocionarno 
                                   // El sensor es en "CM" gracias a la 
                                   //operacion de distancia

 
 if(distancia>=5 && distancia <=10){

   tone(buzzer, NDO, 1000);
   
 }
 if(distancia>=11 && distancia <=15){

   tone(buzzer, NRE, 1000);
  
 }
 if(distancia>=16 && distancia <=20){

   tone(buzzer, NMI, 1000);
   
 }
 if(distancia>=21 && distancia <=25){

   tone(buzzer, NFA, 1000);
   
 }
 if(distancia>=26 && distancia <=30){

   tone(buzzer, NSOL, 1000);
  
 }
 if(distancia>=31 && distancia <=35){

   tone(buzzer, NLA, 1000);
   
 }
 if(distancia>=36 && distancia <=40){

   tone(buzzer, NSI, 1000);
   
 }
 
 if(distancia>=0 && distancia <=5)
   noTone(buzzer);
   

 if(distancia>=41){
   noTone(buzzer);
   
 }
}

void  configPinesInput(void){
  pinMode(echo, INPUT); 
 }

void  configpinesOutput(void)
{ 
     pinMode(trig, OUTPUT);
     pinMode(buzzer, OUTPUT);                      
}
