#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

// Definições do display OLED
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
#define SENSOR_PIN 2 

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  int sensorValue = digitalRead(SENSOR_PIN); 

  display.clearDisplay();
  display.setCursor(0, 30);
  Serial.println(sensorValue);
  if (sensorValue == HIGH) {
    display.print("Som");
    display.setCursor(0, 50);
    display.print("DETECTADO");
  } else {
    display.print("Som nao");
    display.setCursor(0, 50);
    display.print("detectado");
  }
  
  display.display();
  delay(500); 
}