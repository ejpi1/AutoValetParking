// drive(): 입력 방향에 따라 차량을 영구적으로 움직인다. 같은 상태로 유지
// move(): 입력 방향과 시간에 따라 차량을 일시적으로 움직인다. 명령 수행 후 정지 상태로 변경.

void drive(char car_move){
  // 'a', 'd', 's', 'w'에 따라 차량 움직임

  switch(car_move){
    case 'w':
      analogWrite(ENAPin, PWM_forward);
      analogWrite(ENBPin, PWM_forward);
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, LOW);
      digitalWrite(IN4Pin, HIGH);
      break;
    case 's':
      analogWrite(ENAPin, PWM_forward);
      analogWrite(ENBPin, PWM_forward);
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, LOW);
      break;
    case 'd':
      analogWrite(ENAPin, PWM_right);
      analogWrite(ENBPin, PWM_left);
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, LOW);
      digitalWrite(IN4Pin, HIGH);
      break;
    case 'a':
      analogWrite(ENAPin, PWM_right);
      analogWrite(ENBPin, PWM_left);
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, LOW);
      break;
    case 'x':
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, HIGH);
      break;
    default:
      break;
  }

  drive_status = car_move;
}

void move(uint16_t move_time, char direction){
  // move_time[ms]만큼 direction(r, l) 방향으로 회전 또는 direction(f, b) 방향으로 전후진

  switch(direction){
    case 'r':
      drive('d');
      break;
    case 'l':
      drive('a');
      break;
    case 'f':
      drive('w');
      break;
    case 'b':
      drive('s');
      break;
    default:
      break;
  }

  delay(move_time);
  drive('x');
}