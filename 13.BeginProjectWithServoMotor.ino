#include <LiquidCrystal.h>

// inicializace pinu, lze vyměnit za jiné volné
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include  <Servo.h>
Servo servo;
int potpin = 0;
int val=1;
void setup() {
  servo.attach(9);
  lcd.begin(16, 2);
}

void loop() {


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
    if(val <= 180){
      val = val + 1;
      }
  }
  if (analogRead(A0) > 0 && analogRead(A0) < 499) {
    lcd.setCursor(9, 0);
    lcd.print("dolu  ");
    if(val >= 0){
      val = val - 1;
      }
  }
  else if (analogRead(A0) ==  509) {
    lcd.setCursor(9, 0);
    lcd.print("nikam   ");
  }
  //tlacitko u joysticku
  if (analogRead(A2) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("ON ");
    digitalWrite(13, HIGH);

  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("OFF");
    digitalWrite(13, LOW);

  }
  servo.write(val);
  lcd.setCursor(9, 2);
  lcd.print(val);
  lcd.print("  ");
  //analogWrite(A3,1023);
  //analogWrite(A4,0);
  
  delay(20);
}
