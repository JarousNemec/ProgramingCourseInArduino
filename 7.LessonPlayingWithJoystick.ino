void setup() {
  Serial.begin(9600);
}

void loop() {
  if (analogRead(A0) > 0 && analogRead(A0) < 500) {
    Serial.println("vlevo");
  }
  if (analogRead(A0) > 510 && analogRead(A0) < 1024) {
    Serial.println("vpravo");
  }
  if (analogRead(A1) > 0 && analogRead(A1) < 500) {
    Serial.println("dolu");
  }
  if (analogRead(A1) > 510 && analogRead(A1) < 1024) {
    Serial.println("nahuru");
  }
  if (analogRead(A2) == 0) {
    Serial.println("tlacitko je stlacene");
  }
  else {
    Serial.println("tlacitko je volne");
  }

  delay(200);
  
}
