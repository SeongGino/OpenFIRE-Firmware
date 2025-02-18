#ifndef _OPENFIREDEFINES_H_
#define _OPENFIREDEFINES_H_

    // GLOBAL PREDEFINES ----------------------------------------------------------------------------------------------------------
  // Enables input processing on the second core, if available. Currently exclusive to Raspberry Pi Pico, or boards based on the RP2040.
  // Isn't necessarily faster, but might make responding to force feedback more consistent.
  // If unsure, leave this uncommented - it only affects RP2040 anyways.
#define DUAL_CORE

  // Here we define the Manufacturer Name/Device Name/PID:VID of the gun as will be displayed by the operating system.
  // For multiplayer, different guns need different IDs!
  // If unsure, or are only using one gun, just leave these at their defaults!
#define MANUFACTURER_NAME "OpenFIRE"
#define DEVICE_NAME "FIRECon"
#define DEVICE_VID 0xF143
#define DEVICE_PID 0x1998

  // Set what player this board is mapped to by default (1-4). This will change keyboard mappings appropriate for the respective player.
  // If unsure, just leave this at 1 - the mapping can be changed at runtime by sending an 'XR#' command over Serial, where # = player number
#define PLAYER_NUMBER 1

  // Leave this uncommented to enable MAMEHOOKER support, or comment out (//) to disable references to serial reading and only use it for debugging.
  // WARNING: Has a chance of making the board lock up if TinyUSB hasn't been patched to fix serial-related lockups.
  // If you're building this for RP2040, please make sure that you have NOT installed the TinyUSB library.
  // If unsure, leave uncommented - serial activity is used for configuration, and undefining this will cause errors.
#define MAMEHOOKER

  // Leave this uncommented if your build uses hardware switches, or comment out to disable all references to hw switch functionality.
#define USES_SWITCHES

  // Leave this uncommented if your build uses a rumble motor; comment out to disable any references to rumble functionality.
#define USES_RUMBLE

  // Leave this uncommented if your build uses a solenoid, or comment out to disable any references to solenoid functionality.
#define USES_SOLENOID
#ifdef USES_SOLENOID
    // Leave this uncommented for TMP36 temperature sensor support for a solenoid, or comment out to disable references to temperature reading or throttling.
    #define USES_TEMP
#endif // USES_SOLENOID

  // Leave this uncommented if your build uses an analog stick.
#define USES_ANALOG

  // Leave this uncommented if your build uses a four pin RGB LED.
#define FOURPIN_LED
#ifdef FOURPIN_LED
    #define LED_ENABLE
#endif // FOURPIN_LED

  // Leave this uncommented if your build uses an external NeoPixel.
#define CUSTOM_NEOPIXEL
#ifdef CUSTOM_NEOPIXEL
    #define LED_ENABLE
    #include <Adafruit_NeoPixel.h>
#endif // CUSTOM_NEOPIXEL

  // Leave this uncommented to enable optional support for SSD1306 monochrome OLED displays.
#define USES_DISPLAY
#ifdef USES_DISPLAY
  #include "SamcoDisplay.h"
#endif // USES_DISPLAY

#endif // _OPENFIREDEFINES_H_