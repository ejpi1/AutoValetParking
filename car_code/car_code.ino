#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#define trig 5
#define echo 4
#define IN1Pin 13       // LOW일 때 우륜 전진
#define IN2Pin 12       // LOW일 때 우륜 후진
#define IN3Pin 10       // LOW일 때 좌륜 전진
#define IN4Pin 7        // LOW일 때 좌륜 후진
#define ENAPin 11       // PWM 가능한 pin (11, 10, 9, 6, 5, 3)
#define ENBPin 6        // PWM 가능한 pin (11, 10, 9, 6, 5, 3)
#define PWM 255         // 모터 속도 pwm 제어, 0-255

SoftwareSerial hc06(2, 3);  // RX:2, TX:3
AltSoftSerial hc05;         // RX:8, TX:9, 10번 pin에서 PWM 못씀! 그냥 입출력은 가능
                            // AltSoftSerial은 write()에서 문제있음

char serial_data; // Serial Monitor로부터 데이터 수신
char car_move = 0; // 차를 움직이는 블루투스가 읽는 값
float time_intvl, distance; // 초음파 센서 시간 간격, 거리
uint16_t counter = 0;

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  hc06.begin(9600);
  hc05.begin(9600); //
  pinMode(IN1Pin, OUTPUT);  // 각 핀에 대한 출력값 설정
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  analogWrite(ENAPin, PWM);
  analogWrite(ENBPin, PWM);
}

void loop() {
  drive();
  communicate();
  // 주석 해제 시 거리 감지 제동 활성화
  us_stop();
  debug();
}

void debug(){
  // dist_measuring_debug();
  // Serial.print("counter: ");
  // Serial.print(counter);
  // Serial.print("car_move: ");
  // Serial.println(car_move);
}