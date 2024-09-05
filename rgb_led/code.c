// C++ code
//

#define R 3
#define G 5
#define B 6

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
}

void loop()
{
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
  
  int num_items = sizeof(led_colors) / sizeof(led_colors[0]);

  
  for (int digitalNumber = 0; digitalNumber < num_items; digitalNumber++) {
    Serial.print("Nome da cor: ");
    Serial.println(led_colors[digitalNumber].name);
    
    analogWrite(R, led_colors[digitalNumber].rgb[0]);
    analogWrite(G, led_colors[digitalNumber].rgb[2]);
    analogWrite(B, led_colors[digitalNumber].rgb[1]);
    delay(1000);
  }
  

}