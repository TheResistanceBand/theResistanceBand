/*
 * The Resistance Band
 * Interactive Devices Final Project
 * By: Marco White, Brett Leibowitz, and Arpit Sheth
 * Last Modified: 5/8/18
 */

// Include libraries
#include <Adafruit_DotStar.h>

// Pin Definitions
#define EQUALIZER A5 //MSGEQ7 OUT
#define STROBEPIN 12 //MSGEQ7 STROBE
#define RESETPIN 13  //MSGEQ7 RESET
#define LEDDATA 4
#define LEDCLK 5

// Program constants
#define NUMPIXELS 107
#define THRESH 80

// Program variables
int spectrum[6];

// Setup the LED strip
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, LEDDATA, LEDCLK, DOTSTAR_BGR);

void setup() {
  // Setup serial monitor
  Serial.begin(9600);
  // Initialize pins
  pinMode(STROBEPIN, OUTPUT);
  pinMode(RESETPIN, OUTPUT);
  digitalWrite(RESETPIN, LOW);
  digitalWrite(STROBEPIN, HIGH);
  // Initialize LED strip
  strip.begin();
  strip.show();
}

void loop() {
  // Get frequency spectrum information
  // Reset the equalizer chip
  digitalWrite(RESETPIN, HIGH);
  digitalWrite(RESETPIN, LOW);
  for (int i=0; i<=6; i++) {
    // Write the strobe pin to low in order to get the value for the next frequency band
    digitalWrite(STROBEPIN, LOW);
    delay(5);
    // Skip the 16kHz band
    if (i != 0) {
      // Get the value for the current frequency band
      spectrum[i-1] = analogRead(EQUALIZER);
      // Update the LED strip
      switch(i-1) {
        case 0:
          for (int j=34; j<=71; j++) {
            strip.setPixelColor(j, constrain(map(spectrum[i-1], THRESH, 1023, 0, 255), 0, 255), 0, 0);  
          }
          break;
        case 1:
          for (int j=24; j<=33; j++) {
            strip.setPixelColor(j, constrain(map(spectrum[i-1], THRESH, 1023, 0, 250), 0, 250), constrain(map(spectrum[0], THRESH, 1023, 0, 150), 0, 150), 0);  
          }
          for (int j=72; j<=81; j++) {
            strip.setPixelColor(j, constrain(map(spectrum[i-1], THRESH, 1023, 0, 250), 0, 250), constrain(map(spectrum[0], THRESH, 1023, 0, 150), 0, 150), 0);  
          }
          break;
        case 2:
          for (int j=14; j<=23; j++) {
            strip.setPixelColor(j, constrain(map(spectrum[i-1], THRESH, 1023, 0, 200), 0, 200), constrain(map(spectrum[0], THRESH, 1023, 0, 200), 0, 200), 0);
          }
          for (int j=82; j<=91; j++) {
            strip.setPixelColor(j, constrain(map(spectrum[i-1], THRESH, 1023, 0, 200), 0, 200), constrain(map(spectrum[0], THRESH, 1023, 0, 200), 0, 200), 0);
          }
          break;
        case 3:
          for (int j=10; j<=14; j++) {
            strip.setPixelColor(j, 0, constrain(map(spectrum[i-1], THRESH, 1023, 0, 255), 0, 255), 0);
          }
          for (int j=92; j<=96; j++) {
            strip.setPixelColor(j, 0, constrain(map(spectrum[i-1], THRESH, 1023, 0, 255), 0, 255), 0);
          }
          break;
        case 4:
          for (int j=5; j<=9; j++) {
            strip.setPixelColor(j, 0, 0, constrain(map(spectrum[i-1], THRESH, 1023, 0, 255), 0, 255));
          }
          for (int j=97; j<=101; j++) {
            strip.setPixelColor(j, 0, 0, constrain(map(spectrum[i-1], THRESH, 1023, 0, 255), 0, 255));
          }
          break;
        case 5:
          for (int j=0; j<=4; j++) {
            strip.setPixelColor(j, constrain(map(spectrum[i-1], THRESH, 1023, 0, 200), 0, 200), 0, constrain(map(spectrum[0], THRESH, 1023, 0, 200), 0, 200));
          }
          for (int j=102; j<=106; j++) {
            strip.setPixelColor(j, constrain(map(spectrum[i-1], THRESH, 1023, 0, 200), 0, 200), 0, constrain(map(spectrum[0], THRESH, 1023, 0, 200), 0, 200));
          }
          break;
      }
      strip.show();
    }
    // Once you've got the frequency band info write the strobe pin to high
    digitalWrite(STROBEPIN, HIGH);
  }
}
