# embedis : Arduino IDE example for Dialog Semiconductor DA7280
 
## Overview :

 Embedis is an open source library for creating simple embedded dictionary servers. 
 Embedis is used for embedding key-value dictionaries into the SRAM, FLASH, FRAM, 
 NVSRAM, EEPROM, or SDcard memory systems of small, limited resource, 
 embedded computing platforms, such as the Arduino(AVR), Teensy(Cortex-M4), 
 ESP8266, and others. Embedis includes API's for saving and restoring configuration
 settings in persistant memory as well as an extendable Command Line Interface (CLI). 
 
 This example extends the Embedis Command Line Interface (CLI) to add commands to read
 and write the peripherals on the I2C interface bus, namely the DA7280 and ADXL345 devices.
 On those CPU's supporting EEPROM or emulated EEPROM, persistant memory is available for 
 storing parameters using standard Embedis SET/GET/DEL commands. 
 
## Requirements :

 PatternAgents DA7280 library : https://github.com/PatternAgents/Haptic_DA7280

 thingSoc    embedis  library : https://github.com/thingSoC/embedis
 
 adafruit    adxl345  library : https://github.com/adafruit/Adafruit_ADXL345
 
 ## Instructions :

 1) compile and Upload the sketch
 
 2) open the "Serial Monitor and type "commands" (return)
    and you will see a list of the currently installed Embedis commands
    
 3) type "WRITE DA7280 register_address register_value (return)
    for example "WRITE DA7280  0x00 0xFF" 
    or          "WRITE ADXL345 0x00 0xFF"
    
 4) there is also a corresponding READ command
    for example "READ DA7280 0x00"
    
### SCRIPT Notes : 

The embedis WRTIE command only accepts hexadecimal byte values for register address and data, 
so make sure NOT to use Register names, like "DA7280_SNP_MEM_0", use "0x84" instead.
Use a Terminal Emulator program like "TeraTerm" to upload whole files of commands, 
such as the scripts created with the Dialog Semiconductor DA7280 GUI program.
       

## Example Contents

* **/examples/embedis - This Example sketch. Run from the Arduino IDE. 

## Documentation

* **[LibraryExamples](https://www.arduino.cc/en/Tutorial/LibraryExamples)** - Basic information on how to install an Arduino library.

## Products that use this Example

(with integrated accelerometer)
* [DA7280 FeatherWing](https://github.com/PatternAgents/Agent-DA7280-FeatherWing) - PatternAgents DA7280 FeatherWing

## Compatible Products that (can) use this Example

(NO integrated accelerometer)
* (not yet)

## Contributors

The folks who make this project possible:

 * PatternAgents, LLC
 * Tom Moxon, MoxonDesign
 
## Independent Contributors

If you would like to help contribute to this project, we welcome all.
Please see our [Code of Conduct](https://github.com/PatternAgents/Haptic_DA7280/blob/master/ICLA_CONDUCT.md) and our
[Individual Contributor Agreement](https://github.com/PatternAgents/Haptic_DA7280/blob/master/ICLA_LICENSE.txt) for more information.

## Community Supported

These projects are all community supported, you can help by donating to support this work.

<span class="badge-paypal"><a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=5NPC24C7VQ89L" title="Donate to this project using Paypal"><img src="https://img.shields.io/badge/paypal-donate-yellow.svg" alt="PayPal donate button" /></a></span>
