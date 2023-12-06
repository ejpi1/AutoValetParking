#define LED1        9
#define LED2        11
#define FREQUENCY1  100 //[Hz]
#define FREQUENCY2  300 //[Hz]

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  tone(LED1, FREQUENCY1, 1000);
  tone(LED2, FREQUENCY2, 1000);
}