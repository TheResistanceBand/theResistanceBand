// Define potentiometer pin
#define drum1Pin A0
#define drum2Pin A4
#define drum3Pin A2
#define thereminPin A3
#define flexPin A1

// Program variables
int drum1Val = 0;
int drum2Val = 0;
int drum3Val = 0;
int thereminVal = 0;
int flexVal = 0;
bool isDrum1Playing = false;
bool isDrum2Playing = false;
bool isDrum3Playing = false;
bool isThereminPlaying = false;
bool isFlexPlaying = false;



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
  thereminVal = analogRead(thereminPin);
  flexVal = analogRead(flexPin);
  
  if (drum1Val > 200 && !isDrum1Playing) {
    Serial.println("drum1");
    isDrum1Playing = true;
  } else if (drum1Val < 10 && isDrum1Playing) {
    isDrum1Playing = false;
  }
//
//  if (drum2Val > 200 && !isDrum2Playing) {
//    Serial.println("drum2");
//    isDrum2Playing = true;
//  } else if (drum2Val < 10 && isDrum2Playing) {
//    isDrum2Playing = false;
//  }

//  if (drum3Val > 200 && !isDrum3Playing) {
//    Serial.println("drum3");
//    isDrum3Playing = true;
//  } else if (drum3Val < 10 && isDrum3Playing) {
//    isDrum3Playing = false;
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
}
