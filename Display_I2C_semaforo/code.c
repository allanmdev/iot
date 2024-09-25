#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int R = 7;
int G = 5;
int B = 6;

LiquidCrystal_I2C lcd(0x27, 16, 2);

String ledChange(bool rState = false, bool gState = false, bool bState = false) {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);

    if (rState) {
        digitalWrite(R, HIGH);
        return "Vermelho";
    } else if (gState) {
        digitalWrite(G, HIGH);
        return "Verde";
    } else if (bState) {
        digitalWrite(B, HIGH);
        return "Amarelo";
    }
    return "";
}

void setup() {
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    lcd.init();
    lcd.backlight();
}

void loop() {
    String display = "";

    display = ledChange(true, false, false);
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("Cor: ");
    lcd.print(display);
    delay(2000);

    display = ledChange(false, true, false);
    lcd.clear();  
    lcd.setCursor(0, 0);
    lcd.print("Cor: ");
    lcd.print(display);
    delay(3000);

    display = ledChange(false, false, true);
    lcd.clear();  
    lcd.setCursor(0, 0);
    lcd.print("Cor: ");
    lcd.print(display);
    delay(1000);
}
