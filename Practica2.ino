/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Encender un led por medio de un pulsador
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 30 de marzo
*/
#define BA  2    //Se define que el pin 2, se llamara BA que significa Boton A
#define BB  3     //Se define que el pin 3, se llamara BA que significa Boton b
int contador=1;  //Se define una variable, que servira como el contador  

struct productos    // Definimos la estructura de nuestros datos
{
  char items[25];   //De finimos el tipo de variable que usaremos
  float precio;
  int stock;
  int cantidad;
};
productos P1 = {"Tortrix de barbacoa",1.00,2,1.50};  //Estos son nuestros productos los cuales son parte del struc: productos
productos P2 = {"Picarones",1.00,20,50};
productos P3 = {"Pingles",5.00,7,25};
productos P4 = {"Chetos",5.00,10,20};
productos ricitos []= {P1,P2,P3,P4}; // Aqui definimos cuantos productos tenemos a partir de los datos anteriores



void setup() {

  pinMode(BA, INPUT);
  pinMode(BB, INPUT);
  Serial.begin(9600);
  Serial.println("___________________");   //Menu de inicio
  Serial.println("|                 |");
  Serial.println("|____Bienvenido___|");
  Serial.println("|                 |");
  Serial.println("|_________________|");
 
}
void loop() {

          if(digitalRead(BA)==HIGH) //DigitalRead leera si el BA esta prendido o apagado
                                    // y el If hace que si el boton esta en HIGH
                                    //se ejecutara lo que se encuentra entre llaves{}
          {
            delay(100); //es el antirebote que se puede generar
         contador++;
          if(contador>3) contador=0;
 
       
          Serial.println("Productos disponibles");
          Serial.println("Nombre De Producto:");
          Serial.println(ricitos[contador].items);  //Es el struct con la variables
          Serial.println("Precio:");
          Serial.println(ricitos[contador].precio);
          Serial.println("Stock:");
          Serial.println(ricitos[contador].stock);
          Serial.println("Cantidad:");
          Serial.println(ricitos[contador].cantidad);
          delay(1000);  
    }

     if(digitalRead(BB)==HIGH)      //DigitalRead leera si el BA esta prendido o apagado
                                    // y el If hace que si el boton esta en HIGH
                                    //se ejecutara lo que se encuentra entre llaves{}
     {
      delay(100); //es el antirebote que se puede generar
      contador--;
     
      if(contador<-2)  contador=3;
          Serial.println("Productos disponibles");
          Serial.println("Nombre De Producto:");
          Serial.println(ricitos[contador].items); //Es el struct con la variables
          Serial.println("Precio:");
          Serial.println(ricitos[contador].precio);
          Serial.println("Stock:");
          Serial.println(ricitos[contador].stock);
          Serial.println("Cantidad:");
          Serial.println(ricitos[contador].cantidad);
          delay(1000);
     
     }
}
