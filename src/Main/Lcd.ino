// Functions for IC2 LED

//variables

void init_lcd() {
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  update_lcd();
}

void update_lcd() {
  lcd.setCursor(0,0);
  lcd.print("marbles entered: ");
  lcd.setCursor(0,1);
  lcd.print( String(marble_count) );
}
