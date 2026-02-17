// PWM output pin
const int greenLEDpin = 9;
const int redLEDpin = 10;
const int blueLEDpin = 11;

// Analog input pin
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

// Value global variables
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600); // Serial communication at 9600 bps

  pinMode(redLEDpin, OUTPUT);
  pinMode(greenLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5); // Required as ADC takes some time
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw Sensor Values \t red: "); // \t for "tab"
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue); // End of line

  // Analog input [0; 1023] and PWM duty cylce [0; 255]: hence divide by 4
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped Sensor Values \t red: "); // \t for "tab"
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.println(blueValue);

  // PWM outputs
  analogWrite(redLEDpin, redValue);
  analogWrite(greenLEDpin, greenValue);
  analogWrite(blueLEDpin, blueValue);
}
