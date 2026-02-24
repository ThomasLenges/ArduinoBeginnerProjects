#include<Arduino_CapacitiveTouch.h>

const int touchPin = 2;
const int ledPin = 12;
const int touchThreshold = 3000;

CapacitiveTouch touchSensor(touchPin);

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  
  touchSensor.begin(); // Init touchSensor
  touchSensor.setThreshold(touchThreshold); // Set threshold

  Serial.print("Threshold is: ");
  Serial.println(touchSensor.getThreshold());
}

void loop() {
  int touchValue = touchSensor.read();

  Serial.print("Touch value is: ");
  Serial.println(touchValue);

  // Touch value exceeds threshold
  if (touchSensor.isTouched()) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(50);
}
