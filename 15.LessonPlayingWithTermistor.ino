#include <LiquidCrystal.h>

#include <math.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  lcd.begin(16,2);
}
double Termister(int RawADC) {
  double Temp;
  Temp = log(((10240000 / RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp = Temp - 273.15;
  return Temp;
}
void loop() {
  lcd.home();
  int val;
  double Temp; 
  val = analogRead(A0);
  Temp = Termister(val);
  lcd.print("Temp: ");
  lcd.print(Temp);
  Serial.print(Temp);
  if(Temp<=25.5){
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    }
    if(Temp>=25.6 && Temp<=30){
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    
    }
    if(Temp>=30.1){
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    
    }
  delay(200);
Serial.print("\n");
}
