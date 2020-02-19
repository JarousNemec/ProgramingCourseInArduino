#include <LiquidCrystal.h>

#include <Adafruit_NeoPixel.h> // připojení potřebné knihovny
#define pinDI 6 // nastavení propojovacího pinu
#define pocetLED 4 // nastavení počtu LED
// inicializace LED modulu z knihovny
Adafruit_NeoPixel rgbWS = Adafruit_NeoPixel(pocetLED, pinDI, NEO_GRB + NEO_KHZ800);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16,2);
  rgbWS.begin(); // zahájení komunikace s LED modulem
  rgbWS.setBrightness(100); //nastaví jas (0-255)
  Serial.begin(9600);
}
int a = 0;
int b = 0;
int c = 0;
int d = 0;
void serialPrint() {
  Serial.flush();
  Serial.println("a:");
  Serial.print(a);
  Serial.println("b:");
  Serial.print(b);
  Serial.println("c:");
  Serial.print(c);
  Serial.println("d:");
  Serial.print(d);
}
int LowHigh(int LedN) {
  for (int i = 0 ; a <= 254; a++)  {
    rgbWS.setPixelColor(LedN, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
    delay(5);
    rgbWS.show(); //pošle data
    //serialPrint();

  }
  for (int i = 0 ; b <= 254; b++)  {
    rgbWS.setPixelColor(LedN, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
    delay(5);
    rgbWS.show(); //pošle data
    //serialPrint();

  }
  for (int i = 0; c <= 254; c++) {
    rgbWS.setPixelColor(LedN, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
    delay(5);
    rgbWS.show(); //pošle data
    serialPrint();
  }
  for (a = 255 ; a >= 0; a--)  {
    rgbWS.setPixelColor(LedN, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
    delay(5);
    rgbWS.show(); //pošle data
    //serialPrint();
  }
  a = 0;
  for (c = 255 ; b >= 0; b--)  {
    rgbWS.setPixelColor(LedN, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
    delay(5);
    rgbWS.show(); //pošle data
    //serialPrint();
  }
  for (c = 255; c >= 0; c--) {
    rgbWS.setPixelColor(LedN, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
    delay(5);
    rgbWS.show(); //pošle data
    serialPrint();
  }
  c = 0;
}
int AllLedGoAllRGBColours(){
  for (a = 0 ; a <= 254; a++)  {
    for (d = 0 ; d <= 4;  d++) {
      rgbWS.setPixelColor(d, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
      delay(5);
      rgbWS.show(); //pošle data
      //serialPrint();
    }
  }
  b = 0;
  c = 0;
  a = 0;
  for (b = 0; b <= 254; b++)  {
    for (d = 0 ; d <= 4;  d++) {
      rgbWS.setPixelColor(d, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
      delay(5);
      rgbWS.show(); //pošle data
      //serialPrint();
    }
  }
  b = 0;
  c = 0;
  a = 0;
  for (c = 0; c <= 254; c++) {
    for (d = 0 ; d <= 4;  d++) {
      rgbWS.setPixelColor(d, rgbWS.Color(a, b, c)); //nastaví příslušné LED náhodnou hodnotu RGB
      delay(5);
      rgbWS.show(); //pošle data
      serialPrint();
    }
  }
  }

void loop() {
  for (d = 0 ; d <= 4;  d++) {
    lcd.home();
    lcd.print("LedNumber: ");
    lcd.print(d);
    LowHigh(d);
  }
  AllLedGoAllRGBColours();
  for (d = 4 ; d >= 0;  d--) {
    lcd.home();
    lcd.print("LedNumber: ");
    lcd.print(d);
    LowHigh(d);
  }
}
