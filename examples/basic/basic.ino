#include "Haptic_DA7280.h"

Haptic_DA7280 haptic;          // Basic I2C instance - only SDA/SCL pins used
int           effect = 0;      // current "effect" - a complex set of sequences or actions
int           effect_max = 0;  // max (loaded) effects available

void setup() {
  Serial.begin(115200);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Haptic: Driver Basic Tests");
  Serial.println("Haptic: Connect I2C pins to WIRE Pins (SDA, SCL)");

  // initialize the Haptic controller
  if (haptic.begin() < 0) {
    Serial.println("Haptic: Driver Error: Device not found - check your I2C connections?");
  } else {
    int haptic_DeviceID = haptic.getDeviceID();
    if (haptic_DeviceID != HAPTIC_DEVICELIB) {
      Serial.println("Haptic: Driver Error: Device not recognized?");
      Serial.print("Haptic: DeviceID =  ");
      Serial.print(haptic_DeviceID, HEX);
      Serial.println(" was found? ");
    } else {
      Serial.print("Haptic: DeviceID =  ");
      Serial.print(haptic_DeviceID, HEX);
      Serial.println(" was found! ");
      haptic.setMode(REGISTER_MODE);    // trigger haptic effects by I2C register write i.e. "haptic.go()"
      effect_max = haptic.getEffects(); // set max to total number of effects loaded
      if (effect_max == 0) {
        Serial.println("Haptic: Driver Error: No Effects are available?");
      }
    }
  }       
}

void loop() {
  Serial.print("Effect #"); 
  Serial.println(effect);
  
  haptic.setEffect(effect);               // select an "effect" pattern
  haptic.go();                            // play the effect by register write
  delay(500);                             // wait for a while
  effect++;                                // next effect
  if (effect >= effect_max) effect = 0;  // loop through all the effects
}
