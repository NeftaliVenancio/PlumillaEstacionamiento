#include <Servo.h>

Servo plumilla;

int pos = 0; 

int a = 4;
int b = 5;
int c = 6;
int d = 7;
int e = 8;
int f = 10;
int g = 11;

int s1 = 1;
int s2 = 12;

int cont;

int distancia;

//Funcion para lectura del sensor ultrasonico

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Colocar en alto durante 10uS
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return 0.01723 * pulseIn(echoPin, HIGH);
}


void showDisplay(int n)
{
  switch (n)
  {
      case 0:
          //cero
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH);
          digitalWrite(e,HIGH);
          digitalWrite(f,HIGH);
          digitalWrite(g,LOW);
          break;
      case 1:
          //Uno
          digitalWrite(a,LOW);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW);
          digitalWrite(e,LOW);
          digitalWrite(f,LOW);
          digitalWrite(g,LOW);
          break;
      case 2:
          //Dos
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,LOW);
          digitalWrite(d,HIGH);
          digitalWrite(e,HIGH);
          digitalWrite(f,LOW);
          digitalWrite(g,HIGH);
          break;
      case 3:
          //Tres
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH);
          digitalWrite(e,LOW);
          digitalWrite(f,LOW);
          digitalWrite(g,HIGH);
          break;
      case 4:
          //Cuatro
          digitalWrite(a,LOW);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW);
          digitalWrite(e,LOW);
          digitalWrite(f,HIGH);
          digitalWrite(g,HIGH);
          break;
      case 5:
          //Cinco
          digitalWrite(a,HIGH);
          digitalWrite(b,LOW);
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH);
          digitalWrite(e,LOW);
          digitalWrite(f,HIGH);
          digitalWrite(g,HIGH);
          break;
      case 6:
          //Seis
          digitalWrite(a,HIGH);
          digitalWrite(b,LOW);
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH);
          digitalWrite(e,HIGH);
          digitalWrite(f,HIGH);
          digitalWrite(g,HIGH);
          break;
      case 7:
          //Siete
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW);
          digitalWrite(e,LOW);
          digitalWrite(f,LOW);
          digitalWrite(g,LOW);
          break;
      case 8:
        //Ocho
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH);
          digitalWrite(e,HIGH);
          digitalWrite(f,HIGH);
          digitalWrite(g,HIGH);
          break;
      case 9:
        //Nueve
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW);
          digitalWrite(e,LOW);
          digitalWrite(f,HIGH);
          digitalWrite(g,HIGH);
          break;
      
  }
}




void setup() 
{
  
  plumilla.attach(9);

  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  
}

void loop() 
{

  cont = digitalRead(s1) + digitalRead(s2);
  showDisplay(cont);
  delay(100);
  
  distancia = readUltrasonicDistance(2,3);
  
  if(distancia <= 100)
  {
    pos = 90;
    plumilla.write(pos);
  }
  else
  { 
    pos = 0;
  }
  
  plumilla.write(pos);
  
  if(pos == 90)
  {
   for (int i = 90; i >= 0; i--) 
   {
     
     distancia = readUltrasonicDistance(2,3);
     if(distancia > 100)
     {
     plumilla.write(i);
     }
     else
     {
       i = 90;
       plumilla.write(i);
     }
     
   }
  }
  
}
