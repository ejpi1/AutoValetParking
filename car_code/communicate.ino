void communicate(){
  while(hc05.available()){
    hc05_data = hc05.read();
    if(hc05_data != old_hc05_data){
      drive(hc05_data);
      old_hc05_data = hc05_data;
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