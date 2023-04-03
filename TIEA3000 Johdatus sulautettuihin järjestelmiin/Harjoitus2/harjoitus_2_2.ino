// Global variables 
int time = 500;
int leds[3] = {2,3,4};

void setup()
{
  // initialized pins with a list of pins
  for (int i = 0; i < 3; i++) 
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  // blinks led's based on led list & duration params
  for (int i = 0; i < 3; i++) {
  	blinkLed(leds[0], time);
    delay(time);
  }
  ledsOnOff(leds, time);
}

// Blinks a led for a given time in ms
void blinkLed(int led, int time)
{
  digitalWrite(led, HIGH);
  delay(time);
  digitalWrite(led, LOW);
}

// Puts all leds in array on for a while and then puts them off
void ledsOnOff(int leds[3], int time)
{
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(time);
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
  delay(time);
}