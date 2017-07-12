/*! \file SerialTermClass.h
**	\author SMFSW
**	\version 0.2
**	\date 2017/07/12
**	\copyright BSD 3-Clause License (c) 2015-2017, SMFSW
**	\brief Arduino Hardware Serial Terminal header
**	\details Arduino Hardware Serial Terminal header (low level),
**				sending complete sequence to function for processing it (mainly for user input)
**/
#ifndef __SERIAL_TERM_CLASS_H__
	#define __SERIAL_TERM_CLASS_H__


class SerialTerminal {
private:
	char	breakoutChar = ';';		//!< ASCII value of string breakout
	void	(*process)(String);		//!< Pointer to the message processing function
	
	int		maxSize;				//!< Max size of a received message
	bool	SCIbreakout;			//!< Defines if an acquired SCI string breakout char is reached
	
	/*! \brief user prompt written to serial
	**/
	void userPrompt(void) __attribute__((always_inline)) {
		Serial.print("\n./>");
	}
	
	/*! \brief host prompt written to serial
	**/
	void hostPrompt(void) __attribute__((always_inline)) {
		Serial.print("\n$/>");
	}

public:
	String	SCIIn = "";				//!< Empty String which receives chars from serial
	int		SCIInNbChar = 0;		//!< Received chars count
	
	/*! \brief Terminal speed and callbacks initialisation
	**	\param [in] speed - terminal baud rate
	**	\param [in] processing - pointer to message processing function
	**	\param [in] title - pointer to terminal title String
	**	\param [in] ver - pointer to version String
	**	\param [in] msg_size - maximum serial input size
	**	\return nothing
	**/
	void init(uint32_t speed, void (*processing)(String)=NULL, String * title=NULL, String * ver=NULL, int msg_size=64);
	
	/*! \brief handler for SerialTerminal class
	**	\note this method is public for serialEvent to use it, but shall not be called directly (serialEvent does)
	**	\return nothing
	**/
	void handler();
	
	/*! \brief write breakoutChar
	**	\param[in] breakout - New ASCII digit as breakout
	**	\return nothing
	**/
	void setBreakoutChar(char breakout) __attribute__((always_inline)) {
		breakoutChar = breakout;
	}

	/*! \brief reads breakoutChar
	**	\return breakoutChar
	**/
	char getBreakoutChar() __attribute__((always_inline)) {
		return (char) breakoutChar;
	}
};

#endif /* __SERIAL_TERM_CLASS_H__ */
