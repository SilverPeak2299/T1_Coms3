//Main File for the arduino project
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include <LinkedList.h>
#include <AccelStepper.h>
#include <Servo.h>


#define led_count 29 // number od LEDs on LED strip
#define avg_time 7000 // average time it takes to process a marble in milliseconds


// Defining Pins
#define entry_input 2
#define exit_input 3
#define led_pin 5
#define servo_pin 8

// Components
LiquidCrystal_I2C lcd(0x27,16,2); // LCD
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_count, led_pin, NEO_GRB + NEO_KHZ800); // LED Strip
AccelStepper stepper;
Servo myservo;

// Variables
int marble_count {0};

void setup() {
  //pin settup
  pinMode(entry_input, INPUT_PULLUP);
  pinMode(exit_input, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(entry_input), marble_entry, RISING);
  attachInterrupt(digitalPinToInterrupt(exit_input), marble_exit, RISING);

  // settup funcitons
  init_lcd(); // Setting up the LCD in lcd.ino
  led_init();
  stepper_init();
  servo_init();
}

void loop() {
  stepper_update();
}

// Interupt Functions
void marble_entry() {
  marble_count++;

  led_add_marble();
  update_lcd();
  servo_update();
}

void marble_exit () {
  marble_count--;

  led_remove_marble();
  update_lcd();
}


