#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(48,46,44,42,40,38,36,34,32,30,28);
LiquidCrystal lcd(48,44,34,32,30,28);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(52, OUTPUT);           // set pin to OUTPUT
  digitalWrite(52, HIGH);
  pinMode(46, OUTPUT);           // set pin to OUTPUT
  digitalWrite(46, LOW);
  pinMode(50, OUTPUT);           // set pin to OUTPUT
  digitalWrite(50, LOW);// turn on pullup resistors
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("a");
  lcd.setCursor(0, 1);
  lcd.print("bb");

  //setting backlight
  pinMode(24, OUTPUT);           // set pin to OUTPUT
  digitalWrite(24, LOW);
  pinMode(26, OUTPUT);           // set pin to OUTPUT
  analogWrite(26, 255);
}

void loop() {
 
}
