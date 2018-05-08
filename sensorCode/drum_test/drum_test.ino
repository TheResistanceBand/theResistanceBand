// Define potentiometer pin
#define drum1Pin A0
#define drum2Pin A4
#define drum3Pin A2
#define theraminPin A3
#define flexPin A1

// Program variables
int drum1Val = 0;
int drum2Val = 0;
int drum3Val = 0;
int theraminVal = 0;
int flexVal = 0;
bool isPlaying = false;


void setup() {
  // Set up the LCD's number of columns and rows
  // lcd.begin(16, 2);
  // Setup serial monitor
   Serial.begin(9600);
}

void loop() {
  // Read the fsrValue
  drum1Val = analogRead(drum1Pin);
  drum2Val = analogRead(drum2Pin);
  drum3Val = analogRead(drum3Pin);
  theraminVal = analogRead(theraminPin);
  flexVal = analogRead(flexPin);
  if (drum1Val > 10) {
    Serial.println(drum1Val);  
  }
  
  if (drum1Val > 100 && !isPlaying) {
    Serial.println("drum1");
    isPlaying = true;
  } else if (drum1Val < 10 && isPlaying) {
    isPlaying = false;
  }
//
//  if (drum2Val > 100 && !isPlaying) {
//    Serial.println("drum2");
//    isPlaying = true;
//  } else if (drum2Val < 20 && isPlaying) {
//    isPlaying = false;
//  }

//  if (drum3Val > 100 && !isPlaying) {
//    Serial.println("drum3");
//    isPlaying = true;
//  } else if (drum3Val < 20 && isPlaying) {
//    isPlaying = false;
//  }
//
//  if (theraminVal > 100 && !isPlaying) {
//    Serial.println("theramin");
//    isPlaying = true;
//  } else if (theraminVal < 20 && isPlaying) {
//    isPlaying = false;
//  }


//  if (flexVal > 100 && !isPlaying) {
//    Serial.println("flex");
//    isPlaying = true;
//  } else if (flexVal < 20 && isPlaying) {
//    isPlaying = false;
//  }

  //Serial.println("Value: "+String(drumVal));
//  lcd.cle ar();
//  lcd.print("Value: "+String(drumVal));
}
