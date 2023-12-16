float dist_measure(){
  // 초음파 거리재기
  float time_intvl, distance; // 초음파 센서 시간 간격, 거리
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  time_intvl = pulseIn(echo, HIGH, 10000);
  distance = ((340*time_intvl)/10000)/2;
  return distance;
}

void dist_measuring_debug(){
  Serial.print(dist_measure());
  Serial.println("cm");
}