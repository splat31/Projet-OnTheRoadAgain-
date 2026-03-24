

#define LED 8

int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  i = 1000;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  delay(i);

  digitalWrite(LED,LOW);
  delay(i);

  if (i > 250){
    i -= 50;
  }
  
}
