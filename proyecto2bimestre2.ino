#define rele1 2 // bomba de agua del suministro de agua para llenar el tinaco
// si esta vacio el tinaco esta bomba lo llenara con una deteccion automatica (transistor)

#define rele2 3 // bomba de agua de extraccion de agua del tinaco
//si deseo obtener agua del tinaco accionare un boton que hará actuar esta bomba

#define sensor 4 // transistor para deteccion automatica de agua
//si esta lleno o no el tinaco este transistor se encargara de detectarlo y otorgara una lectura

#define push 5 // función de interruptor para extraccion de agua del tinaco

// entradas y salidas :D
void setup()
{
  pinMode (rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(push, INPUT);
  pinMode(sensor, INPUT);
}


void loop() {
  //guardar el estado de la lectura _____ en variable falsa/verdadera
  bool estado = digitalRead(push);
  bool estadoled = digitalRead(sensor);

  //entro al if si el boton esta en bajo
  if (estado == LOW)
    //mantengo la accion ejecutada si se cumple la condicion o no
    //! la niego para continuar la ejecucion en sentido contrario (devolver valor opuesto al obtenido)
  {
    digitalWrite(rele2,  !digitalRead(rele2) );
    //delay para evitar cambios de estado erroneos al detectar lectura en el boton
    delay(300);
  }

  //leo los estados del led que reaccionara como referencia al transistor usado como sensor
  //Actuo y acciono el rele(bomba de agua) dependiendo del estado del led de referencia
  if (estadoled == LOW)
  {
    digitalWrite(rele1, HIGH);
    delay(200);
  }
  if (estadoled == HIGH)
  {
    digitalWrite(rele1, LOW);
    delay(200);
  }
}
