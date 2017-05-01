#include <LedControl.h>
LedControl lc1 = LedControl(10, 9, 8, 1);
LedControl lc2 = LedControl(13, 12, 11, 1);

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int speakerPin = 5;
const int lightPin1 = 0;
const int lightPin2 = 1;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonPressed1 = 0;
int buttonPressed2 = 0;

int lightState1 = 0;
int lightState2 = 0;
int lightTriggered1 = 0;
int lightTriggered2 = 0;
const int lightThreshhold = 500;

int score1 = 0;
int score2 = 0;
int lastScore1 = score1;
int lastScore2 = score2;

// TONES  ==========================================
// Start by defining the relationship between
//       note, period, &  frequency.
#define  c     3830    // 261 Hz
#define  d     3400    // 294 Hz
#define  e     3038    // 329 Hz
#define  f     2864    // 349 Hz
#define  g     2550    // 392 Hz
#define  a     2272    // 440 Hz
#define  b     2028    // 493 Hz
#define  C     1912    // 523 Hz
// Define a special note, 'R', to represent a rest
#define  R     0

// Set up speaker on a PWM pin (digital 9, 10 or 11)
const int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
const int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 };
const int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

const long tempo = 10000;
const int pause = 1000;
const int rest_count = 100;

// Initialize core variables
int tone_ = 0;
int beat = 0;
long duration  = 0;

const int Numbers[11][8][8] = {
  {
  }, {
  }, {
  }, {
  }, {

  }, {

  }, {

  }, {

  }, {

  }, {

  }, {

  }
};

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(speakerPin, OUTPUT);
  // The MAX72XX is in power-saving mode on startup
  // we have to do a wakeup call
  lc1.shutdown(0, false);
  lc2.shutdown(0, false);
  lc1.setIntensity(0, 8);
  lc2.setIntensity(0, 8);
  lc1.clearDisplay(0);
  lc2.clearDisplay(0);
  setNumber(lc1, score1);
  setNumber(lc2, score2);
}

void setNumber(LedControl lc, int num) {
  if (num == 0) {
    setNumber0(lc);
  } else if (num == 1) {
      setNumber1(lc);
  } else if (num == 2) {
    setNumber2(lc);
  } else if (num == 3) {
    setNumber3(lc);
  } else if (num == 4) {
    setNumber4(lc);
  } else if (num == 5) {
    setNumber5(lc);
  } else if (num == 6) {
    setNumber6(lc);
  } else if (num == 7) {
    setNumber7(lc);
  } else if (num == 8) {
    setNumber8(lc);
  } else if (num == 9) {
    setNumber9(lc);
  } else if (num == 10) {
    setNumber10(lc);
  }
}

void setNumber0(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 1, 1}, HIGH);
    lc.setLed(0, 1, 6}, HIGH);
    lc.setLed(0, 2, 1}, HIGH);
    lc.setLed(0, 2, 5}, HIGH);
    lc.setLed(0, 2, 6}, HIGH);
    lc.setLed(0, 3, 1}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 3, 6}, HIGH);
    lc.setLed(0, 4, 1}, HIGH);
    lc.setLed(0, 4, 3}, HIGH);
    lc.setLed(0, 4, 6}, HIGH);
    lc.setLed(0, 5, 1}, HIGH);
    lc.setLed(0, 5, 2}, HIGH);
    lc.setLed(0, 5, 6}, HIGH);
    lc.setLed(0, 6, 1}, HIGH);
    lc.setLed(0, 6, 6}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
}

void setNumber1(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 1, 3}, HIGH);
    lc.setLed(0, 1, 4}, HIGH);
    lc.setLed(0, 2, 2}, HIGH);
    lc.setLed(0, 2, 4}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 4, 4}, HIGH);
    lc.setLed(0, 5, 4}, HIGH);
    lc.setLed(0, 6, 4}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
    lc.setLed(0, 7, 6}, HIGH);
}

void setNumber2(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 1, 1}, HIGH);
    lc.setLed(0, 1, 6}, HIGH);
    lc.setLed(0, 2, 6}, HIGH);
    lc.setLed(0, 3, 6}, HIGH);
    lc.setLed(0, 4, 3}, HIGH);
    lc.setLed(0, 4, 4}, HIGH);
    lc.setLed(0, 4, 5}, HIGH);
    lc.setLed(0, 5, 2}, HIGH);
    lc.setLed(0, 6, 1}, HIGH);
    lc.setLed(0, 7, 1}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
    lc.setLed(0, 7, 6}, HIGH);
}

void setNumber3(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 1, 1}, HIGH);
    lc.setLed(0, 1, 6}, HIGH);
    lc.setLed(0, 2, 6}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 4, 6}, HIGH);
    lc.setLed(0, 5, 6}, HIGH);
    lc.setLed(0, 6, 1}, HIGH);
    lc.setLed(0, 6, 6}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
}

void setNumber4(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 1, 3}, HIGH);
    lc.setLed(0, 1, 5}, HIGH);
    lc.setLed(0, 2, 2}, HIGH);
    lc.setLed(0, 2, 5}, HIGH);
    lc.setLed(0, 3, 1}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 4, 1}, HIGH);
    lc.setLed(0, 4, 2}, HIGH);
    lc.setLed(0, 4, 3}, HIGH);
    lc.setLed(0, 4, 4}, HIGH);
    lc.setLed(0, 4, 5}, HIGH);
    lc.setLed(0, 4, 6}, HIGH);
    lc.setLed(0, 5, 5}, HIGH);
    lc.setLed(0, 6, 5}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
}

void setNumber5(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 1}, HIGH);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 0, 6}, HIGH);
    lc.setLed(0, 1, 1}, HIGH);
    lc.setLed(0, 2, 1}, HIGH);
    lc.setLed(0, 3, 2}, HIGH);
    lc.setLed(0, 3, 3}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 4, 6}, HIGH);
    lc.setLed(0, 5, 6}, HIGH);
    lc.setLed(0, 6, 1}, HIGH);
    lc.setLed(0, 6, 6}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
}

void setNumber6(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 1, 1}, HIGH);
    lc.setLed(0, 1, 6}, HIGH);
    lc.setLed(0, 2, 1}, HIGH);
    lc.setLed(0, 3, 1}, HIGH);
    lc.setLed(0, 3, 3}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 4, 1}, HIGH);
    lc.setLed(0, 4, 2}, HIGH);
    lc.setLed(0, 4, 6}, HIGH);
    lc.setLed(0, 5, 1}, HIGH);
    lc.setLed(0, 5, 6}, HIGH);
    lc.setLed(0, 6, 1}, HIGH);
    lc.setLed(0, 6, 6}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
}

void setNumber7(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 1}, HIGH);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 0, 6}, HIGH);
    lc.setLed(0, 1, 6}, HIGH);
    lc.setLed(0, 2, 6}, HIGH);
    lc.setLed(0, 3, 2}, HIGH);
    lc.setLed(0, 3, 3}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 3, 6}, HIGH);
    lc.setLed(0, 4, 5}, HIGH);
    lc.setLed(0, 5, 4}, HIGH);
    lc.setLed(0, 6, 3}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
}

void setNumber8(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 1, 1}, HIGH);
    lc.setLed(0, 1, 6}, HIGH);
    lc.setLed(0, 2, 1}, HIGH);
    lc.setLed(0, 2, 6}, HIGH);
    lc.setLed(0, 3, 2}, HIGH);
    lc.setLed(0, 3, 3}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 4, 1}, HIGH);
    lc.setLed(0, 4, 6}, HIGH);
    lc.setLed(0, 5, 1}, HIGH);
    lc.setLed(0, 5, 6}, HIGH);
    lc.setLed(0, 6, 1}, HIGH);
    lc.setLed(0, 6, 6}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
}

void setNumber9(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 2}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 1, 1}, HIGH);
    lc.setLed(0, 1, 6}, HIGH);
    lc.setLed(0, 2, 1}, HIGH);
    lc.setLed(0, 2, 6}, HIGH);
    lc.setLed(0, 3, 2}, HIGH);
    lc.setLed(0, 3, 3}, HIGH);
    lc.setLed(0, 3, 4}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 3, 6}, HIGH);
    lc.setLed(0, 4, 5}, HIGH);
    lc.setLed(0, 5, 4}, HIGH);
    lc.setLed(0, 6, 3}, HIGH);
    lc.setLed(0, 7, 2}, HIGH);
}

void setNumber10(LedControl lc) {
    lc.clearDisplay(0);
    lc.setLed(0, 0, 0}, HIGH);
    lc.setLed(0, 0, 3}, HIGH);
    lc.setLed(0, 0, 4}, HIGH);
    lc.setLed(0, 0, 5}, HIGH);
    lc.setLed(0, 0, 6}, HIGH);
    lc.setLed(0, 1, 0}, HIGH);
    lc.setLed(0, 1, 2}, HIGH);
    lc.setLed(0, 1, 7}, HIGH);
    lc.setLed(0, 2, 0}, HIGH);
    lc.setLed(0, 2, 2}, HIGH);
    lc.setLed(0, 2, 6}, HIGH);
    lc.setLed(0, 2, 7}, HIGH);
    lc.setLed(0, 3, 0}, HIGH);
    lc.setLed(0, 3, 2}, HIGH);
    lc.setLed(0, 3, 5}, HIGH);
    lc.setLed(0, 3, 7}, HIGH);
    lc.setLed(0, 4, 0}, HIGH);
    lc.setLed(0, 4, 2}, HIGH);
    lc.setLed(0, 4, 4}, HIGH);
    lc.setLed(0, 4, 7}, HIGH);
    lc.setLed(0, 5, 0}, HIGH);
    lc.setLed(0, 5, 2}, HIGH);
    lc.setLed(0, 5, 3}, HIGH);
    lc.setLed(0, 5, 7}, HIGH);
    lc.setLed(0, 6, 0}, HIGH);
    lc.setLed(0, 6, 2}, HIGH);
    lc.setLed(0, 6, 7}, HIGH);
    lc.setLed(0, 7, 0}, HIGH);
    lc.setLed(0, 7, 3}, HIGH);
    lc.setLed(0, 7, 4}, HIGH);
    lc.setLed(0, 7, 5}, HIGH);
    lc.setLed(0, 7, 6}, HIGH);
}

void playTone() {
  long elapsed_time = 0;
  // if this isn't a Rest beat, while the tone has
  if (tone_ > 0) {
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(tone_ / 2);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(tone_ / 2);
      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    }
  } else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) {
      delayMicroseconds(duration);
    }
  }
}

void playMelody() {
  // Set up a counter to pull from melody[] and beats[]
  for (int i = 0; i < MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];
    duration = beat * tempo; // Set up timing
    playTone();
    // A pause between notes...
    delayMicroseconds(pause);
  }
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == HIGH) {
    if (buttonPressed1 == 0) {
      if (score1 < 10) {
        score1 += 1;
        playMelody();
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
        playMelody();
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
        playMelody();
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
        playMelody();
      }
      lightTriggered2 = 1;
    }
  } else {
    lightTriggered2 = 0;
  }

  if (lastScore1 != score1) {
    setNumber(lc1, score1);
  }

  if (lastScore2 != score2) {
    setNumber(lc2, score2);
  }

  lastScore1 = score1;
  lastScore2 = score2;
}
