#define PHOTOPIN A0
uint16_t photo_data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  photo_data = analogRead(PHOTOPIN);
  Serial.println(photo_data);
}
