int delayValue = 0;
int thresholdValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //while(!Serial.available());
  //delayValue = Serial.parseInt();
  //while(!Serial.available());
  //thresholdValue = Serial.parseInt();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(Serial.available())
  //  newValue = Serial.parseInt();
  //if(newValue != oldValue){
  //  Serial.println(newValue);
  //  oldValue = newValue;
  //}
  //else
  //  Serial.println(oldValue);
  if(Serial.available()){//does not transmit data back each time data is transmitted to it
    String text = Serial.readString();
    char value[(text.length())-1];
    for(int i = 1; i < text.length(); i++){
      value[i-1] = text[i];
    }
    if(text[0] == 'T'){
      thresholdValue = atoi(value);
      //analogWrite(LED_BUILTIN,thresholdValue);
    }else if(text[0] == 'D'){
      delayValue = atoi(value);
      //analogWrite(LED_BUILTIN,delayValue);
    }
    //Serial.write(value,6);
  }
  int test1 = thresholdValue;
  int test2 = delayValue;
  Serial.print(test1);
  Serial.print(test2);
  //Serial.write("abcABC",6);
  //delay(1000);
  //Serial.write("In Prgs",6);
  delay(1000);
}
