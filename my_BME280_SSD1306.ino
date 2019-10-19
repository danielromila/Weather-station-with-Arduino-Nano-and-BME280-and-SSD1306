#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>                            
#include <Adafruit_BME280.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

 if (!bme.begin(0x76)) {  
      display.setCursor(0,0);  
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.println("ERROR SENSOR");  
      display.display();  
      while (1); 
   }
}

void loop() 
{
   display.setTextSize(2);
   display.setTextColor(WHITE);
   display.clearDisplay();
                                 
   display.setCursor(0,0);
   display.print("T :");                         
   display.print(bme.readTemperature());                   
   display.println(" C");

   display.setCursor(0,22);
   display.print("H :");                         
   display.print(bme.readHumidity());                   
   display.println(" %");
   
   display.setCursor(0,44);
   display.print("P:");                 
   display.print(bme.readPressure()*  0.00750062);            
   display.println("mm");

   display.display();

   delay(1000);  
}
