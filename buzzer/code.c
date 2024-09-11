// C++ code
//

#define BUZZER 8
#define R 6
#define G 3
#define B 5

int i = 0;

struct LedColor {
    const char* name;
    int rgb[3];
};

void changeColor(int red = 0, int green = 0, int blue = 0) {
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue);
}

void syncBuzzer(int freq = 0, int color = 0, int time = 500) {
    LedColor led_colors[] = {
        {"Vermelho", {255, 0, 0}},
        {"Verde", {0, 255, 0}},
        {"Azul", {0, 0, 255}},
        {"Amarelo", {255, 255, 0}},
        {"Ciano", {0, 255, 255}},
        {"Magenta", {255, 0, 255}}, 
        {"Branco", {255, 255, 255}},
        {"Laranja", {255, 30, 0}},
        {"Roxo", {128, 0, 128}},
        {"Rosa", {255, 192, 203}}
    };
  
  	tone(BUZZER, freq, time);
  	changeColor(led_colors[color].rgb[0], led_colors[color].rgb[1], led_colors[color].rgb[2]);
  	delay(1000);
  	noTone(BUZZER);
  	delay(1000);
} 

void setup()
{
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

}

void loop()
{  
  int color = 0;
  
  for (int i = 200; i <= 1000; i = i + 100) {
  	syncBuzzer(i, color);
    color++;
  }  
  
}