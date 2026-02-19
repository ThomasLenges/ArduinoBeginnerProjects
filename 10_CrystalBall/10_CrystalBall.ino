// Due to likely broken LCD this software remains unverified for corectness

#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Tilt switch
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  lcd.begin(16, 2);

  lcd.print("Ask the"); // By default at first row
  lcd.setCursor(0, 1); // First column at second row
  lcd.print("Crystal Ball!");
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8); // Random value 0-7

      Serial.println(reply);

      lcd.clear(); // Clears LCD and puts cursor back to (0,0)
      lcd.setCursor(0, 0);
      lcd.print("The ball says:"); // First row
      lcd.setCursor(0, 1); // First column at second row

      switch(reply){
        case 0:
          lcd.print("Yes");
          break;
        case 1:
          lcd.print("Most likely");
          break;
        case 2:
          lcd.print("Certainly");
          break;
        case 3:
          lcd.print("Outlook good");
          break;
        case 4:
          lcd.print("Unsure");
          break;
        case 5:
          lcd.print("Ask again");
          break;
        case 6:
          lcd.print("Doubtful");
          break;
        case 7:
          lcd.print("No");
          break;
      }
    }
  }
  prevSwitchState = switchState;
}
