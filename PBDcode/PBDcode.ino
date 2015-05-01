/*
PBD PROJECT MAIN
================================
        !! WARNING !!
      !!   WARNING   !!
    !!     WARNING     !!
Always check Fritzing Schematic
before running program to ensure
correct pin configurations.

TODO:
- light to lux calculation
- button debounce
- light integration to alarm
- motor integration to alarm
- fix button (bugged after temp check)
*/
  
  
void setup() {
  Serial.begin(9600);
  attachInterrupt(0, buttonInterrupt, RISING);
  setupSeven();
  ledTest();
  sevenDemo();
  //toneTest();
  //motorTest();
}

void loop() {
  showNum(getTemp());
  //Serial.print(getTemp()); Serial.println(" degrees C");
  //Serial.print(getLight()); Serial.println(" L");
  //delay(500);
  
  if(getTemp() > 29) {
    sound(0);
    ledOn();
  } else if (getTemp() <= 29) {
    silent();
    ledOff();
  }
  
  if(latchOn()) {
    sound(0);
    ledOn();
  } else if(latchOff()) {
    silent();
    ledOff();
  }
  
  delay(50);
  
}



