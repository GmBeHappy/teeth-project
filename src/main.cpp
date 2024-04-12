#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include "RedMP3.h"

// init neo pixel
#define PIN 2
#define NUMPIXELS 16

// Group of pixels
int group1[] = {0, 1, 2, 13, 14, 15}; // ฟันกราม
int group2[] = {3, 4, 11, 12};        // ฟันกรามน้อย
int group3[] = {5, 10};               // ฟันเขี้ยว
int group4[] = {6, 7, 8, 9};          // ฟันหน้าตัด

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// init button
#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6

// init mp3
#define MP3_RX 7          // RX of Serial MP3 module connect to D7 of Arduino
#define MP3_TX 8          // TX to D8, note that D8 can not be used as RX on Mega2560, you should modify this if you donot use Arduino UNO
int8_t volume = 0x1a;     // 0~0x1e (30 adjustable level)
int8_t folderName = 0x01; // folder name must be 01 02 03 04 ...
int8_t fileG1 = 0x001;
int8_t fileG2 = 0x002;
int8_t fileG3 = 0x003;
int8_t fileG4 = 0x004;

MP3 mp3(MP3_RX, MP3_TX);

// function prototype
void setPixelGroupColor(int group[], int groupSize, int color[]);
void updateButton();
void runGroup1();
void runGroup2();
void runGroup3();
void runGroup4();

void setup()
{
  pixels.begin();

  // init mp3
  delay(500); // Requires 500ms to wait for the MP3 module to initialize
  mp3.setVolume(volume);
  // delay(50); // you should wait for >=50ms between two commands
  // mp3.playWithFileName(folderName, fileName);
  delay(50);

  // Set button
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
}

void loop()
{
  updateButton();
}

void updateButton()
{
  if (digitalRead(SW1) == LOW)
  {
    runGroup1();
  }
  if (digitalRead(SW2) == LOW)
  {
    runGroup2();
  }
  if (digitalRead(SW3) == LOW)
  {
    runGroup3();
  }
  if (digitalRead(SW4) == LOW)
  {
    runGroup4();
  }
}

void setPixelGroupColor(int group[], int groupSize, int color[])
{
  for (int i = 0; i < groupSize; i++)
  {
    pixels.setPixelColor(group[i], pixels.Color(color[0], color[1], color[2]));
    pixels.show();
  }
}

void runGroup1()
{
  int color[] = {0, 255, 0};
  setPixelGroupColor(group1, 6, color);
  delay(50);
  mp3.playWithFileName(folderName, fileG1);
}

void runGroup2()
{
  int color[] = {0, 0, 255};
  setPixelGroupColor(group2, 4, color);
  delay(50);
  mp3.playWithFileName(folderName, fileG2);
}

void runGroup3()
{
  int color[] = {255, 255, 0};
  setPixelGroupColor(group3, 2, color);
  delay(50);
  mp3.playWithFileName(folderName, fileG3);
}

void runGroup4()
{
  int color[] = {255, 0, 0};
  setPixelGroupColor(group4, 4, color);
  delay(50);
  mp3.playWithFileName(folderName, fileG4);
}
