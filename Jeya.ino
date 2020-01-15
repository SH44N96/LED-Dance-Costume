
#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUM_LEDS 60

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int shoulders[] = {27, 28, 29, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 12, 13, 14, 14};
int shield[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

void setup()
{ 
  strip.begin();
}

void loop()
{ 
  // Wait for Button Press

  // If Button Pressed

  // Test Lights
  setAll(0, 50, 0);

  delay(500);

  strip.clear();
  strip.show();

  // Play Music

  // LED Sequence
  delay(67511);
  
  CylonShoulder(0, 0, 150, 2, 45); // 826ms
  
  Strobe(0, 0, 150, 2, 174);

  delay(23042);
  
  setShield(150, 0, 0);
  
  delay(321);
  
  Sparkle(675); // 1349ms
  
  setAll(0, 200, 50);
  
  delay(3970);
  
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
