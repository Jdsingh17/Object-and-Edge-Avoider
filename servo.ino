#include<Servo.h>
int trigPin=2;
int echoPin=3;
int count=0;
long duration;
int distance;
Servo servo;
void setup() {
  servo.attach(9);
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}
void stop1()
{
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
void left()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(100);
  stop1();
  delay(50);
}
void right()
{
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  delay(100);
  stop1();
  delay(50);
}
void back()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  delay(100);
  stop1();
  delay(200);
}
void forward()
{
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(100);
  stop1();
  delay(100);
}
void loop() 
{
  int a=digitalRead(10);
  int b=digitalRead(11);
  distance=calculateDistance();
  if(distance<=18)
  {
    stop1();
    Serial.println("180");
    servo.write(180);
    delay(1000);
    distance=calculateDistance();
    delay(500);
    Serial.println(distance);
    if(distance<=18)
    {
      Serial.println("0");
      servo.write(0);
      delay(1000);
      distance=calculateDistance();
      delay(500);
      if(distance<=18)
      {
        back();
        delay(200);
        back();
        Serial.println("back");
        left();
        delay(250);
        left();
        delay(250);
        count++;
      }
      if(count==0)
      {
       back();
       delay(200);
       Serial.println("right");
       right();
       delay(250); 
       right();
       delay(250);
       count++;
      }
    }
    if(count==0)
    {
     back();
     delay(200);
     Serial.println("left");
     left();
     delay(250);
     left();
     delay(250);   
    }
  }
  else if(b==0 && a==0)
  {

    back();
    delay(200);
    right();
    delay(100);
    right();
    delay(100);
    right();
    delay(100);
    
  }
  else if(b==0)
  {

    back();
    delay(200);
    right();
    delay(100);
    right();
    delay(100);
    right();
    delay(100);
 
    
  }
    else if(a==0)
  {

    back();
    delay(200);
    left();
    delay(100);
    left();
    delay(100);
    left();
    delay(100);

  }
  Serial.println("90");
  servo.write(90);
  delay(20);
  count=0;
  forward();
}
int calculateDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  return distance;
}
