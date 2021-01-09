#include <Servo.h>

Servo left,right;

int leftbutton = 9, rightbutton = 8, once = 0;

void setup() {
  // put your setup code here, to run once:

  left.attach(13);
  left.write(35);
  right.attach(12);
  right.write(90);

  Serial.begin(9600);
  pinMode(leftbutton, INPUT);
  pinMode(rightbutton, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int lefton = digitalRead(9);
  int righton = digitalRead(8);
  Serial.println(lefton);
  Serial.println(righton);
 
  if(!once) {
    if(lefton == 1){
      once = 1;
    left.write(7);
    delay(100);
    left.write(35);
    }
    if(righton == 1){
      once = 1;
    right.write(125);
    delay(100);
    right.write(90);
    }
  }
  
  delay(100);
  if(!lefton && !righton) once = 0;
}
