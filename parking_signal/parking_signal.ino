#include <SoftwareSerial.h>
int shoot1 = 8;  //적외선 방출핀 1
int shoot2 = 9;  //적외선 방출핀 2
int shoot3 = 10; //적외선 방출핀 3
char info;
SoftwareSerial BTSerial(11, 12);
int parkingsensor1 = 4; //주차 유무 확인 적외선 센서1
int parkingsensor2 = 5; //주차 유무 확인 적외선 센서2
int parkingsensor3 = 6; //주차 유무 확인 적외선 센서3
int val1;
int val2;
int val3;


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(shoot1,OUTPUT);
  pinMode(shoot2,OUTPUT);
  pinMode(shoot3,OUTPUT);
  pinMode(parkingsensor1,INPUT);
  pinMode(parkingsensor2,INPUT);
  pinMode(parkingsensor3,INPUT);
}

void parking_sensor(){
  val1 = digitalRead(parkingsensor1);
  val2 = digitalRead(parkingsensor2);
  val3 = digitalRead(parkingsensor3);
  if (val1 == LOW){ // 1번 자리 주차가 되어있으면 
  digitalWrite(shoot1,LOW); //적외선 x
  delay(10);
  }else{
    digitalWrite(shoot1,HIGH); //안되어 있으면 적외선 o
    delay(10);
  }
  if (val2 == LOW){ // 2번 자리 주차가 되어있으면
    digitalWrite(shoot2,LOW); //적외선 x
    delay(10);
  }else{
    digitalWrite(shoot2,HIGH); //안되어 있으면 적외선 o
    delay(10);
  }
  if (val3 == LOW){ // 3번 자리 주차가 되어있으면
    digitalWrite(shoot3,LOW); //적외선 x
    delay(10);
  }else{
    digitalWrite(shoot3,HIGH); //안되어 있으면 적외선 o
    delay(10);
  }
}
void normal_state(){ //차량에서 신호 없으면 평소에 적외선 x
  digitalWrite(shoot1,LOW);
  digitalWrite(shoot2,LOW);
  digitalWrite(shoot3,LOW);
}


void loop() {
  if(BTSerial.available()){
    info = BTSerial.read();
  }
    if (info == 'h'){ //블루투스 신호값이 'h'일때, 적외선 시스템 가동
    parking_sensor();
    }else{ //아닐 시 적외선 x
      normal_state();
    }
    delay(10);
   // Serial.println(val1);
    //Serial.println(val2);
    //Serial.println(val3);
  //if(Serial.available()){
  //BTSerial.write(Serial.read());
}

