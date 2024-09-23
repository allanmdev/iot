#include<LiquidCrystal.h>

int TEMP = A0;
float temp = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); 
}

void loop()
{
  temp = analogRead(TEMP);
  float tempCelsius = (temp / 1023.0) * 500.0;
  
  lcd.setCursor(2,0);          
  lcd.print("Temperatura "); 
  lcd.setCursor(6,1);           
  lcd.print(tempCelsius);    
  lcd.print("°C");
  }