#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
int ledSet[]={13,12,14,27,26,25,33,32};
void setup() {
  Serial.begin(115200);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  tft.init();
  tft.setRotation(1);

  // Use this calibration code in setup():
  uint16_t calData[5] = { 440, 3315, 489, 3207, 7 };
  tft.setTouch(calData);


  tft.fillScreen(tft.color24to16(0xFFFFFF));
  tft.fillCircle(50, 50, 30, tft.color24to16(0xC3C3C3));
  tft.fillRect(20, 110, 135, 90, tft.color24to16(0x1ABC9C));
  tft.fillRect(155, 110, 140, 90, tft.color24to16(0xE74C3C));
  

  tft.setTextSize(4);
  tft.setTextColor(tft.color24to16(0x3B3B3B));
  tft.setTextDatum(ML_DATUM);
  tft.drawString("LEDSWITCH", 95, 50);

  tft.setTextSize(4);
  tft.setTextColor(tft.color24to16(0xFFFFFF));
  tft.setTextDatum(MC_DATUM);
  tft.drawString("ON", 90, 160);
  tft.drawString("OFF", 230, 160);
  tft.fillCircle(50, 220, 10, tft.color24to16(0xC3C3C3));
  tft.fillCircle(80, 220, 10, tft.color24to16(0xC3C3C3));
  tft.fillCircle(110, 220, 10, tft.color24to16(0xC3C3C3));
  tft.fillCircle(140, 220, 10, tft.color24to16(0xC3C3C3));
  tft.fillCircle(170, 220, 10, tft.color24to16(0xC3C3C3));
  tft.fillCircle(200, 220, 10, tft.color24to16(0xC3C3C3));
  tft.fillCircle(230, 220, 10, tft.color24to16(0xC3C3C3));
  tft.fillCircle(260, 220, 10, tft.color24to16(0xC3C3C3));
  
}

void loop() {
  uint16_t x, y;
  if (tft.getTouch(&x, &y)) {
    Serial.printf("Touched at (%d, %d)\n", x, y);
    if ((x > 0 && x < 140) && (y > 120 && y < 210)) {
      for(int i=0;i<8;i++){
      digitalWrite(ledSet[i],HIGH);
      delay(100);
      if (i==0){
        tft.fillCircle(50, 220, 10, tft.color24to16(0x00008B));
      
      }
      if (i==1){
        tft.fillCircle(80, 220, 10, tft.color24to16(0x00008B));
      
      }
      if (i==2){
        tft.fillCircle(110, 220, 10, tft.color24to16(0x27AE60));
      
      }
      if (i==3){
        tft.fillCircle(140, 220, 10, tft.color24to16(0x27AE60));
      
      }
      if (i==4){
        tft.fillCircle(170, 220, 10, tft.color24to16(0xFFFF00));
      
      }
      if (i==5){
        tft.fillCircle(200, 220, 10, tft.color24to16(0xFFFF00));
      
      }
      if (i==6){
        tft.fillCircle(230, 220, 10, tft.color24to16(0xE74C3C));
      
      }
      if (i==7){
        tft.fillCircle(260, 220, 10, tft.color24to16(0xE74C3C));
      
      }
      
      }
      tft.fillCircle(50, 50, 30, tft.color24to16(0x27AE60));
    } else if ((x > 150 && x < 300) && (y > 120 && y < 210)) {
      for(int i=7;i>=0;i--){
      digitalWrite(ledSet[i],LOW);
      delay(100);
      if (i==0){
        tft.fillCircle(50, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      if (i==1){
        tft.fillCircle(80, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      if (i==2){
        tft.fillCircle(110, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      if (i==3){
        tft.fillCircle(140, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      if (i==4){
        tft.fillCircle(170, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      if (i==5){
        tft.fillCircle(200, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      if (i==6){
        tft.fillCircle(230, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      if (i==7){
        tft.fillCircle(260, 220, 10, tft.color24to16(0xC3C3C3));
      
      }
      }
      tft.fillCircle(50, 50, 30, tft.color24to16(0xC3C3C3));
      
    }
  }
  delay(10);
}
