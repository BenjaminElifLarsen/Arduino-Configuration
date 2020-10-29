int delayValue = 0;
int thresholdValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(Serial.available()){
    String text = Serial.readString();
    char value[(text.length())-1];
    for(int i = 1; i < text.length(); i++){
      value[i-1] = text[i];
    }
    if(text[0] == 'T'){
      thresholdValue = atoi(value);
    }else if(text[0] == 'D'){
      delayValue = atoi(value);
    }
  }
  delay(1000);
}
