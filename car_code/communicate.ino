void communicate(){
  while(hc05.available()){
    hc05_data = hc05.read();
    if(hc05_data != old_hc05_data){
      drive(hc05_data);
      old_hc05_data = hc05_data;
      last_time = millis();
      time_to_go = 1;
    }
  }

  while(hc06.available()){
    hc06_data = hc06.read();
    if(hc06_data != old_hc06_data){
      drive(hc06_data);
      old_hc06_data = hc06_data;
    }
  }

  // while(Serial.available()){
  //   serial_data = Serial.read();
  //   hc05.print(serial_data);
  //   hc06.print(serial_data);
  // }
}

void emergency_stop() {
  if (hc05_data == 'x') {
    drive('x');               // 차량 정지
    no_periodic();
  }
}