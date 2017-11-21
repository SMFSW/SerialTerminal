/*! \file SerialTerminal.cpp
**	\author SMFSW
**	\version 1.2
**	\date 2017/11/21
**	\copyright BSD 3-Clause License (c) 2015-2017, SMFSW
**	\brief Arduino Hardware Serial Terminal
**	\details Arduino Hardware Serial Terminal (class instance and serialEvent function)
**/

#if ARDUINO > 22
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <HardwareSerial.h>
#include "SerialTermClass.h"

SerialTerminal term;	//!< Instanciation of the SerialTerminal class

void serialEvent(void)
{
	if (Serial.available())
	{
		term.SCIIn += (char) Serial.read();
		term.SCIInNbChar++;
		term.handler();
	}
}

