#define acceleration_interval 100
#define acceleration_increment 5

float max_speed {4000};
unsigned long previous_time {0};

void stepper_init() {
  stepper.setMaxSpeed(max_speed);
  stepper.setSpeed(10);
  previous_time = millis();
}


void stepper_update () {
  if (stepper.speed() > max_speed) {
    stepper.setSpeed(max_speed);
    
  } else if (stepper.speed() < max_speed && (millis() - previous_time) > acceleration_interval) {
      stepper.setSpeed(stepper.speed() + acceleration_increment);
      previous_time = millis();
  }

  stepper.runSpeed();
  }

