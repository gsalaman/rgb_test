// The "all white" test

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// Pin defines for the 32x32 RGB matrix.
#define CLK 11  
#define LAT 10
#define OE  9
#define A   A0
#define B   A1
#define C   A2
#define D   A3

/* Other Pin Mappings...hidden in the RGB library:
 *  Sig   Uno  Mega
 *  R0    2    24
 *  G0    3    25
 *  B0    4    26
 *  R1    5    27
 *  G1    6    28
 *  B1    7    29
 */

// Note "false" for double-buffering to consume less memory, or "true" for double-buffered.
RGBmatrixPanel matrix(A, B, C,  D,  CLK, LAT, OE, false);

#define BRIGHTNESS_PIN A5

void setup() 
{
  int i;
  
  matrix.begin();

}

void loop() 
{
  int pin_read;
  uint16_t brightness;

  // this will give us 0-1023
  pin_read = analogRead(BRIGHTNESS_PIN);

  // map this to 0-7
  brightness = map(pin_read,0,1023,0,7);

  //  ...and set the screen
  matrix.fillScreen(matrix.Color333(brightness,brightness,brightness));
  
}
