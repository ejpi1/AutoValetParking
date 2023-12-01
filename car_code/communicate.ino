void communicate(){
  while(hc05.available()){
    car_move = hc05.read();
    // Serial.write(car_move);
  }

  while(hc06.available()){
    car_move = hc06.read();
    // Serial.write(car_move);
  }

  // while(Serial.available()){
  //   serial_data = Serial.read();
  //   hc05.print(serial_data);
  //   hc06.print(serial_data);
  // }
}