//Gina Gerace, 664765515, ggerac3
//Lab 4 - Photoresistor & LCD Screen
//Code should use LCD screen to display should state the relative amount of light in the
//   room as one of 5 predefined text values based on the value read from the photocell. 
//I assume that the photoresistor reads in values 0-1023.
//I used https://playground.arduino.cc/Learning/PhotoResistor/ as reference.


// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int lightPin = 0;        //define a pin for photoresistor
int val;                 //int to store value from photoresistor 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);    //Begin serial communcation
}

void loop() {
  val = analogRead(lightPin);
  Serial.println(val); //Write the value of the photoresistor to the serial monitor.

  lcd.clear();
  //print text values depending on value read in from photoresistor
  if(val < 250)
    lcd.print("dark");
  else if(val < 500)
    lcd.print("partially dark");
  else if(val < 615)
    lcd.print("medium");
  else if(val < 770)
    lcd.print("partially light");
  else 
    lcd.print("fully lit");
  
  delay(10); //short delay for faster response to light.
}
