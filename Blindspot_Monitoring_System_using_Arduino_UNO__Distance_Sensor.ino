
#include <LiquidCrystal.h> 
LiquidCrystal LCD(11,10,9,2,3,4,5);  

#define red 6
#define green 7 
#define blue 8 

#define trigPin 13 
#define echoPin 12 

long duration;
double distance;

void setup() 
{  
  pinMode(green,OUTPUT);  
  pinMode(blue,OUTPUT);  
  pinMode(red,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  LCD.begin(16,2); 
  LCD.setCursor(0,0);  
  LCD.print("Target Distance:");  
  
  analogWrite(red, 0); 
  analogWrite(green, 0);
  analogWrite(blue, 0);

}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  LCD.setCursor(0,1);  
  LCD.print("                "); 
  LCD.setCursor(0,1);   
  LCD.print(distance); 
  LCD.print(" cm");  
  delay(250); 
  
  if(distance<10)
  {
  analogWrite(red, 225); 
  analogWrite(green, 0);
  }
  else if (distance>30)
  {
  analogWrite(red, 0); 
  analogWrite(green,225);
  }
  else 
  {
  analogWrite(red, 225); 
  analogWrite(green, 130);
  analogWrite(blue, 28);
  }
  delay(100);
}
