/*
  Parrot Terminal
  Writes back terminal entries to terminal

  Note that a sequence has to end with ';' to be processed

  This example code is in the public domain.

  created 25 March 2017
  by SMFSW
 */

#include <SerialTerminal.h>

String project = "Parrot Terminal";	//!< Project Name
String vers = "v1.0";				//!< Version

// the setup function runs once when you press reset or power the board
void setup() {
	term.init(115200, &parrot, &project, &vers);
}

// the loop function runs over and over again forever
void loop() {
}

void parrot(String msg)
{
	int NbChar = msg.length() - 1;
	msg.remove(NbChar);	// Remove last char (breakout char)
	Serial.print(msg);
}