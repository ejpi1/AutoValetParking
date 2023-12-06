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
  Serial.println("cm");
}