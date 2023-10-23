/* experimental_lcd.ino
 * By peter Griffin */

/* TODO - adapt to beambreak */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//arbitrary - change to whatever is needed
#define IN_SENS 12

/*system vars*/
LiquidCrystal_I2C lcd(32,16,2);
int marble_count = 0;

/*methods*/
void init_lcd() {
  lcd.setCursor(0,0);
  lcd.print("marbleCt: ");
  lcd.print( String(marble_count) );
}

void marble_entered() {
  marble_count = marble_count + 1;
  
  lcd.setCursor(0,0);
  lcd.print("marbleCt: ");
  lcd.print( String(marble_count) );
  delay(200);
}


/*main*/
void setup() { 
  pinMode(IN_SENS, INPUT);

  //lcd boilerplate
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600); //?
  
  init_lcd();
  //attachInterrupt(digitalPinToInterrupt(IN_SENS), marble_entered, RISING); //huh??
}

void loop() {
  //peter griffin writes this
  //when interrupts work, remove the conditional
  if ( digitalRead(IN_SENS) ) {
    marble_entered();
  }
}
