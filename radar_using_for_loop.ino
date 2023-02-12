#include <Servo.h>
Servo myservo; // create servo object to control a servo
int angle = 0; // variable to store the servo position

#define echoPin 9 // Echo Pin
#define trigPin 8 // Trigger Pin

int duration;
float distance;

void setup()
{
  myservo.attach(5); // attaches the servo on pin 5 to the servo object
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop()
{
  for(angle = 0; angle < 180; angle += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    myservo.write(angle); // tell servo to go to position in variable 'angle'
    distance= measure_distance();
    Serial.println(angle);
    Serial.println(distance);
    delay(20); // waits 20ms between servo commands
  }


  for(angle = 180; angle >= 1; angle -= 1) // goes from 180 degrees to 0 degrees
  {
    myservo.write(angle); // tell servo to go to position in variable 'pos'
    distance= measure_distance();
    Serial.println(angle);
    Serial.println(distance);
    delay(20); // waits 20ms between servo commands
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

