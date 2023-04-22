int greenLed = 12; // declare led pin variable
int leftButton = 3; // declare button pin variable

void setup()
{
  pinMode(greenLed, OUTPUT); // init pin for led
  pinMode(leftButton, INPUT); // init pin for button
}

void loop()
{
  // Led is turned on when button is pressed
  if (!isButtonPressed(leftButton)) {
  	setLedState(greenLed, LOW); // function call with params
  }
  else {
    setLedState(greenLed, HIGH); // function call with params
  }
}

// Sets led state
// parameters:
// led		the led to control
// state	the state to set
void setLedState (int led, int state) 
{
	digitalWrite(led, state); // write value to led pin
}

// returns true when button is pressed
// parameters: 
// button	the button to check
boolean isButtonPressed(int button) 
{
  	// check the return value of digitalRead
  	if (digitalRead(leftButton)) 
    {
      return false; // if button is not depressed
    }
  return true; // if button is depressed
}