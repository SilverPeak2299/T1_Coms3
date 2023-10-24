
//Main File for the arduino project
#include <LiquidCrystal_I2C.h>

// Defining Pins
#define entry_input 2
#define exit_input 3
//function prototypes


// Components
LiquidCrystal_I2C lcd(0x27,16,2);

// Variables
int marble_count {0};


void setup() {
  //pin settup
  pinMode(entry_input, INPUT_PULLUP);
  pinMode(exit_inpit, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(entry_input), marble_entry, RISING);
  attachInterrupt(digitalPinToInterrupt(exit_input), marble_exit, RISING);

  // settup funcitons
  init_lcd(); // Setting up the LCD in lcd.ino
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Interupt Functions

void marble_entry() {
  marble_count++;
 
  update_lcd();
}

void marble_exit () {
  marble_count--;

  update_lcd();
}


