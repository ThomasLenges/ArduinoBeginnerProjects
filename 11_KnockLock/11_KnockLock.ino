#include<Servo.h>

Servo myServo;

// Pins
const int piezoPin = A0;
const int switchPin = 2;
const int redLedPin = 5;
const int yellowLedPin = 4;
const int greenLedPin = 3;

// Variables
int knockVal;
int switchVal;
bool locked = false; // Start position
int nbKnocks = 0;
const int knockGoal = 3;

// Knock intensity detection
const int minKnock = 90; // Tap the piezo directly otherwise way too much noise
const int maxKnock = 200;

void setup() {
  Serial.begin(9600);

  myServo.attach(9);

  pinMode(switchPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  if(locked){
    digitalWrite(redLedPin, HIGH);
    myServo.write(90);
    Serial.println("Init Locked");
  } else {
    digitalWrite(greenLedPin, HIGH);
    myServo.write(0);
    Serial.println("Init Unlocked");
  }
}

void loop() {
  // If unlocked then can lock through switch press
  if(!locked){
    switchVal = digitalRead(switchPin);

    if(switchVal){
      locked = true;
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      myServo.write(90);
      Serial.println("Locked");
      Serial.println(switchVal);
      delay(1000); // Delay to let servo move to position
    }
  } else {
    knockVal = analogRead(piezoPin);

    if(nbKnocks < knockGoal && knockVal > 3){
      if(checkForKnock(knockVal)){
        nbKnocks++;
      }
      // Serial.print("Nb knocks is: ");
      // Serial.print(nbKnocks);
      // Serial.print(" Out of: ");
      // Serial.println(knockGoal);
    }

    if(nbKnocks == knockGoal){
      locked = false;
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
      digitalWrite(yellowLedPin, LOW);
      myServo.write(0);
      Serial.println("Unlocked");
      delay(1000); // Delay to let servo move to position
      nbKnocks = 0; // Important to reset to allow repetition
    }
  }
}


bool checkForKnock(int value){
  if(value > minKnock && value < maxKnock){
    digitalWrite(yellowLedPin, HIGH);
    delay(500); // Flash yellow LED to indicate valid knock
    Serial.print("Valid knock of value: ");
    Serial.println(value);
    return true;
  } else{
    // Serial.print("Invalid knock of value: ");
    // Serial.println(value);
    return false;
  }
}