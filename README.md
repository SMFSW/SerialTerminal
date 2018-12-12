# SerialTerminal [![Build Status](https://travis-ci.com/SMFSW/SerialTerminal.svg?branch=master)](https://travis-ci.com/SMFSW/SerialTerminal)

Arduino Hardware Serial Terminal

Arduino Hardware Serial Terminal (low level), sending complete sequence to function for processing it (mainly for user input)

## Usage

- Declare a function of type `void (*func)(String)` for message processing
- Initialize terminal with `term.init(uint32_t speed, void (*processing)(String)=NULL, String * title=NULL, String * ver=NULL, int msg_size=64)`
  - `speed`: terminal baud rate
  - `processing`: pointer to message processing function
  - `title`: pointer to terminal title String
  - `ver`: pointer to version String
  - `msg_size`: maximum serial input size
- messages will be passed to `func` for processing when breakout char (default being ';') occurs or max size is reached
- Other methods:
  - `term.setBreakoutChar()`: change breakout character
  - `term.getBreakoutChar()`: get actual breakout character

## Examples included

- [ParrotTerminal.ino](examples/ParrotTerminal/ParrotTerminal.ino): Writes back terminal entries to terminal
- [SetLEDTerm.ino](examples/SetLEDTerm/SetLEDTerm.ino): Set onboard LED state through serial terminal

## Documentation

Doxygen doc can be generated using "Doxyfile".

See [generated documentation](https://smfsw.github.io/SerialTerminal/)

## Release Notes

See [release notes](ReleaseNotes.md)
