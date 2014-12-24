float unit, theta;
int num = 55, frames=180;


//heartRate = 
//int heartRate = mouseX;
 
void setup() {
  size(500, 500);
  unit = width/num;
}
 
void draw() {
  fill(0,30);
  noStroke();
  rect(0,0,width, height);
  fill(255);
  
  
  if( mouseX > 450 ) {
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
  
  else if( mouseX > 350 ) {
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
  
  
  
  else if( mouseX > 250 ) {
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
  
  
 else if( mouseX > 150 ) {
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
  
  
  else if( mouseX > 50 ) {
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
  
  else if( mouseX > 0 ) {
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

