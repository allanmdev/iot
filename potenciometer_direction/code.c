#define P1 A0
#define P2 A1

void setup()
{
  Serial.begin(9600);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);

}

void loop()
{
  int valorX = analogRead(P1);  
  int valorY = analogRead(P2); 

  if (valorY > 600) {
    Serial.println("Para cima");
  } else if (valorY < 400) {
    Serial.println("Para baixo");
  }

  if (valorX > 600) {
    Serial.println("Para direita");
  } else if (valorX < 400) {
    Serial.println("Para esquerda");
  }

  delay(500); 

}