 /*
---------------------------------------------------------------------------------------
Project Title = Mood Lamp (Single WS2812B RGB LED based)
Date Created - 11/05/2020 | Version - 0.2 (Improvised but still at N00B Level)
Code Author = https://github.com/asidar
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
char chc=0;
char chcupdn=0;
char TMPC=0;

void showit(){
  leds[0]=CRGB(cr,cg,cb);
  FastLED.show();
  delay(50); // Change the delay according to your taste.
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

//The function below makes descision on which function to execute to decrease the value of the RGB element.
void goup(){
  switch (chcupdn){
    case 0:
      if(cr==0){
        crup();
      }
      else{
        ;
      }
      break;
    case 1:
      if(cg==0){
        cgup();
      }
      else{
        ;
      }
      break;
    case 2:
      if(cb==0){
        cbup();
      }
      else{
        ;
      }
      break;
  }
}

//The function below makes descision on which function to execute to increase the value of the RGB element.
void godn(){
  switch (chcupdn){
    case 3:               
      if(cr==255){
        crdn();
      }
      else{
        ;
      }
      break;
    case 4:
      if(cg==255){
        cgdn();
      }
      else{
        ;
      }
      break;
    case 5:
      if(cb==255){
        cbdn();
      }
      else{
        ;
      }
      break;
  }
  
}


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  //Serial.begin(9600);
}

void loop() {
  while(1){
   chc = random(0,2); // a random number is generated 
   delay(1);
   while(TMPC==chcupdn){
    chcupdn = random(0,6); //attempt to generate a random number in between 0 to 5
   }
   TMPC=chcupdn;
   //Serial.print(TMPC, DEC);
   switch(chc){
    case 0:
      goup();
      break;
    case 1:
      godn();
      break;
   }
  } 
}
