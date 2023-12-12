// 차량을 조종하기 위한 리모트 컨트롤러
// 향후 차량에 주차 신호와 출차 신호를 주기 위한 컨트롤러로 바꿀 예정이다.
// 버튼을 눌렀을 때 SoftwareSerial을 통한 문자열을 전송
// HC-06을 사용; Baud Rate = 9600
// a = 12 = yellow = 좌회전
// w = 11 = blue   = 전진
// s = 10 = orange = 후진
// d = 9 = green  = 우회전
// x = 8  = white  = 정지
// 13번(LED_BUILTIN)은 mode 표시용으로 사용!
// 노랑과 초록을 동시에 누르면 0.5초 딜레이 후 mode 전환
#include <SoftwareSerial.h>
#define yellow  12  // 좌회전:  a
#define blue    11  // 전진:    w
#define red     10  // 후진:    s
#define green   9   // 우회전:  d
#define white   8   // 정지:    x

SoftwareSerial BT(6, 7);  // ArduitnoRX:6, ArduinoTX:7, HC06RX:7, HC06TX: 6
uint8_t signal;
uint8_t mode = 0;             // 0: 기본 디지털 키, 1: 레이싱 모드

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pin_pullup();
  BT.begin(9600);
  // 디버깅
  Serial.begin(9600);
}

void loop() {
  if(!(digitalRead(yellow) || digitalRead(green))){
    mode = !mode;
    delay(500);
  }
  if(mode == 0){
    select_signal_park();
    digitalWrite(LED_BUILTIN, LOW);
  }else if(mode == 1){
    select_signal_race();
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if(signal != 0){  //아무 버튼도 안 눌린 상태면 무시
    BT.write(signal);
    // 디버깅
    Serial.write(signal);
    Serial.print(mode);
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

void select_signal_race(){
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

void select_signal_park(){
  if(!digitalRead(yellow)){

  }else if(!digitalRead(blue)){
    signal = 'i';
  }else if(!digitalRead(red)){
    signal = 'o';
  }else if(!digitalRead(green)){

  }else if(!digitalRead(white)){
    signal = 'x';
  }else{
    signal = 0;
  }
}