// light_stop(): 적외선 센서의 값이 일정 이상이면 차량 정지, 다음 act로 진행.

void light_stop(){
  uint16_t lightpower;
  lightpower = analogRead(A0);

  // 만약 적외선 센서가 주차장 적외선 LED에 일정 이상 가까워지면
  if(lightpower >= 100){
    drive('x');                       // 정지
    no_periodic();                    // periodic_stop() 비활성화
    act += 1;                         // 다음 act로 진행
  }
  
  // Serial.print("light: ");
  // Serial.println(lightpower);
}