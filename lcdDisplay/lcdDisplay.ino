#include <LiquidCrystal.h>

//this code displays hello world to the lcd 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() {
  // put your setup code here, to run once:
  analogWrite(6,.1);
  lcd.begin(16,2);
  lcd.print("hello world"); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
