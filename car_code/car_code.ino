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

  if(counter == 10){
    dist_measure();
    // dist_measuring_debug();
    counter = 0;
  }
  counter++;
  // Serial.print("counter: ");
  // Serial.print(counter);
  // Serial.print("car_move: ");
  // Serial.println(car_move);
}

void drive(){               // 'a', 'd', 's', 'w'에 따라 차량 움직임
  if(car_move == 'w'){
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
  }else if(car_move == 's'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, LOW);
  }else if(car_move == 'd'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
  }else if(car_move == 'a'){
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, LOW);
  }else if(car_move == 'x'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, HIGH);
  }
}

void us_stop(){                 // 초음파 거리가 일정 미만이면 차량 정지
  if((distance < 15) && (distance > 1)){
    car_move = 'x';
  }
}

void dist_measure(){            // 초음파 거리재기
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  time_intvl = pulseIn(echo, HIGH);
  distance = ((340*time_intvl)/10000)/2;
}

void dist_measuring_debug(){
  Serial.print(distance);
  Serial.print("cm");
}

void communicate(){
  while(hc05.available()){
    car_move = hc05.read();
    // Serial.write(car_move);
  }

  while(hc06.available()){
    car_move = hc06.read();
    // Serial.write(car_move);
  }

  // while(Serial.available()){
  //   serial_data = Serial.read();
  //   hc05.print(serial_data);
  //   hc06.print(serial_data);
  // }
}