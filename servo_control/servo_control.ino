// Control the pan/tilt mechaism.
// Record input for MATLAB analysis.

// A hobby servo is controlled using a square wave form that is pulsed at a fixed frequency. 
// The time that the waveform signal is set to “on” determines what the position of the shaft should be. 
// This scheme is called “pulse width modulation” (PWM) and the percentage of “on” time during the period
// is called the “duty cycle”. Most hobby servos use a pulse width of between 1ms and 2ms
// (sometimes the range can be as wide as 0.8ms to 2.2ms).

// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int pos = 0;    // variable to store the servo position 
 
void setup() { 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() { 
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
