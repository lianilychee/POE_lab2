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
Servo pan;  // servo object to control a servo (maximum eight servo objects can be created)
int pan_pos = 0;    // store servo position 
Servo tilt;
int tilt_pos = 0;
 
void setup() { 
  pan.attach(9);  // attaches the servo on pin 9 to the servo object 
  tilt.attach(10);
  Serial.begin(9600);
} 
 
void loop() { 
  
  for(pan_pos = 0; pan_pos < 180; pan_pos += 1){  // goes from 0 degrees to 180 degrees // in steps of 1 degree 
    
    pan.write(pan_pos);              // tell servo to go to position in variable 'pos' 
    Serial.print("Pan: ");
    Serial.println(pan_pos);
    delay(15);      // waits 15ms for the servo to reach the position 
    
    tilt_pos = tilt_pos + 5;
    tilt.write(tilt_pos);
    Serial.print("Tilt: ");
    Serial.println(tilt_pos);
    delay(15);
  }
  
  for(pan_pos = 180; pan_pos >= 1; pan_pos -= 1){     // goes from 180 degrees to 0 degrees 
  
    pan.write(pan_pos);              // tell servo to go to position in variable 'pos' 
    Serial.print("Pan: ");
    Serial.println(pan_pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
    
    tilt_pos = tilt_pos + 5;
    tilt.write(tilt_pos);
    Serial.print("Tilt: ");
    Serial.println(tilt_pos);
    delay(15);
  } 
}
