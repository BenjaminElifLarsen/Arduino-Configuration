int analogPin = A0;
int groundPin = 13

int delayValue = 0;
int thresholdLevel = 0;
int value = 0;
int del = 0;

void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(groundPin, OUTPUT);
}

void loop() {
  value = analogRead(analogPin);
  if(value <= thresholdLevel) //state changes on input
  {
    if(del + delayValue < millis())
    {
      digitalWrite(groundPin, LOW);
    }
    else
    {
      del = millis();
      digitalWrite(groundPin, HIGH);
    }
  }
  if(Serial.available()) //configuration part. 
  {
    String text = Serial.readString();
    char value[(text.length())-1];
    for(int i = 1; i < text.length(); i++){
      value[i-1] = text[i];
    }
    if(text[0] == 'T'){
      thresholdLevel = atoi(value);
    }else if(text[0] == 'D'){
      delayValue = atoi(value);
    }
  }
}