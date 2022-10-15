// Pin selections here are based on the original Adafruit Learning System
// guide for the Teensy 3.x project.  Some of these pin numbers don't even
// exist on the smaller SAMD M0 & M4 boards, so you may need to make other
// selections:

// GRAPHICS SETTINGS (appearance of eye) -----------------------------------


// Enable ONE of these #includes -- HUGE graphics tables for various eyes:
//#include "owlEye.h"      // Standard human-ish hazel eye -OR-
#include "dragonEye.h"     // Slit pupil fiery dragon/demon eye -OR-
#include "defaultEye.h"

// EYE LIST ----------------------------------------------------------------

// This table contains ONE LINE PER EYE.  The table MUST be present with
// this name and contain ONE OR MORE lines.  Each line contains THREE items:
// a pin number for the corresponding TFT/OLED display's SELECT line, a pin
// pin number for that eye's "wink" button (or -1 if not used), and a screen
// rotation value (0-3) for that eye.

eyeInfo_t eyeInfo[] = {
  { 4, -1, 2 }, // LEFT EYE display-select and wink pins, no rotation
  {  12, -1, 2 }, // RIGHT EYE display-select and wink pins, no rotation
};

// set trigger distance for change of eye type in centimeters
  #define triggerDistance 110

// DISPLAY HARDWARE SETTINGS (screen type & connections) -------------------
  #define TFT_SPI        SPI
  #define TFT_PERIPH     PERIPH_SPI
  


  #include <ST7735_t3.h> // TFT display library (enable one only)
  #define DISPLAY_DC        5    // Data/command pin for ALL displays
  #define DISPLAY_RESET     16    // Reset pin for ALL displays
  #define SPI_FREQ 48000000    // TFT: use max SPI (clips to 12 MHz on M0)


// INPUT SETTINGS (for controlling eye motion) -----------------------------

// JOYSTICK_X_PIN and JOYSTICK_Y_PIN specify analog input pins for manually
// controlling the eye with an analog joystick.  If set to -1 or if not
// defined, the eye will move on its own.
// IRIS_PIN speficies an analog input pin for a photocell to make pupils
// react to light (or potentiometer for manual control).  If set to -1 or
// if not defined, the pupils will change on their own.
// BLINK_PIN specifies an input pin for a button (to ground) that will
// make any/all eyes blink.  If set to -1 or if not defined, the eyes will
// only blink if AUTOBLINK is defined, or if the eyeInfo[] table above
// includes wink button settings for each eye.

//#define TRACKING
#define AUTOBLINK           // If defined, eyes also blink autonomously
/*
  #define BLINK_PIN         1 // Pin for manual blink button (BOTH eyes)
  #define LIGHT_PIN      A2 // Photocell or potentiometer (else auto iris)
  #define LIGHT_PIN_FLIP    // If defined, reverse reading from dial/photocell
  #define LIGHT_MIN       0 // Lower reading from sensor
  #define LIGHT_MAX    1023 // Upper reading from sensor
*/

#define IRIS_SMOOTH         // If enabled, filter input from IRIS_PIN
#if !defined(IRIS_MIN)      // Each eye might have its own MIN/MAX
  #define IRIS_MIN      120 // Iris size (0-1023) in brightest light
#endif
#if !defined(IRIS_MAX)
  #define IRIS_MAX      720 // Iris size (0-1023) in darkest light
#endif
