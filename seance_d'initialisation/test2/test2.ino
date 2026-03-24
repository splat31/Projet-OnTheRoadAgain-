
#define BUT 2
#define LED 8

int pushed = 0;
bool allume = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUT, INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUT)==HIGH){
    pushed=1;
  }
  else if (pushed) {
    Serial.println("Clicked\n");
    if (allume) {
      digitalWrite(LED,LOW);
      allume = false;
       Serial.println("j'ai eteint\n");
    } else {
      digitalWrite(LED,HIGH);
       Serial.println("j'ai allume\n");
      allume = true;
    }
    pushed=0;
  }

}
