#include "SevSeg.h"

#define sensibility 1000
SevSeg sevseg; 
int counter = 20;
bool flag;
uint32_t tmr;
void setup() {
  byte numDigits = 2;
  byte digitPins[] = {13, 12};
  byte segmentPins[] = {A1, 8, 7, 5, 6, 2, 4, A5};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
  pinMode(A0, INPUT);
  pinMode(A3,OUTPUT);
  digitalWrite(A3, 1);
}

void loop() {
  int val = analogRead(A0);
 if((millis()-tmr)>=500){
   tmr = millis();
    if((val<sensibility) and (flag ==0)){
      counter--;
      flag=1;
    }
  
  if(val>sensibility){
    flag =0;
  }
  if(counter == 0){
    digitalWrite(A3, 0);
    while(true){
      sevseg.setNumber(0);
      sevseg.refreshDisplay();
    }
  }
  }
  sevseg.setNumber(counter);
  sevseg.refreshDisplay();
  
  
   // Must run repeatedly
}