int notes[] = {262, 294, 330, 349};
int const sensorPin = A0;
int const piezoPin = 8;


void setup() {
  Serial.begin(9600); // 9600 bps
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);

  // Only one frequency can play on a pin at a given time
  if(sensorVal == 1023){
    tone(piezoPin, notes[0]);
  } else if(sensorVal >= 990 && sensorVal <= 1010){
    tone(piezoPin, notes[1]);
  } else if(sensorVal >= 490 && sensorVal <= 510){
    tone(piezoPin, notes[2]);
  } else if(sensorVal >= 15 && sensorVal <= 35){
    tone(piezoPin, notes[3]);
  } else{
    noTone(piezoPin); // Required otherwise sound keeps playing as no duration was set for the tone
  }
}
