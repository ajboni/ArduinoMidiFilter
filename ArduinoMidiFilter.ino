// This is required to set up the MIDI library.
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

// FILTER CONFIGURATION
// Inspect midi_defs for more details on messages.
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

// END FILTER CONFIGURATION

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Launch MIDI and listen to all channels
  MIDI.turnThruOff();             // Disable automatic MIDI Thru function
}

void loop() {
  
  if (MIDI.read())  // If we have received a message
  {
    byte cmd = MIDI.getType();
    byte ch = MIDI.getChannel();

    bool filter = false;
    if ((cmd == midi::NoteOn || cmd == midi::NoteOff) && NOTE) filter = true;
    if (cmd == midi::AfterTouchPoly && AFTERTOUCH_POLY) filter = true;
    if (cmd == midi::AfterTouchChannel && AFTERTOUCH_CHANNEL) filter = true;
    if (cmd == midi::ControlChange && CONTROL_CHANGE) filter = true;
    if (cmd == midi::ProgramChange && PROGRAM_CHANGE) filter = true;
    if (cmd == midi::PitchBend && PITCHBEND) filter = true;
    if (cmd == midi::InvalidType && ERRORS) filter = true;
    if (cmd >= midi::SystemExclusiveStart && cmd <= midi::SystemExclusiveEnd && SYSTEM) filter = true;
    if (cmd >= midi::Clock && cmd <= midi::SystemReset && CLOCK) filter = true;
    
    if ((filter && !FILTER_MODE) || (!filter && FILTER_MODE)) {
      MIDI.send(MIDI.getType(), MIDI.getData1(), MIDI.getData2(), MIDI.getChannel());
    }    
  }
}