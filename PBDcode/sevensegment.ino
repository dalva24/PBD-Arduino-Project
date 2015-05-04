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
#define pin_clock 7
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
  digitalWrite(pin_sr1, LOW);
  digitalWrite(pin_sr2, LOW);
  digitalWrite(pin_reset, LOW);
  clockSeven();
  digitalWrite(pin_reset, HIGH);
  clockSeven();
}

void showNum(int num) {
  initSeven();
  if (num >= 0 && num <= 9) {
    int digit[] = {0, String(num)[0]-'0'};
    for (int i=0; i<8; i++) {
      digitalWrite(pin_sr1, number[digit[0]] & (B00000001<<i));
      digitalWrite(pin_sr2, number[digit[1]] & (B00000001<<i));
      clockSeven();
    }
  } else if (num >= 10 && num <= 99) {
    int digit[] = {String(num)[0]-'0', String(num)[1]-'0'};
    for (int i=0; i<8; i++) {
      digitalWrite(pin_sr1, number[digit[0]] & (B00000001<<i));
      digitalWrite(pin_sr2, number[digit[1]] & (B00000001<<i));
      clockSeven();
    }
  }
  delay(10);
}

void showLH() {
  initSeven();
  for (int i=0; i<8; i++) {
    digitalWrite(pin_sr1, B11100010 & (B00000001<<i));
    digitalWrite(pin_sr2, B10101011 & (B00000001<<i));
    clockSeven();
  }
}

void clockSeven() {
  digitalWrite(pin_clock, LOW);
  digitalWrite(pin_clock, HIGH);
}

void sevenDemo() {
  int i;
  for (i=0; i<100; i++) {
    showNum(i);
    delay(5);
  }
  for (int i=0; i<=3; i++) {
    showNum(88);
    delay(100);
    initSeven();
    delay(100+(50*i));
  }
  showNum(88);
}
