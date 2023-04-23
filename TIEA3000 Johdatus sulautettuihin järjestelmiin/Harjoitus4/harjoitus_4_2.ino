#include <EEPROM.h>
// Genrate random number to write into memory
int dataToWrite = random(1, 100 + 1);
int currentMemoryPosition = 0;
int leftButton = 4;
int middleButton = 3;
int rightButton = 2;
boolean isValues = false;

// Init button pin, serial port & interruptions
void setup()
{
  pinMode(leftButton, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(middleButton), emptyEEPROM, FALLING);
  attachInterrupt(digitalPinToInterrupt(rightButton), printEEPROM, FALLING);
}

void loop()
{
  delay(40);
  // Write to memory when button is pressed
  if (isButtonPressed(leftButton)) {
  	
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
  	if (digitalRead(button)) 
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

// Empty the EEPROM
void emptyEEPROM()
{
  byte value = 0;
  
  Serial.println("Tyhjennetään EEPROM...");
  Serial.flush(); // Flush the Serial buffer to ensure all data is sent

  for (int i = 0; i < EEPROM.length(); i++) 
  {
  	// Update the EEPROM with the value, only if it's different
    EEPROM.update(i, value);
  }
  currentMemoryPosition = 0;
  isValues = false;
  Serial.println("EPROM on tyhjä.");
}

// Print the EEPROM
void printEEPROM()
{
  Serial.println("Tulostetaan arvot, jos niitä on");
  Serial.println("--------------------------------");
  for (int i = 0; i < EEPROM.length(); i++) 
  {
  	// Read the EEPROM
    byte readValue = EEPROM.read(i);
    if(readValue)
    {
      isValues = true;
      Serial.println("Muistipaikka: " + String(i));
      Serial.println("Arvo: " + String(readValue));
    } 
    
  }
  if (!isValues) 
  {
    Serial.println("Ei arvoja tallennettuna."); 
  }
  Serial.println("--------------------------------");
}