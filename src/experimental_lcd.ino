#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define IN_SENS 12

/*system vars*/
LiquidCrystal_I2C lcd(32,16,2);
int marble_count = 0;

/*cheeky methods*/
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
  
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  
  init_lcd();
  //attachInterrupt(digitalPinToInterrupt(IN_SENS), marble_entered, RISING); //huh??
}

void loop() {
  //peter griffin
  if ( digitalRead(IN_SENS) ) {
    marble_entered();
  }
}