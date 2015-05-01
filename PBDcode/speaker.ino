/*
SPEAKER TONE CREATOR
=========================

*/

#define pin_speaker 3

short tones[] = {261, 294, 330, 349, 392, 440, 493, 523};

void toneTest() {
  for (int i = 0; i < 8; i++) {
    tone(pin_speaker, tones[i]);
    while(!buttGet()) {
      delay(10);
    }
    delay(500);
    noTone(pin_speaker);
    buttState = false;
  }
}

void sound(int scale) {
  tone(pin_speaker, 150);
}

void silent() {
  noTone(pin_speaker);
}
