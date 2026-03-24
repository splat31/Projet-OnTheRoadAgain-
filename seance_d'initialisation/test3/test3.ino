#define LED 6
int power = 0;
int step = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED,power);
  power=power+step;
  if (power<=0||power>=255) {
    step=-step;
  }
  delay(10);
}
