int sloupce = 16;
int radky = 2;
#include <LiquidCrystal.h>
int GameArray[16][2];

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int radek = 0;
int sloupec = 0;
int j = 0;
int i = 0;
int markForEmptyArrayPoint = 0;
int markForFullArrayPoint = 1;
int VictoryNumber = 0;
int kill = 0;
int number = 1;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  fillArray();
}
void loop() {
  GameProcess();
}
int GameProcess() {
  printArray();
  if (VictoryNumber == (radky * sloupce) - 1) {
    VictoryScreen();
  }
  if (analogRead(A0) >= 600 && analogRead(A0) <= 1024 || analogRead(A0) >= 0 && analogRead(A0) <= 400 || analogRead(A1) >= 600 && analogRead(A1) <= 1024 || analogRead(A1) >= 0 && analogRead(A1) <= 400 && sloupec)
  {
    CheckColisionOrFillPointInArray();
  }
  else if (analogRead(A2) > 0 && analogRead(A2) < 60) {
    Reset();
  }
  GameArray[sloupec][radek] = markForFullArrayPoint;
  delay(100);
}
int CheckColisionOrFillPointInArray() {
  if (analogRead(A0) >= 600 && analogRead(A0) <= 1024 && radek >= 1) {
    if (GameArray[sloupec][radek - 1] == markForFullArrayPoint) {
      FailScreen();
    }
    else {
      radek = radek - 1;
      VictoryNumber = VictoryNumber + 1;
    }
  }

  if (analogRead(A0) >= 0 && analogRead(A0) <= 400 && radek <= 2) {
    if (GameArray[sloupec][radek + 1] == markForFullArrayPoint) {
      FailScreen();
    }
    else {
      radek = radek + 1;
      VictoryNumber = VictoryNumber + 1;
    }
  }

  if (analogRead(A1) >= 600 && analogRead(A1) <= 1024 && sloupec <= 14 && GameArray[sloupec + 1][radek] != markForFullArrayPoint) {
    if (GameArray[sloupec + 1][radek] == markForFullArrayPoint) {
      FailScreen();
    }
    else {
      sloupec = sloupec + 1;
      VictoryNumber = VictoryNumber + 1;
    }
  }

  if (analogRead(A1) >= 0 && analogRead(A1) <= 400 && sloupec >= 1) {
    if (GameArray[sloupec - 1][radek] == markForFullArrayPoint) {
      FailScreen();
    }
    else {
      sloupec = sloupec - 1;
      VictoryNumber = VictoryNumber + 1;
    }
  }

  delay(100);
}
int FailScreen() {
  lcd.clear();
  lcd.home();
  while (number = ! 0) {
    lcd.home();
    lcd.print("Game Over");
    if (analogRead(A2) > 0 && analogRead(A2) < 60) {
      Reset();
      goto point;
    }
  }
point: i = 0;
}
int Reset() {
  fillArray();
  i = 0;
  j = 0;
  VictoryNumber = 0;
  radek = 0;
  sloupec = 0;
  number = 0;
}
int VictoryScreen() {
  lcd.clear();
  lcd.home();
  while (true) {
    lcd.home();
    lcd.print("Game Victory");
    if (analogRead(A2) > 0 && analogRead(A2) < 60) {
      Reset();
      goto point;
    }
  }
point: i = 0;
}
int fillArray() {
  while (j < radky) {
    while (i < sloupce) {
      GameArray[i][j] = markForEmptyArrayPoint;
      i = i + 1;
    }
    i = 0;
    j = j + 1;
  }
}
int printArray() {
  while (j < radky) {
    delay(1);
    while (i < sloupce) {
      delay(1);
      lcd.setCursor(i, j);
      lcd.print(GameArray[i][j]);
      i = i + 1;
    }
    i = 0;
    j = j + 1;
  }
  j = 0;
}
