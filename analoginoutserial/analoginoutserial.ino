/*
Test: verify that sensor voltage/distance readings match datasheet 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const float analogInPin = A0;  // Analog input pin that the infrared sensor
const float analogOutPin = 9; // Analog output pin that the LED is attached to

float sensorVal = 0;        // value read from the infrared sensor
float outputVal = 0;        // value output to the PWM (analog out) of infrared sensor

void setup() {
  Serial.begin(9600); 
}

void loop() {
  sensorVal = analogRead(analogInPin);    // read analog in value        
  outputVal = map(sensorVal, 0, 560, 0, 2.75);  // map it to range of analog out
  // change the analog out value:
  analogWrite(analogOutPin, outputVal);           

  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorVal);      
  Serial.print("\t output = ");      
  Serial.println(outputVal);   

  delay(2);   // wait 2ms before next loop for analog-digital converter to settle after last reading                  
}
