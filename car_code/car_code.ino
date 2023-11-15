int IN1Pin = 13;
int IN2Pin = 12;
int IN3Pin = 11;
int IN4Pin = 10;
int ENAPin = A0;
int ENBPin = A1;

char in_data;             // 입력된 데이터 저장을 위한 변수

void setup(){
  Serial.begin(9600);
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  analogWrite(ENAPin, 255);
  analogWrite(ENBPin, 255);
}
void loop(){
  if(Serial.available()){  //시리얼모니터에서 데이터가 들어오면
    in_data = Serial.read();  //입력된 데이터 in_data에 저장
    Serial.println(in_data);
    Serial.print("data : ");
      if(in_data == 's'){
        digitalWrite(IN1Pin, HIGH);
        digitalWrite(IN2Pin, LOW);
        digitalWrite(IN3Pin, HIGH);
        digitalWrite(IN4Pin, LOW);
        delay(1000);
      }else if(in_data == 'w'){
        digitalWrite(IN1Pin, LOW);
        digitalWrite(IN2Pin, HIGH);
        digitalWrite(IN3Pin, LOW);
        digitalWrite(IN4Pin, HIGH);
        delay(1000);
      }else if(in_data == 'd'){
        digitalWrite(IN1Pin, HIGH);
        digitalWrite(IN2Pin, LOW);
        digitalWrite(IN3Pin, LOW);
        digitalWrite(IN4Pin, HIGH);
      }else if(in_data == 'a'){
        digitalWrite(IN1Pin, LOW);
        digitalWrite(IN2Pin, HIGH);
        digitalWrite(IN3Pin, HIGH);
        digitalWrite(IN4Pin, LOW);
      }else if(in_data == 'x'){
        digitalWrite(IN1Pin, HIGH);
        digitalWrite(IN2Pin, HIGH);
        digitalWrite(IN3Pin, HIGH);
        digitalWrite(IN4Pin, HIGH);
      }
  }
}