// Bool: 1 byte
// Short: 2 bytes
// Int: 4 bytes
// Long: 4 bytes

// Tilt switch
const int switchPin = 8;
int switchState = 0;
int prevSwitchState = 0;

// Piezo
const int piezoPin = 9;
const int note = 262;

// LED management
unsigned long previousTime = 0; // Hold time an LED was last changed
int led = 2; // Starts at pin 2
long interval = 1000; // New LED lights on every 3 seconds passed

void setup() {
  Serial.begin(9600);

  // Set LED digital pins to output
  for(int i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }

  // Set tilt switch digital pin to input
  pinMode(switchPin, INPUT);
}

void loop() {
  // Serial.println(sizeof(bool)); // To visally verify data type length (in bytes)

  unsigned long currentTime = millis(); // Get time

  // If interval has passed then manage time markers and light a new LED
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

    // Play sound at end of hourglass and restart it
    if(led == 8){
      tone(piezoPin, note, 2000);
      delay(2000); // Wait before restarting
      previousTime = millis(); // Reset timer
      led = 2; // Reset LED index

      for(int i = 2; i < 8; i++){
        digitalWrite(i, LOW);
      }
    }
  }

  // Tilt switch management
  switchState = digitalRead(switchPin);

  Serial.println(switchState);

  // Turn of all LEDs if switch sensed
  if(switchState != prevSwitchState){
    for(int i = 2; i < 8; i++){
      digitalWrite(i, LOW);
    }

    led = 2; // Reset LED index
    previousTime = currentTime; // Reset timer
    prevSwitchState = switchState; // Update switch state
  }
}
