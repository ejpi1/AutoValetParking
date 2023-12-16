void us_stop(){                 // 초음파 거리가 일정 미만이면 차량 정지
  float distance;
  distance = dist_measure();
  if((distance < 5) && (distance > 1)){   // 가급적 3cm미만까지 내리지 말 것
    drive('x');
    no_periodic();
  }
}