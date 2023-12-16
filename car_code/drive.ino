void drive(char car_move){
  // 'a', 'd', 's', 'w'에 따라 차량 움직임
  if(car_move == 'w'){
    analogWrite(ENAPin, PWM_forward);
    analogWrite(ENBPin, PWM_forward);
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
  }else if(car_move == 's'){
    analogWrite(ENAPin, PWM_forward);
    analogWrite(ENBPin, PWM_forward);
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, LOW);
  }else if(car_move == 'd'){
    analogWrite(ENAPin, PWM_right);
    analogWrite(ENBPin, PWM_left);
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
  }else if(car_move == 'a'){
    analogWrite(ENAPin, PWM_right);
    analogWrite(ENBPin, PWM_left);
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, LOW);
  }else if(car_move == 'x'){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, HIGH);
  }
  drive_status = car_move;
}

void move(uint16_t move_time, char direction){
  // move_time[ms]만큼 direction(r, l) 방향으로 회전 또는 direction(f, b) 방향으로 전후진
  // drive와는 다르게 일시적인 움직임 후 정지
  if(direction == 'r'){
    drive('d');
  }else if(direction == 'l'){
    drive('a');
  }else if(direction == 'f'){
    drive('w');
  }else if(direction == 'b'){
    drive('s');
  }
  delay(move_time);
  drive('x');
}