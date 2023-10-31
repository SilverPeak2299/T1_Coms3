
#define pos_0 0
#define pos_1 40

#define interval 500


unsigned long int prev_time {0};
byte pos = 0;

void servo_init() {
  myservo.attach(servo_pin);
  prev_time = millis();
}

void servo_update() {
  //if (millis() - prev_time < interval) { return; }

  switch (pos) {
    case 0:
      myservo.write(pos_1);
      pos = 1;
      break;

    case 1:
      myservo.write(pos_0);
      pos = 0;
      break;
  }

  prev_time = millis();
  }