/*  Haptic DA7280 - Haptic Driver for Dialog DA7280
    Copyright (C) 2018,2019 PatternAgents, LLC

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Wire.h>
#include "Haptic_DA7280.h"

//! ----------------------------
//!   Default Scripts :
//! 0 DA7280 Reset/Init
//! 1 DA7280 LRA Motor Init
//! 2 DA7280 ERM Motor Init
//! 3 DA7280 ERM COIN Motor Init
//! 4 DA7280 LRA Calibrate
//! 5 Complex Effect 1
//! 6 Complex Effect 2
//! 7 Complex Effect 3
//! ----------------------------
//! haptic_reset[] - DA7280 reset & basic setup :
//! (Actuator independent setup commands)
//! Reset and Load (12) basic Waveforms
const struct scr_type haptic_reset[] = {
	{DA7280_CIF_I2C1, 0x80},					//! normal I2C mode - no timeouts
	{DA7280_IRQ_EVENT1, 0xff},					//! reset all faults
	{DA7280_IRQ_EVENT_WARNING_DIAG, 0xff},		//! reset all warnings
	{DA7280_TOP_CTL2, ACTUATOR_OVERIDE_VAL},    //! set override
	{DA7280_SEQ_CTL2, ACTUATOR_SEQ_LOOP << DA7280_PS_SEQ_LOOP_SHIFT | ACTUATOR_SEQ_ID << DA7280_PS_SEQ_ID_SHIFT},
	{0x03, 0x00},
	{0x04, 0x00},
	{0x05, 0x00},
	{0x07, 0x00},
	{0x08, 0x80},
	{0x0A, 0x19},
	{0x0B, 0x05},
	{0x0C, 0x81},
	{0x0D, 0x90},
	{0x0E, 0x13},
	{0x0F, 0x01},
	{0x10, 0x23},
	{0x13, 0x20},
	{0x14, 0x11},
	{0x15, 0x04},
	{0x16, 0xC0},
	{0x17, 0x81},
	{0x1C, 0x03},
	{0x1D, 0x20},
	{0x1E, 0x02},
	{0x1F, 0x58},
	{0x20, 0x43},
	{0x22, 0x00},
	{0x23, 0x48},
	{0x24, 0x04},
	{0x25, 0x61},
	{0x26, 0xB4},
	{0x27, 0xEC},
	{0x28, 0x00},
	{0x29, 0x00},
	{0x2A, 0x08},
	{0x2B, 0x10},
	{0x2D, 0x80},
	{0x48, 0x28},
	{0x49, 0x00},
	{0x4C, 0x00},
	{0x5F, 0x08},
	{0x60, 0x0B},
	{0x62, 0x0F},
	{0x6E, 0x00},
	{0x81, 0x00},
	{0x83, 0x00},
	{0x84, 0x08},
	{0x85, 0x0C},
	{0x86, 0x16},
	{0x87, 0x17},
	{0x88, 0x18},
	{0x89, 0x19},
	{0x8A, 0x1A},
	{0x8B, 0x1C},
	{0x8C, 0x1E},
	{0x8D, 0x20},
	{0x8E, 0x27},
	{0x8F, 0x2C},
	{0x90, 0x31},
	{0x91, 0x33},
	{0x92, 0x35},
	{0x93, 0x3C},
	{0x94, 0x3E},
	{0x95, 0x46},
	{0x96, 0x50},
	{0x97, 0x53},
	{0x98, 0x59},
	{0x99, 0x5D},
	{0x9A, 0x47},
	{0x9B, 0x49},
	{0x9C, 0x36},
	{0x9D, 0x29},
	{0x9E, 0xF4},
	{0x9F, 0x17},
	{0xA0, 0xF0},
	{0xA1, 0x47},
	{0xA2, 0x50},
	{0xA3, 0x77},
	{0xA4, 0x20},
	{0xA5, 0x01},
	{0xA6, 0x84},
	{0xA7, 0x74},
	{0xA8, 0x02},
	{0xA9, 0x18},
	{0xAA, 0x84},
	{0xAB, 0x74},
	{0xAC, 0x21},
	{0xAD, 0x84},
	{0xAE, 0x74},
	{0xAF, 0x22},
	{0xB0, 0x18},
	{0xB1, 0x03},
	{0xB2, 0x84},
	{0xB3, 0x74},
	{0xB4, 0x04},
	{0xB5, 0x10},
	{0xB6, 0x01},
	{0xB7, 0x18},
	{0xB8, 0x31},
	{0xB9, 0xA0},
	{0xBA, 0x29},
	{0xBB, 0x18},
	{0xBC, 0x29},
	{0xBD, 0x18},
	{0xBE, 0x59},
	{0xBF, 0x88},
	{0xC0, 0x18},
	{0xC1, 0x31},
	{0xC2, 0x18},
	{0xC3, 0x29},
	{0xC4, 0xA0},
	{0xC5, 0x18},
	{0xC6, 0x90},
	{0xC7, 0x29},
	{0xC8, 0xA0},
	{0xC9, 0x18},
	{0xCA, 0xA0},
	{0xCB, 0x57},
	{0xCC, 0x90},
	{0xCD, 0x18},
	{0xCE, 0x88},
	{0xCF, 0x58},
	{0xD0, 0x91},
	{0xD1, 0x18},
	{0xD2, 0x88},
	{0xD3, 0x57},
	{0xD4, 0x90},
	{0xD5, 0x1D},
	{0xD6, 0x10},
	{0xD7, 0xC8},
	{0xD8, 0x36},
	{0xD9, 0x18},
	{0xDA, 0x88},
	{0xDB, 0x36},
	{0xDC, 0x18},
	{0xDD, 0x98},
	{0xDE, 0x77},
	{0xDF, 0x57},
	{0xE0, 0x37},
	{0xE1, 0x0F},
	{0xE2, 0x00},
	{0xE3, 0x00},
	{0xE4, 0x00},
	{0xE5, 0x00},
	{0xE6, 0x00},
	{0xE7, 0x00},
	{ACTUATOR_SCRIPT_END,       0x00}			//! DA7280 - end of script flag
};
#define SCRIPT_RESET 0

//! haptic_LRA_basic[] - DA7280 setup for LRA coin types :
//! register load table for basic device/actuator initialization 
//! (Actuator dependent setup commands with auto-calibration)
const struct scr_type haptic_LRA_basic[] = {
	{ACTUATOR_SCRIPT_END,       0x00}  //! DA7280 - end of script flag
};
#define SCRIPT_LRA_BASIC 1

//! haptic_ERM_basic[] - DA7280 setup for ERM types :
//! register load table for basic device/actuator initialization 
//! (Actuator dependent setup commands)
const struct scr_type haptic_ERM_basic[] = {
	{0x03, 0x00},
	{0x04, 0x00},
	{0x05, 0x00},
	{0x07, 0x00},
	{0x08, 0x80},
	{0x0A, 0x19},
	{0x0B, 0x05},
	{0x0C, 0x81},
	{0x0D, 0x90},
	{0x0E, 0x13},
	{0x0F, 0x01},
	{0x10, 0x23},
	{0x13, 0x20},
	{0x14, 0x11},
	{0x15, 0x04},
	{0x16, 0xC0},
	{0x17, 0x81},
	{0x1C, 0x03},
	{0x1D, 0x20},
	{0x1E, 0x02},
	{0x1F, 0x58},
	{0x20, 0x43},
	{0x22, 0x00},
	{0x23, 0x48},
	{0x24, 0x04},
	{0x25, 0x61},
	{0x26, 0xB4},
	{0x27, 0xEC},
	{0x28, 0x00},
	{0x29, 0x00},
	{0x2A, 0x08},
	{0x2B, 0x10},
	{0x2D, 0x80},
	{0x48, 0x28},
	{0x49, 0x00},
	{0x4C, 0x00},
	{0x5F, 0x08},
	{0x60, 0x0B},
	{0x62, 0x0F},
	{ACTUATOR_SCRIPT_END, 0x00}  //! DA7280 - end of script flag
};
#define SCRIPT_ERM_BASIC 2

//! haptic_ERM_coin[] - DA7280 setup for ERM Disc/Coin types :
//! register load table for basic device/actuator initialization 
//! (Actuator dependent setup commands)
const struct scr_type haptic_ERM_coin[] = {
	{DA7280_TOP_CFG1,           0xA0},
	{ACTUATOR_SCRIPT_END,       0x00}  //! DA7280 - end of script flag
};
#define SCRIPT_ERM_COIN 3

//! haptic_LRA_basic[] - DA7280 setup for LRA coin types :
//! register load table for basic device/actuator initialization 
//! (Actuator dependent setup commands with auto-calibration)
const struct scr_type haptic_LRA_calibrate[] = {
	{ACTUATOR_SCRIPT_END,       0x00}  //! DA7280 - end of script flag
};
#define SCRIPT_LRA_CALIBRATE 4

//! haptic_complex1[] - complex script 1
const struct scr_type haptic_complex1[] = {
	{DA7280_IRQ_EVENT1, 0xff},
	{ACTUATOR_SCRIPT_GOWAIT,    0x00}, //! DA7280 - go and wait
	{ACTUATOR_SCRIPT_END,       0x00}  //! DA7280 - end of script flag
};
#define SCRIPT_COMPLEX1 5

//! haptic_complex2[] - complex script 2
const struct scr_type haptic_complex2[] = {
	{ACTUATOR_SCRIPT_GOWAIT,    0x00},  //! DA7280 - go and wait
	{ACTUATOR_SCRIPT_END,       0x00}   //! DA7280 - end of script flag
};
#define SCRIPT_COMPLEX2 6

//! haptic_complex3[] - complex script 3
const struct scr_type haptic_complex3[] = {
	{ACTUATOR_SCRIPT_GOWAIT,    0x00}, //! DA7280 - go and wait
	{ACTUATOR_SCRIPT_END,       0x00}  //! DA7280 - end of script flag
};
#define SCRIPT_COMPLEX3 7
#define SCRIPT_LAST 7

//! array of pointers to arrays of FX scripts...
const scr_type* scriptList[ACTUATOR_SCRIPT_MAX];

//! Define a structure to hold the actuator instance data for the haptic driver
static struct haptic_driver actuator;

/**************************************************************************/
/*! 
    @brief  Instantiate a new DA7280 class
	        Use -1 for any unused pin assignments
			i.e. only GPIO0 for PWM on Pin #5, no Interrupts
			Haptic_DA7280 actuator( -1, 5, -1, -1);
*/
Haptic_DA7280::Haptic_DA7280() {
  // I2C Only
  _irq_pin = -1;
  _gp0_pin = -1;
  _gp1_pin = -1;
  _gp2_pin = -1;
}

Haptic_DA7280::Haptic_DA7280(int8_t irq_pin) {
  // I2C with Interrupts
  _irq_pin = irq_pin;
  _gp0_pin = -1;
  _gp1_pin = -1;
  _gp2_pin = -1;
}

Haptic_DA7280::Haptic_DA7280(int8_t irq_pin, int8_t g0_pin, int8_t g1_pin, int8_t g2_pin){
 // I2C with Interrupts and GPIO pins
   _irq_pin = irq_pin;
   _gp0_pin = g0_pin;
   _gp1_pin = g1_pin;
   _gp2_pin = g2_pin;
}

/********************************************************************/

int Haptic_DA7280::readReg(uint8_t reg) {
  uint8_t dada;
    Wire.beginTransmission(Haptic_I2C_Address);
    Wire.write((byte)reg);
    Wire.endTransmission();
    Wire.requestFrom((byte)Haptic_I2C_Address, (byte)1);
    dada = Wire.read();
  return((int)dada);  //! a career in dada processing!
}

int Haptic_DA7280::writeReg(uint8_t reg, uint8_t dada) {
    Wire.beginTransmission(Haptic_I2C_Address);
    Wire.write((byte)reg);
    Wire.write((byte)dada);
    Wire.endTransmission();
	return(HAPTIC_SUCCESS);
}

int Haptic_DA7280::writeRegBits(uint8_t reg, uint8_t mask, uint8_t bits) {
	uint8_t val = readReg(reg);
	if (val < 0) return(HAPTIC_FAIL);
	val = val & ~mask; val |= bits;
	return(writeReg(reg, val));
}

int Haptic_DA7280::writeRegBulk(uint8_t reg, uint8_t *dada, uint8_t size) {
	for (int i = 0; i < size; i++) {
		int ret = writeReg(reg + i, *dada++);
		if (ret != HAPTIC_SUCCESS) return(HAPTIC_FAIL);
	}
	return(HAPTIC_SUCCESS);
}

int Haptic_DA7280::writeRegScript(const struct scr_type script[])
{
	for (int i = 0; script[i].reg != ACTUATOR_SCRIPT_END; i++) {
		if (script[i].reg == ACTUATOR_SCRIPT_DELAY) {
			delay(script[i].val);
		} else if (script[i].reg == ACTUATOR_SCRIPT_GOWAIT) {
          goWait();
		} else if (writeReg(script[i].reg, script[i].val)) {
			Serial.println("ERROR DA7280: writeRegScript failure\n");
			return(HAPTIC_FAIL);
		}
	}
	return(HAPTIC_SUCCESS);
}

int Haptic_DA7280::getDeviceID(void) {
  return(readReg(DA7280_CHIP_REV)); //! read chip ID register
}

/**************************************************************************/
/*! 
    @brief  Initialize the DA7280 Controller
*/
int Haptic_DA7280::begin() {
  if (_irq_pin >= 0){
	  pinMode(_irq_pin, INPUT);
  }
  if (_gp0_pin >= 0){
	  pinMode(_gp0_pin, INPUT);
  }
  if (_gp1_pin >= 0){
	  pinMode(_gp1_pin, INPUT);
  }
  if (_gp2_pin >= 0){
	  pinMode(_gp2_pin, INPUT);
  }

  //! initialize an array of pointers to effects scripts with 'setup' at index zero
  //! users can add their own scripts using the addScript(scriptNum, pointer to Script Struct) API
  //! some basic initialization and setup scripts for ERM & LRA, etc.
  scriptList[SCRIPT_RESET]          =  haptic_reset;       //! 'reset' script always at index zero
  scriptList[SCRIPT_LRA_BASIC]      =  haptic_LRA_basic;   //! LRA coin basic setup
  scriptList[SCRIPT_ERM_BASIC]      =  haptic_ERM_basic;   //! ERM (bar) basic setup
  scriptList[SCRIPT_ERM_COIN]       =  haptic_ERM_coin;    //! ERM (coin) basic setup
  scriptList[SCRIPT_LRA_CALIBRATE]  =  haptic_LRA_calibrate;
  scriptList[SCRIPT_COMPLEX1]       =  haptic_complex1;
  scriptList[SCRIPT_COMPLEX2]       =  haptic_complex2;
  scriptList[SCRIPT_COMPLEX3]       =  haptic_complex3;
  actuator.dev_scripts_max = SCRIPT_LAST + 1;

  //! initialize the I2C controller
  Wire.begin();

  playScript(SCRIPT_RESET);                 //! play the reset script
  int haptic_DeviceID = getDeviceID();
  if (haptic_DeviceID != HAPTIC_CHIP_ID) {
    return(HAPTIC_FAIL);
  } else {
	return(HAPTIC_SUCCESS);
  }
}

/**************************************************************************/
/*!
    Settings and control API's
*/
int Haptic_DA7280::setActuatorType(enum haptic_dev_t type) {
	if (type >= HAPTIC_DEV_MAX) {
		return (HAPTIC_FAIL);
	}
    actuator.dev_type = type;
	// writeRegBits(DA7280_TOP_CFG1,DA7280_ACTUATOR_TYPE_MASK,(type ? 1:0) << DA7280_ACTUATOR_TYPE_SHIFT);
	switch (actuator.dev_type)
	{
	  case LRA :
		// setup for LRA Type
	    playScript(SCRIPT_LRA_BASIC); //! the LRA "setup"/init script
		break;
	  case ERM :
		// setup for ERM type
	    playScript(SCRIPT_ERM_BASIC); //! the ERM "setup"/init script
		break;
	  case ERM_COIN :
		// setup for ERM coin type
	    playScript(SCRIPT_ERM_COIN);  //! the ERM Disc "setup"/init script
	    break;
	  case ERM_DMA :
        // setup for ERM Dual Mode type
	    playScript(SCRIPT_ERM_BASIC); //! the ERM "setup"/init script
	    break;
	  case LRA_DMA :
		// setup for LRA Dual Mode type
	    playScript(SCRIPT_LRA_BASIC); //! the LRA "setup"/init script
	    break;
	  default:
		break;
	}
    return(HAPTIC_SUCCESS);
}


int Haptic_DA7280::writeWaveformBulk(uint8_t reg, uint8_t *wave, uint8_t size) {
	if (size > DA7280_SNP_MEM_SIZE) {
		Serial.println("ERROR DA7820: writeWaveform invalid size parameter\n");
		return(HAPTIC_FAIL);
	}

	/* It is recommended to update the patterns
	* while haptic is not running, in order to avoid conflict
	*/
	int val = reg;
	val = readReg(DA7280_IRQ_STATUS1);
	if (val < 0) return(val);
	if (val & DA7280_STA_WARNING_MASK) {
		Serial.println("WARNING DA7820: writeWaveform DA7280 check Status\n");
		return(HAPTIC_FAIL);
	}

	/* Patterns will not be updated if the DA7280 lock bit is enabled */
	val = readReg(DA7280_MEM_CTL2);
	if (val < 0) return(val);
	val = (~val & DA7280_PATTERN_MEM_LOCK_MASK);
	if (val) {
		Serial.println("WARNING DA7820: writeWaveform memory is locked, unlocking...\n");
        writeReg(DA7280_MEM_CTL2, val);
	}
    /* read the current memory pointer */
	val = readReg(DA7280_MEM_CTL1);
	if (val < 0) return(val);
	return(writeRegBulk(val, wave, DA7280_SNP_MEM_MAX - val + 1));
}

int Haptic_DA7280::readWaveformBulk(uint8_t reg, uint8_t *wave, uint8_t size) {
	if (size > DA7280_SNP_MEM_SIZE) {
		Serial.println("ERROR DA7820: writeWaveform invalid size parameter\n");
		return(HAPTIC_FAIL);
	}
	int val = reg;

    /* read the current memory pointer */
	val = readReg(DA7280_MEM_CTL1);
	if (val < 0) return(val);
	for (int i = 0; i < size; i++) {
		int mem_val = readReg(val + i);
		*(wave + i) = (uint8_t)mem_val & 0xff;
	}
    return(size);
}

int Haptic_DA7280::setWaveform(uint8_t slot, uint8_t wave) {
	if (slot >= 16) {
		Serial.println("ERROR DA7280: Invalid Parameter - Slot out of range \n");
		return(HAPTIC_ILL_ARG);
	}
	if (wave >= actuator.dev_waveforms_max) {
		Serial.println("ERROR DA7280: Invalid Parameter - Waveform out of range");
		return(HAPTIC_ILL_ARG);
	}
  // Slot is used as "loop id" here, wave is sequence id
  uint8_t seq = ((slot<<4) & 0xF0) | (wave & 0x0F);
  return(writeReg(DA7280_SEQ_CTL2, seq));
}

int Haptic_DA7280::setWaveformLib(uint8_t lib){
	if (lib >= actuator.dev_libs_max) {
		Serial.println("ERROR DRV2605: Invalid Parameter - ROM Library out of range \n");
		return(HAPTIC_ILL_ARG);
	}
	actuator.dev_lib = lib;
	return(HAPTIC_SUCCESS);
}

int Haptic_DA7280::getWaveforms(void) {
	return(actuator.dev_waveforms_max);
}

int Haptic_DA7280::setScript(int num) {
	if (num < 0 || num >= actuator.dev_scripts_max) {
		return(HAPTIC_ILL_ARG);
	}
	actuator.dev_script = num;
  return(HAPTIC_SUCCESS);
}

int Haptic_DA7280::getScripts(void) {
  return(actuator.dev_scripts_max);
}

int Haptic_DA7280::playScript(int num) {
	if (num < 0 || num >= actuator.dev_scripts_max) {
		return(HAPTIC_ILL_ARG);
	}
	actuator.dev_script = num;
    return(writeRegScript(scriptList[num]));
}

int Haptic_DA7280::addScript(int num, const struct scr_type script[]) {
	if (num < 0 || num >= ACTUATOR_SCRIPT_MAX || ((actuator.dev_scripts_max+1) >= ACTUATOR_SCRIPT_MAX)) {
		return(HAPTIC_ILL_ARG);
	}
	actuator.dev_script = num;
	actuator.dev_scripts_max++;
    scriptList[num] = script;
    return(HAPTIC_SUCCESS);
}

/*! @brief go - trigger sequence play - nonblocking
*/
int Haptic_DA7280::go(void) {
	return(writeReg(DA7280_TOP_CTL1, 0x13));
}

/*! @brief goWait - trigger sequence play and wait for completion - blocking
*/
int Haptic_DA7280::goWait(void) {
  writeReg(DA7280_TOP_CTL1, 0x13);
  while (!(readReg(DA7280_IRQ_EVENT1)&0x04)) {
	  yield(); // needed for RTOS based ESP8266/ESP32, etc.
  }
  writeReg(DA7280_IRQ_EVENT1, 0xFF); //! clear interrupts/flags
  return(HAPTIC_SUCCESS);
}

/*! @brief stop - stop sequence play immediately  - nonblocking
*/
int Haptic_DA7280::stop(void) {
  //int ctl1 = readReg(DA7280_TOP_CTL1) & ~(0x10);
  return(writeReg(DA7280_TOP_CTL1, 0x03));
}


int Haptic_DA7280::setMode(enum op_mode mode)
{
	if (mode < 0 || mode >= HAPTIC_MODE_MAX) {
		return(HAPTIC_FAIL);
	}
	actuator.op_mode = mode;
	writeRegBits(DA7280_TOP_CTL1, DA7280_OPERATION_MODE_MASK, (mode & DA7280_OPERATION_MODE_MASK)<< DA7280_OPERATION_MODE_SHIFT);

    // these may need to expand differently...
	switch (actuator.op_mode)
	{
	  case INACTIVE_MODE :
		  // setup for inactive mode
		break;
	  case STREAM_MODE :
		  // setup for Direct Write/Realtime modes
		break;
	  case PWM_MODE :
		  // PWM input (GPIO-0) controls vibration
	    break;
	  case REGISTER_MODE :
		  // register triggered playback
	    break;
	  case GPIO_MODE :
		  // GPIO controlled playback
	    break;
	  // "modes" above DA7280_OPERATION_MODE_MASK are "soft" modes
	  case SLEEP_MODE :
		  // setup for low power/sleep mode
	    break;
	  default:
		break;
	}
	return(HAPTIC_SUCCESS);
}

int Haptic_DA7280::setRealtimeValue(uint8_t rtp) {
  return(writeReg(DA7280_TOP_CTL2, rtp)); // override value
}

//! audio play mode
int Haptic_DA7280::playAudio(uint8_t vibectrl, uint8_t minlevel, uint8_t maxlevel, uint8_t mindrv, uint8_t maxdrv) {
    return(HAPTIC_FAIL); // no audio mode?
}

//! stop audio play mode
int Haptic_DA7280::stopAudio(void) {
	stop();
	return(HAPTIC_SUCCESS);
}
