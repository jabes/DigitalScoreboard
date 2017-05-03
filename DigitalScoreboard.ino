#include <LedControl.h>
LedControl lc1 = LedControl(10, 9, 8, 1);
LedControl lc2 = LedControl(13, 12, 11, 1);

#include "Melody.h"
#include "Led.h"

int buttonPin = 2;
int lightPin1 = 0;
int lightPin2 = 1;

int buttonState = LOW;
boolean buttonPressed = false;

int lightState1 = LOW;
int lightState2 = LOW;
boolean lightTriggered1 = false;
boolean lightTriggered2 = false;
int lightThreshhold = 500;

boolean gameOn = false;
boolean win1 = false;
boolean win2 = false;

int blinkState = 0;

int score1 = 0;
int score2 = 0;
int lastScore1 = score1;
int lastScore2 = score2;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  // The MAX72XX is in power-saving mode on startup
  // we have to do a wakeup call
  lc1.shutdown(0, false);
  lc2.shutdown(0, false);
  lc1.setIntensity(0, 8);
  lc2.setIntensity(0, 8);
  reset(); // begin
}

void reset() {
  gameOn = true;
  win1 = false;
  win2 = false;
  score1 = 0;
  score2 = 0;
  lastScore1 = score1;
  lastScore2 = score2;
  drawNumber(lc1, score1);
  drawNumber(lc2, score2);
  playGameStartMelody();
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (buttonPressed == false) {
      reset();
      buttonPressed = true;
    }
  } else {
    buttonPressed = false;
  }

  if (gameOn) {

    lightState1 = analogRead(lightPin1);
    if (lightState1 > lightThreshhold) {
      if (lightTriggered1 == false) {
        if (score1 < 10) {
          score1 += 1;
        }
        lightTriggered1 = true;
      }
    } else {
      lightTriggered1 = false;
    }

    lightState2 = analogRead(lightPin2);
    if (lightState2 > lightThreshhold) {
      if (lightTriggered2 == false) {
        if (score2 < 10) {
          score2 += 1;
        }
        lightTriggered2 = true;
      }
    } else {
      lightTriggered2 = false;
    }

    if (lastScore1 != score1) {
      drawNumber(lc1, score1);
      if (score1 == 10) {
        win1 = true;
        gameOn = false;
        playGameEndMelody();
      } else {
        playGameScoreMelody();
      }
    }

    if (lastScore2 != score2) {
      drawNumber(lc2, score2);
      if (score2 == 10) {
        win2 = true;
        gameOn = false;
        playGameEndMelody();
      } else {
        playGameScoreMelody();
      }
    }

    lastScore1 = score1;
    lastScore2 = score2;

  } else {

    if (win1 == true) {

      if (blinkState == 1) {
        drawNumber(lc1, score1);
        drawNumber(lc2, score2);
        blinkState = 0;
      } else {
        drawHappyFace(lc1);
        drawSadFace(lc2);
        blinkState = 1;
      }
      delay(1000);

    } else if (win2 == true) {

      if (blinkState == 1) {
        drawNumber(lc2, score2);
        drawNumber(lc1, score1);
        blinkState = 0;
      } else {
        drawHappyFace(lc2);
        drawSadFace(lc1);
        blinkState = 1;
      }
      delay(1000);

    }
  }
}
