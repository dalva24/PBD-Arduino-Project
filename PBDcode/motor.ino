/*
MOTOR CONTROLLER
=========================

*/

#define pin_motor 5

void motorTest() {
  motorOn();
  delay(5000);
  motorOff();
}

void motorOn() {
  analogWrite(pin_motor, 255);
}

void motorOff() {
  analogWrite(pin_motor, 0);
}
