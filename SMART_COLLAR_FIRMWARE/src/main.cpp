#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "images.h"

// TFT pin definitions
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4

// Remap hardware SPI pins (ESP32): set MOSI to GPIO16 (D16)
#define TFT_MOSI 16  // D16
#define TFT_SCLK 18  // example SCLK (GPIO18) - adjust to your wiring
#define TFT_MISO 19  // example MISO (GPIO19) - set to -1 if unused

// Use hardware SPI (constructor with CS, DC, RST)
Adafruit_ILI9341 lcd = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// If you prefer software (bit-banged) SPI instead, uncomment the line below and comment out the hardware constructor above.
// Adafruit_ILI9341 lcd = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 57696)
const int epd_bitmap_allArray_LEN = 6;
const unsigned char* epd_bitmap_allArray[6] = {
    epd_bitmap_CatAgitated1,
    epd_bitmap_CatAgitated2,
    epd_bitmap_CatContent1,
    epd_bitmap_CatContent2,
    epd_bitmap_CatHappy1,
    epd_bitmap_CatHappy2
};
 
const uint8_t* images[] = { epd_bitmap_CatAgitated1, epd_bitmap_CatAgitated2, epd_bitmap_CatContent1, epd_bitmap_CatContent2, epd_bitmap_CatHappy1, epd_bitmap_CatHappy2 };
const uint8_t numImages = 6;

void setup() {
  // Remap hardware SPI pins on ESP32: SPI.begin(SCLK, MISO, MOSI, SS)
  SPI.begin(TFT_SCLK, TFT_MISO, TFT_MOSI, TFT_CS);

  lcd.begin();
  lcd.setRotation(3); // Portrait: X is left-right, Y is up-down
  lcd.fillScreen(ILI9341_BLACK);
}

void loop() {
  lcd.drawBitmap(0, 0, epd_bitmap_CatHappy1, 320, 240, ILI9341_GREENYELLOW, ILI9341_BLACK);
  delay(500);
  lcd.drawBitmap(0, 0, epd_bitmap_CatHappy2, 320, 240, ILI9341_GREENYELLOW, ILI9341_BLACK);
  delay(500);
}
