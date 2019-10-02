//------------------------------------
//Blikačka opakování z minulé hodiny
//------------------------------------

/*
int index = 0;
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
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
}
void loop() {

  if(index == 20){
    index = 0;
    }
  for(int i = 2;i<13;i++)
  {
  digitalWrite(i, HIGH);  
  delay(250);                 
  }

  for(int i = 2;i<13;i++)
  {
  digitalWrite(i, LOW);   
  delay(250);           
  }
while(index < 20)
{
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
  index++;
}
}
*/

//-----------------------------
//OnOff-Led_AND_Buzzer-Sounds
//-----------------------------

/*
bool HighSound = false;

int OnOffLed = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() 
{
  delay(100);
  OnOffLed = digitalRead(2);
  if(OnOffLed == 1)
  {
    Serial.println("Led je zapnuta");
    digitalWrite(13,HIGH);
    noTone(8);
  }
  else if (OnOffLed == 0)
  {
    Serial.println("Led je vypnuta");
    digitalWrite(13,LOW);
    if(HighSound==true)
      {
        Serial.println("BZZZZZZZZZZZZZ");
        tone(8, 100);
      }
    else if (HighSound == false)
      {
        Serial.println("PPŠŠŠŠŠŠŠŠŠŠTT");
      }
  }
}
*/
