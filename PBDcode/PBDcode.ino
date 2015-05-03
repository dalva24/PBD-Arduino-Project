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
  
int time;
int frq;
String commandBuff = "";         // a string to hold incoming data
boolean commandDone = false;  // whether the string is complete
int tempT1 = 40;
int tempT2 = 45;
int luxT = 60;

void setup() {
  Serial.begin(9600);
  Serial.println("Self Test Init...");
  commandBuff.reserve(64);
  attachInterrupt(0, buttonInterrupt, RISING);
  setupSeven();
  ledTest();
  sevenDemo();
  toneTest();
  //motorTest();
  Serial.println("Default Thresholds:");
  Serial.println("  t1 = 40 *C");
  Serial.println("  t2 = 45 *C");
  Serial.println("  l  = 60 Lux");
  Serial.println("Warning: Lux measurement is approximate.");
  Serial.println("Info:    Type \"help\" for a list of commands");
  Serial.println("System Ready.");
}

void loop() {
  time = millis();
  showNum(getTemp());
  
  if((getTemp() > tempT2 && getLight() > luxT) || buttGet()) {
    soundFreq(1000);
    ledOn();
    delay(200);
    silent();
    ledOff();
    motorOn();
    if (buttGet()) {
      Serial.println("Self-Test...");
    }
  } else if ((getTemp() > tempT1 && getLight() > luxT)) {
    ledSet(50);
    soundFreq(300);
    motorOff();
  } else if(!buttGet()) {
    silent();
    ledOff();
    motorOff();
  }
  
  if (commandDone) {
    Serial.println("");
    if (commandBuff[0] == 't') {
      int num = commandBuff.substring(3).toInt();
      if (num >= 20) {
        if (commandBuff[1] == '1') {
          tempT1 = num;
          Serial.print("Success: Temp threshold 1 set to "); Serial.print(num); Serial.println(" *C");
        } else if (commandBuff[1] == '2') {
          tempT2 = num;
          Serial.print("Success: Temp threshold 2 set to "); Serial.print(num); Serial.println(" *C");
        } else {
          Serial.println("ERR02: Unknown command received. ");
        }
      } else {
        Serial.println("ERR03: Erronous Temperature . Reverting to original. ");
      }
    } else if (commandBuff[0] == 'l') {
      int num = commandBuff.substring(2).toInt();
      if (num >= 0) {
        luxT = num;
        Serial.print("Success: Lux threshold set to "); Serial.print(num); Serial.println(" Lux");
      } else {
        Serial.println("ERR04: Erronous Lux Level . Reverting to original. ");
      }
    } else if (commandBuff[0] == 'h') {
      Serial.println("Available Commands:");
      Serial.println("  t1 {num} - set temp threshold 1 (pre-overheat alarm) to {num}");
      Serial.println("  t2 {num} - set temp threshold 2 (overheat alarm) to {num}");
      Serial.println("  l {num} - set light level on which alarm system will be active");
    } else {
      Serial.println("ERR01: Unknown command received. ");
    }
    
    commandDone = false;
    commandBuff = "";
  }
  delay(50);
}

void serialEvent() {
  while (Serial.available() && !commandDone) {
    char inChar = (char)Serial.read();
    commandBuff += inChar;
    if (inChar == '\n') {
      commandDone = true;
    }
  }
}


