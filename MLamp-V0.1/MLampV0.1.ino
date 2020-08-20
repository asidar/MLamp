/*
---------------------------------------------------------------------------------------
Project Title = Mood Lamp (Single WS2812B RGB LED based)
Date Created - 11/05/2020 | Version - 0.1 (N00B Level)
Code Author = https://github.com/pytxt
Learned about FastLED usage from = https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/

Feel free to suggest new features  / PR!
---------------------------------------------------------------------------------------
*/

#include <FastLED.h>
#define LED_PIN     05
#define NUM_LEDS    1
CRGB leds[NUM_LEDS];
char cr=0;
char cg=0;
char cb=0;

void showit(){
  leds[0]=CRGB(cr,cg,cb);
  FastLED.show();
  delay(50); // Change the delay according to your taste
  //Serial.print("R= ");
  //Serial.print(cr, DEC);
  //Serial.print(" | G= ");
  //Serial.print(cg, DEC);
  //Serial.print(" | B= ");
  //Serial.print(cb, DEC);
  //Serial.println();
}

void crup(){
  //Serial.println("\t\tRED Increasing!");
  for(cr=0;cr<=254;cr++)
  {
    showit();
  }
}

void cgup(){
  //Serial.println("\t\tGREEN Increasing!");
   for(cg=0;cg<=254;cg++)
  {
    showit();
  }
}

void crdn(){
  //Serial.println("\t\tRED Decreasing!");
   for(cr=255;cr>=1;cr--)
  {
    showit();
  }
}


void cgdn(){
  //Serial.println("\t\tGREEN Decreasing!");
   for(cg=255;cg>=1;cg--)
  {
    showit();
  }
}


void cbup(){
  //Serial.println("\t\tBLUE Increasing!");
  for(cb=0;cb<=254;cb++)
  {
    showit();
  }
}


void cbdn(){
  //Serial.println("\t\tBLUE Decreasing!");
   for(cb=255;cb>=1;cb--)
  {
    showit();
  }
}


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  //Serial.begin(9600); //added for debugging purposes.

}

void loop() {
      crup();  //Increase RED value
      
      cgup();  //Increase GREEN value
     
      crdn();  //Decrease RED value
       
      cbup();  //Increase BLUE value
       
      cgdn();  //Decrease GREEN value
       
      crup();  //Increase RED value
       
      cbdn();  //Decrease BLUE value
       
      cgup();  //Increase GREEN value
       
      cbup();  //Increase BLUE value
       
      crdn();  //Decrease RED value
       
      cgdn();  //Decrease GREEN value
       
      cbdn();  //Decrease BLUE value

      delay(100); //optional delay
}
