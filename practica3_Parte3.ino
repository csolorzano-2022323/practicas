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

//Librerias
#include <Keypad.h>    //Libreria que me permite usar el teclado matricial.

//Macros o directivas de preprocesador
#define filas 4   //cantidad de filas que posee el teclado matricial.
#define columnas 4 //cantidad de columnas que posee el teclado matricial.
#define f1 2  //pin2 conectado a la fila 1
#define f2 3  //pin3 conectado a la fila 2
#define f3 4  //pin4 conectado a la fila 3
#define f4 5  //pin5 conectado a la fila 4
#define c1 6  //pin6 conectado a la columna 1
#define c2 7  //pin7 conectado a la columna 2
#define c3 8  //pin8 conectado a la columna 3
#define c4 9  //pin9 conectado a la columna 4
#define a 10
#define b 11
#define c A0
#define d A1
#define e A2
#define f A3
#define g A4


//Creo una matriz led con la disposicion fisica de las teclas
char keys[filas][columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Arreglos en los que defino los pines a utilizar, tanto para las columnas como para las filas
byte PF[filas] = {f1,f2,f3,f4};
byte PC[columnas] = {c1,c2,c3,c4};


//Creo el constructor para poder usar el teclado matricial.
Keypad teclado1 = Keypad( makeKeymap(keys), PF, PC, filas,columnas);




void setup() 
{
  Serial.begin(9600);    //Inicio la comunicacion serial.
  Serial.println("Prueba del teclado matricial");   //Envio de mensaje
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() 
{
  char tecla = teclado1.getKey();  //Obtengo la tecla que presione

      //Si ninguna tecla a sido presionada
      
                digitalWrite(a, HIGH);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, LOW);
                
  //Si alguna tecla ha sido presionada
  switch(tecla){
  case('1'):
  {
                digitalWrite(a, LOW);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);

                delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
  }
  case('2'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, HIGH);
                digitalWrite(c, LOW);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, LOW);
                digitalWrite(g, HIGH);
    
                delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;}
  case('3'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, HIGH);
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
  }
  case('4'):
  {
                digitalWrite(a, LOW);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH);
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
  }
  case('5'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, LOW);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, LOW);
                digitalWrite(f, HIGH);  
                digitalWrite(g, HIGH);
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  case('6'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, LOW);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH);
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;  }
  case('7'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  case('8'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH); 
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  case('9'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, LOW);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH);
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
    break;
                }
  case('*'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH); 
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  case('#'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH);  
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  case('A'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, LOW);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH);  
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
   case('B'):
  {
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, HIGH); 
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  case('C'):
  {
                digitalWrite(a, HIGH);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, HIGH);
                digitalWrite(g, LOW);
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  case('D'):
  {
                digitalWrite(a, LOW);
                digitalWrite(b, HIGH);
                digitalWrite(c, HIGH);
                digitalWrite(d, HIGH);
                digitalWrite(e, HIGH);
                digitalWrite(f, LOW);
                digitalWrite(g, HIGH); 
    delay(1000);
                digitalWrite(a, LOW);
                digitalWrite(b, LOW);
                digitalWrite(c, LOW);
                digitalWrite(d, LOW);
                digitalWrite(e, LOW);
                digitalWrite(f, LOW);
                digitalWrite(g, LOW);
                break;
                }
  }
}  
