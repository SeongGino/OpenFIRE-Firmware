# SAMCO Enhanced+ - Arduino Powered Light Gun (now with added pew-pews!)
##### Alt working title: GUN4ALL

Based on the [Prow Enhanced fork](https://github.com/Prow7/ir-light-gun), which in itself is based on the 4IR Beta "Big Code Update" [SAMCO project](https://github.com/samuelballantyne/IR-Light-Gun)

## PLUS Enhancements!
- **Solenoid Support!** Get the authentic arcade feedback with every shot. Works when aiming *on-screen!*
- **Rumble Support!** Feel the subtle feedback of a motor, for those moments when you need to *shoot outside of the screen!*
- **Temperature Sensor Support!** With an optional TMP36 sensor, you can keep your solenoid working better for longer! Tempers feedback based on temperature readings with every shot.
- All upgrades are *optional,* and can work as a drop-in replacement for current SAMCO builds (with minor changes).
- Plenty of safety checks, to ensure rock-solid functionality without parts sticking or overheating. Now you too can feel like a helicopter parent!
- Remains forever open source, with *compatibility for GUN4IR parts!* Can use the same community resources of parts and tutorials for easier assembly of a complete build.
- Clearer labeling in the sketch for user readability. Ain't nobody got time to read!
- Fully cross-platform solution, all configuration done using the open-source Arduino IDE and adjustments done on the board!
- Made out of at least 49% passion and 49% stubbornness (and 2% spite)!

## Original Prow's Fork Enhancements
- Increased precision for maths and mouse pointer position
- Glitch-free DFRobot positioning (DFRobotIRPositionEx library)
- IR camera sensitivity adjustment (DFRobotIRPositionEx library)
- Faster IIC clock option for IR camera (DFRobotIRPositionEx library)
- Optional averaging modes can be enabled to slightly reduce mouse position jitter
- Enhanced button debouncing and handling (LightgunButtons library)
- Modified AbsMouse to be a 5 button device (AbsMouse5 library)
- Multiple calibration profiles
- Save settings and calibration profiles to flash memory (SAMD) or EEPROM (ATmega32U4)
- Built in Processing mode for use with the SAMCO Processing sketch

## Requirements
- Adafruit ItsyBitsy [M0](https://www.adafruit.com/product/3727), [M4](https://www.adafruit.com/product/3800), or [RP2040](https://www.adafruit.com/product/4888) (ATmega32U4 5V 16MHz or Pro Micro ATmega32U4 5V 16MHz might still work, but no guarantees on performance)
- DFRobot IR Positioning Camera [SEN0158](https://www.mouser.com/ProductDetail/DFRobot/SEN0158?qs=lqAf%2FiVYw9hCccCG%2BpzjbQ%3D%3D)
- 4 IR LED emitters | regular Wii sensor bars might work for small distances, but it's HIGHLY recommended to use [SFH 4547 LEDs](https://www.mouser.com/ProductDetail/720-SFH4547) w/ 5.6 ohm resistors. [Build tutorial here!](https://www.youtube.com/watch?v=dNoWT8CaGRc)
 * Optional: Any 12V solenoid, w/ associated relay board. [Build tutorial here!](https://www.youtube.com/watch?v=4uWgqc8g1PM)
   * Requires a DC power extension cable and an adjustable 12V power supply.
 * Optional: Any 5V rumble motor, w/ associated relay board. [Build tutorial here!](https://www.youtube.com/watch?v=LiJ5rE-MeHw)
 * Optional: Any 2-way SPDT switches, to adjust state of rumble/solenoid/rapid fire.

With minor modifications it should work with any SAMD21, SAMD51, or ATmega32U4 16MHz boards. [See the SAMCO project for build details.](https://github.com/samuelballantyne/IR-Light-Gun)

The RP2040 is the most performant board for the cheapest price, and future proofs your build (at the cost of no working EEPROM storage for profile saves), but the M0 and M4 should still work well! The ATmega-based boards have an EEPROM for saving settings, but might be out of code space by now with this build.

## Installation
1. Ensure you have the Arduino development environment (currently 1.x) installed with support for your board.
2. Install the `Keyboard` library by Arduino in the Library Manager.
  * If you use an **ItsyBitsy M0** or **M4** then install the `Adafruit DotStar` and `Adafruit SPIFlash` libraries in the Library Manager.
  * If you use an **ItsyBitsy RP2040** then install `Adafruit NeoPixel` and `Adafruit TinyUSB`.
3. Copy all the folders under `libraries` into your Arduino libraries folder.
4. Copy the `SamcoEnhanced` folder to your Arduino sketch folder.
5. Open the `SamcoEnhanced` sketch.

## Additional information
[Check out the enclosed instruction book!](https://github.com/SeongGino/ir-light-gun-plus/blob/plus/SamcoEnhanced/README.md) Also see the README files in `libraries` for more information on library functionality.

## Known Issues:
- Trigger might incidentally double-press on rare occasions, as a result of reading the pin state directly which doesn't use debouncing logic.
- Start/Select/Dpad debouncing logic is weird and may cause buttons to stick or require a few tries to actuate properly. Still needs investigation.
- Code is still kind of a mess, so I should clean things up at some point maybe kinda.
- Solenoid *may or may not* cause EMI disconnects depending on the build, the input voltage, and the disarray of wiring in tight gun builds. **This is not caused by the sketch,** but something that theoretically applies to most custom gun builds (just happened to happen to me and didn't find many consistent search results involving this, so be forewarned!)

## TODO:
- Should implement support for rumble as an alternative force-feedback system; decouple rumble from off-screen exclusively at some point.
- Implement software solution for enabling the rumble or solenoid, or toggle rapid fire system; should probably make a new button mask combo to activate while in pause mode.
- Make an option for a true autofire that auto-reloads after a set amount of seconds or trigger pulls? Make the coordinates move to 0,0 and force a mouse unclick/click/unclick. Might be cheaty, but if someone wants it...
- Console support? [It's definitely possible!](https://github.com/88hcsif/IR-Light-Gun)

## Thanks:
* Samuel Ballantyne, for his SAMCO project which inspired my madness in the first place.
* Prow7, for improving an already promising project and providing the basis for this madness.
* Jaybee, for a frame of reference on implementing the feedback additions, and to hopefully act as an OS-agnostic competition for the (I assume) great GUN4IR.
* [My YouTube audience,](https://youtube.com/ThatOneSeong) for their endless patience as I couldn't help but work on this instead of videos.
* Emm, for being there when I needed her.
* And Autism.

If you enjoy my work, or somehow found entertainment in this, [please support my endeavors on Ko-fi!](https://ko-fi.com/ThatOneSeong)

  *~<3*
  
  *That One Seong*
