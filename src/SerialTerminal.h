/*! \file SerialTerminal.h
**	\author SMFSW
**	\version 1.2
**	\date 2017/11/21
**	\copyright BSD 3-Clause License (c) 2015-2017, SMFSW
**	\brief Arduino Hardware Serial Terminal header
**	\details Arduino Hardware Serial Terminal header (class instance and serialEvent function prototypes)
**/
#ifndef __SERIAL_TERMINAL_H__
	#define __SERIAL_TERMINAL_H__

#include "SerialTermClass.h"

extern SerialTerminal term;

/*! \brief Called whenever a new data has been received on RX
**	\remark This routine is run between each time loop() runs, no delay here set in here
**	\note Multiple bytes of data may be available
**	\details serialEvent appends all bytes read to string SCIIn of SerialTerminal class
**				It also makes available SCIIn for processing when max String size is reached
**/
void serialEvent(void);


#endif /* __SERIAL_TERMINAL_H__ */
