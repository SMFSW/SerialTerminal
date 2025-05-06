# SerialTerminal

[![author](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/auth_SMFSW.json)](https://github.com/SMFSW)
![badge](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/SerialTerminal_status_badge.json)
[![license](https://img.shields.io/badge/License-BSD3-darkred.svg)](LICENSE)
[![CodeFactor](https://www.codefactor.io/repository/github/smfsw/seqtimer/badge)](https://www.codefactor.io/repository/github/smfsw/serialterminal)

![platform](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/platform_INO.json)

[![doxy](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/tool_DOXY.json)](https://smfsw.github.io/SerialTerminal)
[![re_note](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/tool_RN.json)](ReleaseNotes.md)

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
