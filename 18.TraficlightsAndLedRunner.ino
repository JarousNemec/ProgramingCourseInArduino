#include <LiquidCrystal.h>

#include <Adafruit_NeoPixel.h> // připojení potřebné knihovny
#define pinDI 6 // nastavení propojovacího pinu
#define pocetLED 4 // nastavení počtu LED
// inicializace LED modulu z knihovny
Adafruit_NeoPixel rgbWS = Adafruit_NeoPixel(pocetLED, pinDI, NEO_GRB + NEO_KHZ800);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  rgbWS.begin(); // zahájení komunikace s LED modulem
  rgbWS.setBrightness(100); //nastaví jas (0-255)
  Serial.begin(9600);
}
void loop() {
  semafor();
  //LedRunner();
}

int LedRunner(){
  for (int i = 0; i < 4; i++) {
    LedLighting(255, 200, 0, i);
    delay(analogRead(A0));
    LedLighting(0, 0, 0, i);
  }
  }

int semafor() {
  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      LedLighting(0, 255, 0, i);
      delay(10000);
      LedLighting(0, 0, 0, i);
    }
    else if (i == 1) {
      LedLighting(255, 200, 0, i);
      delay(3000);
      LedLighting(0, 0, 0, i);
    }
    else if (i == 2) {
      LedLighting(255, 0, 0, i);
      delay(10000);
      LedLighting(0, 0, 0, i);
    }
  }
}
int LedLighting(int r, int g, int b, int i) {
  rgbWS.setPixelColor(i, rgbWS.Color(r, g, b)); //nastaví příslušné LED náhodnou hodnotu RGB
rgbWS.show();
LCDDisplay(r,g,b,i);
}
int LCDDisplay(int r, int g, int b, int i){
  
  lcd.print("            ");
  lcd.setCursor(0,0);
  lcd.print(i);
  lcd.print(" ");
  lcd.print(r);
  lcd.print(" ");
  lcd.print(g);
  lcd.print(" ");
  lcd.print(b);
  }
