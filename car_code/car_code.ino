#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#define trig 11
#define echo 4
#define IN1Pin 13       // LOW일 때 우륜 전진
#define IN2Pin 12       // LOW일 때 우륜 후진
#define IN3Pin 10       // LOW일 때 좌륜 전진
#define IN4Pin 7        // LOW일 때 좌륜 후진
#define ENAPin 6        // PWM 가능한 pin (11, 10, 9, 6, 5, 3)
#define ENBPin 5        // PWM 가능한 pin (11, 10, 9, 6, 5, 3)
#define PWM_forward 100 // 전진, 후진 시 PWM
#define PWM_left 140    // 회전 시 좌륜 PWM, 일반적으로 좌륜에 더 많은 부하가 걸림
#define PWM_right 120   // 회전 시 우륜 PWM

SoftwareSerial hc06(2, 3);  // RX:2, TX:3
AltSoftSerial hc05;         // RX:8, TX:9, 10번 pin에서 PWM 못씀! 그냥 입출력은 가능
                            // AltSoftSerial은 write()에서 문제있음

char serial_data; // Serial Monitor로부터 데이터 수신
char drive_status = 'x';    // drive()를 수행하는 값
char old_hc05_data = 0;
char hc05_data;
char old_hc06_data = 0;
char hc06_data;
float time_intvl, distance; // 초음파 센서 시간 간격, 거리

uint8_t time_to_go;
char old_drive_status = 'x';

uint32_t last_time = 0;         // millis()가 4바이트 정수임
uint16_t stop_duration = 1000;  // 정지 시간 [ms]
uint16_t move_duration = 300;   // 움직이는 시간 [ms]

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  hc06.begin(9600);
  hc05.begin(9600);
  pinMode(IN1Pin, OUTPUT);  // 각 핀에 대한 출력값 설정
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
}

void loop() {
  communicate();
  // 주석 해제 시 거리 감지 제동 활성화
  us_stop();
  periodic_stop();
  emergency_stop();
  debug();
}

void debug(){
  // dist_measuring_debug();
  // Serial.print("counter: ");
  // Serial.print(counter);
  // Serial.print("drive_status: ");
  // Serial.println(drive_status);
}