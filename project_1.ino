#include <SoftwareSerial.h>
#include "Servo.h"

//SotfwareSerial(RX, TX) 형식, HC-06 TX, RX와 교차 연결
Servo myservo;
SoftwareSerial BTSerial(2,3); //SW시리얼통신 객체 생성
String myString="";

void setup() {
  //컴퓨터와의 시리얼통신 초기화
  Serial.begin(9600);
//  while(!Serial);
  Serial.println("시리얼통신 연결 완료!");

  //블루투스 모듈과의 시리얼통신 초기화
  BTSerial.begin(9600);

  myservo.attach(7);
  myservo.write(0);
}

void loop() {
  
 while(BTSerial.available())
  {
    char myChar = (char)BTSerial.read();
    myString+=myChar;
    delay(5);
  }
  if(!myString.equals(""))
  {
    while(myString == "on")
  {
      myservo.write(20);
      delay(300);

      myservo.write(0);
      break;
}
   myString="";
}
}
