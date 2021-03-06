
#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUM_LEDS 62

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int shoulders[] = {14, 13, 12, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 29, 28, 27, 27};
int shield[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
int tls[] = {61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42};

int btnState;
int btn = 9;
int tracker = 0;

void setup()
{
  pinMode(btn, INPUT_PULLUP);
  strip.begin();
}

void loop()
{
  // Wait for Button Press
  btnState = digitalRead(btn);
  
  // If Button Pressed
  if(btnState == LOW)
  {
    if(tracker == 1)
    {
      // Test Lights
      setAll(0, 50, 0);
      
      delay(500);
      
      strip.clear();
      strip.show();
      
      // Play Music
            
      // LED Sequence
      delay(97860);
      
      CylonShoulder(0, 0, 150, 2, 35); // 688ms
      
      strip.clear();
      strip.show();
      
      delay(588);
      
      StrobeShield(0, 0, 150, 2, 174);
      
      delay(650);
      
      colorWipe(200, 200, 200, 35); // 650ms
      
      delay(650);
      
      strip.clear();
      strip.show();
      
      delay(197);
      
      StrobeTLS(200, 200, 200, 2, 197);
      
      delay(1377);
      
      setShield(0, 150, 0);
      
      delay(598);
      
      setShield(150, 0, 0);
      
      delay(2155);
      
      StrobeTLS(0, 0, 150, 2, 173);
      
      setTLS(0, 0, 150);
      
      delay(500);
      
      strip.clear();
      strip.show();
      
      delay(11584);
      
      // CHANGE TWINKLE VALUES
      
      TwinkleRight(300); // 726ms
      strip.clear();
      strip.show();
      
      TwinkleLeft(300); //726ms
      
      strip.clear();
      strip.show();
      
      TwinkleRight(300); // 726ms
      strip.clear();
      strip.show();
      
      TwinkleLeft(150); // 363ms
      strip.clear();
      strip.show();
      
      setShield(150, 0, 0);
      
      delay(1605);
      
      Sparkle(675); // 1349ms
      
      setAll(0, 200, 50);
      
      delay(3970);
      
      strip.clear();
      strip.show();
    }
    else
    {
      tracker++;
      delay(30000);
    }
  }
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
  for(int i = 0; i < 20; i++)
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

void StrobeTLS(byte red, byte green, byte blue, int StrobeCount, int FlashDelay)
{
  for(int j = 0; j < StrobeCount; j++)
  {
    for(int i = 0; i < 20; i++)
    {
      setPixel(tls[i], red, green, blue);
    }
    strip.show();
    delay(FlashDelay);
    for(int i = 0; i < 20; i++)
    {
      setPixel(tls[i], 0, 0, 0);
    }
    strip.show();
    delay(FlashDelay);
  }
}

void StrobeShield(byte red, byte green, byte blue, int StrobeCount, int FlashDelay)
{
  for(int j = 0; j < StrobeCount; j++)
  {
    for(int i = 0; i < 36; i++)
    {
      setPixel(shield[i], red, green, blue);
    }
    strip.show();
    delay(FlashDelay);
    for(int i = 0; i < 36; i++)
    {
      setPixel(shield[i], 0, 0, 0);
    }
    strip.show();
    delay(FlashDelay);
  }
}

void colorWipe(byte red, byte green, byte blue, int SpeedDelay)
{
  for(int i = 0; i < 20; i++)
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

void TwinkleRight(int Count)
{
  setAll(0, 0, 0);
  for(int i = 0; i < Count; i++)
  {
    setPixel(random(21, 42), random(255), random(255), random(255));
    strip.show();
  }
}

void TwinkleLeft(int Count)
{
  setAll(0, 0, 0);
  for(int i = 0; i < Count; i++)
  {
    setPixel(random(0, 21), random(255), random(255), random(255));
    strip.show();
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
