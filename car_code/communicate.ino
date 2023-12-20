void communicate(){
  while(hc05.available()){
    hc05_data = hc05.read();
    if(hc05_data != old_hc05_data){
      if(hc05_data == 'i'){
        act = 1;
        drive('w');
        hc06.write('h');
        last_time = millis();
      }else if(hc05_data == 'o'){
        act = 4;
        drive('s');
        delay(150);
        hc06.write('h');
        last_time = millis();
      }else if(hc05_data == 'e'){
        emergency_stop();
      }else{
        drive(hc05_data);
      }
      old_hc05_data = hc05_data;
      // last_time = millis();
      // time_to_go = 1;
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

void emergency_stop(){
  drive('x');           // 차량 정지
  no_periodic();
  act = 0;
  hc06.write('0');
}