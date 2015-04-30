/*
TEMPERATURE SENSOR READER
=========================
*/

#define pin_temp 1

int getTemp() {
 return analogRead(1)*4.9/10; 
}
