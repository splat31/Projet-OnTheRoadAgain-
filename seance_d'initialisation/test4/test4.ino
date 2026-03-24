#define PHOTO A0
#define LED 8
#define MIN 250
#define MAX 450

bool allume = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(PHOTO);
  Serial.print("light :");
  Serial.println(x);

  if (x <= MIN){
    digitalWrite(LED, HIGH);
    if (!allume){
      Serial.println("J'allume");
    }
    allume = true;
    

  } else if(x >= MAX){
    digitalWrite(LED, LOW);
    if (allume){
      Serial.println("J'eteint");
    }
    allume = false;
  }


  delay(200);
}
