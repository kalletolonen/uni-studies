int delayTime = 50;
int greenLed = 12;
int leftButton = 3;
int buttonState = HIGH;

void setup()
{
  pinMode(greenLed, OUTPUT);
  pinMode(leftButton, INPUT);
}

void loop()
{
  // Led is turned on when button is pressed
  if (!isButtonPressed(leftButton)) {
  	setLedState(greenLed, LOW);
  }
  else {
    setLedState(greenLed, HIGH);
  }
  delay(delayTime);
}

// Sets led state
// parameters:
// led		the led to control
// state	the state to set
void setLedState (int led, int state) 
{
	digitalWrite(led, state);
}

// returns true when button is pressed
// parameters: 
// button	the button to check
boolean isButtonPressed(int button) 
{
  	int buttonState = digitalRead(leftButton);
	if (buttonState != LOW) 
    {
      return false;
    }
  return true;
}