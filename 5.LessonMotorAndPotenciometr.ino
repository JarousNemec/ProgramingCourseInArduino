///////////////////////////////////////////////
// řízení otáček motoru pomocí fotorezistoru //
///////////////////////////////////////////////
/*
int pin = 6;
int value = 0;
void setup()
{
  //Serial.begin(9600);
}

void loop()
{
 value = analogRead(A0);
 //Serial.println(value);
 if(value <100 && value > 0){
    analogWrite(pin, 25);
    delay(10);
    }
  if(value <200 && value > 100){
    analogWrite(pin, 50);
    delay(10);
    }
    if(value <300 && value > 200){
    analogWrite(pin, 75);
    delay(10);
    }
    if(value <400 && value > 300){
    analogWrite(pin, 100);
    delay(10);
    }
    if(value <500 && value > 400){
    analogWrite(pin, 125);
    delay(10);
    }
    if(value <600 && value > 500){
    analogWrite(pin, 150);
    delay(10);
    }
    if(value <700 && value > 600){
    analogWrite(pin, 200);
    delay(10);
    }
    if(value <800 && value > 700){
    analogWrite(pin, 225);
    delay(10);
    }
    if(value <900 && value > 800){
    analogWrite(pin, 250);
    delay(10);
    }
    if(value <1023 && value > 900){
    analogWrite(pin, 300);
    delay(10);
    }
    
    
  }

*/
////////////////////////////////////////////////////////////
// řízení otáček motoru podle hodnoty dané potenciometrem //
////////////////////////////////////////////////////////////
/*
int value = 0;
int pin = 6;
void setup()
{
  
Serial.begin(9600);
  
  }
  void loop()
{
  value = analogRead(A0);
  Serial.println(value);
  if(value <100 && value > 0){
    analogWrite(pin, 25);
    delay(10);
    }
  if(value <200 && value > 100){
    analogWrite(pin, 50);
    delay(10);
    }
    if(value <300 && value > 200){
    analogWrite(pin, 75);
    delay(10);
    }
    if(value <400 && value > 300){
    analogWrite(pin, 100);
    delay(10);
    }
    if(value <500 && value > 400){
    analogWrite(pin, 125);
    delay(10);
    }
    if(value <600 && value > 500){
    analogWrite(pin, 150);
    delay(10);
    }
    if(value <700 && value > 600){
    analogWrite(pin, 200);
    delay(10);
    }
    if(value <800 && value > 700){
    analogWrite(pin, 225);
    delay(10);
    }
    if(value <900 && value > 800){
    analogWrite(pin, 250);
    delay(10);
    }
    if(value <1023 && value > 900){
    analogWrite(pin, 300);
    delay(10);
    }
    
    
  }
  */
  ////////////////////////////////////////////
  // výpis hodnoty měnitelné potenciometrem //
  ////////////////////////////////////////////
/*int value;
void setup() {
 Serial.begin(9600);

}

void loop() {
  value = analogRead(A0);
  Serial.println(value);
  delay(value);

}*/
