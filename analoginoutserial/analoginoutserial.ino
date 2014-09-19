/*
Test: verify that sensor voltage/distance readings match datasheet 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the infrared sensor
int outputValue = 0;        // value output to the PWM (analog out) of infrared sensor

void setup() {
  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(analogInPin);    // read analog in value        
  outputValue = map(sensorValue, 0, 1023, 0, 255);  // map it to range of analog out
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);           

  Serial.println(sensorValue);

  // print the results to the serial monitor:
//  Serial.print("sensor = " );                       
//  Serial.print(sensorValue);      
//  Serial.print("\t output = ");      
//  Serial.println(outputValue);   

  delay(2);   // wait 2ms before next loop for analog-digital converter to settle after last reading                  
}
