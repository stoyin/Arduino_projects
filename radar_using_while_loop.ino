#include<Servo.h>
int spin=6;
Servo myservo;
int angle=0;
int max_angle=180;
int min_angle=0;

#define echoPin 9 // Echo Pin
#define trigPin 8 // Trigger Pin
int duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(spin);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(angle<=max_angle){
  myservo.write(angle);
  distance= measure_distance();
  angle= angle+1;
  Serial.println(angle);
  Serial.println(distance);
  delay(20);
  }

  while(angle>=min_angle){
  myservo.write(angle);
  distance= measure_distance();
  angle= angle-1;
  Serial.print(angle);
  Serial.println(distance);
  delay(20);
  }
}

float measure_distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration;
  }
