/*
PBD PROJECT MAIN
================================
        !! WARNING !!
      !!   WARNING   !!
    !!     WARNING     !!
Always check Fritzing Schematic
before running program to ensure
correct pin configurations.
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
