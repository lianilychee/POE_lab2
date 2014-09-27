#include <Servo.h> 
 
// Servo definition
Servo pan;  // servo object to control a servo (maximum eight servo objects can be created)
int pan_pos = 0;    // store servo position 
Servo tilt;
int tilt_pos = 0;

// Pin definition
const float analogInPin = A0;  // Infrared sensor to Analog
float sensorVal = 0;        // value read from the infrared sensor
float v = 0;    // voltage output
float dist = 0;    // distance in cm
 
void setup() { 
  pan.attach(9);  // attaches the servo on pin 9 to the servo object 
  tilt.attach(10);
  Serial.begin(9600);
} 
 
void loop() { 
  
  tilt.write(tilt_pos);
  pan.write(pan_pos); 

  for (pan_pos = 0; pan_pos < 180; pan_pos += 1){  // goes from 0 degrees to 180 degrees 
    pan.write(pan_pos);  // tell servo to go to position in variable 'pos' 
    delay(15);      // waits 15ms for the servo to reach the position 
    
    if (pan_pos >= 179) {
      tilt_pos = tilt_pos + 10;
      tilt.write(tilt_pos);
      delay(15);
    } 
    
    sensorVal = analogRead(analogInPin);    // read analog in value        
    v = sensorVal/200;   // convert to volts
    delay(15);
    
    Serial.print(tilt_pos);
    Serial.print(",");
    Serial.print(pan_pos);
    Serial.print(",");
    Serial.println(sensorVal);
  }
  
  for (pan_pos = 180; pan_pos >= 1; pan_pos -= 1){     // goes from 180 degrees to 0 degrees 
    pan.write(pan_pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
    
    if (pan_pos <= 1){
      tilt_pos = tilt_pos + 10;
      tilt.write(tilt_pos);
      delay(15);
    }
    
    sensorVal = analogRead(analogInPin);    // read analog in value        
    v = sensorVal/200;   // convert to volts
    delay(15);
    
    Serial.print(tilt_pos);
    Serial.print(",");
    Serial.print(pan_pos);
    Serial.print(",");
    Serial.println(sensorVal);
  }
 
  if (tilt_pos >= 180) {
    tilt_pos = 0;
    tilt.write(tilt_pos);
  } 
}
