#include <WS2812.h>

#define NUM_LEDS_X 8
#define NUM_LEDS_Y 8
#define COLOR_PER_LEDS 3
#define NUM_BYTES (NUM_LEDS_X * NUM_LEDS_Y * COLOR_PER_LEDS)

__xdata uint8_t ledData[NUM_BYTES];

void setPixel(uint8_t *ledData, uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
  uint16_t index = (y * NUM_LEDS_X + x) * COLOR_PER_LEDS;
  ledData[index] = green;
  ledData[index + 1] = red;
  ledData[index + 2] = blue;
}

void clearGrid() {
  for (uint8_t y = 0; y < NUM_LEDS_Y; y++) {
    for (uint8_t x = 0; x < NUM_LEDS_X; x++) {
      setPixel(ledData, x, y, 0, 0, 0); 
    }
  }
}

void pixelGridData() {
  setPixel(ledData, 0, 0, 0, 0, 0); setPixel(ledData, 1, 0, 0, 0, 0); setPixel(ledData, 2, 0, 174, 35, 52); setPixel(ledData, 3, 0, 174, 35, 52); setPixel(ledData, 4, 0, 174, 35, 52); setPixel(ledData, 5, 0, 174, 35, 52); setPixel(ledData, 6, 0, 0, 0, 0); setPixel(ledData, 7, 0, 0, 0, 0); 
  setPixel(ledData, 0, 1, 0, 0, 0); setPixel(ledData, 1, 1, 174, 35, 52); setPixel(ledData, 2, 1, 232, 59, 59); setPixel(ledData, 3, 1, 232, 59, 59); setPixel(ledData, 4, 1, 232, 59, 59); setPixel(ledData, 5, 1, 240, 135, 135); setPixel(ledData, 6, 1, 174, 35, 52); setPixel(ledData, 7, 1, 0, 0, 0); 
  setPixel(ledData, 0, 2, 174, 35, 52); setPixel(ledData, 1, 2, 232, 59, 59); setPixel(ledData, 2, 2, 232, 59, 59); setPixel(ledData, 3, 2, 232, 59, 59); setPixel(ledData, 4, 2, 232, 59, 59); setPixel(ledData, 5, 2, 232, 59, 59); setPixel(ledData, 6, 2, 240, 135, 135); setPixel(ledData, 7, 2, 174, 35, 52); 
  setPixel(ledData, 0, 3, 174, 35, 52); setPixel(ledData, 1, 3, 232, 59, 59); setPixel(ledData, 2, 3, 232, 59, 59); setPixel(ledData, 3, 3, 0, 0, 0); setPixel(ledData, 4, 3, 0, 0, 0); setPixel(ledData, 5, 3, 232, 59, 59); setPixel(ledData, 6, 3, 232, 59, 59); setPixel(ledData, 7, 3, 174, 35, 52); 
  setPixel(ledData, 0, 4, 0, 0, 0); setPixel(ledData, 1, 4, 0, 0, 0); setPixel(ledData, 2, 4, 0, 0, 0); setPixel(ledData, 3, 4, 255, 255, 255); setPixel(ledData, 4, 4, 255, 255, 255); setPixel(ledData, 5, 4, 0, 0, 0); setPixel(ledData, 6, 4, 0, 0, 0); setPixel(ledData, 7, 4, 0, 0, 0); 
  setPixel(ledData, 0, 5, 204, 204, 204); setPixel(ledData, 1, 5, 255, 255, 255); setPixel(ledData, 2, 5, 255, 255, 255); setPixel(ledData, 3, 5, 0, 0, 0); setPixel(ledData, 4, 5, 0, 0, 0); setPixel(ledData, 5, 5, 255, 255, 255); setPixel(ledData, 6, 5, 255, 255, 255); setPixel(ledData, 7, 5, 204, 204, 204); 
  setPixel(ledData, 0, 6, 0, 0, 0); setPixel(ledData, 1, 6, 204, 204, 204); setPixel(ledData, 2, 6, 255, 255, 255); setPixel(ledData, 3, 6, 255, 255, 255); setPixel(ledData, 4, 6, 255, 255, 255); setPixel(ledData, 5, 6, 255, 255, 255); setPixel(ledData, 6, 6, 204, 204, 204); setPixel(ledData, 7, 6, 0, 0, 0); 
  setPixel(ledData, 0, 7, 0, 0, 0); setPixel(ledData, 1, 7, 0, 0, 0); setPixel(ledData, 2, 7, 204, 204, 204); setPixel(ledData, 3, 7, 204, 204, 204); setPixel(ledData, 4, 7, 204, 204, 204); setPixel(ledData, 5, 7, 204, 204, 204); setPixel(ledData, 6, 7, 0, 0, 0); setPixel(ledData, 7, 7, 0, 0, 0); 

}

void fillRainbowStartupAnimation(uint8_t brightness) {
  uint8_t rainbowColors[7][3] = {
    { 255, 0, 0 },    // Red
    { 255, 165, 0 },  // Orange
    { 255, 255, 0 },  // Yellow
    { 0, 128, 0 },    // Green
    { 0, 0, 255 },    // Blue
    { 75, 0, 130 },   // Indigo
    { 148, 0, 211 }   // Violet
  };

  for (uint8_t y = 0; y < NUM_LEDS_Y; y++) {
    for (uint8_t x = 0; x < NUM_LEDS_X; x++) {
      uint8_t colorIndex = (x + y) % 7;  // Calculate color index based on position
      uint8_t red = (rainbowColors[colorIndex][0] * brightness) / 255;
      uint8_t green = (rainbowColors[colorIndex][1] * brightness) / 255;
      uint8_t blue = (rainbowColors[colorIndex][2] * brightness) / 255;

      setPixel(ledData, x, y, red, green, blue);
    }
    neopixel_show_P1_4(ledData, NUM_BYTES);
    delay(100);  // Adjust delay to control the speed of the wave
  }
}

void setup() {
  pinMode(14, OUTPUT);
  clearGrid();
  fillRainbowStartupAnimation(5);
}

void loop() {
  // clearGrid();

  uint8_t brightness = 5;  // Adjust brightness level (0 to 255)
  pixelGridData();

  // Apply brightness to all LEDs
  for (uint16_t i = 0; i < NUM_BYTES; i++) {
    ledData[i] = ledData[i] * brightness / 255;
  }

  neopixel_show_P1_4(ledData, NUM_BYTES);
  delay(1000);
}