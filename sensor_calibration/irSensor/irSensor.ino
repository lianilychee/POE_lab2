// Pin definition
const float analogInPin = A0;  // Infrared sensor to Analog
float sensorVal = 0;        // value read from the infrared sensor
float v = 0;    // voltage output
float dist = 0;    // distance in cm

void setup() {
  Serial.begin(9600); 
}

void loop() {
  
  sensorVal = analogRead(analogInPin);    // read analog in value        
  v = sensorVal/200;   // convert to volts
  
  Serial.println(sensorVal);

  delay(2);   // wait 2ms before next loop for analog-digital converter to settle after last reading                  
}
