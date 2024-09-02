// C++ code
//

int LED = 9;
int PORT_ANALOG = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(PORT_ANALOG, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int LDR = analogRead(PORT_ANALOG);
  if (LDR > 650) {
    digitalWrite(LED, HIGH);
  	Serial.println("LED ligado");
  } else {
  	digitalWrite(LED, LOW);
    Serial.println("LED desligado");
  }
  
  delay(1000);
}