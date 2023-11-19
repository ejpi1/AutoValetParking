#include <SoftwareSerial.h>
// code for HC-05
// 시리얼통신 시 "Both NL&CR" 선택
// AT모드로 들어가려면 HC-05 기판 위 버튼을 누른 채 VCC선을 뺐다가 다시 꼽으면 된다.
// 가급적 TX, RX PIN도 제거한 상태에서 VCC선을 뺏다가 꼽을 것
// LED가 2초마다 점멸하면 AT Command 모드이다.

SoftwareSerial BTSerial1(8, 9); // Arduino RX, TX
SoftwareSerial BTSerial2(12, 13);
// 아두이노의 TX, RX를 각각 HC-05의 RX, TX에 연결할 것

int BTState = 0;                // 기본값은 BTSerial1과 통신
int serial_data = 0;           // Serial.read()의 값 저장
int is_command = 0;             // BTSerial 변경하는 명령어라면 1

void setup() {
  Serial.begin(9600);
  BTSerial1.begin(38400);  // HC-05는 기본적으로 9600 or 38400 baud rate
  BTSerial2.begin(38400);
  Serial.println("AT코드를 입력하세요:");
}

void loop() {
  if(Serial.available()){
    serial_data = Serial.read();
    Serial.print(serial_data, HEX);
    if(serial_data == "49" || serial_data == "50"){
      BTState = serial_data - 48;
      is_command = 1;
      Serial.print("BT");
      Serial.print(BTState);
      Serial.println("으로 변경되었습니다.");
    }
    if(!is_command){
      if(BTState == 1){
        BTSerial1.write(serial_data);
      }else if(BTState == 2){
        BTSerial2.write(serial_data);
      }
    }
  }

  if(BTSerial1.available()){
    Serial.print("From BT1: ");
    Serial.write(BTSerial1.read());
  }
  if(BTSerial2.available()){
    Serial.print("From BT2: ");
    Serial.write(BTSerial2.read());
  }
}
