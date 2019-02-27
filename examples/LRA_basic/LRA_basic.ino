/*
 * LRA_Basic : Arduino IDE LRA example for Dialog Semiconductor DA7280
 * 
 * Overview:
 * --------- 
 * This simple example for the LRA actuator types runs through 
 * all the effects in sequence.
 * 
 * Requirements:
 * -------------
 * PatternAgents DA7280 library : https://github.com/PatternAgents/Haptic_DA7280
 * 
 * Instructions:
 * -------------
 * 1) compile and Upload the sketch
 * 2) open the Serial Monitor
 *       
 */


/* set up the DA7280 Haptic Driver Library */
#include "Haptic_DA7280.h"
Haptic_DA7280 haptic;          // Basic I2C instance - only SDA/SCL pins used
int           effect = 0;      // current "effect" - a complex set of sequences or actions
int           effect_max = 0;  // max (loaded) effects available


/* initialize the system */
void setup() {
  // Start the Serial Console (Virtual USB Serial)
  Serial.begin(115200);
   while (!Serial) { ;       
    // wait for serial port to connect. Needed for some Native USB controllers.
    // You MUST open the Serial console for the program to continue !!! 
  }
  Serial.println("Haptic: Driver Basic Tests");
  Serial.println("Haptic: Connect I2C pins to WIRE Pins (SDA, SCL)");

    // initialize the Haptic controller
    if (haptic.begin() < 0) {
      Serial.println("Haptic: No DA7280 detected! - check your I2C connections?");
    } else {
      haptic.setMode(REGISTER_MODE);    // trigger haptic effects by I2C register write i.e. "haptic.go()"
      effect_max = haptic.getEffects(); // set max to total number of effects loaded
      if (effect_max == 0) {
        Serial.println("Haptic: Driver Error: No Effects are available? ]");
      }
    }       
}

// loop through all the loaded effects
void loop() {
  Serial.print("Effect #"); 
  Serial.println(effect);
  
  haptic.setEffect(effect);              // select an "effect" pattern
  haptic.go();                           // play the effect by register write
  delay(1000);                           // wait for a while
  effect++;                              // next effect
  if (effect >= effect_max) effect = 0;  // loop through all the effects
}
