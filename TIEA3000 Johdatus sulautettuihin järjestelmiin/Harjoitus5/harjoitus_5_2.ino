#include <LiquidCrystal.h>
int lcdColumns = 16;
int lcdRows = 2;

int buttonPin = 2;
int tempSensorPin = A0;
int tiltSensorPin = 6;
int reply = random(8);
volatile boolean buttonPressed = false;
boolean tiltSensorCurrentState;
boolean tiltSensorBasicState;
boolean startingStateIsActive = false;
boolean askingStateIsActive = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 7);

void setup()
{
  lcd.begin(lcdColumns, lcdRows);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, FALLING);
  // for debugging
  Serial.begin(9600);
}

void loop()
{
  if (buttonPressed) 
  {	
    // Get the value, convert it and print it
    float temperature = ((5 * measureAdc() / 1024.0) - 0.5) * 100;
    printTemperature(temperature);
    buttonPressed = false;
  }
  
  // Check if sensor is on the original value
  if (tiltSensorCurrentState == tiltSensorBasicState) 
  {
    if (!startingStateIsActive) 
    {
      startingState();
    }
    reply = random(8);
  }
  // read the tilt sensor
  tiltSensorCurrentState = digitalRead(tiltSensorPin);
  if (tiltSensorCurrentState != tiltSensorBasicState)
  {
    if (!askingStateIsActive) 
    {
      crystalBallSaysWhat(reply);
    }
    startingStateIsActive = false;
  }
  
}

// Prints out the standard promt
void startingState() 
{
  lcd.clear();
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal ball");
  lcd.setCursor(0, 0);
  startingStateIsActive = true;
  askingStateIsActive = false;
}

// Prints out an answer
void crystalBallSaysWhat(int reply)
{
  askingStateIsActive = true;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The ball says:");
  lcd.setCursor(0, 1);
  switch(reply)
  {
	case 0:
	lcd.print("Yes");
	break;
	case 1:
	lcd.print("Most likely");
	break;
	case 2:
	lcd.print("Certainly");
	break;
	case 3:
	lcd.print("Outlook good");
	break;
	case 4:
	lcd.print("Unsure");
	break;
	case 5:
	lcd.print("Ask again");
	break;
	case 6:
	lcd.print("Doubtful");
	break;
	case 7:
	lcd.print("No");
	break;
  }
}

void buttonInterrupt()
{
  buttonPressed = true;
}

// Prints out the temperature
void printTemperature(float temp)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The temp is:");
  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.print(" celcius");
  delay(500);
  startingStateIsActive = false;
  askingStateIsActive = false;
}

// Measures temperature
int measureAdc() {
  int adcReadings = 0;
  adcReadings = analogRead(tempSensorPin);
  return adcReadings;
}