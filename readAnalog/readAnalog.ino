int analogPin = A0;
int groundPin = 13;

int value = 0;
unsigned long del = 0;
int thressholdLevel = 25; //from monitor when the feedback is off.

void setup() {
  // put your setup code here, to run once:
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(groundPin, OUTPUT);
}

void loop() { //if microphone feedback is off some noise is present.
  // put your main code here, to run repeatedly:
  value = analogRead(analogPin);
  if (value <= thressholdLevel )
  {
    Serial.println(0);

    if (del + 100 < millis() )
    {
      digitalWrite(groundPin, LOW);
    }
  }
  else
  {
    del = millis();
    Serial.println(value);
    digitalWrite(groundPin, HIGH);
  }
}
