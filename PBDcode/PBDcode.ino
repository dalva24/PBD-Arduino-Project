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

int i = 0;
void setup() {
  Serial.begin(9600);
  setupSeven();
  //sevenDemo();
  initbutton();
}

void loop() {
  showNum(getTemp());
  loopbutton();
  Serial.print(getTemp()); Serial.println(" degrees C");
  Serial.print(getLight()); Serial.println(" L");
  delay(500);
}
