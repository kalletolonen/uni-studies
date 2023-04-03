// Global variables 
int time = 2000;
int leds[3] = {2,3,4};

void setup()
{
  // Serial port init
  Serial.begin(9600);
  // initialized pins with a list of pins
  for (int i = 0; i < 3; i++) 
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
   ledsOnOff(leds, time);
}

// Puts all leds in array on for a while and then puts them off
// Led state is printed to Serial Monitor
void ledsOnOff(int leds[3], int time)
{
  Serial.println("LED ON");
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(time);
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
  Serial.println("LED OFF");
  delay(time);
}
