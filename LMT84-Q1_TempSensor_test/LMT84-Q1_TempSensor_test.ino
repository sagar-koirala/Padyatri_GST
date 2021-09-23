#include <Arduino.h>

const int sensorPin = A3;
float tempC = 0;

void setup() {
  Serial.begin(96000);
}

void loop() {
  int tempRead = analogRead(sensorPin);
  float tempmV = ((float) tempRead) / 1024.0 * 5000; 
  tempC = ((5.506 - sqrt(sq(-5.506) + (4 * 0.00176 * (870.6 - tempmV))))/(2 * -0.00176)) + 30; //LMT84 temp sensor transfer function
  Serial.println("LMT84 Temp Sensor: "); 
  Serial.print("Analog: "); Serial.println(tempRead);
  Serial.print("mVolts: "); Serial.print(tempmV,4); Serial.println("mV");
  Serial.print("Temp: "); Serial.print(tempC, 4); Serial.println("*C");
  delay(1000);
}
