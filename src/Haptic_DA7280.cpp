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

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>
#include "Haptic_DA7280.h"

//! Define a structure to hold the actuator instance data for the haptic driver
static struct haptic_driver actuator;

//! basic setup - register load table for device initialization
const struct scr_type haptic_fx0[] = {
	{DA7280_IRQ_EVENT1, 0xff},
	{DA7280_TOP_CTL2, ACTUATOR_OVERIDE_VAL},
	{DA7280_SEQ_CTL2, ACTUATOR_SEQ_LOOP << DA7280_PS_SEQ_LOOP_SHIFT | ACTUATOR_SEQ_ID << DA7280_PS_SEQ_ID_SHIFT},
	{ACTUATOR_SEQ_END, 0}
};

const struct scr_type haptic_fx1[] = {
	{DA7280_IRQ_EVENT1, 0xff},
	{ACTUATOR_SEQ_END, 0}
};

//! array of pointers to arrays of FX scripts...
const scr_type* fxList[ACTUATOR_FX_MAX];

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
	return(SUCCESS);
}

int Haptic_DA7280::writeRegBits(uint8_t reg, uint8_t mask, uint8_t bits) {
	uint8_t val = readReg(reg);
	if (val < 0) return(FAIL);
	val = val & ~mask; val |= bits;
	return(writeReg(reg, val));
}

int Haptic_DA7280::writeRegBulk(uint8_t reg, uint8_t *dada, uint8_t size) {
	for (int i = 0; i < size; i++) {
		int ret = writeReg(reg + i, *dada++);
		if (ret != 0) return(FAIL);
	}
	return(SUCCESS);
}

int Haptic_DA7280::writeRegScript(const struct scr_type script[])
{
	for (int i = 0; script[i].reg != ACTUATOR_SEQ_END; i++) {
		if (script[i].reg == ACTUATOR_SEQ_DELAY) {
			delay(script[i].val);
		} else if (writeReg(script[i].reg, script[i].val)) {
			Serial.println("ERROR DA7820: writeRegScript failure\n");
			return(FAIL);
		}
	}
	return(SUCCESS);
}

void Haptic_DA7280::irq_service(void) {
	Haptic_irq_cnt++;
	// placeholder for ISR handler (define weak binding?)
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

  //! initialize the I2C controller
  Wire.begin();

  //! initialize an array of pointers to effects scripts with 'setup' at index zero
  fxList[0] =  haptic_fx0;
  fxList[1] =  haptic_fx1;
  actuator.dev_effects_max = 2;
  int haptic_DeviceID = getDeviceID();
  if (haptic_DeviceID != HAPTIC_DEVICELIB) {
    return(FAIL);
  } else {
	return(SUCCESS);
  }
}

/**************************************************************************/
/*!
    Settings and control API's
*/
int Haptic_DA7280::setActuatorType(enum haptic_dev_t type) {
	if (type >= HAPTIC_DEV_MAX) {
		return (FAIL);
	}
	return writeRegBits(DA7280_TOP_CFG1,DA7280_ACTUATOR_TYPE_MASK,
			(type ? 1:0) << DA7280_ACTUATOR_TYPE_SHIFT);
}

int Haptic_DA7280::writeWaveformBulk(uint8_t reg, uint8_t *wave, uint8_t size) {
	if (size > DA7280_SNP_MEM_SIZE) {
		Serial.println("ERROR DA7820: writeWaveform invalid size parameter\n");
		return(FAIL);
	}

	/* It is recommended to update the patterns
	* while haptic is not running, in order to avoid conflict
	*/
	int val = reg;
	val = readReg(DA7280_IRQ_STATUS1);
	if (val < 0) return(val);
	if (val & DA7280_STA_WARNING_MASK) {
		Serial.println("WARNING DA7820: writeWaveform DA7280 check Status\n");
		return(FAIL);
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
		return(FAIL);
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

int Haptic_DA7280::setEffect(int effectnum) {
	if (effectnum < 0 || effectnum > actuator.dev_effects_max) {
		return(FAIL);
	}
	actuator.dev_effect = effectnum;
  return(SUCCESS);
}

int Haptic_DA7280::getEffects(void) {
  // returns the number of effects currently loaded 
  // - which may be none(zero) in RAM based devices
  // - until waveforms/sequences are loaded and referenced by an effect
  return(actuator.dev_effects_max);
}

int Haptic_DA7280::getDeviceID(void) {
  return(readReg(DA7280_CHIP_REV)); //! read chip ID register
}

int Haptic_DA7280::go(void) {
	return(writeRegBits(DA7280_TOP_CTL1, DA7280_SEQ_START_MASK, DA7280_SEQ_START_MASK));
}

int Haptic_DA7280::setMode(enum op_mode mode)
{
	if (mode < 0 || mode >= HAPTIC_MODE_MAX) {
		return(FAIL);
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

	return(SUCCESS);
}

int Haptic_DA7280::setRealtimeValue(uint8_t rtp) {
  return(SUCCESS);
}

