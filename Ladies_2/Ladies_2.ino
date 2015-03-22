const int switchPin = 2; //coin opp switch
const int maxRand = 2;

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

//variables to select the different ladies
int switchState = 0;
int ladySelector;
int previousSelector = maxRand;
int returnRate = 2000;
int returnTimer;
int returnRate1 = 2000;
int returnTimer1;
int returnRate2 = 2000;
int returnTimer2;

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
  returnTimer = millis();
  returnTimer1 = millis();
  returnTimer2 = millis();
}

void loop(){
  if(switchState == HIGH){
    ladySelection();
  }

  lady();
  Serial.println(ladySelector);
}

void ladySelection(){
  do{
    ladySelector = random(maxRand);
  } 
  while (ladySelector == previousSelector);
  previousSelector = ladySelector;
  Serial.println(ladySelector);
}


void lady(){
  switch(ladySelector){
  case 0:
    if (millis()-returnTimer>returnRate){
      returnTimer = millis();
      digitalWrite(relay1, LOW);
      delay(300);
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);
      delay(300);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, LOW);
      delay(300);
      digitalWrite(relay3, HIGH);
      ladySelector = 3;
    }
    break;
  case 1:
    if (millis()-returnTimer1>returnRate1){
      returnTimer1 = millis();
      digitalWrite(relay4, LOW);
      delay(300);
      digitalWrite(relay4, HIGH);
      digitalWrite(relay5, LOW);
      delay(300);
      digitalWrite(relay5, HIGH);
      ladySelector = 3;
    }
    break;
  case 2:
    if (millis()-returnTimer2>returnRate2){
      returnTimer2 = millis();
      digitalWrite(relay6, LOW);
      delay(300);
      digitalWrite(relay6, HIGH);
      ladySelector = 3;
    }
    break;
  case 3:
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    digitalWrite(relay5, HIGH);
    digitalWrite(relay6, HIGH);
    digitalWrite(relay7, HIGH);
  }
}




