//firmata arduino connection here

import processing.serial.*;
import cc.arduino.*;
Arduino arduino;
int ledPin = 13;

// from sensor eg

int Sensor;      // HOLDS PULSE SENSOR DATA FROM ARDUINO
int IBI;         // HOLDS TIME BETWEN HEARTBEATS FROM ARDUINO
int BPM;         // HOLDS HEART RATE VALUE FROM ARDUINO
int[] RawY;      // HOLDS HEARTBEAT WAVEFORM DATA BEFORE SCALING
int[] ScaledY;   // USED TO POSITION SCALED HEARTBEAT WAVEFORM
int[] rate;      // USED TO POSITION BPM DATA WAVEFORM

//from hearRateAnimation

float unit, theta;
int num = 55, frames=180;

void setup()
{
//println(Arduino.list());
arduino = new Arduino(this, Arduino.list()[0], 57600);
arduino.pinMode(ledPin, Arduino.OUTPUT);
 size(500, 500);
  unit = width/num;
}

void draw()
{
arduino.digitalWrite(ledPin, Arduino.HIGH);
delay(500);
arduino.digitalWrite(ledPin, Arduino.LOW);
delay(1000);

  fill(0,30);
  noStroke();
  rect(0,0,width, height);
  fill(255);
  
  
  if( BPM > 45 ) {
    for (int y=0; y<=num; y++) {
      for (int x=0; x<=num; x++) {
        float distance = dist(width/2, height/2, x*unit, y*unit);
        float offSet = map(distance, 0, sqrt(sq(width/2)+sq(height/2)), 0, TWO_PI);
        float sz = map(sin(theta+offSet), -1, 1, unit*.2, unit*.1);
        float angle = atan2(y*unit-height/2, x*unit-width/2);
        pushMatrix();
        translate(x*unit, y*unit);
        rotate(angle);
        float px = map(sin(theta+offSet),1,9,0,50);
        ellipse(px,0, sz, sz);
        popMatrix();
      }
    }
  }
  
  else if( BPM > 35 ) {
    for (int y=0; y<=num; y++) {
      for (int x=0; x<=num; x++) {
        float distance = dist(width/2, height/2, x*unit, y*unit);
        float offSet = map(distance, 0, sqrt(sq(width/2)+sq(height/2)), 0, TWO_PI);
        float sz = map(sin(theta+offSet), -1, 1, unit*.2, unit*.1);
        float angle = atan2(y*unit-height/2, x*unit-width/2);
        pushMatrix();
        translate(x*unit, y*unit);
        rotate(angle);
        float px = map(sin(theta+offSet),1,7,0,50);
        ellipse(px,0, sz, sz);
        popMatrix();
      }
    }
  }
  
  
  
  else if( BPM > 55 ) {
    for (int y=0; y<=num; y++) {
      for (int x=0; x<=num; x++) {
        float distance = dist(width/2, height/2, x*unit, y*unit);
        float offSet = map(distance, 0, sqrt(sq(width/2)+sq(height/2)), 0, TWO_PI);
        float sz = map(sin(theta+offSet), -1, 1, unit*.2, unit*.1);
        float angle = atan2(y*unit-height/2, x*unit-width/2);
        pushMatrix();
        translate(x*unit, y*unit);
        rotate(angle);
        float px = map(sin(theta+offSet),1,5,0,50);
        ellipse(px,0, sz, sz);
        popMatrix();
      }
    }
  }
  
  
 else if( BPM > 40 ) {
    for (int y=0; y<=num; y++) {
      for (int x=0; x<=num; x++) {
        float distance = dist(width/2, height/2, x*unit, y*unit);
        float offSet = map(distance, 0, sqrt(sq(width/2)+sq(height/2)), 0, TWO_PI);
        float sz = map(sin(theta+offSet), -1, 1, unit*.2, unit*.1);
        float angle = atan2(y*unit-height/2, x*unit-width/2);
        pushMatrix();
        translate(x*unit, y*unit);
        rotate(angle);
        float px = map(sin(theta+offSet),1,3,0,50);
        ellipse(px,0, sz, sz);
        popMatrix();
      }
    }
  }
  
  
  else if( BPM > 60 ) {
    for (int y=0; y<=num; y++) {
      for (int x=0; x<=num; x++) {
        float distance = dist(width/2, height/2, x*unit, y*unit);
        float offSet = map(distance, 0, sqrt(sq(width/2)+sq(height/2)), 0, TWO_PI);
        float sz = map(sin(theta+offSet), -1, 1, unit*.2, unit*.1);
        float angle = atan2(y*unit-height/2, x*unit-width/2);
        pushMatrix();
        translate(x*unit, y*unit);
        rotate(angle);
        float px = map(sin(theta+offSet),1,0,0,50);
        ellipse(px,0, sz, sz);
        popMatrix();
      }
    }
  }
  
  else if( BPM > 0 ) {
    for (int y=0; y<=num; y++) {
      for (int x=0; x<=num; x++) {
        float distance = dist(width/2, height/2, x*unit, y*unit);
        float offSet = map(distance, 0, sqrt(sq(width/2)+sq(height/2)), 0, TWO_PI);
        float sz = map(sin(theta+offSet), -1, 1, unit*.2, unit*.1);
        float angle = atan2(y*unit-height/2, x*unit-width/2);
        pushMatrix();
        translate(x*unit, y*unit);
        rotate(angle);
        float px = map(sin(theta+offSet),1,-3,0,50);
        ellipse(px,0, sz, sz);
        popMatrix();
      }
    }
  }
  
  stroke(255);
 
  theta -= TWO_PI/frames;

}

//firmata arduino connection ends here



