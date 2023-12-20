// communicate(): HC-05와 HC-06(블루투스)에서 문자열을 읽어들인다.
// emergency_stop(): 차량을 정지시키고, act를 초기 상태로 초기화한다.

void communicate(){
  // hc05_data와 hc06_data에 수신 문자 저장, 기타 명령 수행

  while(hc05.available()){
    hc05_data = hc05.read();

    // hc05에서 읽어온 값이 중복되는 문자열일 경우, 처음 문자에만 반응한다.
    if(hc05_data != old_hc05_data){

      switch(hc05_data){

        // 주차 신호 'i'n
        case 'i':
          act = 1;                  // 1. 진입
          drive('w');               // 전진
          hc06.write('h');          // 주차장의 주차 감지 및 적외선 발산 활성화 (cf. parking_signal/parking_signal.ino)
          last_time = millis();     // periodic_stop() 시간 갱신
          break;

        // 출차 신호 'o'ut
        case 'o':
          act = 4;                  // 4. 출차
          drive('s');               // 후진
          delay(300);               // 주차장 적외선 거리 센서와 간섭 방지
          hc06.write('h');          // 주차장의 주차 감지 및 적외선 발산 활성화 (cf. parking_signal/parking_signal.ino)
          last_time = millis();     // periodic_stop() 시간 갱신
          break;

        // 긴급 정지 신호 'e'mergency
        case 'e':
          emergency_stop();
          break;

        // i, o, e가 아니라면
        default:
          drive(hc05_data);         // 레이싱 모드 (cf. remote_controller/remote_controller.ino)
          break;
      }

      old_hc05_data = hc05_data;    // 중복되는 문자열인지 확인하기 위해 현재 문자 저장
    }
  }

  while(hc06.available()){
    hc06_data = hc06.read();

    // hc06에서 읽어온 값이 중복되는 문자열일 경우, 처음 문자에만 반응한다.
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
  drive('x');                       // 차량 정지
  no_periodic();                    // periodic_stop() 비활성화
  act = 0;                          // 0. 초기
  hc06.write('0');                  // 주차장의 주차 감지 및 적외선 발산 비활성화 (cf. parking_signal/parking_signal.ino)
}