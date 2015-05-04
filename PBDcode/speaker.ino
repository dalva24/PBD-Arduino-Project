/*
SPEAKER TONE CREATOR
=========================
NOTE:
Ryth = rythm. delay in 1/8 note
Note = note type
Scale = freq of each note
*/

#define pin_speaker 3

short scale[] = {261, 294, 330, 349, 392, 440, 493, 523};
short shinScale[] = {0, 698, 784, 880, 923, 988, 1046, 1175, 1480, 1568, 1760, 1975, 2093, 2349, 2960};
unsigned char shinNote1[] = {8, 9, 10, 11, 10, 11, 12, 13, 14 };
unsigned char shinRyth1[] = {2, 2, 2,  1,  1,  1,  1,  1,  1  };
unsigned char shinLeng1 = 9;
unsigned char shinNote2[] = {5, 3, 2, 1, 3, 7, 4, 6, 1, 3, 0, 6, 1, 2, 3, 5, 2, 6, 5, 3, 0 };
unsigned char shinRyth2[] = {2, 2, 2, 3, 1, 2, 2, 2, 2, 4, 2, 4, 2, 3, 1, 2, 2, 2, 2, 4, 2 };
unsigned char shinLeng2 = 21;
unsigned char shinNote3[] = {7, 0, 9, 8, 9, 8, 9, 8, 6, 5, 6, 7, 5, 9, 7, 5, 9, 8, 9, 8, 9, 8, 6, 5, 6, 5, 2, 9 };
unsigned char shinRyth3[] = {4, 2, 2, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 6 };
unsigned char shinLeng3 = 28;

void shinsekai() {
  unsigned char i;
  short tempo = 100; // in BPM
  tempo = 1000/((100*2)/60);
  for (i=0; i<shinLeng1; i++) {
    tone(pin_speaker, shinScale[shinNote1[i]]);
    delay(shinRyth1[i]*tempo);
  }
  for (unsigned char j=0; j<2; j++) {
    for (i=0; i<shinLeng2; i++) {
      tone(pin_speaker, shinScale[shinNote2[i]]);
      delay(shinRyth2[i]*tempo);
    }
  }
  for (i=0; i<shinLeng3; i++) {
    tone(pin_speaker, shinScale[shinNote3[i]]);
    delay(shinRyth3[i]*tempo);
  }
  noTone(pin_speaker);
}

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
