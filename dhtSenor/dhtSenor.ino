#include <dht.h>
#include <LiquidCrystal.h>

  //this sets the pins of the lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;
#define DHT11_PIN 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //analogWrite(6,Contrast);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(DHT11_PIN);

    //sensor cheeks for temperature
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);

    //prints the temperature from sensor to lcd 
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(DHT.temperature);

    //sensor checks from humidity
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);

    //prints the humidity from sensor to lcd
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.print(DHT.humidity);

  delay(1000);
}
