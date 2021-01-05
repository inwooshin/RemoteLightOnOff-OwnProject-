#include <Servo.h>


  int state = 1;

Servo left,right;

int leftbutton = 9, rightbutton = 8, once = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(11, OUTPUT);

  left.attach(13);
  left.write(45);
  right.attach(12);
  //right.write(90);

  Serial.begin(9600);
  pinMode(leftbutton, INPUT);
  pinMode(rightbutton, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  state ^= 1;
  digitalWrite(11,state);
  left.write(45);
  right.write(45);
  delay(300);
  left.write(130);
  right.write(130);
  delay(300);
}
