//Main File for the arduino project
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include <LinkedList.h>
#include <AccelStepper.h>
#include <Servo.h>
#include <Wire.h>

#define led_count 29 // number od LEDs on LED strip
#define avg_time 7000 // average time it takes to process a marble in milliseconds

// Defining Pins
#define entry_input 2
#define exit_input 3
#define led_pin 11
#define servo_pin 10

// Stepper Pins
#define STEPPER_PIN_1 7
#define STEPPER_PIN_2 6
#define STEPPER_PIN_3 5
#define STEPPER_PIN_4 4
int step_number = 0;


// Components
LiquidCrystal_I2C lcd(0x27,16,2); // LCD
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_count, led_pin, NEO_GRB + NEO_KHZ800); // LED Strip
//AccelStepper stepper(AccelStepper::FULL4WIRE, s_1, s_2, s_3, s_4);
Servo myservo;

// Variables
unsigned long marble_count {0};
int entry_rising = 0;
//int exit_rising = 0;
int tick = 0;

void setup() {
  //pin settup
  pinMode(entry_input, INPUT);
  digitalWrite(entry_input, HIGH);
  pinMode(exit_input, INPUT);

  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);


  //attachInterrupt(digitalPinToInterrupt(entry_input), marble_entry, LOW);
  //attachInterrupt(digitalPinToInterrupt(exit_input), marble_exit, FALLING);

  // settup funcitons
  init_lcd(); // Setting up the LCD in lcd.ino
  led_init();
  //stepper_init();
  servo_init();
}

void loop() {
  //stepper_update();
  //marble_entry();
  OneStep(false);

  servo_update();
  

  if (tick == 0) {
    if (digitalRead(entry_input) == LOW && entry_rising == 0) {
      marble_entry();
      entry_rising = 1;
    } else {entry_rising = 0;}
  
    //exit beambreak does not work so we have omitted this
    /*
    if (digitalRead(exit_input) == LOW && exit_rising == 0) {
      marble_exit();
      exit_rising = 1;
    } else {exit_rising = 0;}
    */
  }
  //TODO - REMOVE MAGIC NUMBER (idk what im doing hlep)
  tick = (tick + 1) % 30;
  delay(2);

  //if (digitalRead(exit_input) == LOW) {
    //marble_exit();
  //}

}

//Interupt Functions
void marble_entry() {
  marble_count++;

  //led_add_marble();
  update_lcd();
  //servo_update();
}

void marble_exit () {
  marble_count--;

  //led_remove_marble();
  update_lcd();
}


