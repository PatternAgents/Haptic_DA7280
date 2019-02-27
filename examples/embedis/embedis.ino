/*
 * embedis : Arduino IDE example for Dialog Semiconductor DA7280
 * 
 * Overview:
 * ---------
 * Embedis is an open source library for creating simple embedded dictionary servers. 
 * Embedis is used for embedding key-value dictionaries into the SRAM, FLASH, FRAM, 
 * NVSRAM, EEPROM, or SDcard memory systems of small, limited resource, 
 * embedded computing platforms, such as the Arduino(AVR), Teensy(Cortex-M4), 
 * ESP8266, and others. Embedis includes API's for saving and restoring configuration
 * settings in persistant memory as well as an extendable Command Line Interface (CLI). 
 * 
 * This example extends the Embedis Command Line Interface (CLI) to add commands to read
 * and write the peripherals on the I2C interface bus, namely the DA7280 and ADXL345 devices.
 * On those CPU's supporting EEPROM or emulated EEPROM, persistant memory is available for 
 * storing parameters using standard Embedis SET/GET/DEL commands. 
 * 
 * Requirements:
 * -------------
 * PatternAgents DA7280 library : https://github.com/PatternAgents/Haptic_DA7280
 * thingSoc    embedis  library : https://github.com/thingSoC/embedis
 * adafruit    adxl345  library : https://github.com/adafruit/Adafruit_ADXL345
 * 
 * Instructions:
 * -------------
 * 1) compile and Upload the sketch
 * 
 * 2) open the "Serial Monitor and type "commands" (return)
 *    and you will see a list of the currently installed Embedis commands
 *    
 * 3) type "WRITE DA7280 register_address register_value (return)
 *    for example "WRITE DA7280  0x00 0xFF" 
 *    or          "WRITE ADXL345 0x00 0xFF"
 *    
 * 4) there is also a corresponding READ command
 *    for example "READ DA7280 0x00"
 *    
 * SCRIPT Notes: 
 * -------------
 *  The embedis WRTIE command only accepts hexadecimal byte values for register address and data, 
 *  so make sure NOT to use Register names, like "DA7280_SNP_MEM_0", use "0x84" instead.
 *  Use a Terminal Emulator program like "TeraTerm" to upload whole files of commands,  
 *  such as the ones created with the Dialog Semiconductor DA7280 GUI program.
 *       
 */

/* set up the Embedis Environment */
#include <Arduino.h>
#include <EEPROM.h>
#include <Embedis.h>
#define embedis_console Serial      /* USB Virtual Serial - can also be changed to (Hardware) Serial1, Serial2, etc. */
Embedis embedis(embedis_console);   /* instantiate the embedis CLI */

/* set up the DA7280 Haptic Driver Library */
#include "Haptic_DA7280.h"
Haptic_DA7280 haptic;          // Basic I2C instance - only SDA/SCL pins used
int           effect = 0;      // current "effect" - a complex set of sequences or actions (i.e. a script)
int           effect_max = 0;  // max (loaded) effects available

/* set up the ADXL345 3D Accelerometer Driver Library */
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345); /* Assign a unique ID to this sensor at the same time */

/* initialize the system */
void setup() {
    // Start the Serial Console (Virtual USB Serial)
    Serial.begin(115200);
    while (!Serial) { ; 
      // wait for serial port to connect. Needed for some Native USB controllers.
      // You MUST open the Serial console for the program to continue !!! 
    }
    
    // Start Logging
    LOG( String() + F("[ Embedis: Embedis Framework Installed ]") );

    // start all the subsystems and log it
    EEPROM_setup();
    LOG( String() + F("[ Embedis: Embedis EEPROM dictionary installed ]") );
    
    // add new Embedis commands 
    commands_setup();
    LOG( String() + F("[ Embedis: type 'commands' to get a list of installed Embedis commands ]") );

    // Initialise the Accelerometer
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

// run the Embedis interpreter system
void loop() {
  embedis.process();
}

// This will log to an embedis channel called "log".
// Use SUBSCRIBE LOG to get these messages.
// Logs are also printed to Serial until an empty message is received.
// Success with WiFi (as Serial) sends an empty message.
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
