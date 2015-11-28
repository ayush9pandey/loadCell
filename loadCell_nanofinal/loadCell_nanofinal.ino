#include <LiquidCrystal.h>

const int numReadings = 30;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A7;
int groundPin = A6;



// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(48,46,44,42,40,38,36,34,32,30,28);
LiquidCrystal lcd(4, 6, 9, 10, 11, 12); //using 4 data pins d4-d7. for mega



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
  pinMode(2, OUTPUT);           // set pin to OUTPUT
  digitalWrite(2, HIGH);
  pinMode(5, OUTPUT);           // set pin RS to OUTPUT and GND
  digitalWrite(5, LOW);
  pinMode(3, OUTPUT);           // set pin to OUTPUT
  digitalWrite(3, LOW);// turn on pullup resistors
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  //setting backlight
  //  pinMode(24, OUTPUT);           // set pin to OUTPUT
  //  digitalWrite(24, LOW);
  //  pinMode(26, OUTPUT);           // set pin to OUTPUT
  //  digitalWrite(26, HIGH);
  //
//  analogReference(INTERNAL);
}

// the loop routine runs over and over again forever:
void loop() {

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = 1.035445373 * (analogRead(inputPin));//-18 -analogRead(groundPin));
  // add the reading to the total:
  total = total + readings[readIndex];
//  total = max(total, readings[readIndex]);
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  average=average-10;
//  average = total-13;

  // send it to the computer as ASCII digits
  //  Serial.println(average);

  // Print a message to the LCD.
  lcd.begin(16, 2);
  lcd.print(average);
  lcd.setCursor(5, 0);
  lcd.print("gm");
  delay(100);        // delay in between reads for stability
}
