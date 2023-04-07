int greenLed = 12;
int leftButton = 3;
int counter = 0;
// Volatile makes the variable state changes 
// instantly visible to main loop()
volatile bool ledState = false;
volatile bool buttonPressed = false;
volatile long lastInterruptTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(leftButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(leftButton), buttonInterrupt, CHANGE);
}

void loop() {
  if (buttonPressed) {
    // Reverse current led state
    ledState = !ledState;
    setLedState(greenLed, ledState);
    buttonPressed = false;
    counter++;
    Serial.println("Laskuri: " + String(counter));
  }
}

// Sets led state
// parameters:
// led		the led to control
// state	the state to set
void setLedState(int led, int state) {
  digitalWrite(led, state);
}

void buttonInterrupt() {
  // the current time in milliseconds
  unsigned long interruptTime = millis();
  // Checks whether the interrupt is the first one in over 50ms
  if (interruptTime - lastInterruptTime > 50) {
    lastInterruptTime = interruptTime;
    buttonPressed = true;
    
  }
}
