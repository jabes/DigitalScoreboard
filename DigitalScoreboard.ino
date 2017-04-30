#include <LedControl.h>
LedControl lc1 = LedControl(10, 9, 8, 1);
LedControl lc2 = LedControl(13, 12, 11, 1);

const int buttonPin = 2;
int buttonState = 0;
boolean buttonPressed = false;

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
const int speakerOut = 6;
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
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0}
  }, {
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0}
  }, {
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0}
  }, {
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0}
  }, {
    {0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0}
  }, {
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0}
  }, {
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0}
  }, {
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0}
  }, {
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0}
  }, {
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0}
  }, {
    {1, 0, 0, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0}
  }
};

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(speakerOut, OUTPUT);
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
  lc.clearDisplay(0);
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      int state = Numbers[num][row][col];
      lc.setLed(0, row, col, state);
    }
  }
}

void playTone() {
  long elapsed_time = 0;
  // if this isn't a Rest beat, while the tone has
  if (tone_ > 0) {
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {
      digitalWrite(speakerOut, HIGH);
      delayMicroseconds(tone_ / 2);
      digitalWrite(speakerOut, LOW);
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
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (buttonPressed == false) {
      if (score1 < 10) {
        score1 += 1;
        playMelody();
      }
      buttonPressed = true;
    }
  } else {
    buttonPressed = false;
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
