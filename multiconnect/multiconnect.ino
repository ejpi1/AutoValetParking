#include <SoftwareSerial.h>
SoftwareSerial bluetooth1(2,3);
SoftwareSerial bluetooth2(10,11);

char serial_data;

void setup() {
  Serial.begin(38400);
  bluetooth1.begin(38400);
  bluetooth2.begin(38400);
}



void loop() {
  bluetooth1.listen();
  while(bluetooth1.available()){
    Serial.write(bluetooth1.read());
  }

  bluetooth2.listen();
  while(bluetooth2.available()){
    Serial.write(bluetooth2.read());
  }

  while(Serial.available()){
    serial_data = Serial.read();
    bluetooth1.write(serial_data);
    bluetooth2.write(serial_data);
  }
}