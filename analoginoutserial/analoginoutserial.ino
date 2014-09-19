/*
Test: verify that sensor voltage/distance readings match datasheet 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorVal = 0;        // value read from the infrared sensor
int outputVal = 0;        // value output to the PWM (analog out) of infrared sensor

void setup() {
  Serial.begin(9600); 
}

void loop() {
  sensorVal = analogRead(analogInPin);    // read analog in value        
  outputVal = map(sensorVal, 0, 1023, 0, 255);  // map it to range of analog out
  // change the analog out value:
  analogWrite(analogOutPin, outputVal);           

  Serial.println(sensorValue); // prints 400?  don't know how that corresponds to voltage
  //Serial.println(outputVal);

  // print the results to the serial monitor:
//  Serial.print("sensor = " );                       
//  Serial.print(sensorValue);      
//  Serial.print("\t output = ");      
//  Serial.println(outputValue);   

  delay(2);   // wait 2ms before next loop for analog-digital converter to settle after last reading                  
}
