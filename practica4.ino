 /*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: keypad
   alumno:Christian Solorzano
   Fecha: 20 de abril
*/

#define led  2


#define DWH(pin)   digitalWrite(pin, HIGH)
#define DWL(pin)   digitalWrite(pin, LOW)
void  configPinesInput(void);
void  configpinesOutput(void);
int   contador_display(int a, int b, int c, int d, int e, int f, int g, int B);
int trig = 11;
int echo = 12;
int duracion;
int distancia;
int contador=0;
int dis7;

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
  Serial.println(" cm");
  delay(400);                      //la distancia que nos va a estar propocionarno 
                                   // El sensor es en "CM" gracias a la 
                                   //operacion de distancia

  if(distancia>=6 && distancia <=10) // Si la distancia es entre 6 y 10 hara lo que esta entre llaves
  {
    digitalWrite(led, HIGH);
    contador++;
     delay(1000);
    } 
  else  // de lo contrario hara esta otra opcion 
  {
    digitalWrite(led, LOW);
    }

    contador_display(3,4,5,6,7,8,9,10);

           
          
     
}
 void  configPinesInput(void){
  pinMode(echo, INPUT);
  
 }

void  configpinesOutput(void)
{
     pinMode(led, OUTPUT);
     pinMode(trig, OUTPUT);  
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT);
     pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT);           
                     
}
int   contador_display(int a, int b, int c, int d, int e, int f, int g, int B){
switch(contador){
          
          case(0):
              DWH(a);
              DWH(b);
              DWH(c);
              DWH(d);
              DWH(e);
              DWH(f);
              DWL(g);
            break;
          case(1):
            DWL(a);
            DWH(b);
            DWH(c);
            DWL(d);
            DWL(e);
            DWL(f);
            DWL(g);
         break;
           case(2):
            DWH(a);
            DWH(b);
            DWL(c);
            DWH(d);
            DWH(e);
            DWL(f);
            DWH(g);
         break;
          case(3):
            DWH(a);
            DWH(b);
            DWH(c);
            DWH(d);
            DWL(e);
            DWL(f);
            DWH(g);
         break;
          case(4):
            DWL(a);
            DWH(b);
            DWH(c);
            DWL(d);
            DWL(e);
            DWH(f);
            DWH(g);
         break;                
          case(5):
            DWH(a);
            DWL(b);
            DWH(c);
            DWH(d);
            DWL(e);
            DWH(f);
            DWH(g);
         break;       
          case(6):
            DWH(a);
            DWL(b);
            DWH(c);
            DWH(d);
            DWH(e);
            DWH(f);
            DWH(g);
         break;        
          case(7):
            DWH(a);
            DWH(b);
            DWH(c);
            DWL(d);
            DWL(e);
            DWL(f);
            DWL(g);
         break;
          case(8):
            DWH(a);
            DWH(b);
            DWH(c);
            DWH(d);
            DWH(e);
            DWH(f);
            DWH(g);
         break;
           case(9):
            DWH(a);
            DWH(b);
            DWH(c);
            DWH(d);
            DWL(e);
            DWH(f);
            DWH(g);
            DWH(B);
            contador=9;
         break; 
             
    }
  
}
