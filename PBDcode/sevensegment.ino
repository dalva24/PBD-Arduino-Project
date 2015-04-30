/*
SEVEN SEGMENT CONTROLLER
========================
7seg byte: efg.cbad
abc
 d
efg
*/

#define pin_sr1 8
#define pin_sr2 9
#define pin_clock 2
#define pin_reset 4

byte number[] = {
  B11101110, // 0
  B00101000, // 1
  B11001101, // 2
  B01101101, // 3
  B00101011, // 4
  B01100111, // 5
  B11100111, // 6
  B00101100, // 7
  B11101111, // 8
  B01101111  // 9
};

void setupSeven() {
  pinMode(pin_clock, OUTPUT); 
  pinMode(pin_sr1, OUTPUT); 
  pinMode(pin_sr2, OUTPUT); 
  pinMode(pin_reset, OUTPUT);
}

void initSeven() {
  digitalWrite(pin_reset, LOW);
  clockSeven();
  digitalWrite(pin_reset, HIGH);
  clockSeven();
}

void showNum(int num) {
  if (num >= 0 && num <= 9) {
    initSeven();
    int i = 0;
    for (i=0; i<8; i++) {
      digitalWrite(pin_sr1, number[0] & (B00000001<<i));
      digitalWrite(pin_sr2, number[String(num)[0]-'0'] & (B00000001<<i));
      clockSeven();
      // delay(500);
    }
    delay(50);
  } else if (num >= 10 && num <= 99) {
    initSeven();
    int i = 0;
    for (i=0; i<8; i++) {
      digitalWrite(pin_sr1, number[String(num)[0]-'0'] & (B00000001<<i));
      digitalWrite(pin_sr2, number[String(num)[1]-'0'] & (B00000001<<i));
      clockSeven();
      // delay(500);
    }
    delay(50);
  }
}

void clockSeven() {
  digitalWrite(pin_clock, LOW);
  digitalWrite(pin_clock, HIGH);
}
