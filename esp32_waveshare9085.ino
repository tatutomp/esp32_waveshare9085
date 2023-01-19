/**************************************************************************
 
 This example is for a 128x64 pixel display using SPI to communicate
 4 or 5 pins are required to interface. based on SSD1306 drivers

 See: ssd1306_128x64_spi.ino for more examples.
 
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI :
#define OLED_MOSI   23
#define OLED_CLK    22
#define OLED_DC     21
#define OLED_CS     19
#define OLED_RESET  18

// Initialize library
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
 
void setup() {
  Serial.begin(9600); 
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    
    for(;;) // Don't proceed, loop forever
      Serial.println(F("SSD1306 allocation failed"));
    
  }
 
  WriteToDisplay();       
}

void loop() {
} 
 
void WriteToDisplay(void) {
  display.clearDisplay();

  display.cp437(true);                  // Use full 256 char 'Code Page 437' font
  display.setTextColor(SSD1306_WHITE);  // The display in question shows Yellow text at first row and Blue in second.
  display.setCursor(15, 0);             // Start at top-left corner    
  display.setTextSize(2);               // Set font size for Hello text
       
  display.write("Hello");
  
  display.setCursor(20, 20);     
  display.setTextSize(3);               // Set font size for World text
  
  display.write("World"); 

  // Add this to draw a filled circle 
  // display.fillCircle(100,55,8,SSD1306_WHITE);
 
  display.display();

  // Starts to scroll Hello text to left.
  display.startscrollleft(0x00, 0x01); 
}
 

 
