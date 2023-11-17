#define PWM_CONSTANT 200

int IN1Pin = 13;
int IN2Pin = 12;
int IN3Pin = 8;
int IN4Pin = 7;
int ENAPin = 11;
int ENBPin = 10;

char in_data;					//입력된 데이터 저장을 위한 변수

void setup(){
  Serial.begin(9600);
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  analogWrite(ENAPin, PWM_CONSTANT);
  analogWrite(ENBPin, PWM_CONSTANT);
}

void loop(){
  if(Serial.available()){		//시리얼모니터에서 데이터가 들어오면
    in_data = Serial.read();	//입력된 데이터 in_data에 저장
    Serial.println(in_data);
    Serial.print("data : ");
    if(in_data == 's'){			//후진
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, LOW);
    }else if(in_data == 'w'){	//전진
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, LOW);
      digitalWrite(IN4Pin, HIGH);
    }else if(in_data == 'd'){	//우회전
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, LOW);
      digitalWrite(IN4Pin, HIGH);
    }else if(in_data == 'a'){	//좌회전
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, LOW);
    }else if(in_data == 'x'){	//정지
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, HIGH);
    }
  }
}