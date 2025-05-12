// include the library
#include <LiquidCrystal.h>

//define pins
const int buzzerPin = 13;
const int tiltPin = 3;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

//Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variables for debouncing
bool lastTiltState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("System Ready");
  Serial.begin(9600);
  Serial.println("Tilt Alarm System Ready");
}

void checkTilt() {
  int currentTiltState = digitalRead(tiltPin);

  if (currentTiltState != lastTiltState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentTiltState == HIGH) {
      Serial.println("Tilt Detected");
      digitalWrite(buzzerPin, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CALL 123-456-7890");
    } else {
      digitalWrite(buzzerPin, LOW);
      Serial.print("No Tilt");
      lcd.clear();
      lcd.print("System Ready");
    }
  }
  lastTiltState = currentTiltState;
}

void loop() {
  checkTilt();
  delay(300);
}
