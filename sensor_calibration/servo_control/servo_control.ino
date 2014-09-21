// Control the pan/tilt mechaism.
// Record input for MATLAB analysis.

// A hobby servo is controlled using a square wave form that is pulsed at a fixed frequency. 
// The time that the waveform signal is set to “on” determines what the position of the shaft should be. 
// This scheme is called “pulse width modulation” (PWM) and the percentage of “on” time during the period
// is called the “duty cycle”. Most hobby servos use a pulse width of between 1ms and 2ms
// (sometimes the range can be as wide as 0.8ms to 2.2ms).


// Built off of sweep by BARRAGAN <http://barraganstudio.com> (public domain).

#include <Servo.h> 
 
// Initialize servos
Servo servo1;  // servo object to control a servo (maximum eight servo objects can be created)
int pos1 = 0;    // store servo position 
Servo servo2;
int post2 = 0;
 
void setup() { 
  servo1.attach(8);  // attaches the servo on pin 9 to the servo object 
  servo2.attach(9);
  Serial.begin(9600);
} 
 
void loop() { 
  for(pos1 = 0; pos1 < 180; pos1 += 1){  // goes from 0 degrees to 180 degrees // in steps of 1 degree 
    servo1.write(pos1);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos1);
    delay(15);      // waits 15ms for the servo to reach the position 
  }
  for(pos1 = 180; pos1 >= 1; pos1 -= 1){     // goes from 180 degrees to 0 degrees 
    servo1.write(pos1);              // tell servo to go to position in variable 'pos' 
    Serial.println(pos1);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
