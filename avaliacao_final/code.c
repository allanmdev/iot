#include <SPI.h>
#include <MFRC522.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <DHT.h>
#include <Adafruit_Sensor.h> 

#define OLED_RESET -1
#define SS_PIN 10
#define RST_PIN 9
#define BUZZER 2
#define LDR A0
#define TEMP A1

#define bt_out1 3
#define bt_out2 4
#define bt_out3 5
#define bt_out4 6

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
MFRC522 mfrc522(SS_PIN, RST_PIN); 
float temp;

void buzzerSync(int freq, int time = 500) {
    tone(BUZZER, freq, time);
  	delay(1000);
  	noTone(BUZZER);
  	delay(1000);
}

String initRFID() {
    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
      return "";
    }

    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
      return "";
    }

    String content= "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
      // Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      // Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }

    content.toUpperCase();
    return content.substring(1);
}

int ldrValue = 0;
 
void displayMessage(int opt, String msg = "", int auth = 0) {
    display.clearDisplay();
    display.setCursor(0, 10);


    if (opt == 0 && auth == 0) {
        display.print("Acesso negado");
        display.setCursor(0, 30);
    } 

    if (opt == 0 && auth == 1) {
        display.print("Acesso Liberado");
        display.setCursor(0, 30);
        display.print("Bem-vindo ao Sistema");
    } 
    else if (opt == 1 && auth == 1) {
        display.print("Configura\xC3\xA7\xC3\xB5es");
        display.setCursor(0, 30);
        display.print("1. Acessar Configura\xC3\xA7\xC3\xB5es");
        display.setCursor(0, 50);
        display.print("2. Tela Inicial");
    } 
    else if (opt == 2 && auth == 1) {
  
      temp = analogRead(TEMP);
      Serial.println(temp);
      display.print("Temperatura:");
      display.setCursor(0, 30);
      display.print(temp); 
    } 
    else if (opt == 3 && auth == 1) {
        display.print("Opções de Tela");
        display.setCursor(0, 30);
        display.print("Op 1: clique 3");
        display.setCursor(0, 50);
        display.print("Op 2: clique 4");
    }

    display.display();
}

int optValues() {
   if(digitalRead(bt_out1) == HIGH){ 
      return 1;
  }

  if(digitalRead(bt_out2) == HIGH){ 
      return 2;
  }

  if(digitalRead(bt_out4) == HIGH){ 
      return 3;
  }

  if(digitalRead(bt_out3) == HIGH){ 
      return 4;
  }

  return 0;
  
}

void setup() {
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);
  pinMode(LDR, INPUT);

  pinMode(bt_out1, INPUT);
  pinMode(bt_out2, INPUT);
  pinMode(bt_out3, INPUT);
  pinMode(bt_out4, INPUT);

  SPI.begin();      
  mfrc522.PCD_Init();   

  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

}

void loop() {
  String code = initRFID();
  String keyValidate = "56 C8 99 AC";

  if (code == keyValidate) {
    int opt = optValues();
    displayMessage(opt, "", 1);
  } 
  
  if (code != "" && code != keyValidate) {
      displayMessage(0, "", 0);
  }   

}