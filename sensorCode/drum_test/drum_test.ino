// Libraries
#include "Adafruit_VL53L0X.h"

// Define potentiometer pin
#define drum1Pin A0
#define drum2Pin A1
#define drum3Pin A2
#define flexPin A3

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

// Theremin
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  // Setup serial monitor
   Serial.begin(9600);
   lox.begin();
}

void loop() {
  // Read the fsrValue
  drum1Val = analogRead(drum1Pin);
  drum2Val = analogRead(drum2Pin);
  drum3Val = analogRead(drum3Pin);
  flexVal = analogRead(flexPin);
  
  if (drum1Val > 200 && !isDrum1Playing) {
    isDrum1Playing = true;
    Serial.println("drum1");
  } else if (drum1Val < 10 && isDrum1Playing) {
    isDrum1Playing = false;
  }

  if (drum2Val > 200 && !isDrum2Playing) {
    Serial.println("drum2");
    isDrum2Playing = true;
  } else if (drum2Val < 10 && isDrum2Playing) {
    isDrum2Playing = false;
  }

  if (drum3Val > 200 && !isDrum3Playing) {
    Serial.println("drum3");
    isDrum3Playing = true;
  } else if (drum3Val < 10 && isDrum3Playing) {
    isDrum3Playing = false;
  }

//  if (thereminVal > 100 && !isPlaying) {
//    Serial.println("theremin");
//    isPlaying = true;
//  } else if (thereminVal < 20 && isPlaying) {
//    isPlaying = false;
//  }

  if (flexVal < 300 && !isFlexPlaying) {
    Serial.println("flex");
    isFlexPlaying = true;
  } else if (flexVal > 450 && isFlexPlaying) {
    isFlexPlaying = false;
  }

  // Sensor measure object
  VL53L0X_RangingMeasurementData_t measure;

  // Get the measurement
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  // Check for a valid measurement
  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    thereminVal = measure.RangeMilliMeter;
  }
  if (thereminVal >= 60 && thereminVal <= 150) {
    if (!isThereminPlaying) {
      Serial.println("theremin1");
    }
    isThereminPlaying = true;
  } else if (thereminVal >= 151 && thereminVal <= 250) {
    if (!isThereminPlaying) {
      Serial.println("theremin2");
    }
    isThereminPlaying = true;
  } else if (thereminVal >= 251) {
    if (!isThereminPlaying) {
      Serial.println("theremin3");
    }
    isThereminPlaying = true;
  } else {
    isThereminPlaying = false;
  }
  
}
