#ifndef Melody_h
#define Melody_h

#include "Arduino.h"

// Set up speaker on a PWM pin (digital 9, 10 or 11)
#define SPEAKER_PIN 5

void playTone(int tone, int duration);
void playNote(int note, int duration);

void playGameStartMelody();
void playGameEndMelody();
void playGameScoreMelody();

#endif
