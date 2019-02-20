/*  Embedis - Embedded Dictionary Server
    Copyright (C) 2015, 2016 PatternAgents, LLC

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

// Adds some useful commands to Embedis.
// We'll add some Arduino I/O commands for making it interpretive...
//
// Call setup_commands from your main setup() function.
// e.g. setup_commands();
//
void commands_setup()
{
    /* create an interactive "pinMode" command */
    Embedis::command( F("pinMode"), [](Embedis* e) {
        if (e->argc != 3) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        String argv2(e->argv[2]);
        argv2.toUpperCase();
        int mode;
        if (argv2 == "INPUT") mode = INPUT;
        else if (argv2 == "OUTPUT") mode = OUTPUT;
        else if (argv2 == "INPUT_PULLUP") mode = INPUT_PULLUP;
        else return e->response(Embedis::ARGS_ERROR);
        pinMode(pin, mode);
        e->response(Embedis::OK);
    });

    /* create an interactive "digitalWrite" command */
    Embedis::command( F("digitalWrite"), [](Embedis* e) {
        if (e->argc != 3) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        String argv2(e->argv[2]);
        argv2.toUpperCase();
        int mode;
        if (argv2 == "HIGH") mode = HIGH;
        else if (argv2 == "LOW") mode = LOW;
        else mode = argv2.toInt();
        digitalWrite(pin, mode);
        e->response(Embedis::OK);
    });

    /* create an interactive "digitalRead" command */
    Embedis::command( F("digitalRead"), [](Embedis* e) {
        if (e->argc != 2) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        if (digitalRead(pin)) {
            e->response(F("HIGH"));
        } else {
            e->response(F("LOW"));
        }
    });

    /* create an interactive "analogRead" command */
    Embedis::command( F("analogRead"), [](Embedis* e) {
        if (e->argc != 2) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        e->response(':', analogRead(pin));
    });

    /* create an interactive WRITE command for I2C peripherals  */
    /* WRITE DA7280  REG_ADDRESS REG_DATA                       */
    /* WRITE ADXL345 REG_ADDRESS REG_DATA                       */
    Embedis::command( F("WRITE"), [](Embedis* e) {
        if (e->argc != 4) return e->response(Embedis::ARGS_ERROR);
        uint8_t reg = (uint8_t)strtoul(e->argv[2], NULL, 0);
        uint8_t val = (uint8_t)strtoul(e->argv[3], NULL, 0);
        if (strcmp(e->argv[1], "DA7280") == 0) {
          haptic.writeReg(reg, val);
          return e->response(Embedis::OK);
        } 
        if (strcmp(e->argv[1], "ADXL345") == 0) {
          accel.writeRegister(reg, val);
          return e->response(Embedis::OK);
        }
        return e->response(Embedis::UNKNOWN_COMMAND);
    });

    /* create an interactive WRITE command for I2C peripherals  */
    /* READ DA7280  REG_ADDRESS                                */
    /* READ ADXL345 REG_ADDRESS                                */
    Embedis::command( F("READ"), [](Embedis* e) {
        if (e->argc != 3) return e->response(Embedis::ARGS_ERROR);
        uint8_t reg = (uint8_t)strtoul(e->argv[2], NULL, 0);
        if (strcmp(e->argv[1], "DA7280") == 0) {
          int val = haptic.readReg(reg);
          Serial.print("DA7280 REG=0x");
          Serial.print(reg, HEX);
          Serial.print(" VALUE=0x");
          Serial.println(val, HEX);
          return e->response(Embedis::OK);
        } 
        if (strcmp(e->argv[1], "ADXL345") == 0) {
          int val = accel.readRegister(reg);
          Serial.print("ADXL345 REG=0x");
          Serial.print(reg, HEX);
          Serial.print(" VALUE=0x");
          Serial.println(val, HEX);
          return e->response(Embedis::OK);
        }
        return e->response(Embedis::UNKNOWN_COMMAND);
    });
}
