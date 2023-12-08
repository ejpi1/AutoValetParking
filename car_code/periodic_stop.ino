void periodic_stop(){
  uint32_t current_time = millis(); // 지금 시간 측정
  uint16_t duration;
  if(time_to_go){                   // time_to_go일 때 움직임
    duration = move_duration;
  }else{
    duration = stop_duration;
  }

  if((current_time - last_time) >= duration){ // 그동안 흐른 시간이 duration이면
    if(drive_status == 'x'){        // 지금 멈춰있는 상태면
      drive(old_drive_status);      // 이전 운동 상태로 움직임
      time_to_go = 1;               // 다음에는 stop_duration으로
    }else{                          // 지금 움직이는 상태면
      old_drive_status = drive_status;  // 운동 상태 저장
      drive('x');                   // 정지
      time_to_go = 0;               // 다음에는 move_duration으로
    }
    last_time = current_time;       // 시간 갱신
  }
}