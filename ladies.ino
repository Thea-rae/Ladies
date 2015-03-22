const int switchPin = 2; //coin opp switch

// relay control pins
// lady with book {
const int relay1 = 3;
const int relay2 = 4;
const int relay3 = 5;
//}
// lady dancing{
const int relay4 = 6;
const int relay5 = 7;
//}
// lady on cell phone{
const int relay6 = 8;
const int relay7 = 9;
//}

//varriables to select the different ladies
int switchState = 0;
int ladySelector = 0;

void setup(){
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
}

void loop(){
  switchState = digitalRead(switchPin);

  if(switchState == HIGH){
    ladySelector= random(1,3);
    Serial.println(ladySelector);
  }
  lady();
  delay(1000);
}

void lady(){
  switch(ladySelector){
  case 1:
    digitalWrite(relay1, LOW);
    delay(100);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    delay(100);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, LOW);
    delay(100);
    digitalWrite(relay3, HIGH);
    break;
  case 2:
    digitalWrite(relay4, LOW);
    delay(300);
    digitalWrite(relay5, LOW);
    delay(300);
    break;
  case 3:
    digitalWrite(relay6, LOW);
    delay(500);
    digitalWrite(relay7, LOW);
    delay(500);
    break;
  default:
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    digitalWrite(relay5, HIGH);
    digitalWrite(relay6, HIGH);
    digitalWrite(relay7, HIGH);
  }
}


