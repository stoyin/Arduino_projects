#include<Servo.h>
int angle=6;
int trigPin=8; //Sensor Trig pin connected to Arduino pin 13
int echoPin=7;  //Sensor Echo pin connected to Arduino pin 11
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
int openUp=0;
int closeDown=90;
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(angle);
  pinMode(trigPin, OUTPUT);
  pinMode(angle, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.write(closeDown);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(5); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(10); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent

  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
//  pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
// 
//  targetDistance= speedOfSound * pingTime;  //This will be in miles, since speed of sound was miles per hour
//  targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance=(pingTime/2) / 29.1;
  
  Serial.println(targetDistance);

  
  delay(500); //delay tenth of a  second to slow things down a little.

  if (targetDistance < 20){
    myservo.write(openUp);
  }else{
    myservo.write(closeDown);
    }
  
}
