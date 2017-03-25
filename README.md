# SerialTerminal
Arduino Hardware Serial Terminal

Arduino Hardware Serial Terminal (low level), sending complete sequence to function for processing it (mainly for user input)


## Usage: 
- Declare a function of type void (*func)(String) for message processing
- Initialise terminal with _term.init(uint32_t speed, void (*processing)(String)=NULL, String * title=NULL, String * ver=NULL, int msg_size=64)_
  - speed - terminal baud rate
  - processing - pointer to message processing function
  - title - pointer to terminal title String
  - ver - pointer to version String
  - msg_size - maximum serial input size
- messages will be passed to _func_ for processing when breakout char (default being ';') occurs or max size is reached
- Other methods:
  - term.setBreakoutChar(): to change breakout character
  - term.getBreakoutChar(): to get actual breakout character

## Examples included:
- ParrotTerminal.ino: Writes back terminal entries to terminal
- SetLEDTerm.ino: Set onboard LED state through serial terminal

## Misc:
Doxygen doc can be generated for the class using doxyfile.

Feel free to share your thoughts @ xgarmanboziax@gmail.com about:
  - issues encountered
  - optimisations
  - improvements & new functionalities
