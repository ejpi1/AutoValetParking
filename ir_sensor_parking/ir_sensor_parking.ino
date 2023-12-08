int Sensor1 = 7;    
int Sensor2 = 9;    
int Sensor3 = 11;
//int Button = 13;
//int val;
 
void setup () {  
  //Serial.begin(9600);
  pinMode(Sensor1, INPUT);    
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  //pinMode(Button, INPUT_PULLUP); // 장애인 주차구역 스위치로 조정
}
 
void loop () {
  //int buttonstate = digitalRead(Button);
  //Serial.println(buttonstate);
  //if (buttonstate == 0){
  //  pinMode(Sensor3, INPUT);
  //}
  //delay(1);
  //val = digitalRead(Sensor);  // 센서값 읽어옴
 // if (val == HIGH) {          // 장애물 감지가 안되면
    //digitalWrite(led_red,LOW);                // 버저가 울리지 않는다
   // delay(100);
 // } else {                    // 장애물이 감지되면
   // digitalWrite(led_red,HIGH);         // 버저가 울린다
   // delay(100);
 // }
}
