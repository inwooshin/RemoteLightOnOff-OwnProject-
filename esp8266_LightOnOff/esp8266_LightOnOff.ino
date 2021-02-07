

#include "config.h"
#include <Servo.h>
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#define delayPin D2
AdafruitIO_Feed *counter = io.feed("LedControlFeed");
Servo left, right;

IRrecv irrecv(14);
decode_results results;

void right(){
  digitalWrite(delayPin,HIGH);
  delay(100);
  right.write(125);
  delay(300);
  right.write(90);
  delay(300);
  digitalWrite(delayPin,LOW);
}

void left(){
  digitalWrite(delayPin,HIGH);
  delay(100);
  left.write(7);
  delay(300);
  left.write(35);
  delay(300);
  digitalWrite(delayPin,LOW); 
}


void setup() {

  Serial.begin(115200);
  irrecv.enableIRIn(); // 리모컨 수신 사용

  left.attach(D0);
  left.write(35);
  right.attach(D6);
  right.write(90);

  pinMode(delayPin, OUTPUT);
  
  while (! Serial);
  
  Serial.print("Connecting to Adafruit IO");

  io.connect();


  counter->onMessage(handleMessage);

  while (io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  counter->get();

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  io.run();

  //적외선 센서 코드 추가하기
  if (irrecv.decode(&results)){ 
    serialPrintUint64(results.value, HEX);
    Serial.println("");  
    switch (results.value) {
      case 0xFFA25D: 
        right();
        break;
      case 0xFF629D: 
        left();
        break; 
    }
    irrecv.resume();
  }

}

void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  Serial.println(data->value());

  int state = data->toInt();
  if(state) {
    right();
    }
  else {
    left();
    }
}
