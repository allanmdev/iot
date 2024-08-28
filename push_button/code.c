// C++ code
//

int btnState = 0;
int greenLed = 1;
int yellowLed = 2;
int redLed = 3;

void setup()
{
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(btnState, INPUT);
}

void loop()
{
  
  btnState = digitalRead(10);
  
  if (btnState == HIGH) {
    digitalWrite(greenLed, HIGH);
    delay(2000);

    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    delay(3000);

    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(1000);
  } else {
    digitalWrite(1, LOW);
    delay(1000);
  }

}