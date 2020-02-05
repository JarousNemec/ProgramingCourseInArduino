//inicializace knihoven
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <math.h>


//metoda pro výpočet teploty
double Termister(int RawADC) {
  int Temp;
  Temp = log(((10240000 / RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp = Temp - 273.15;
  return Temp;
}

void setup() {
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);
}
void loop() {

  //inicializace promněnných
  int Temp;
  int val = analogRead(A0);
  int valFan = 0;

  //zjískání hodnoty Temp
  Temp = Termister(val);

  //rozsvícení příslušné led podle hodnoty Temp
  if (Temp <= 25.5) {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    valFan = 0;
  }
  if (Temp >= 25.6 && Temp <= 30) {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    valFan = 20;
  }
  if (Temp >= 30.1) {
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    valFan = 90;
  }

  //regulace otáček motoru
  digitalWrite(7, HIGH);
  delay(valFan);
  digitalWrite(7, LOW);
  delay(20);

  //výpis do sériového portu
  Serial.print(Temp);
  Serial.print("\n");

  //výpis na display
  lcd.home();
  lcd.print("Temp: ");
  lcd.print(Temp);
}
