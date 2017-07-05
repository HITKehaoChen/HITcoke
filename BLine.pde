void setup(){
  size(500,500);
  smooth();
  background(255);
}
void draw(){
  background(random(0,255),random(0,255),random(0,255));
}
void mousePressed(){
  float a =random(250);
  ellipse(mouseX,mouseY,a,a);
}