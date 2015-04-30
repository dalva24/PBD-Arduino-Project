/*
PBD PROJECT MAIN
=========================
*/


void setup() {
  Serial.begin(9600);
  setupSeven();
  sevenDemo();
}

void loop() {
  showNum(getTemp());
  delay(50);
}
