#include <LiquidCrystal.h>
int lcdColumns = 16;
int lcdRows = 2;

int tiltSensorPin = 6;
boolean tiltSensorCurrentState;
boolean tiltSensorBasicState;
int reply = random(8);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(tiltSensorPin, INPUT);
  lcd.begin(lcdColumns, lcdRows);
  // for debugging
  Serial.begin(9600);
}

void loop()
{
  // delay is needed to keep the LCD looking nice
  delay(500);
  // Check if sensor is on the original value
  if (tiltSensorCurrentState == tiltSensorBasicState) 
  {
    lcd.clear();
    startingState();
    reply = random(8);
  }
  // read the tilt sensor
  tiltSensorCurrentState = digitalRead(tiltSensorPin);
  Serial.println(tiltSensorCurrentState);
  if (tiltSensorCurrentState != tiltSensorBasicState)
  {
    crystalBallSaysWhat(reply);
  }
}

// Prints out the standard promt
void startingState() 
{
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal ball");
  lcd.setCursor(0, 0);
}

// Prints out an answer
void crystalBallSaysWhat(int reply)
{
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
