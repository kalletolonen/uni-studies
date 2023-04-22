#include <EEPROM.h>

// Genrate random number to write into memory
int dataToWrite = random(1, 100 + 1);
int currentMemoryPosition = 0;
int leftButton = 4;

// Init button pin & serial port
void setup()
{
  pinMode(leftButton, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // Write to memory when button is pressed
  if (isButtonPressed(leftButton)) {
  	delay(75);
    writeToEEPROM(currentMemoryPosition, dataToWrite);
    currentMemoryPosition = currentMemoryPosition + 1;
    dataToWrite = random(1, 100 + 1);
  }
}

// returns true when button is pressed
// parameters: 
// button	the button to check
boolean isButtonPressed(int button) 
{
  	if (digitalRead(leftButton)) 
    {
      return false; 
    }
  return true; 
}

// Write to EEPROM
// parameters:
// address		the address to write to
// data			the data to write
void writeToEEPROM(int address, int data) 
{	
  	EEPROM.write(address, data);
  	writeOutAddressAndData(address, data);
  	  	
}

// Write out parameters to serial port
void writeOutAddressAndData(int address, int data) 
{
  Serial.println("Address: " + String(address));
  Serial.println("Data: " + String(data));
}