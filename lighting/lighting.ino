#define LEDPIN      8
#define FREQUENCY   31 //[Hz]

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  tone(LEDPIN, FREQUENCY);
  delay(1000);
}