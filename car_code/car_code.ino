#include <SoftwareSerial.h>
#define trig 5
#define echo 4
#define IN1Pin 13
#define IN2Pin 12
#define IN3Pin 8
#define IN4Pin 7
#define ENAPin 11
#define ENBPin 10
#define PWM 255         // 모터 속도 pwm 제어, 0-255

unsigned long previousMillis = 0;
const long interval = 1000;

SoftwareSerial hc06(2, 3);
SoftwareSerial hc05(6, 9);

char val; // 블루투스로부터 데이터 수신
char car_move; // 차를 움직이는 블루투스가 읽는 값
float time_intvl, distance; // 초음파 센서 시간 간격, 거리

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
  us_stop();
  dist_measure();
}

void drive(){               // 'a', 'd', 's', 'w'에 따라 차량 움직임
  if(car_move == 's'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, LOW);
  }else if(car_move == 'w'){
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
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
  if(distance < 15){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, HIGH);
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
  //디버깅을 위해서 아래 주석처리 해제
  /*
  Serial.print(distance);
  Serial.println("cm");
  */
}

void communicate(){
  // hc05.listen();
  while(hc05.available()){
    Serial.print("HC05: ");
    Serial.write(hc05.read());
  }

  hc06.listen();
  while(hc06.available()){
    car_move = hc06.read();
    Serial.write(car_move);
  }

  while(Serial.available()){
    val = Serial.read();
    hc05.write(val);
    hc06.write(val);
  }
}