/*
*  dXFM2 synthesizer main module
*
*  this is the main module for the dXFM2 synthesizer
*  the individual IC's are controled from submodules
*  this module will set the pinout and start of the SPI and I2C libraries
*
*/
#include "SPI.h"

const uint8_t MAXPIN_LOAD = 10; //LOAD pin for Teensy of the MAX7219CNG chip

void setup() {
  //We begin with the LEDs, splash them and continu with the OLED screens
  pinMode(MAXPIN_LOAD, OUTPUT); //MAXPIN_LOAD is defined in the submodule
  SPI.begin();
  setupLEDButtons(); //setup instructions for the LED buttons
  splashLEDs(); //default splash screen for the LEDs

  //Next, we splash the screens
  Wire.begin();
  setupScreens();
  splashScreens();

  delay(2000); //two seconds splash screen

  initLEDs(); //Initialize LEDs to startup position
  initScreens(); //Initialize OLED screens to startup position
}

void loop() {
  scanLEDButtons();
  delay(50); //Some delay to mitigate bouncing, should be done with timer and not a delay - whatever for now!
}

void doLEDButtonPressed(uint8_t row, uint8_t col, uint8_t menu, uint8_t btn) {
  if (menu==7) {
    //Blue menu toggle
    toggleLEDRow(row,col,menu,btn);
  } else {
    if (menu>7) {
      //Green menu toggle (a bit of a hack: buttons might not have the correct value, but we don't use that anyway...)
      clearLEDRow(5);
      clearLEDRow(7);
      toggleLEDRow(row,col,menu,btn);
    } else {
      //Operator matrix set/unset
      toggleLED(row,col,menu,btn);
    }
  }
}