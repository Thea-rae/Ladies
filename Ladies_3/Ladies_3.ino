#define switchPin  2 //coin op switch
#define maxRand  3
#define relayOn 0
#define relayOff 1
// relay control pins
#define relay1  3
#define relay2  4
#define relay3  5
#define relay4  6
#define relay5  7
#define relay6  8
#define relay7  9

//variables to select the different ladies
int switchState = 0;
int ladySelector;
int previousSelector = maxRand;
int returnRate = 5000;
long returnTimer;
int returnRate1 = 5000;
long returnTimer1;
int returnRate2 = 5000;
long returnTimer2;

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
  digitalWrite(relay1, relayOff);
  digitalWrite(relay2, relayOff);
  digitalWrite(relay3, relayOff);
  digitalWrite(relay4, relayOff);
  digitalWrite(relay5, relayOff);
  digitalWrite(relay6, relayOff);
  digitalWrite(relay7, relayOff);
  returnTimer = millis();
  returnTimer1 = millis();
  returnTimer2 = millis();
}

void loop(){
  switchState = digitalRead(switchPin);
  if(switchState == relayOff){
    ladySelection();
    Serial.println(ladySelector);
  }
  else{
    ladySelector = 3;
  }
  lady();
}

void ladySelection(){
  do{
    ladySelector = random(maxRand);
  } 
  while (ladySelector == previousSelector);
  previousSelector = ladySelector;
}


void lady(){
  if ((ladySelector== 0)&&(millis()-returnTimer>returnRate)){
    returnTimer = millis();
    digitalWrite(relay1, relayOn);
    delay(300);
    digitalWrite(relay1, relayOff);
    digitalWrite(relay2, relayOn);
    delay(300);
    digitalWrite(relay2, relayOff);
    digitalWrite(relay3, relayOn);
    delay(300);
    digitalWrite(relay3, relayOff);
    ladySelector = 3;
  }
  if ((ladySelector ==1)&&(millis()-returnTimer1>returnRate1)){
    returnTimer1 = millis();
    digitalWrite(relay4, relayOn);
    delay(300);
    digitalWrite(relay4, relayOff);
    digitalWrite(relay5, relayOn);
    delay(300);
    digitalWrite(relay5, relayOff);
    ladySelector = 3;
  }
  if ((ladySelector == 2)&&(millis()-returnTimer2>returnRate2)){
    returnTimer2 = millis();
    digitalWrite(relay6, relayOn);
    delay(300);
    digitalWrite(relay6, relayOff);
    ladySelector = 3;
  }
  else {
    digitalWrite(relay1, relayOff);
    digitalWrite(relay2, relayOff);
    digitalWrite(relay3, relayOff);
    digitalWrite(relay4, relayOff);
    digitalWrite(relay5, relayOff);
    digitalWrite(relay6, relayOff);
    digitalWrite(relay7, relayOff);
  }
}


