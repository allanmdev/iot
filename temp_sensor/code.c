#include <Wire.h>              
#include <LiquidCrystal_I2C.h> 

#define R 8           
#define BUZZER 9      
#define BTN 10      
#define TEMP A0

LiquidCrystal_I2C lcd(0x27, 16, 2);
// Dependendo alterar para 0x3F

int inches = 0;
int btnState = 0;
int lastBtnState = LOW;
int alarmActive = true; 
int cm = 0;
int temp = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void controlLeds() {
  digitalWrite(R, LOW);
}

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");

  pinMode(R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop() {
  btnState = digitalRead(BTN);
  
  if (btnState == HIGH && lastBtnState == LOW) {
    alarmActive = !alarmActive; 
    noTone(BUZZER);
    digitalWrite(R, LOW); 
    delay(200); 
  }
  
  lastBtnState = btnState; 
  temp = analogRead(TEMP);
  float tempCelsius = (temp / 1023.0) * 500.0; 
  
  cm = 0.01723 * readUltrasonicDistance(5, 7);
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); 
  
  if (cm <= 20 && alarmActive) {
    digitalWrite(R, HIGH); 
    tone(BUZZER, 1000);    
    Serial.println(tempCelsius);

  } else {
    digitalWrite(R, LOW); 
    noTone(BUZZER);       
  }
  
  lcd.setCursor(6, 0); 
  lcd.print(tempCelsius);
  lcd.print(" C");
}