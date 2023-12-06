void communicate(){
  while(hc05.available()){
    drive(hc05.read());
  }

  while(hc06.available()){
    drive(hc06.read());
  }

  // while(Serial.available()){
  //   serial_data = Serial.read();
  //   hc05.print(serial_data);
  //   hc06.print(serial_data);
  // }
}