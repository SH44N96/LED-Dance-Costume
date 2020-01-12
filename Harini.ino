
// CHANGE PIN / NUM_LEDS / ARRAYS / FOR-LOOP LENGTHS IN FUNCTIONS

#include <Adafruit_NeoPixel.h>
#define PIN 7
#define NUM_LEDS 60

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int shoulders[] = {14, 13, 12, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 29, 28, 27, 27}; // CHANGE CYCLON SHOULDER TO 18
int shield[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
int tls[] = {59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42}; // CHANGE LENGTH IN FUNCTION

void setup()
{ 
  strip.begin();
}

void loop()
{ 
  delay(66985);
  
  CylonShoulder(0, 0, 150, 2, 45); // 826ms
  
  strip.clear();
  strip.show();
  
  delay(2822); 

  colorWipe(200, 200, 200, 35); // 650ms
  
  strip.clear();
  strip.show();  

  StrobeTLS(200, 200, 200, 2, 197);
  
  delay(1676);
  
  setShield(150, 0, 0);

  delay(299);

  setShield(0, 150, 0);

  delay(2155);
  
  StrobeTLS(0, 0, 150, 2, 173);
  
  setTLS(0, 0, 150);
  
  delay(488);

  strip.clear();
  strip.show();

  delay(14179);

  setShield(150, 0, 0);

  delay(963);
  
  Sparkle(675); // 1349ms
  
  strip.clear();
  strip.show();
}

void setPixel(int Pixel, byte red, byte green, byte blue)
{
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
}

void setShield(byte red, byte green, byte blue)
{
  for(int i = 0; i < 36; i++)
  {
    setPixel(shield[i], red, green, blue);
  }
  strip.show();
}

void setTLS(byte red, byte green, byte blue)
{
  for(int i = 0; i < 18; i++)
  {
    setPixel(tls[i], red, green, blue);
  }
  strip.show();
}

void setAll(byte red, byte green, byte blue)
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    setPixel(i, red, green, blue);
  }
  strip.show();
}

void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay)
{
  for(int j = 0; j < StrobeCount; j++)
  {
    setAll(red, green, blue);
    strip.show();
    delay(FlashDelay);
    strip.clear();
    strip.show();
    delay(FlashDelay);
  }
}

void StrobeTLS(byte red, byte green, byte blue, int StrobeCount, int FlashDelay)
{
  for(int j = 0; j < StrobeCount; j++)
  {
    for(int i = 0; i < 18; i++)
    {
      setPixel(tls[i], red, green, blue);
    }
    strip.show();
    delay(FlashDelay);
    for(int i = 0; i < 18; i++)
    {
      setPixel(tls[i], 0, 0, 0);
    }    
    strip.show();
    delay(FlashDelay);
  }
}

void colorWipe(byte red, byte green, byte blue, int SpeedDelay)
{
  for(int i = 0; i < 18; i++)
  {
    setPixel(tls[i], red, green, blue);
    strip.show();
    delay(SpeedDelay);
  }
}

void CylonShoulder(byte red, byte green, byte blue, int EyeSize, int SpeedDelay)
{ 
  for(int i = 0; i < (18 - 2); i++)
  {
    strip.clear();
    setPixel(shoulders[i], red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++)
    {
      setPixel(shoulders[i+j], red, green, blue);
    }
    setPixel(shoulders[i + EyeSize + 1], red/10, green/10, blue/10);
    strip.show();
    delay(SpeedDelay);
  }
}

void Sparkle(int Times)
{
  for(int i = 0; i < Times; i++)
  {
    int Pixel = random(NUM_LEDS);
    setPixel(Pixel, random(255), random(255), random(255));
    strip.show();
  }
}
