#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(48,46,44,42,40,38,36,34,32,30,28);
LiquidCrystal lcd(4,6,9,10,11,12);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(2, OUTPUT);           // set pin to OUTPUT
  digitalWrite(2, HIGH);
  pinMode(5, OUTPUT);           // set pin to OUTPUT
  digitalWrite(5, LOW);
  pinMode(3, OUTPUT);           // set pin to OUTPUT
  digitalWrite(3, LOW);// turn on pullup resistors
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("a");
  lcd.setCursor(0, 1);
  lcd.print("bb");

  //setting backlight
//  pinMode(24, OUTPUT);           // set pin to OUTPUT
//  digitalWrite(24, LOW);
//  pinMode(26, OUTPUT);           // set pin to OUTPUT
//  analogWrite(26, 255);
}

void loop() {
 
}
