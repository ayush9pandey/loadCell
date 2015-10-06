#include <LiquidCrystal.h>

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;



// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(48,46,44,42,40,38,36,34,32,30,28);
LiquidCrystal lcd(48,44,34,32,30,28); //using 4 data pins d4-d7.

//RW is gnd, RS and EN are in the func. 

/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    // set up the LCD's number of columns and rows:
  pinMode(52, OUTPUT);           // set pin to OUTPUT
  digitalWrite(52, HIGH);
  pinMode(46, OUTPUT);           // set pin RS to OUTPUT and GND
  digitalWrite(46, LOW);
  pinMode(50, OUTPUT);           // set pin to OUTPUT
  digitalWrite(50, LOW);// turn on pullup resistors
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  //setting backlight
  pinMode(24, OUTPUT);           // set pin to OUTPUT
  digitalWrite(24, LOW);
  pinMode(26, OUTPUT);           // set pin to OUTPUT
  digitalWrite(26, HIGH);
  
}

// the loop routine runs over and over again forever:
void loop() {

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = 1.027*analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(average);
  lcd.setCursor(5, 0);
  lcd.print(grams);
  delay(2);        // delay in between reads for stability
}
