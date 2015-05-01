/*
BUSH BUTTON INTERRUPT
=========================

*/

#define pin_button 2
#define pin_LED 6

bool buttState = false;
bool latch = true;

void buttonInterrupt(){
  if (digitalRead (2) == HIGH)
    buttState = !buttState;
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
