#define sloupce 16
#define radky 2
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
lcd.begin(sloupce, radky);
}

void loop() {
  //Serial.println(analogRead(A5));
  for(int i = 0;i<sloupce;i++){
    lcd.setCursor(i,1);
    lcd.print("0");
    delay(analogRead(A5));
    delay(10);
    }
    for(int i = 0;i<sloupce;i++){
    lcd.setCursor(i,1);
    lcd.print("1");
    delay(analogRead(A5));
    delay(10);
    }
  

}
