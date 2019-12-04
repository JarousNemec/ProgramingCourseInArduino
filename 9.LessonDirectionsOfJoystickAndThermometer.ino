#include "DHT.h"
// nastavení čísla pinu s připojeným DHT senzorem
#define pinDHT 6

// odkomentování správného typu čidla
#define typDHT11 DHT11     // DHT 11

// inicializace DHT senzoru s nastaveným pinem a typem senzoru
DHT mojeDHT(pinDHT, typDHT11);
#include <LiquidCrystal.h>

// inicializace pinu, lze vyměnit za jiné volné
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  mojeDHT.begin();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  lcd.begin(16, 2);
  
}

void loop() {
  //vypisování hodnot teploty a vlhokosti na LCD
  int tep = mojeDHT.readTemperature();
  lcd.setCursor(4, 1);
  lcd.print("temp. ");
  lcd.print(tep);
  //pohyby joysticku a vypisovani na lcd

  if (analogRead(A1) > 0 && analogRead(A1) < 489) {
    lcd.setCursor(0, 0);
    lcd.print("do leva ");
  }
  if (analogRead(A1) > 501 && analogRead(A1) < 1024) {
    lcd.setCursor(0, 0);
    lcd.print("do prava");
  }
  else if (analogRead(A1) == 497 ) {
    lcd.setCursor(0, 0);
    lcd.print("nikam   ");
  }

  if (analogRead(A0) > 510 && analogRead(A0) < 1024) {
    lcd.setCursor(9, 0);
    lcd.print("nahodu");
  }
  if (analogRead(A0) > 0 && analogRead(A0) < 499) {
    lcd.setCursor(9, 0);
    lcd.print("dolu  ");
  }
  else if (analogRead(A0) ==  509) {
    lcd.setCursor(9, 0);
    lcd.print("nikam   ");
  }
  //tlacitko u joysticku
  if (analogRead(A2) == 0)
  {
    lcd.setCursor(0, 2);
    lcd.print("ON ");
    digitalWrite(13, HIGH);

  }
  else {
    lcd.setCursor(0, 2);
    lcd.print("OFF");
    digitalWrite(13, LOW);

  }
  delay(200);

}
