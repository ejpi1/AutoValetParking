void light_stop(){
  uint16_t lightpower;
  lightpower = analogRead(A0);
  if(lightpower >= 100){
    drive('x');
    no_periodic();
    act += 1;
  }
  Serial.println(lightpower);
}