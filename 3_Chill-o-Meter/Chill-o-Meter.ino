const int sensorPin = A0;
const float baselineTemp = 27.15;

void setup() {
  Serial.begin(9600); // Open serial communication between board & computer. Communication speed is 9600 bits/s

  // Put all LEDs to ports to output and set them to low
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin); // Ranges from 0 to 1023

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // Convert value to voltage. Ranges from 0 to 5V
  float voltage = (sensorVal/1024.0) * 5.0; // At least one of the values in the division needs to be a float to avoid issues

  Serial.print(" , Volts: ");
  Serial.print(voltage);

  // Looking at datasheet (page 8 table 4) to convert from voltage to Celcius
  float temperature = (voltage - 0.5) * 100;

  Serial.print(" , Degrees C: ");
  Serial.println(temperature); //println for new line

  // LEDs management depending on temperature
  if(temperature < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1); // Required as ADC is a bottleneck
}
