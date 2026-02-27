#include "ArduinoGraphics.h" // For scrolling text (before next inclusion)
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// Sub-optimal for memory management (1 LED = 1 byte memory)
uint8_t heartFrame[8][12] = {
  { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// Optimal for memory management (1 LED = 1 bit memory)
uint32_t hexHeartFrame[] = {
  0x3184a444,
  0x42081100, // 42481100 for prolonged heart crack
  0xa0040000
};

uint32_t hexHappyFrame[] = {
  0x00019819,
  0x80000001,
  0x081f8000
};

// == WINK ==
uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void leftEye(){
  frame[1][3] = 1;
  frame[1][4] = 1;
  frame[2][3] = 1;
  frame[2][4] = 1;
}

void leftWink(){
  frame[1][3] = 0;
  frame[1][4] = 0;
  frame[2][3] = 1;
  frame[2][4] = 1;
}

void rightEye(){
  frame[1][8] = 1;
  frame[1][9] = 1;
  frame[2][8] = 1;
  frame[2][9] = 1;
}

void mouth(){
  frame[5][3] = 1;
  frame[5][9] = 1;
  frame[6][3] = 1;
  frame[6][4] = 1;
  frame[6][5] = 1;
  frame[6][6] = 1;
  frame[6][7] = 1;
  frame[6][8] = 1;
  frame[6][9] = 1;
}

void setup() {
  Serial.begin(9600);
  matrix.begin();

  // For binary frame format
  //heartFrame[3][5] = 1;
  //matrix.renderBitmap(heartFrame, 8, 12);

  // For hex frame format
  //hexHeartFrame[1] = 0x42481100;
  //matrix.loadFrame(hexHeartFrame);

  // == HEX TO BIN ==
  // To convert hex to bin (if starts with zero it is not showcased)
  // delay(1000); // Required to let serial port requires some time (will not print if directly following Serial.begin())
  // for (int b=0; b<3; b++){
  //   Serial.println(hexHeartFrame[b], BIN);
  // }

  // // To convert hex to bin (showcases starting zeroes)
  // for (int B=0; B<3; B++){
  //   for (int b=31; b>=0; b--){
  //     Serial.print((hexHeartFrame[B]>>b) & 1);
  //   }
  //   Serial.println();
  // }

  // To convert hex to bin with 8x12 format
  // uint8_t row_cnt = 0;
  // for (int B=0; B<3; B++){
  //   for (int b=31; b>=0; b--){
  //     Serial.print((hexHeartFrame[B]>>b) & 1);
  //     row_cnt++;

  //     // Go to next row
  //     if(row_cnt == 12){
  //       row_cnt = 0;
  //       Serial.println();
  //     }
  //   }
  // }

  // == WRITE TEXT ==
  matrix.beginDraw();
  const char text[] = "UNO";
  matrix.textFont(Font_4x6); // 4x6 for each char (most right is for space)
  // XXX
  matrix.beginText(0, 1, 0xFFFFFF); // Start at LED[0][1] with 
  matrix.println(text); // Print text
  matrix.endText();

  matrix.endDraw();

}

void loop() {
  // == SWITCH BETWEEN HEART AND SMILEY ==
  // matrix.loadFrame(hexHeartFrame);
  // delay(500);

  // matrix.loadFrame(hexHappyFrame);
  // delay(500);

  // == WINK ==
  // leftEye();
  // rightEye();
  // mouth();

  // matrix.renderBitmap(frame, 8, 12);
  // delay(1000);

  // leftWink();

  // matrix.renderBitmap(frame, 8, 12);
  // delay(1000);

  // == SCROLLING TEXT ==

}
