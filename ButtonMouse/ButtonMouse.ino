
/*
Button Mouse - physical buttons which cause clicks in specific
screen locations for activating controls in Eko and other interfaces
*/ 

#include "Mouse.h"

  byte buttonL = 6;
  byte buttonR = 7;
  byte LED1 = 9;
  byte LED2 = 10;
  bool buttonLprev = LOW;
  bool buttonRprev = LOW;
  
void setup() { 
  // initialize mouse control:
  Mouse.begin();

  pinMode(buttonL, INPUT);
  pinMode(buttonR, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop() {
      
  byte buttonLState = digitalRead(buttonL); // read from the button
  byte buttonRState = digitalRead(buttonR); // read from the button
  
  if(buttonLState == HIGH) { // button pressed
    
    digitalWrite(LED1, HIGH); // turn on LED
    //digitalWrite(LED1, LOW); // turn off LED
    
    if(buttonLprev != buttonLState) { // state changed from Low to High
    //move mouse to L location and perform Click event
      for(byte i=0;i<100; i++) {
          Mouse.move(-1000, -1000);
      }
        //then move back down to a specific location now 
        //that the cursor is centered on the corner
        //perhaps use bottom corners instead of top to 'hide' the 
        //cursor arrow/pointer
        Mouse.move(1000,250);
        //  Mouse.click(); // click on that spot
    }
  }
  else {
    digitalWrite(LED1, LOW); // turn off LED, button not pressed
    if(buttonLprev != buttonLState) { // state changed from High to Low
      //button released
    }
  }
  buttonLprev = buttonLState; // store new Value

  if(buttonRState == HIGH) { // button pressed
    digitalWrite(LED2, HIGH); // turn on LED
    if(buttonRprev != buttonRState) { // state changed from Low to High
    //move mouse to L location and perform Click event
      for(byte i=0;i<100; i++) {
          Mouse.move(1000, -1000);
      }
      Mouse.move(-1000,250);
             //   Mouse.click(); // click on that spot
    }
  }
  else {
    digitalWrite(LED2, LOW); // turn off LED, button not pressed
    if(buttonRprev != buttonRState) { // state changed from High to Low
      //button released
    }
  }
  buttonRprev = buttonRState; // store new Value

}

