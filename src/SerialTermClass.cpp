/*! \file SerialTermClass.cpp
**	\author SMFSW
**	\version 1.2
**	\date 2017/11/21
**	\copyright BSD 3-Clause License (c) 2015-2017, SMFSW
**	\brief Arduino Hardware Serial Terminal
**	\details Arduino Hardware Serial Terminal (low level),
**				sending complete sequence to function for processing it (mainly for user input)
**/

#if ARDUINO > 22
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <HardwareSerial.h>
#include "SerialTermClass.h"


void SerialTerminal::init(const uint32_t speed, void (*processing)(String), const String * title, const String * ver, const int msg_size)
{
	Serial.begin(speed);
	
	maxSize = msg_size;
	process = processing;
	
	if (title)	{ Serial.println(*title); }
	if (ver)
	{
		Serial.print("Running software version: ");
		Serial.print(*ver);
	}
	userPrompt();
}

void SerialTerminal::handler(void)
{
	if ((SCIInNbChar > maxSize-1) || (SCIIn.charAt(SCIInNbChar-1) == breakoutChar))	{ SCIbreakout = true; }
	
	if (SCIbreakout == true)
	{
		Serial.print(SCIIn);
		hostPrompt();
		int rem = SCIIn.length();
		
		// Process message if function pointer is defined
		if (process)	{ (void) process(SCIIn); }
		
		// Clean treated part of serial internal buffer
		SCIIn.remove(0, rem);
		SCIInNbChar -= rem;
		SCIbreakout = false;
		
		userPrompt();
	}
}


