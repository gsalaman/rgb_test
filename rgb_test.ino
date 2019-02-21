// Example primatives.

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
// Double-buffered makes animation smoother, but on the UNO, we don't quite have enough mem for that.
RGBmatrixPanel matrix(A, B, C,  D,  CLK, LAT, OE, false);

// This function shows examples of using each matrix primative.
void demo_primatives( void )
{
  // Each of these primatives is going to take a color.  Color is a 16 bit unsigned number...to set it 
  // to an RGB value, you can use either:
  //     matrix.Color333 (which takes 3 bit values for R,G,B)  or   
  //     matrix.Color444 (which takes 4 bit values.)
  //  I'll demo both below.  Note that a quick "black" is the number 0.

  // Here's a list of primatives I'll be using.   You can find more examples at:
  //    https://learn.adafruit.com/32x16-32x32-rgb-led-matrix/library
  //
  // fillScreen(color)
  // drawPixel(x,y,color)
  // drawRect(x,y,length,width,color);
  // fillRect(x,y,length,width,color);
  // drawLine(start_x, start_y, end_x, end_y, color);
  // drawCircle(x,y,radius, color);
  // fillCircle(x,y,radius,color);
  //
  // Text:
  // setCursor(x,y);
  // setTextSize(n)  -- height = 8*n
  // setTextColor(color)
  // print()
  
  // When specifying x and y coordinates, (0,0) is the top left corner, and (31,31) is the bottom right.
  
  // Fill screen with a dim blue background.
  matrix.fillScreen(matrix.Color333(0,0,1));

  // set the far bottom right pixel to a bright red
  matrix.drawPixel(31,31,matrix.Color333(7,0,0));

  // draw a 5x10 green rectangle in the top left
  matrix.drawRect(0,0, 5, 10, matrix.Color333(0,4,0));

  // now draw another one that's filled in right next to it...but we'll make this one only 4 pixels wide.
  matrix.fillRect(6,0,4,10,matrix.Color333(0,4,0));

  // use drawLine twice to draw a purple x in the bottom left corner.
  matrix.drawLine(0,31,4,27,matrix.Color444(8,0,15));
  matrix.drawLine(4,31,0,27,matrix.Color444(8,0,15));

  // Now, two circles...one filled, one not...in the top-right.  We're gonna make these black...hence the 0 for color.
  matrix.drawCircle(26,5,4,0);
  matrix.fillCircle(15,5,4,0);

  // Time for some text...we'll print it in the middle.  
  matrix.setCursor(0,16);
  matrix.setTextSize(1);
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print("Hello");

  // note that print acts like a regular print, so you can print variables...
  matrix.setCursor(9,24);
  matrix.setTextColor(matrix.Color444(15,15,15));
  int number=42;  // What kind of a programmer declares a variable in the middle of their function?!?!?
  matrix.print(number);
  
}



void setup() 
{
  int i;
  
  matrix.begin();

  demo_primatives();  
}


void loop() 
{
  

}
