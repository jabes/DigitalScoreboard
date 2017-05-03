#ifndef Melody_h
#define Melody_h

#include "Arduino.h"
#include "Pitches.h"

// Set up speaker on a PWM pin (digital 9, 10 or 11)
#define SPEAKER_PIN 5

void playGameStartMelody();
void playGameEndMelody();
void playGameScoreMelody();

#endif
