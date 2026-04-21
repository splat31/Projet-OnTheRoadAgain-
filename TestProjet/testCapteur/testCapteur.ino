#define IR1 2 
#define IR2 3
#define IR3 4

const uint8_t capteur[] = {IR1, IR2, IR3};
uint16_t lu[3];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(IR1, OUTPUT);
  pinMode(IR2, OUTPUT);
  pinMode(IR3, OUTPUT);
  
  Serial.print("\n\n\n\n\nFin init\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nIn the beginning\n");
  lu[0] = lireCapteur(IR1);
  lu[1] = lireCapteur(IR2);
  lu[2] = lireCapteur(IR3);

  Serial.print("1: ");
  Serial.println(lu[0]);
  Serial.print("2: ");
  Serial.println(lu[1]);
  Serial.print("3: ");
  Serial.println(lu[2]);
  Serial.print("\n");
  delay(1000);
}

unsigned int lireCapteur(int capteur){
  pinMode(capteur, OUTPUT);
  digitalWrite(capteur, 1);

  // 10 micro second
  delayMicroseconds(10);

  pinMode(capteur, INPUT);
  digitalWrite(capteur, 0);

  unsigned long t = micros();
  int un;
  //  rajouter un timeout avec un compteur basique et un ou dans le while
  do {
    un = digitalRead(capteur);
  } while (un != 0);

  unsigned long tprime = micros();
  return tprime - t;
}
