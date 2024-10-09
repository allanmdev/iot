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
  int v1 = analogRead(P1);
  int v2 = analogRead(P2);
  
  Serial.println("Eixo X: " + String(v1));
  Serial.println("Eixo Y: " + String(v2));
  Serial.println("----------------------");

}