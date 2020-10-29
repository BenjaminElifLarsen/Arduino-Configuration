long oldValue = 0; 
long newValue = 0; 
long delayValue = 0;
long thresholdValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //while(!Serial.available());
  //delayValue = Serial.parseInt();
  //while(!Serial.available());
  //thresholdValue = Serial.parseInt();
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
    }else if(text[0] == 'D'){
      delayValue = atoi(value);
    }
    delay(1000);
    Serial.write(value,6);
  }
  //Serial.write("abcABC",6);
  //delay(1000);
  Serial.write("In Prgs",6);
  delay(1000);
}
