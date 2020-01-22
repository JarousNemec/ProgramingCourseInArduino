#include <Servo.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define AAPin 6
#define ABPin 7
int ServoPos = 0;
int MotorPos = 0;

Servo servo;

void setup() {
lcd.begin(16, 2);
lcd.print("Hello, world!");
delay(2000);
lcd.home();
lcd.print("             ");
pinMode(AAPin, OUTPUT);
pinMode(ABPin, OUTPUT);
servo.attach(9);
}
void loop(){
  lcd.home();
  
  for(ServoPos = 0;ServoPos <= 180; ServoPos++){
  lcd.setCursor(0,0);
  lcd.print(ServoPos);
  servo.write(ServoPos);
  delay(50);
  }
  for(ServoPos = 180;ServoPos >= 0; ServoPos--){
  lcd.setCursor(0,0);
  lcd.print(ServoPos);
  servo.write(ServoPos);
  delay(50);
  }

  for(MotorPos = 0;MotorPos <= 360; MotorPos++){
  lcd.setCursor(0,1);
  lcd.print(MotorPos);
  digitalWrite(ABPin, LOW);
  digitalWrite(AAPin, HIGH);
  delay(800);
  digitalWrite(ABPin, LOW);
  digitalWrite(AAPin, LOW);
  delay(1000); 
  }
  for(MotorPos = 360;MotorPos >= 0; MotorPos--){
  lcd.setCursor(0,1);
  lcd.print(MotorPos);
  digitalWrite(ABPin, HIGH);
  digitalWrite(AAPin, LOW);
  delay(800);
  digitalWrite(ABPin, LOW);
  digitalWrite(AAPin, LOW);
  delay(1000); 
  }
  
}
