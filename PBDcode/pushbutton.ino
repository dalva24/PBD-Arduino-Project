/*
BUSH BUTTON INTERRUPT
=========================
TODO:
- [cancelled] fix latch
*/

#define pin_button 2
#define pin_LED 6

bool buttState = false;
bool latch = true;
unsigned long lastPressed;

void buttonInterrupt(){
  if (digitalRead (2) == HIGH && millis() >= lastPressed + 200) {
    buttState = !buttState;
    lastPressed = millis();
  }
}

bool buttGet() {
  return buttState;
}

bool latchOn() {
  if (buttState && latch) {
    latch = false;
    return true;
  } else {
    return false;
  }
}

bool latchOff() {
  if (!buttState && !latch) {
    latch = true;
    return true;
  } else {
    return false;
  }
}
