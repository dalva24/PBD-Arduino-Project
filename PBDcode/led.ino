/*
LED CONTROLLER
=========================

*/

#define pin_led 6

void ledTest() {
  for (int i=0; i<255; i++) {
    analogWrite(pin_led, i);
    delay(5);
  }
  for (int i=0; i<=3; i++) {
    ledOn();
    delay(100);
    ledOff();
    delay(100+(50*i));
  }
  ledOn();
}

void ledOn() {
  analogWrite(pin_led, 255);
}

void ledOff() {
  analogWrite(pin_led, 0);
}

void ledSet(int val) {
  analogWrite(pin_led, val);
}
