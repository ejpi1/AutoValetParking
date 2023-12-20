// us_stop(): 거리가 일정 미만이면 정지한다.
// dist_measure(): HC-SR04로 거리를 측정해 반환한다.
// dist_measuring_debug(): 거리 측정 디버깅용

void us_stop(){
  float distance;
  distance = dist_measure();

  if((distance < 5) && (distance > 1)){     // 가급적 3cm미만까지 내리지 말 것
    drive('x');
    no_periodic();
  }
}

float dist_measure(){
  // 거리를 측정해 [cm]로 반환
  float time_intvl, distance;               // 초음파 센서 시간 간격, 거리
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  time_intvl = pulseIn(echo, HIGH, 10000);  // 10ms이상 echo가 1로 안바뀌면 0 반환
  distance = ((340*time_intvl)/10000)/2;    // 거리 = 음속*시간/2
  return distance;
}

void dist_measuring_debug(){
  Serial.print(dist_measure());
  Serial.println("cm");
}