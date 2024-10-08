#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#define SS_PIN 10
#define RST_PIN 9

#define BUZZER 8
#define SENSOR  2

int sensorState = 0;
bool alarmActive = false; 
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin(); 
  mfrc522.PCD_Init();

  pinMode(SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
}

bool validateRFID() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return false;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return false;
  }

  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println(content.substring(1));

  if (content.substring(1) == "07 ed c9 3b" )  {
    return true;
  } else {
    return false;
  }
}

void loop() {
  sensorState = digitalRead(SENSOR);
  Serial.println(sensorState);
  if (sensorState == HIGH && !alarmActive) {
    alarmActive = true;  
    tone(BUZZER, 1); 
  }

  if (alarmActive) {
    if (validateRFID()) {
      noTone(BUZZER);  
      alarmActive = false;  
    }
  }

  delay(1000);
}
