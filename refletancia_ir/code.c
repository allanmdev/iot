#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SH1106.h>

#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBoldOblique9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h> 

#define OLED_RESET -1 

#define sensor 7

Adafruit_SH1106 display(OLED_RESET);

void displayMessage(String message) {
    display.clearDisplay();]
    display.setFont(&FreeMonoOblique9pt7b);
    display.setTextColor(WHITE); ]
    display.setTextSize(1); 
    display.setCursor(1, 13); 
    display.print(message); 
    display.display();
}

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
}

void loop() {
  bool stateSensor = digitalRead(sensor);
  Serial.println(digitalRead(sensor));
  if (stateSensor) {
    Serial.println("PRETO (ou nada)");
    displayMessage("Nada");
  } else {
    displayMessage("Obstaculo");
    Serial.println("BRANCO (diferente de preto)");
  }
}
