#include <LedControl.h>
LedControl lc1=LedControl(10,9,8,1);
LedControl lc2=LedControl(13,12,11,1);

int score1 = 0;
int score2 = 0;
int lastScore1 = score1;
int lastScore2 = score2;

int Numbers[11][8][8] = {
  {
    {0,0,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,1,1,0},
    {0,1,0,0,1,0,1,0},
    {0,1,0,1,0,0,1,0},
    {0,1,1,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,0,0}
  },{
    {0,0,0,0,1,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,1,0,1,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,1,1,1,1,1,0}
  },{
    {0,0,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,1,1,1,0,0},
    {0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,0}
  },{
    {0,0,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,1,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,0,0}
  },{
    {0,0,0,0,1,1,0,0},
    {0,0,0,1,0,1,0,0},
    {0,0,1,0,0,1,0,0},
    {0,1,0,0,0,1,0,0},
    {0,1,1,1,1,1,1,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,0}
  },{
    {0,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,0,0}
  },{
    {0,0,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,0},
    {0,1,0,1,1,1,0,0},
    {0,1,1,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,0,0}
  },{
    {0,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,0},
    {0,0,1,1,1,1,1,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,1,0,0,0,0,0}
  },{
    {0,0,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,0,0}
  },{
    {0,0,1,1,1,1,0,0},
    {0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,1,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,1,0,0,0,0,0}
  },{
    {1,0,0,1,1,1,1,0},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,1},
    {1,0,1,0,0,1,0,1},
    {1,0,1,0,1,0,0,1},
    {1,0,1,1,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,1,1,1,1,0}
  }
};

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc1.shutdown(0,false);
  lc2.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc1.setIntensity(0,8);
  lc2.setIntensity(0,8);
  /* and clear the display */
  lc1.clearDisplay(0);
  lc2.clearDisplay(0);
  /* Set score */
  setNumber(lc1, score1);
  setNumber(lc2, score2);
}

void setNumber(LedControl lc, int num) {
  lc.clearDisplay(0);
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      boolean state = Numbers[num][row][col];
      lc.setLed(0,row,col,state);
    }
  }
}

void loop() {
  if (lastScore1 != score1) {
    setNumber(lc1, score1);
  }

  if (lastScore2 != score2) {
    setNumber(lc2, score2);
  }

  lastScore1 = score1;
  lastScore2 = score2;

  delay(500);
}
