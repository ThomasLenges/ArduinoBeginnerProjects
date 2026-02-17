#include <Servo.h> // Servo library

Servo myServo; // Instantiate object

int const potPin = A0;
int potVal;
int angle;

void setup() {
  Serial.begin(9600); // Serial communication at 9600 bps

  myServo.attach(9); // Servo method to indicate the board output pin to Servo

  analogReadResolution(12); // 12 bits for ADC resolution (0-4095)
}

void loop() {
  // Read potentiometer value
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Map potentiometer value to servo value (can only go from 0 to 180 degree)
  angle = map(potVal, 0, 4095, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  // Rotate servo
  myServo.write(angle);
  delay(15); // Delay so Servo has time to move to new position
}
