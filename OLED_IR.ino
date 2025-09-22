#include <U8g2lib.h>
#include <Wire.h>  

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
int ir = 34;

unsigned long previousMillis = 0;
const long interval1 = 1500; // 1 second
const long interval2 = 100;  

enum EyeState { EYE_OPEN, EYE_CLOSE, EYE_IDLE };
EyeState eyeState = EYE_IDLE;

void setup() {
  pinMode(ir, INPUT);
  u8g2.begin();  
}

void loop() {
  int Read = digitalRead(ir);
  unsigned long currentMillis = millis();

  if (Read == 0) {
    eye_up();
    eyeState = EYE_IDLE;
    previousMillis = currentMillis; 
  } else {
    switch (eyeState) {
      case EYE_IDLE:
        eye_open();
        previousMillis = currentMillis;
        eyeState = EYE_CLOSE;
        break;
        
      case EYE_CLOSE:
        if (currentMillis - previousMillis >= interval1) {
          eye_close();
          previousMillis = currentMillis;
          eyeState = EYE_OPEN;
        }
        break;
        
      case EYE_OPEN:
        if (currentMillis - previousMillis >= interval2) {
          eye_open();
          previousMillis = currentMillis;
          eyeState = EYE_IDLE;
        }
        break;
    }
  }
}

void eye_up() {
  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);
  u8g2.drawRBox(80, 12, 40, 20, 5);
  u8g2.drawRBox(10, 12, 40, 20, 5);
  u8g2.drawFilledEllipse(99.5, 13, 19.5, 11);
  u8g2.drawFilledEllipse(29.5, 13, 19.5, 11);
  u8g2.sendBuffer();
}

void eye_open() {
  u8g2.clearBuffer(); 
  u8g2.setBitmapMode(1);
  u8g2.drawRBox(14, 13, 36, 36, 5);
  u8g2.drawRBox(78, 13, 36, 36, 5);
  u8g2.sendBuffer();
}

void eye_close() {
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.drawRBox(14, 27, 36, 7, 3);
  u8g2.drawRBox(78, 27, 36, 7, 3);
  u8g2.sendBuffer();
}
