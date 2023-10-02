int controllPin {3};

void setup() {
  pinMode(controllPin, OUTPUT);
}

void loop() {
    analogWrite(controllPin, 50);
    delay(1000);
    analogWrite(controllPin, 0);
    delay(1000);
    analogWrite(controllPin, 255);
    delay(1000);
}
