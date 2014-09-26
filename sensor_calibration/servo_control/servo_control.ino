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
  
  tilt.write(tilt_pos);
  pan.write(pan_pos); 

  for (pan_pos = 0; pan_pos < 180; pan_pos += 1){  // goes from 0 degrees to 180 degrees // in steps of 1 degree 
    
    pan.write(pan_pos);  // tell servo to go to position in variable 'pos' 
    delay(15);      // waits 15ms for the servo to reach the position 
    
    if (pan_pos >= 179) {
      Serial.println("pan > 179");\
      tilt_pos = tilt_pos + 5;
      tilt.write(tilt_pos);
      Serial.print("Tilt: ");
      Serial.println(tilt_pos);
      delay(15);
    }
      
  }
  
  for (pan_pos = 180; pan_pos >= 1; pan_pos -= 1){     // goes from 180 degrees to 0 degrees 
  
    pan.write(pan_pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
    
    if (pan_pos <= 1){
      Serial.println("pan <= 1");
      tilt_pos = tilt_pos + 5;
      tilt.write(tilt_pos);
      Serial.print("Tilt: ");
      Serial.println(tilt_pos);
      delay(15);
    }

  }
 
  if (tilt_pos = 180) {
    tilt_pos = 0;
    tilt.write(tilt_pos);
  } 
}
