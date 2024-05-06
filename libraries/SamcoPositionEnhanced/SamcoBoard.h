/*!
 * @file SamcoBoard.h
 * @brief Build configuration for Arduino boards.
 *
 * @copyright Mike Lynch, 2021
 * @copyright GNU Lesser General Public License
 *
 * @author Mike Lynch
 * @version V1.0
 * @date 2021
 */

#ifndef _SAMCOBOARD_H_
#define _SAMCOBOARD_H_

//// GUI BOARD IDENTIFIERS

#ifdef ARDUINO_ADAFRUIT_ITSYBITSY_RP2040
#define OPENFIRE_BOARD "adafruitItsyRP2040"
#elifdef ARDUINO_ADAFRUIT_KB2040_RP2040
#define OPENFIRE_BOARD "adafruitKB2040"
#elifdef ARDUINO_NANO_RP2040_CONNECT
#define OPENFIRE_BOARD "arduinoNanoRP2040"
#elifdef ARDUINO_RASPBERRY_PI_PICO
#define OPENFIRE_BOARD "rpipico"
#else
#define OPENFIRE_BOARD "generic"
#endif // board

//// COMPATIBILIY FLAGS
#if defined(ARDUINO_ARCH_RP2040)
    // Raspberry Pi Pico RP2040
    #define SAMCO_RP2040 1
    
    // DFRobot IR camera IIC clock
    // even with cheap clips and the full length IR cam cable 1MHz is fine
    #define DFROBOT_IR_IIC_CLOCK 1000000

    // Earle Philhower Arduino RP2040 reserves 4KB of flash using the Arduino EEPROM object, neat!
    #define SAMCO_EEPROM_ENABLE 1

    // software button anti-glitch
    #define BTN_AG_MASK 0xFFFFFFFF
    #define BTN_AG_MASK2 0xFFFFFFFF
#else
    // unknown board
    // this will use millis() for camera update timing instead of a hardware timer
    #define SAMCO_NO_HW_TIMER 1
    #define DFROBOT_IR_IIC_CLOCK 400000

    // software button anti-glitch mask
    #define BTN_AG_MASK1 0xF
    #define BTN_AG_MASK2 0xF
#endif // determine SAMCO_xxx board

//// ONBOARD LEDS
// specific ItsyBitsy board configuration
#if defined(NEOPIXEL_POWER)
    // included NeoPixel on compatible Adafruit boards
    #define NEOPIXEL_PIN PIN_NEOPIXEL
    #define NEOPIXEL_ENABLEPIN NEOPIXEL_POWER
#endif // NEOPIXEL_POWER

#endif // _SAMCOBOARD_H_
