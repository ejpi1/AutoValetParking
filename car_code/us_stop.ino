void us_stop(){                 // 초음파 거리가 일정 미만이면 차량 정지
  if((distance < 15) && (distance > 1)){
    drive('x');
  }
  dist_measure();
}