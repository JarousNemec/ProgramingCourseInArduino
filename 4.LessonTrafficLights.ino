
void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
Serial.begin(9600);
digitalWrite(4,HIGH);
digitalWrite(13,HIGH);
}

void loop() {
  int buttonState = digitalRead(2);
  Serial.println(buttonState);
  if(buttonState==1){
    delay(2000);
    digitalWrite(12,HIGH);
    delay(2000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    delay(2000);
    digitalWrite(4,LOW);
    digitalWrite(9,HIGH);
    for(int i = 0;i<100;i++){
      tone(7,700,50);
      delay(150);
      noTone(7);
      }
      noTone(8);
      delay(500);
    digitalWrite(4,HIGH);
    digitalWrite(9,LOW);
    delay(2000);
    digitalWrite(12,HIGH);
    delay(2000);
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(4,HIGH);
    }
delay(100);
tone(7,700,50);
      delay(500);
      noTone(7);
}
