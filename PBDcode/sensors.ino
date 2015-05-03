/*
SENSOR READERS
=========================
TODO:
- [cancelled] use AREF of 3.3V - currently uses default AREF of 5V
  means 5/1024 precision = 4.88mV
  3.3V allows higher precision -> 3.3/1024 = 3.22mV
analogRead(pin_temp)*4.88/10;
NOTE:
temp sensor outputs 10mV/*C
Light sensor wildly inaccurate. originally analogread-570 for 60 lux calibration
*/

#define pin_temp 1
#define pin_light 0

int getTemp() {
  int temperatureC = analogRead(pin_temp)*4.88/10; 
   return temperatureC; 
}

int getLight() {
 return (analogRead(pin_light)-500); //
}
