#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

 void setup()
 {
    Serial.begin(9600);
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
  } 
     void loop()
 { 
  // lcd.clear();
  // lcd.home();
     lcd.setCursor(0, 0);
     lcd.print("Innovative");
     
    lcd.setCursor(0, 1);
    lcd.print("Subscribe");
    delay(500);
 }
