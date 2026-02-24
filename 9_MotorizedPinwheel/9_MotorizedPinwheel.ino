const int switchPin = 2;
const int gatePin = 9;
bool switchState = false;
int potentioMeter = 0;
const int potentioMeterPin = A0;

void setup() {
  Serial.begin(9600);

  pinMode(switchPin, INPUT);
  pinMode(gatePin, OUTPUT);
}

void loop() {
  switchState = digitalRead(switchPin);

  potentioMeter = analogRead(potentioMeterPin);
  Serial.println(potentioMeter);

  if(switchState){
    digitalWrite(gatePin, HIGH);
  } else {
    digitalWrite(gatePin, LOW);
  }


}
