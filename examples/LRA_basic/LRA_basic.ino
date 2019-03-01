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
Haptic_DA7280 haptic;                // Basic I2C instance - only SDA/SCL pins used
int waveform = 0;      // current "waveform" - a complex set of sequences or actions
int waveform_max = 0;                  // max (loaded) waveforms available

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
    if (haptic.begin() != HAPTIC_SUCCESS) {
      Serial.println("Haptic: No DA7280 detected! - check your I2C connections?");
    } else {
      haptic.setActuatorType(LRA);      // pick an actuator type
      haptic.setMode(REGISTER_MODE);    // trigger haptic waveforms by I2C register write i.e. "haptic.go()"
      waveform_max = haptic.getWaveforms(); // set max to total number of waveforms loaded
      if (waveform_max <= 0) {
        Serial.println("Haptic: Driver Error: No waveforms are available? ]");
      }
    }       
}

// loop through all the loaded waveforms
void loop() {
  Serial.print("waveform #"); 
  Serial.println(waveform);
  
  haptic.setWaveform(1, waveform);           // select an "waveform"  pattern
  haptic.goWait();                           // play the waveform by register write
  delay(1000);                               // wait for a while
  waveform++;                                // next waveform
  if (waveform >= waveform_max) {
    waveform = 0;                           // loop through the waveforms
  }
}
