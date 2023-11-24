#include <SoftwareSerial.h>
// code for HC-05
// 시리얼통신 시 "Both NL&CR" 선택
// AT모드로 들어가려면 HC-05 기판 위 버튼을 누른 채 VCC선을 뺐다가 다시 꼽으면 된다.
// 가급적 TX, RX PIN도 제거한 상태에서 VCC선을 뺏다가 꼽을 것
// LED가 2초마다 점멸하면 AT Command 모드이다.

SoftwareSerial BTSerial(8, 9); // Arduino RX, TX
// 아두이노의 TX, RX를 각각 HC-05의 RX, TX에 연결할 것

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);  // HC-05는 기본적으로 9600 or 38400 baud rate
  Serial.println("AT코드를 입력하세요:");
}

void loop() {
  if(BTSerial.available()){
    Serial.write(BTSerial.read());
  }
  if(Serial.available()){
    BTSerial.write(Serial.read());
  }
}
