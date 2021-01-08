

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


void setup() {

  Serial.begin(115200);
  irrecv.enableIRIn(); // 리모컨 수신 사용

  left.attach(D0);
  left.write(35);
  right.attach(D1);
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
    digitalWrite(delayPin,HIGH);
    delay(50);
    switch (results.value) {
      case 0xFFA25D: 
        right.write(7);
        delay(300);
        right.write(35);
        delay(300); break;
      case 0xFF629D: 
        left.write(125);
        delay(300);
        left.write(90);
        delay(300); break; 
    }
    irrecv.resume();
    digitalWrite(delayPin,LOW);
  }

}

void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  Serial.println(data->value());

  int state = data->toInt();
  if(state) {
    digitalWrite(delayPin,HIGH);
    delay(300);
    right.write(7);
    delay(300);
    right.write(35);
    delay(300);
    }
  else {
    digitalWrite(delayPin,HIGH);
    delay(300);
    left.write(125);
    delay(300);
    left.write(90);
    delay(300);
    }
  digitalWrite(delayPin,LOW);
}
