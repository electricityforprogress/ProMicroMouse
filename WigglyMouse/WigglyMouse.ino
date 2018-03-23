
/*
Wiggly Mouse - Keep a machine awake through USB Mouse emulation
*/

#include "Mouse.h"

int distance = 10; //how far to 'wiggle'
int wiggleTime = 1; //milliseconds to perform wiggle displacement
int waitTime = 5000; //delay between wiggles

void setup() { 
  Serial.begin(9600);
  // initialize mouse control:
  Mouse.begin();
 
}

void loop() {
  
      Mouse.move(0, -1*distance);
      
      delay(wiggleTime);//wait a little while and move back (minimize this value)
      
      Mouse.move(0, distance);
      
      Serial.println("wiggle ...----___==.....");

      //turn off red LEDs on ProMicro for USB serial
       TXLED1;
       RXLED1;
      
      delay(waitTime);//don't wiggle all the time
}

//can type here and the wiggle just doesnt bother me
