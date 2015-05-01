#define pin_button 12
#define pin_LED 6

int val = 0;     // variable for reading the pin status
bool nyala = false;

void initbutton() {
  pinMode(pin_LED, OUTPUT);  // declare LED as output
  pinMode(pin_button, INPUT);    // declare pushbutton as input
}

void loopbutton(){
  val = digitalRead(pin_button);  // read input value
  Serial.print(val + nyala);Serial.println("===========");
  if (val == HIGH){
      if (!nyala){
        digitalWrite(pin_LED, LOW);
        nyala = true;}
      else{
        digitalWrite(pin_LED, HIGH);
        nyala = false;}
  }
}
