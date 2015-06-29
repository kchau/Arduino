#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include "RGB.h"

#define PIN 1

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
                            NEO_MATRIX_TOP + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB + NEO_KHZ800);

int ring1[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
int ring2[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
int ring3[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
int ring4[8][8] = {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1}
};

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(30);
  matrix.setTextColor(matrix.Color(255, 0, 0));
}

int count = 0;

void loop() {
  if (count % 8 == 0) {
    count = 0; 
  }

  switch(count) {
    case 0:
      ring(ring1, red);    ring(ring2, orange); 
      ring(ring3, yellow); ring(ring4, green);
      break;
    case 1:
      ring(ring1, orange); ring(ring2, yellow);
      ring(ring3, green);  ring(ring4, blue);
      break;
    case 2:
      ring(ring1, yellow); ring(ring2, green);
      ring(ring3, blue);   ring(ring4, purple);
      break;
    case 3:
      ring(ring1, green);  ring(ring2, blue);
      ring(ring3, purple); ring(ring4, red);
      break;
    case 4:
      ring(ring1, blue);   ring(ring2, purple);
      ring(ring3, red);    ring(ring4, orange);
      break;
    case 5:
      ring(ring1, purple); ring(ring2, red);
      ring(ring3, orange); ring(ring4, yellow);
      break;
  }
  matrix.show();
  count++;
}

void ring(int pattern[8][8], RGB color) {
  for(int row=0; row < 8; row++) {
    for(int column=0; column < 8; column++) {
      if (pattern[row][column] == 1) {
        matrix.drawPixel(row, column, 
          matrix.Color(color.r, color.g, color.b));  
      }
    }
  }
  delay(125);
}

