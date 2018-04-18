// Define potentiometer pin
#define drumPin A0

// Program variables
int drumVal = 0;
bool isPlaying = false;

// LCD library
#include <LiquidCrystal.h>

// Initialize LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Setup serial monitor
  Serial.begin(9600);
}

void loop() {
  // Read the fsrValue
  drumVal = analogRead(drumPin);
  if (drumVal > 100 && !isPlaying) {
    Serial.println("drum1");
    isPlaying = true;
  } else {
    isPlaying = false;
  }
  //Serial.println("Value: "+String(drumVal));
  lcd.clear();
  lcd.print("Value: "+String(drumVal));
}
