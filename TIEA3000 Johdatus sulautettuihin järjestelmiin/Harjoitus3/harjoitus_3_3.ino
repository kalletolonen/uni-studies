int leftButton = 3;	// integer for button pin
int tempSensorPin = A0; // temp senson pin
int measurementTimes = 50; // set how many measurements
int timeBetweenMeasurements = 20; // time between measurements
// Volatile makes the variable state changes 
// instantly visible to main loop()
volatile bool buttonPressed = false; // boolean for button state

void setup() {
  Serial.begin(9600); // init Serial port
  pinMode(leftButton, INPUT_PULLUP); //init button
  // The FALLING param is for registering a downward button stroke
  attachInterrupt(digitalPinToInterrupt(leftButton), buttonInterrupt, FALLING);
}

void loop() {
  
  // buttonpressed == true -> then go into control structure
  if (buttonPressed) {
    // call a function, divide return value by measurementTimes
    float avgAdc = measureAdc(tempSensorPin, measurementTimes, timeBetweenMeasurements) / measurementTimes; 
    float avgTemp = ((5 * avgAdc / 1024.0) - 0.5) * 100; // calculate avg-temp based on given formula
    Serial.println("ADC: " + String(avgAdc) + " lt: " + String(avgTemp)); // print and catenate results
   	buttonPressed = false; // set button state to false
  }
}

// Interruption routine
void buttonInterrupt() {
      buttonPressed = true; // sets buttonpressed true
  }

/*
Takes analog pin input, measumerent times and time delay between measument 
times and returns ADC-readings
*/
int measureAdc(int sensorPin, int measurementTimes, int timeBetweenMeasurements) {
	int adcReadings = 0; // variable for gathering results
  	
  	// loop for as many times as there are measurements
    for (int i = 0; i <= measurementTimes; i++) {
       delay(timeBetweenMeasurements); // Wait for 20 ms
       int adc = analogRead(tempSensorPin); // Get a reading from the temperature sensor
       adcReadings = adcReadings + adc; // add to previous readings
    }
  return adcReadings; // return the reading after loop is complete
}
