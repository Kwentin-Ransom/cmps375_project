#include <virtuabotixRTC.h>
#define CLK 6
#define DATA 7
#define RST 8
#define LEDPin6 9
#define LEDPin5 10
#define LEDPin4 11
#define LEDPin3 12
#define LEDPin2 13
#define LEDPin1 5

virtuabotixRTC myRTC(CLK, DATA, RST);// create rtc object
void setup(){
  Serial.begin(9600);
  pinMode(LEDPin6, OUTPUT);
  pinMode(LEDPin5, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin1, OUTPUT);



  //set time code dont uncomment unless trying to set time
//myRTC.setDS1302Time(00, 11, 12, 07, 2, 6, 2021);
}



void loop() {
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

 

}
