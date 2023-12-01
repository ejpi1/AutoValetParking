// 차량을 조종하기 위한 리모트 컨트롤러
// 향후 차량에 주차 신호와 출차 신호를 주기 위한 컨트롤러로 바꿀 예정이다.
// 버튼을 눌렀을 때 SoftwareSerial을 통한 문자열을 전송
// HC-06을 사용; Baud Rate = 9600
// a = 13 = yellow = 좌회전
// w = 12 = blue   = 전진
// s = 11 = orange = 후진
// d = 10 = green  = 우회전
// x = 9  = white  = 정지
#include <SoftwareSerial.h>
#define yellow  13  // 좌회전:  a
#define blue    12  // 전진:    w
#define red     11  // 후진:    s
#define green   10  // 우회전:  d
#define white   9   // 정지:    x

SoftwareSerial BT(6, 7);  // ArduitnoRX:6, ArduinoTX:7, HC06RX:7, HC06TX: 6
uint8_t signal;

void setup() {
  pin_pullup();
  BT.begin(9600);
  // 디버깅
  // Serial.begin(9600);
}

void loop() {
  select_signal();
  if(signal != 0){  //아무 버튼도 안 눌린 상태면 무시
    BT.write(signal);
    // 디버깅
    // Serial.write(signal);
  }
  delay(10);
}

void pin_pullup(){
  // 반드시 내부 pullup저항 활성화할것!
  pinMode(yellow, INPUT_PULLUP);
  pinMode(blue, INPUT_PULLUP);
  pinMode(red, INPUT_PULLUP);
  pinMode(green, INPUT_PULLUP);
  pinMode(white, INPUT_PULLUP);
}

void select_signal(){
  // 버튼을 눌렀을 때 LOW(0), 버튼이 눌리지 않았을 때 HIGH(1)이다.
  // !digitalRead(pin)은 버튼을 눌렀을 때 1
  if(!digitalRead(yellow)){
    signal = 'a';
  }else if(!digitalRead(blue)){
    signal = 'w';
  }else if(!digitalRead(red)){
    signal = 's';
  }else if(!digitalRead(green)){
    signal = 'd';
  }else if(!digitalRead(white)){
    signal = 'x';
  }else{
    signal = 0;
  }
}