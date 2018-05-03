// Define potentiometer pin
#define drum1Pin A0
#define drum2Pin A1
#define drum3Pin A2
#define theraminPin A3
#define flexPin A4

// Program variables
int drum1Val = 0;
int drum2Val = 0;
int drum3Val = 0;
int theraminVal = 0;
int flexVal = 0;
bool isPlaying = false;

// LCD library
#include <LiquidCrystal.h>

// Initialize LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set up the LCD's number of columns and rows
  // lcd.begin(16, 2);
  // Setup serial monitor
  // Serial.begin(9600);
}

void loop() {
  // Read the fsrValue
  drum1Val = analogRead(drum1Pin);
  drum2Val = analogRead(drum2Pin);
  drum3Val = analogRead(drum3Pin);
  theraminVal = analogRead(theraminPin);
  flexVal = analogRead(flexPin);
  if (drum1Val > 100 && !isPlaying) {
    Serial.println("drum1");
    isPlaying = true;
  } else if (drum1Val < 20 && isPlaying) {
    isPlaying = false;
  }

  if (drum2Val > 100 && !isPlaying) {
    Serial.println("drum2");
    isPlaying = true;
  } else if (drum2Val < 20 && isPlaying) {
    isPlaying = false;
  }

  if (drum3Val > 100 && !isPlaying) {
    Serial.println("drum3");
    isPlaying = true;
  } else if (drum3Val < 20 && isPlaying) {
    isPlaying = false;
  }

  if (theraminVal > 100 && !isPlaying) {
    Serial.println("theramin");
    isPlaying = true;
  } else if (theraminVal < 20 && isPlaying) {
    isPlaying = false;
  }


  if (flexValVal > 100 && !isPlaying) {
    Serial.println("theramin");
    isPlaying = true;
  } else if (flexValVal < 20 && isPlaying) {
    isPlaying = false;
  }

  //Serial.println("Value: "+String(drumVal));
  lcd.clear();
  lcd.print("Value: "+String(drumVal));
}
