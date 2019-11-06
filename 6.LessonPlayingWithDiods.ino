///////////////////////////////////////////////////////////////////////////////////////
//řízení rychlosti blikání diod pomocí potenciometru a přepínání módů pomocí tlačítka//
///////////////////////////////////////////////////////////////////////////////////////

#define onestate HIGH
#define state LOW
int mode = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(A0));
  readKey();
  moding();
  delay(100);
  
}
/////////////////////////////////////////////////////////////////////
int readKey(){
  if(digitalRead(13)==HIGH && mode >= 0 && mode <= 5){
    if(mode == 5){
      mode = 0;
      }
    mode = mode + 1;
    }
  }
/////////////////////////////////////////////////////////////////////
int moding(){
  if (mode == 0 || mode == 1) {
    zLevaDoPrava();
  }
  if (mode == 2 || mode==3) {
    blikaniVsech();
  }
  if (mode == 4 || mode == 5) {
    zPravaDoLeva();
  }
  }
/////////////////////////////////////////////////////////////////////
int zPravaDoLeva() {
  for (int pin = 10; pin >= 2; pin--) {
    int sleep = analogRead(A0);
    digitalWrite(pin, state);
    delay(sleep);
  }
  for (int pin = 10; pin >= 2; pin--) {
    int sleep = analogRead(A0);
    digitalWrite(pin, onestate);
    delay(sleep);
  }
}
//////////////////////////////////////////////////////////////////////
int blikaniVsech() {
  int sleep = analogRead(A0);
  delay(sleep);
  for (int pin = 2; pin <= 10; pin++) {
    digitalWrite(pin, onestate);
  }
  delay(sleep);
  for (int pin = 2; pin <= 10; pin++) {
    digitalWrite(pin, state);
  }
}
//////////////////////////////////////////////////////////////////////
int zLevaDoPrava() {
  for (int pin = 2; pin <= 10; pin++) {
    int sleep = analogRead(A0);
    digitalWrite(pin, state);
    delay(sleep);
  }
  for (int pin = 2; pin <= 10; pin++) {
    int sleep = analogRead(A0);
    digitalWrite(pin, onestate);
    delay(sleep);
  }
}
