/*
SENSOR READERS
=========================
TODO:
- use AREF of 3.3V - currently uses default AREF of 5V
  means 5/1024 precision = 4.88mV
  3.3V allows higher precision -> 3.3/1024 = 3.22mV
- create light sensor

NOTE:
temp sensor outputs 10mV/*C
*/

#define pin_temp 0
#define pin_light 1

int getTemp() {
 return analogRead(pin_temp)*4.88/10; 
}

int getLight() {
 return analogRead(pin_light); 
}
