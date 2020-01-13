
// CHANGE PIN / NUM_LEDS / ARRAYS / FOR-LOOP LENGTHS IN FUNCTIONS

#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUM_LEDS 60

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int shoulders[] = {14, 13, 12, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 29, 28, 27, 27}; // CHANGE CYCLON SHOULDER TO 18
int shield[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

void setup()
{ 
  Serial.begin(9600);
  strip.begin();
}

void loop()
{ 
  Serial.print("5...");
  delay(1000);
  Serial.print("4...");
  delay(1000);
  Serial.print("3...");
  delay(1000);
  Serial.print("2...");
  delay(1000);
  Serial.print("1...");
  delay(1000);
  Serial.print("MUSIC!!!");
  delay(1000);

  delay(67411);
  
  CylonShoulder(0, 0, 150, 2, 45); // 826ms
  
  Strobe(0, 0, 150, 2, 174);

  delay(22079);
  
  setShield(150, 0, 0);
  
  delay(1284);
  
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
