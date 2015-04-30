

// ===== PINS ============


void setup() {
  Serial.begin(9600);
  setupSeven();
}

void loop() {
  int i = 0;
  for (i=0; i<100; i++) {
    showNum(i);
    delay(50);
  }
}
