#include <Servo.h>          // Incluir la librería Servo
Servo servoRight;    // Crear un objeto tipo Servo llamado servo1
Servo servoLeft;
int anguloRight = 0 ;
int anguloLeft = 0;

void setup()
{
   servoRight.attach(9) ;  // Conectar servo1 al pin 9
   servoLeft.attach(10);
   Serial.begin(9600);
}

void loop()
{
   anguloRight  = map( analogRead(A0), 0, 1024, 0, 1024);

   if(anguloRight < 100)
    cerrar();
    else
    abrir();
   
   Serial.println(anguloRight);
   delay(250);
}

void abrir()
{
  servoRight.write(30);
  servoLeft.write(105);
}

void cerrar()
{
  servoRight.write(90);
  servoLeft.write(45);
}

