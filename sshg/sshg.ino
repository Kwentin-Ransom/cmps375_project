#include <dht.h>
#include <LiquidCrystal.h>
#include <virtuabotixRTC.h>

dht DHT;
#define DHT11_PIN 7

#define anInput A8 //analog feed from MQ135
#define co2Zero 55 //calibrated CO2 0 level
#define CLK 10
#define DATA 9
#define RST 8
#define LEDPin6 9
#define LEDPin5 10
#define LEDPin4 11
#define LEDPin3 12
#define LEDPin2 13
#define LEDPin1 5

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //sets pins of lcd
virtuabotixRTC myRTC(CLK, DATA, RST);// create rtc object

void dhtSensor() {
  int chk = DHT.read11(DHT11_PIN); //sensor checks for readings

  Serial.print("Temperature: ");
  Serial.print(DHT.temperature); //temperature printed to serial moniter 

  lcd.setCursor(0,0);         //cursor of lcd set to top left
  lcd.print("Temperature:");
  lcd.print(DHT.temperature); //temperature printed to lcd

  Serial.print("Humidity: ");
  Serial.print(DHT.humidity); //humidity printed to serial moniter 

  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.print(DHT.humidity); //humidity printed to lcd

  delay(1000);
} //end dhtSensor

void mq135_CO2() {
  int co2now[10]; //int array for co2 readings
  int co2raw = 0; //int for raw value of co2
  int co2ppm = 0; //int for calculated ppm
  int zzz = 0;    //int for averaging

  for (int x = 0;x<10;x++)  //samplpe co2 10x over 2 seconds
  {                   
    co2now[x]=analogRead(A8);
    delay(200);
  } //end for

  for (int x = 0;x<10;x++)  //add samples together
  {                     
    zzz=zzz + co2now[x];  
  } //end for 

  co2raw = zzz/10;           //divide samples by 10
  co2ppm = co2raw - co2Zero; //get calculated ppm
  
  Serial.print("AirQuality=");
  Serial.print(co2ppm);  // prints the value read
  Serial.println(" PPM");
  delay(50);
} //end mq135_CO2

void ledLights() { 
  int timeDiff, lastUpdate =0;
  myRTC.updateTime();
  //check time code to check if time is properly saved
  //Serial.print("Current Date / Time: ");
  //Serial.print(myRTC.dayofmonth);
  //Serial.print("/");
  //Serial.print(myRTC.month);
  //Serial.print("/");
  //Serial.print(myRTC.year);
  //Serial.print(" ");
  //Serial.print(myRTC.hours);
  //Serial.print(":");
  //Serial.print(myRTC.minutes);
  //Serial.print(":");
  //Serial.println(myRTC.seconds);

  timeDiff = myRTC.seconds - lastUpdate;
  if (timeDiff % 2 == 0){
    digitalWrite(LEDPin1, HIGH);
  }
  else{
  digitalWrite(LEDPin1, LOW);
  }
  if (timeDiff % 3 == 0){
    digitalWrite(LEDPin2, HIGH);
  }
  else{
     digitalWrite(LEDPin2, LOW);

 }
 if (timeDiff % 4 == 0){
    digitalWrite(LEDPin3, HIGH);
  }
  else{
  digitalWrite(LEDPin3, LOW);
  }
  if (timeDiff % 5 == 0){
    digitalWrite(LEDPin4, HIGH);
  }
  else{
  digitalWrite(LEDPin4, LOW);
  }
  if (timeDiff % 6 == 0){
    digitalWrite(LEDPin5, HIGH);
  }
  else{
  digitalWrite(LEDPin5, LOW);
  } 
  if (timeDiff % 7 == 0){
    digitalWrite(LEDPin6, HIGH);
  }
  else{
  digitalWrite(LEDPin6, LOW);
  }
  lastUpdate = myRTC.seconds;
} //end ledLights

void setup() {
  Serial.begin(9600);        //serial comms for debuging
  lcd.begin(16,2);           //dimensions of lcd
  
  pinMode(anInput,INPUT);    //MQ135 analog feed set for input
  pinMode(LEDPin6, OUTPUT);
  pinMode(LEDPin5, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin1, OUTPUT);
  //code sets time, uncomment to set time
  //myRTC.setDS1302Time(00, 11, 12, 07, 2, 6, 2021);
} //end setup

void loop() {

  dhtSensor(); //run loop
  mq135_CO2(); //run loop
  ledLights(); //run loop

} //end loop
