/*
  SetLEDTerm
  Set onboard LED state through serial terminal

  Note that a sequence has to end with ';' to be processed

  This example code is in the public domain.

  created 25 March 2017
  by SMFSW
 */

#include <SerialTerminal.h>

String project = "SetLED Terminal";	//!< Project Name
String vers = "v1.0";				//!< Version

// the setup function runs once when you press reset or power the board
void setup() {
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
	
	term.init(115200, &LEDState, &project, &vers);
}

// the loop function runs over and over again forever
void loop() {
}

void LEDState(String msg)
{
	int NbChar = msg.length() - 1;
	msg.remove(NbChar);	// Remove last char (breakout char)

	if (msg.compareTo("ON") == 0)	// Match ON
	{
		digitalWrite(13, HIGH);
		Serial.print("LED turned ON");
	}
	else if (msg.compareTo("OFF") == 0)	// Match OFF
	{
		digitalWrite(13, LOW);
		Serial.print("LED turned OFF");
	}
	else	{ Serial.print("unknown command"); }
}