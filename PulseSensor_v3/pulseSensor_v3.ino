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
//for sensor 2 on pin A1
int prevCount1=1;
int countdigits1[] = {
  0, 0, 0};
int prevdigits1[] = {
  0, 0, 0};
int digitpos1[] = {
  30, 90, 150};
int x1=0; 

//  VARIABLES
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int pulsePin1 = 1;                 // Pulse Sensor purple wire connected to analog pin 1

// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

//for sensor 2
volatile int BPM1;                   // used to hold the pulse rate
volatile int Signal1;                // holds the incoming raw data
volatile int IBI1 = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse1 = false;     // true when pulse wave is high, false when it's low
volatile boolean QS1 = false;        // becomes true when Arduoino finds a beat.


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
  
  if (QS == true){                       // Quantified Self flag is true when arduino finds a heartbeat
    if((BPM>=50) && (BPM<=100)){
      
    Serial.print("B");
    Serial.println(BPM);   
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
          Serial.println(prevdigits[x]);
          //print new value in white
          if((x == 0) and (BPM > 99) and (countdigits[x] > 0)){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits[x]);
          }
          if((x == 1) and (BPM >= 99)){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits[x]);
          }
          else if((x == 1) and (BPM < 99) and (countdigits[x] > 0)){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits[x]);
          }
          if(x == 2){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits[x]);
          }
        }
      }
      prevCount = BPM; //Store current bpm for comparison on the next loop.
    } 
    QS = false;  // reset the Quantified Self flag for next time    
  
  
  //for sensor 2
  
  if (QS == true){                       // Quantified Self flag is true when arduino finds a heartbeat
    if((BPM1>=50) && (BPM1<=100)){
      
    Serial.print("B1");
    Serial.println(BPM1);   
    }
    countdigits1[2] = BPM1 % 10;
    //How to handle the middle digit depends on if the
    //the speed is a two or three digit number
    if(BPM1 > 99){
      countdigits1[1] = (BPM1 / 10) % 10;
    }
    else{
      countdigits1[1] = BPM1 / 10;
    }
    //Grab the first digit
    countdigits1[0] = BPM1 / 100;

    //Split out the digits of the previous speed
    prevdigits1[2] = prevCount1 % 10;
    if(prevCount1 > 99){
      prevdigits1[1] = (prevCount1 / 10) % 10;
    }
    else{
      prevdigits1[1] = prevCount1 / 10;
    }
    prevdigits1[0] = prevCount1 / 100;
    //Now print the digits on the TFT screen.
    //Only execute this block if the bpm has changed.
    if(BPM1 != prevCount1){
      //tft.setTextSize(10);
      //Compare each digit to the value from the previous loop.
      //The digit will only be redrawn if it has changed.
      for(x1=0; x1 < 3; x1++){
        if(countdigits1[x1] != prevdigits1[x1]){
          //black out old value first.
          //Draw digit in black over the top of white digit
          //tft.setCursor(digitpos[x], 70);
          //tft.setTextColor(ILI9340_BLACK);
          Serial.println(prevdigits1[x1]);
          //print new value in white
          if((x1 == 0) and (BPM1 > 99) and (countdigits1[x1] > 0)){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits1[x1]);
          }
          if((x1 == 1) and (BPM1 >= 99)){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits1[x]);
          }
          else if((x1 == 1) and (BPM1 < 99) and (countdigits1[x1] > 0)){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits1[x1]);
          }
          if(x1 == 2){
            //tft.setCursor(digitpos[x], 70);
            //tft.setTextColor(ILI9340_WHITE);
            Serial.println(countdigits1[x1]);
          }
        }
      }
      prevCount1 = BPM1; //Store current bpm for comparison on the next loop.
    } 
    QS1 = false;  // reset the Quantified Self flag for next time    
  }
}











