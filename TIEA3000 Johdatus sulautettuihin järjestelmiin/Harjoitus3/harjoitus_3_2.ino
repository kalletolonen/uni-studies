int greenLed = 12; // integer for LED PIN
int leftButton = 3;	// integer for BUTTON PIN
int counter = 0; // integer for counter
// Volatile makes the variable state changes 
// instantly visible to main loop()
volatile bool ledState = false; //boolean for led state saving
volatile bool buttonPressed = false; // boolean for button state


void setup() {
  Serial.begin(9600); // init Serial port
  pinMode(greenLed, OUTPUT); // init Pin for led
  pinMode(leftButton, INPUT_PULLUP); //init button
  // The FALLING param is for registering a downward button stroke
  attachInterrupt(digitalPinToInterrupt(leftButton), buttonInterrupt, FALLING);
}

void loop() {
  // buttonpressed == true -> then go into control structure
  if (buttonPressed) {
    ledState = !ledState; // Reverse current led state
    setLedState(greenLed, ledState); // call function with params
    buttonPressed = false; // set variable to false
    counter++; // iterate counter
    Serial.println("Laskuri: " + String(counter)); // print out to serial port
  }
}

// Sets led state
// parameters:
// led		the led to control
// state	the state to set
void setLedState(int led, int state) {
  digitalWrite(led, state); // write led state low/high to led
}

// Interruption routine
void buttonInterrupt() {
     buttonPressed = true; // sets buttonpressed true
}
