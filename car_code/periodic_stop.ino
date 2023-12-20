// periodic_stop(): 차량을 일정 시간동안 정지, 일정 시간동안 운행을 번갈아 하도록 조정.
// no_periodic(): periodic_stop()을 비활성화

void periodic_stop(){
  uint32_t current_time = millis();     // 지금 시간 측정
  uint16_t duration;

  // 운동 상태
  if(time_to_go){
    duration = move_duration;

  // 정지 상태
  }else{ 
    duration = stop_duration;
  }

  // 그동안 흐른 시간이 duration이면
  if((current_time - last_time) >= duration){

    // 지금 멈춰있는 상태면
    if(drive_status == 'x'){
      drive(old_drive_status);          // 이전 운동 상태로 움직임
      time_to_go = 1;                   // 다음에는 move_duration으로

    // 지금 움직이는 상태면
    }else{
      old_drive_status = drive_status;  // 현재 운동 상태 저장
      drive('x');                       // 정지
      time_to_go = 0;                   // 다음에는 stop_duration으로
    }

    last_time = current_time;           // 시간 갱신
  }
}

void no_periodic(){
  old_drive_status = 'x';               // 앞으로 움직이지 않도록
  time_to_go = 1;                       // 다음 이동을 위해 move_duration으로 저장
  old_hc05_data = 0;                    // hc05 데이터 읽을 준비
}