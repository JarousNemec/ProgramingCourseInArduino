// Hodiny reálného času DS1307

// připojení knihoven
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include "RTClib.h"
int Year;
int Month;
int Day;
int Hour;
int Minute;
int Seconds;
RTC_DS1307 DS1307;


void setup () {
  lcd.begin();
  lcd.backlight();
  DS1307.adjust(DateTime(2005, 10, 26, 0, 0, 0));
}

void loop () {
  // načtení aktuálního času a data do proměnné datumCas
  DateTime datumCas = DS1307.now();
  lcd.setCursor ( 0, 0 );
   lcd.print("Time ");
  lcd.print(datumCas.hour());
  lcd.print(":");
  lcd.print(datumCas.minute());
  lcd.print(":");
  lcd.print(datumCas.second());
  lcd.setCursor ( 0, 1 );
   lcd.print("Date ");
  lcd.print(datumCas.day());
lcd.print(":");
  lcd.print(datumCas.month());
lcd.print(":");
  lcd.print(datumCas.year());
  delay(1000);
}
