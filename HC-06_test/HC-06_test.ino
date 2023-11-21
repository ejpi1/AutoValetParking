#include <SoftwareSerial.h>
// code for HC-06
// 시리얼통신 시 "No Line Ending" 선택

#define arduino_RX 7
#define arduino_TX 8
SoftwareSerial hc06(arduino_RX, arduino_TX); // 아두이노의 RX, TX를 각각 HC-06의 TX, RX에 연결할 것

char serial_data;

void setup() {
  Serial.begin(38400);
  hc06.begin(38400);  // HC-06는 기본적으로 9600 or 38400 baud rate
  Serial.println("AT코드를 입력하세요:");
}

void loop() {
  while(Serial.available()){
    hc06.write(Serial.read());
  }
  while(hc06.available()){
    serial_data = hc06.read();
    Serial.write(serial_data);
  }
}
