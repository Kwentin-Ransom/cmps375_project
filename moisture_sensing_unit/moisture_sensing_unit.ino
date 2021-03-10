//modified from https://www.instructables.com/Arduino-Soil-Moisture-Sensor/
// and https://arduino.stackexchange.com/questions/1615/how-to-loop-over-analog-pins

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5};
  for (int i = 0; i <= 5; i++) {
  int moisture = analogRead(analog_pins[i]);
   // print out the values read:
  Serial.print("\nmoisture sensor");
  Serial.print(i);
  Serial.print(":    ");
  Serial.println(moisture);
  delay(5);        // delay in between reads for stability
  }
  delay(5000);        // delay in between reads for readability
}
