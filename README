# Arduino MIDI filter

This is very simple midi filter for arduino UNO (will probably work with others).

The program has two modes: 
  1. Whitelist: Deny everything except allowed messages.
  2. Blacklist: Allow everything except allowed messages.

To configure just set to 1 the messages that you want to filter in/out.


```cpp
// Deny everything except clock related messages.
// FILTER MODE: 0 = Whitelist , 1 = Blacklist
int FILTER_MODE         = 0;
int NOTE                = 0;
int CONTROL_CHANGE      = 0;
int PROGRAM_CHANGE      = 0;
int AFTERTOUCH_POLY     = 0;
int AFTERTOUCH_CHANNEL  = 0;
int PITCHBEND           = 0;
int SYSTEM              = 0;
int CLOCK               = 1;
int ERRORS              = 0;
```

This project was made using [this great post](https://diyelectromusic.wordpress.com/2020/09/12/arduino-midi-filter/) as reference.

