#include <LedControl.h>
LedControl lc1 = LedControl(10, 9, 8, 1);
LedControl lc2 = LedControl(13, 12, 11, 1);

#include "Melody.h"
#include "Led.h"

int buttonPin1 = 2;
int buttonPin2 = 3;
int lightPin1 = 0;
int lightPin2 = 1;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonPressed1 = 0;
int buttonPressed2 = 0;

int lightState1 = 0;
int lightState2 = 0;
int lightTriggered1 = 0;
int lightTriggered2 = 0;
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
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  // The MAX72XX is in power-saving mode on startup
  // we have to do a wakeup call
  lc1.shutdown(0, false);
  lc2.shutdown(0, false);
  lc1.setIntensity(0, 8);
  lc2.setIntensity(0, 8);
  lc1.clearDisplay(0);
  lc2.clearDisplay(0);
  drawNumber(lc1, score1);
  drawNumber(lc2, score2);
  gameOn = true;
}

void loop() {
  if (gameOn) {

    buttonState1 = digitalRead(buttonPin1);
    if (buttonState1 == HIGH) {
      if (buttonPressed1 == 0) {
        if (score1 < 10) {
          score1 += 1;
        }
        buttonPressed1 = 1;
      }
    } else {
      buttonPressed1 = 0;
    }

    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 == HIGH) {
      if (buttonPressed2 == 0) {
        if (score2 < 10) {
          score2 += 1;
        }
        buttonPressed2 = 1;
      }
    } else {
      buttonPressed2 = 0;
    }

    lightState1 = analogRead(lightPin1);
    if (lightState1 > lightThreshhold) {
      if (lightTriggered1 == 0) {
        if (score1 < 10) {
          score1 += 1;
        }
        lightTriggered1 = 1;
      }
    } else {
      lightTriggered1 = 0;
    }

    lightState2 = analogRead(lightPin2);
    if (lightState2 > lightThreshhold) {
      if (lightTriggered2 == 0) {
        if (score2 < 10) {
          score2 += 1;
        }
        lightTriggered2 = 1;
      }
    } else {
      lightTriggered2 = 0;
    }

    if (lastScore1 != score1) {
      if (score1 == 10) {
        win1 = true;
        gameOn = false;
      }
      drawNumber(lc1, score1);
      playMelody();
    }

    if (lastScore2 != score2) {
      if (score2 == 10) {
        win2 = true;
        gameOn = false;
      }
      drawNumber(lc2, score2);
      playMelody();
    }

    lastScore1 = score1;
    lastScore2 = score2;

  } else {

    if (win1 == true) {

      if (blinkState == 0) {
        drawNumber(lc1, score1);
        drawNumber(lc2, score2);
        blinkState = 1;
      } else {
        drawHappyFace(lc1);
        drawSadFace(lc2);
        blinkState = 0;
      }
      delay(1000);

    } else if (win2 == true) {

      if (blinkState == 0) {
        drawNumber(lc2, score2);
        drawNumber(lc1, score1);
        blinkState = 1;
      } else {
        drawHappyFace(lc2);
        drawSadFace(lc1);
        blinkState = 0;
      }
      delay(1000);

    }
  }
}
