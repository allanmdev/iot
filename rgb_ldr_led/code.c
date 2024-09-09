// C++ code
//

#define R 6
#define G 3
#define B 5
#define LDR A0

int ldrValue = 0;
int digitalNumber = 0;

struct LedColor {
	const char* name;
  	int rgb[3];
};


void setup()
{
  Serial.begin(9600);
  
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(LDR, INPUT);
}

void ledActive(int number = 0) {
  LedColor led_colors[] = {
    {"Desligado", {0, 0, 0}},
    {"Vermelho", {255, 0, 0}},
    {"Verde", {0, 255, 0}},
    {"Azul", {0, 0, 255}},
    {"Amarelo", {255, 255, 0}},
    {"Ciano", {0, 255, 255}},
    {"Magenta", {255, 0, 255}},
  };
  
  analogWrite(R, led_colors[number].rgb[0]);
  analogWrite(G, led_colors[number].rgb[2]);
  analogWrite(B, led_colors[number].rgb[1]);

}


void loop()
{
  
  int count[7] = {0, 100, 200, 300, 400, 500, 600};
  
  ldrValue = analogRead(LDR);
  
  for (int i = 0; i < 6; i++ ) {
    int newCount = newCount + (i + 1);
    if (ldrValue >= count[i] && ldrValue < count[newCount]) {
      	ledActive(i);
    }
  }
 
}