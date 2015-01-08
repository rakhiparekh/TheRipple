/*
 Pulse Sensor Amped + 2.2" TFT
 www.bajdi.com 
*/
//#include "SPI.h"
//#include "Adafruit_GFX.h"
//#include "Adafruit_ILI9340.h" 
//#define _sclk 13
//#define _miso 12
//#define _mosi 11
//#define _cs 10
//#define _rst 9
//#define _dc 8
//
//Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _rst);
int prevCount=1;
int countdigits[] = {
  0, 0, 0};
int prevdigits[] = {
  0, 0, 0};
int digitpos[] = {
  30, 90, 150};
int x=0; 

//  VARIABLES
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0

// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

void setup(){
  //Start the TFT screen and paint it black
//  tft.begin();
//  tft.setRotation(1);
//  tft.fillScreen(ILI9340_BLACK); 
//  tft.setTextColor(ILI9340_WHITE);
//  tft.setTextSize(4);
//  tft.setCursor(230, 90);
//  tft.print("bpm");  
//  tft.setTextColor(ILI9340_WHITE);

  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS  
}

void loop(){
  
  if (QS == true) {      // Quantified Self flag is true when arduino finds a heartbeat
      
      if((BPM>=50) && (BPM<=100)){
      
          Serial.print("BOne");
          Serial.println(BPM);   
      }
      else{
          Serial.print("BOne");
          Serial.println(0); 
      }

      countdigits[2] = BPM % 10;
      //How to handle the middle digit depends on if the
      //the speed is a two or three digit number
      if(BPM > 99){
          countdigits[1] = (BPM / 10) % 10;
      }
      else{
          countdigits[1] = BPM / 10;
      }
      //Grab the first digit
      countdigits[0] = BPM / 100;

      //Split out the digits of the previous speed
      prevdigits[2] = prevCount % 10;
      if(prevCount > 99){
          prevdigits[1] = (prevCount / 10) % 10;
      }
      else{
          prevdigits[1] = prevCount / 10;
      }
      prevdigits[0] = prevCount / 100;
      //Now print the digits on the TFT screen.
      //Only execute this block if the bpm has changed.
      if(BPM != prevCount){
          //tft.setTextSize(10);
          //Compare each digit to the value from the previous loop.
          //The digit will only be redrawn if it has changed.
          for(x=0; x < 3; x++){
              if(countdigits[x] != prevdigits[x]){
                  //black out old value first.
                  //Draw digit in black over the top of white digit
                  //tft.setCursor(digitpos[x], 70);
                  //tft.setTextColor(ILI9340_BLACK);
//                  Serial.println(prevdigits[x]);
                  //print new value in white
                  if((x == 0) and (BPM > 99) and (countdigits[x] > 0)){
                      //tft.setCursor(digitpos[x], 70);
                      //tft.setTextColor(ILI9340_WHITE);
//                      Serial.println(countdigits[x]);
                  }
                  if((x == 1) and (BPM >= 99)){
                      //tft.setCursor(digitpos[x], 70);
                      //tft.setTextColor(ILI9340_WHITE);
//                      Serial.println(countdigits[x]);
                  }
                  else if((x == 1) and (BPM < 99) and (countdigits[x] > 0)){
                      //tft.setCursor(digitpos[x], 70);
                      //tft.setTextColor(ILI9340_WHITE);
//                      Serial.println(countdigits[x]);
                  }
                 if(x == 2){
                    //tft.setCursor(digitpos[x], 70);
                    //tft.setTextColor(ILI9340_WHITE);
//                    Serial.println(countdigits[x]);
                 }
             }
          }
          prevCount = BPM; //Store current bpm for comparison on the next loop.
      } 
      QS = false;  // reset the Quantified Self flag for next time    
   }
}











