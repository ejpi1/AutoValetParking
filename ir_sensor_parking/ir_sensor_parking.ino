int Sensor1 = 7;    // 
int Sensor2 = 9;    // 센서핀은 9번에 연결
int Sensor3 = 11;
int val;
 
void setup () {  
  pinMode(Sensor1, INPUT);    // 센서값을 입력으로 설정
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
}
 
void loop () {
  //val = digitalRead(Sensor);  // 센서값 읽어옴
 // if (val == HIGH) {          // 장애물 감지가 안되면
    //digitalWrite(led_red,LOW);                // 버저가 울리지 않는다
   // delay(100);
 // } else {                    // 장애물이 감지되면
   // digitalWrite(led_red,HIGH);         // 버저가 울린다
   // delay(100);
 // }
}
