int analogPin = A0;
int groundPin = 13;

int delayValue = 200;
int thresholdLevel = 20;
int value = 0;
int del = 0;

void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(groundPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  value = analogRead(analogPin);
  Serial.println(value);
  if(value <= thresholdLevel) //state changes on input
  {
    if(del + delayValue < millis())
    {
      digitalWrite(groundPin, LOW);
    }
  }
  else
  {
    del = millis();
    digitalWrite(groundPin, HIGH);
  }
  if(Serial.available()) //configuration part. 
  {
    String text = Serial.readString();
      analogWrite(LED_BUILTIN,200);
    if(text[0] == 'A')
    {
      delay(2000);
      Serial.write("I AM HERE",9);
    }
    else
    {
      char value[(text.length())-1];
      for(int i = 1; i < text.length(); i++){
        value[i-1] = text[i];
      }
      if(text[0] == 'T'){
        thresholdLevel = atoi(value);
      }
      if(text[0] == 'D'){
        delayValue = atoi(value);
      }
      delay(1000);
    }
  }
}
