/*
 * embedis : Embedis example for Dialog Semiconductor DA7280
 * 
 * 1) compile and Upload the sketch
 * 2) open the "Serial Monitor and type "commands" (return)
 *    and you will see a list of the currently installed commands
 * 3) type "WRITE DA7280 register_address register_value (return)
 *    for example "WRITE DA7280  0x00 0xFF" 
 *    or          "WRITE ADXL345 0x00 0xFF"
 * 4) there is also a corresponding READ command
 *    for example "READ DA7280 0x00"
 *    
 * NOTE: The commands accept only hexadecimal values for register and data, 
 *       so make sure to NOT use Register names, like "DA7280_SNP_MEM_0",
 *       as these will not be recognized properly. Use a Terminal Emulator program
 *       like "TeraTerm" to upload whole files of commands, like the ones created with
 *       the Dialog Semiconductor DA7280 GUI program.
 *       
 */
#include <Arduino.h>
#include <EEPROM.h>
#include <Embedis.h>
#define embedis_console Serial
Embedis embedis(embedis_console);

#include "Haptic_DA7280.h"
Haptic_DA7280 haptic;          // Basic I2C instance - only SDA/SCL pins used
int           effect = 0;      // current "effect" - a complex set of sequences or actions
int           effect_max = 0;  // max (loaded) effects available

#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345); /* Assign a unique ID to this sensor at the same time */

void setup() {
  Serial.begin(115200);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
    // Start Logging
    LOG( String() + F("[ Embedis: Embedis Framework Installed ]") );

    // start all the subsystems and log it
    EEPROM_setup();
    LOG( String() + F("[ Embedis: Embedis EEPROM dictionary installed ]") );
    
    // add new Embedis commands 
    commands_setup();
    LOG( String() + F("[ Embedis: type 'commands' to get a list of installed Embedis commands ]") );

    /* Initialise the Accelerometer */
    if(!accel.begin())
    {
      /* There was a problem detecting the ADXL345 ... check your connections */
      Serial.println("[ ADXL345: No ADXL345 detected! - check your I2C connections? ]");

    }
    
    // initialize the Haptic controller
    if (haptic.begin() < 0) {
      LOG( String() + F("[ DA7280: No DA7280 detected! - check your I2C connections? ]") );
    } else {
      haptic.setMode(REGISTER_MODE);    // trigger haptic effects by I2C register write i.e. "haptic.go()"
      effect_max = haptic.getEffects(); // set max to total number of effects loaded
      if (effect_max == 0) {
        LOG( String() + F("[ Haptic: Driver Error: No Effects are available? ]") );
    }
  }       
}

void loop() {
  embedis.process();
}

// This will log to an embedis channel called "log".
// Use SUBSCRIBE LOG to get these messages.
// Logs are also printed to Serial until an empty message is received.
// Success with WiFi sends an empty message.
void LOG(const String& message) {
    static bool inSetup = true;
    if (inSetup) {
        if (!message.length()) {
            inSetup = false;
            return;
        }
        Serial.println(message);
    }
    Embedis::publish("log", message);
}
