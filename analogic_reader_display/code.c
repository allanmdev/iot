#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int x = A0;
int y = A1;
int btn = 7;
String move;
String lastMove = "";

const int threshold = 100;  

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);

  lcd.begin(16, 2);
  pinMode(6, OUTPUT);
  analogWrite(6, 50);

  lcd.setCursor(0, 0);
  lcd.print("Movimento:");
}

void loop() {
  move = moviment();
  Serial.println(move);

  if (move != lastMove) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(move);

    lastMove = move;
  }

  delay(100);
}

String moviment() {
  int xVal = analogRead(x);
  int yVal = analogRead(y);

  if (xVal < threshold) {
    return "Baixo";
  }
  if (xVal > 1023 - threshold) {
    return "Cima";
  }
  if (yVal < threshold) {
    return "Esquerda";
  }
  if (yVal > 1023 - threshold) {
    return "Direita";
  }
  if (digitalRead(btn) == 0) {
    return "Pressionado";
  }
  if (digitalRead(btn) == 1) {
    return "Solto";
  }

  return lastMove;
}
