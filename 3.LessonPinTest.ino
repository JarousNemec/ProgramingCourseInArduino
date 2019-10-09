
int pinLED = 2;
int pole[10];

void setup() {
pinMode(2, OUTPUT);
for(int p = 0;p<10;p++) 
{
  pole[p]=p;
  }
Serial.begin(9600);
}

void loop() {

for(int i = 0;i<10;i++)
{
Serial.println(i);

digitalWrite(pinLED,HIGH);
delay(50);
digitalWrite(pinLED,LOW);
delay(50);
}
if(pinLED == 13){
  pinLED = 2;
  }
pinLED = (pinLED + 1);
}
