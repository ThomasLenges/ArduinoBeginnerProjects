bool switchState = false;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  // If switch pressed
  if(switchState){
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);

    // Blinking effect
    delay(250); // Pause for 250 milliseconds
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(250);

  } else {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
