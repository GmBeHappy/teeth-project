#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// init neo pixel
#define PIN 2
#define NUMPIXELS 16

#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// function prototype
void setPixelColor(int group[], int color[]);

void setup()
{
  pixels.begin();

  // Set button
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
}

void loop()
{
  int delayval = 500;

  // Group of pixels
  int group1[] = {0, 1, 2};    // ฟันกราม
  int group2[] = {3, 4};       // ฟันกรามน้อย
  int group3[] = {5};          // ฟันเขี้ยว
  int group4[] = {6, 7};       // ฟันหน้าตัด
  int group5[] = {8, 9};       // ฟันหน้าตัด
  int group6[] = {10};         // ฟันเขี้ยว
  int group7[] = {11, 12};     // ฟันกรามน้อย
  int group8[] = {13, 14, 15}; // ฟันกราม

  for (int i = 0; i < NUMPIXELS; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    delay(delayval);
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
    delay(delayval);
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(delayval);
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
    pixels.show();
    delay(delayval);
  }
}

void setPixelColor(int group[], int color[])
{
  for (int i = 0; i < sizeof(group); i++)
  {
    pixels.setPixelColor(group[i], pixels.Color(color[0], color[1], color[2]));
    pixels.show();
  }
}
