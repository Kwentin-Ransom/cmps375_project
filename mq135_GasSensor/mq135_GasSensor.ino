int sensorValue;
int digitalValue;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); //sets the serial port to 9600
  pinMode(13,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sensorValue = analogRead(0); //read analog intput pin 0 
  digitalValue = digitalRead(2);
  
  if(sensorValue > 400) { 
    digitalWrite(13,HIGH);
  }
  else  //add braces if code doesn't work 
  digitalWrite(13, LOW);
  
  Serial.println(sensorValue, DEC); //prints the value read
  Serial.println(digitalValue, DEC);
 
  delay(100000000); //waits 100ms for the next reading
}
