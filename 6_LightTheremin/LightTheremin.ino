int sensorValue;
int sensorLow = 4095; // Max values to ensure calibration
int sensorHigh = 0;
int const sensorPin = A0;
int const piezoPin = 8;

int const ledPin = 13; // On board LED

void setup() {
  Serial.begin(9600); // For debugging
  analogReadResolution(12); // ADC resolution to 12 bits

  pinMode(ledPin, OUTPUT); // On board LED
  digitalWrite(ledPin, HIGH); // Turn LED on

  // Calibration (move hand around same range one wants to play theremin)
  while(millis() < 5000){ // millis() indicates how many milliseconds has passed since board has been up or reset
    sensorValue = analogRead(sensorPin);

    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }

  // Indicate calibration has ended
  digitalWrite(ledPin, LOW);

  Serial.print("Range is: ");
  Serial.print(sensorLow);
  Serial.print(" to ");
  Serial.println(sensorHigh);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  //Serial.println(sensorValue);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000); // [40; 5000] frequency range

  tone(piezoPin, pitch, 20); // Pin, tone frequency, duration in ms (always pulses with 50% duty cycle)
  delay(10); // Delay to enable sound to play
}
