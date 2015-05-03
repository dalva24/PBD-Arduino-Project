/*
SPEAKER TONE CREATOR
=========================

*/

#define pin_speaker 3

short scale[] = {261, 294, 330, 349, 392, 440, 493, 523};

void toneTest() {
  for (int i = 0; i < 8; i++) {
    tone(pin_speaker, scale[i]);
    delay(100);
    noTone(pin_speaker);
  }
}

void sound(int num) {
  tone(pin_speaker, scale[num]);
}

void soundFreq(int freq) {
  tone(pin_speaker, freq);
}

void silent() {
  noTone(pin_speaker);
}
