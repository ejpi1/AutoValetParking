void drive(char car_move){               // 'a', 'd', 's', 'w'에 따라 차량 움직임
  if(car_move == 'w'){
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
  }else if(car_move == 's'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, LOW);
  }else if(car_move == 'd'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, HIGH);
  }else if(car_move == 'a'){
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, HIGH);
  }else if(car_move == 'x'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, HIGH);
  }
  // 디버깅용
  drive_status = car_move;
}