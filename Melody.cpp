#include "Melody.h"

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(SPEAKER_PIN, HIGH);
    delayMicroseconds(tone);
    digitalWrite(SPEAKER_PIN, LOW);
    delayMicroseconds(tone);
  }
}

void playMelody(int notes[], int beats[], int length, int tempo) {
  for (int i = 0; i < length; i++) {
    if (notes[i] == 0) {
      delay(beats[i] * tempo); // rest
    } else {
      playTone(notes[i], beats[i] * tempo);
    }
    // pause between notes
    delay(tempo / 2);
  }
}

void playGameStartMelody() {
  int notes[] = { NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0, 0, NOTE_G6, 0, 0, 0 };
  int beats[] = {       1,       1, 1,       1, 1,       1,       1, 1,       1, 1, 1, 1,       1, 1, 1, 1 };
  int length = sizeof(beats) / 2;
  int tempo = 100;
  playMelody(notes, beats, length, tempo);
}

void playGameEndMelody() {
  int notes[] = { NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C7, 0, NOTE_G7, 0, NOTE_A7, 0, NOTE_B6, 0, NOTE_A6, NOTE_B6 };
  int beats[] = {       1,       1,       1,       3, 1,       3, 1,       2, 1,       1, 1,       1,       3 };
  int length = sizeof(beats) / 2;
  int tempo = 100;
  playMelody(notes, beats, length, tempo);
}

void playGameScoreMelody() {
  int notes[] = { NOTE_B6, NOTE_A6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6 };
  int beats[] = {       1,       1,       1,       1,       1,       1,       1 };
  int length = sizeof(beats) / 2;
  int tempo = 80;
  playMelody(notes, beats, length, tempo);
}
