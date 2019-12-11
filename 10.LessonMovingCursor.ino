
#include <LiquidCrystal.h>

// inicializace pinu, lze vyměnit za jiné volné
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int radky = 0;
int sloupce = 0;
void setup() {
  lcd.begin(16, 2);

}

void loop() {
  if (analogRead(A0) >= 600 && analogRead(A0) <= 1024 && radky >= 1) {
    radky = radky - 1;
  }
  if (analogRead(A0) >= 0 && analogRead(A0) <= 400 && radky <= 2) {
    radky = radky + 1;
  }

  if (analogRead(A1) >= 600 && analogRead(A1) <= 1024 && sloupce <= 14) {
    sloupce = sloupce + 1;
  }
  if (analogRead(A1) >= 0 && analogRead(A1) <= 400 && sloupce >= 0) {
    sloupce = sloupce - 1;
  } 
  
  
  lcd.clear();
  lcd.setCursor(sloupce, radky);
  lcd.print("0");
  delay(100);
}
