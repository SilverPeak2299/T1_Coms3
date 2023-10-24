// Controlls IC2 LED

//variables
extern int marble_count;

void init_lcd() {
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("marbleCt: ");
  lcd.print( String(marble_count) );
}

void update_lcd() {
  lcd.setCursor(0,0);
  lcd.print("marbleCt: ");
  lcd.print( String(marble_count) );
}
