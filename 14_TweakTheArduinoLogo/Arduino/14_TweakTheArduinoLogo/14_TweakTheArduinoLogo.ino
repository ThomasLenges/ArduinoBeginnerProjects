void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.println(analogRead(A0));
  Serial.write(analogRead(A0)/4); // Serial.write [0;255] hence need to be divided by 4 to go from 10 to 8 bits
  delay(1); // ADC takes some time
}
