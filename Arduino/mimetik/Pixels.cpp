#include "Pixels.h"
#include "Arduino.h"
//#include <Adafruit_NeoPixel.h>


Pixels::Pixels()
{

}

Pixels::~Pixels()
{

}

void Pixels::randomColor(Adafruit_NeoPixel &_pixels)
{
  Serial.println("in rand");
  int red = random(0, 255);
  int green = random(0, 255);
  int blue = random(0, 255);
  for (int i = 0; i < NUMPIXELS; i++) {
    _pixels.setPixelColor(i, _pixels.Color(red, green, blue));
    _pixels.show();
  }
}

void Pixels::RGBColor(Adafruit_NeoPixel &_pixels, int _red, int _green, int _blue)
{
  for (int i = 0; i < NUMPIXELS; i++) {
    _pixels.setPixelColor(i, _pixels.Color(_red, _green, _blue));
    _pixels.show();
  }
  
}

void Pixels::ColorShift(Adafruit_NeoPixel &_pixels, String _kColor, float _accx){
  Serial.println(_accx);
  if(_kColor = "blue"){
    for (int i = 0; i < NUMPIXELS; i++) {
    _pixels.setPixelColor(i, _pixels.Color(0, 0, 255*_accx));
    _pixels.show();
    }
  }
  else if(_kColor = "red"){
    for (int i = 0; i < NUMPIXELS; i++) {
    _pixels.setPixelColor(i, _pixels.Color(255*_accx, 0, 0));
    _pixels.show();
    }
  }
}




// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Pixels::Wheel(Adafruit_NeoPixel &_pixels,byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return _pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return _pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return _pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}