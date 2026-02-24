const int launchPin = 5;
int launchState = 0;
const int directionPin = 4;
int directionState = 0;
const int HBridge2 = 3; // Direction1
const int HBridge7 = 2; // Direction2
const int HBridge1 = 9; // Enable

/*
 1 : Enable
 2 : Direction1
 3 : MotorPin1
 4 : GND
 5 : GND
 6 : MotorPin2
 7 : Direction2
 8 : 9V +
 16: Arduino 5V +
*/
void setup() {
  pinMode(launchPin, INPUT);
  pinMode(directionPin, INPUT);
  pinMode(HBridge2, OUTPUT);
  pinMode(HBridge7, OUTPUT);
  pinMode(HBridge1, OUTPUT);
}

void loop() {
  launchState = digitalRead(launchPin);
  directionState = digitalRead(directionPin);

  if(launchState){
    digitalWrite(HBridge1, HIGH);
  } else {
    digitalWrite(HBridge1, LOW);
  }

  // Clockwise
  if(directionState){
    digitalWrite(HBridge2, HIGH);
    digitalWrite(HBridge7, LOW);
  // Anticlockwise
  } else {
    digitalWrite(HBridge2, LOW);
    digitalWrite(HBridge7, HIGH);
  }
}
