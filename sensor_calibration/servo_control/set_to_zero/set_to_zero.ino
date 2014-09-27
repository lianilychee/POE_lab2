#include <Servo.h> 

// Servo definition
Servo pan;  // servo object to control a servo (maximum eight servo objects can be created)
Servo tilt;

void setup() { 
  pan.attach(9);  // attaches the servo on pin 9 to the servo object 
  tilt.attach(10);
  Serial.begin(9600);
} 

void loop() { 
  tilt.write(0);
  pan.write(0); 
}

