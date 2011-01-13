#ifndef MIDIKIT_DRIVER_COREMIDI_H
#define MIDIKIT_DRIVER_COREMIDI_H
#include "midi/driver.h"
#include "midi/message.h"
#include <CoreMIDI/MIDIServices.h>

struct MIDIDriverCoreMIDI;
extern struct MIDIDriverDelegate MIDIDriverDelegateCoreMIDI;

struct MIDIDriverCoreMIDI * MIDIDriverCoreMIDICreate( MIDIClientRef client );
void MIDIDriverCoreMIDIDestroy( struct MIDIDriverCoreMIDI * driver );
void MIDIDriverCoreMIDIRetain( struct MIDIDriverCoreMIDI * driver );
void MIDIDriverCoreMIDIRelease( struct MIDIDriverCoreMIDI * driver );

int MIDIDriverCoreMIDIReceiveMessage( struct MIDIDriverCoreMIDI * driver, struct MIDIMessage * message );
int MIDIDriverCoreMIDISendMessage( struct MIDIDriverCoreMIDI * driver, struct MIDIMessage * message );

int MIDIDriverCoreMIDIReceive( struct MIDIDriverCoreMIDI * driver );
int MIDIDriverCoreMIDISend( struct MIDIDriverCoreMIDI * driver );
int MIDIDriverCoreMIDIIdle( struct MIDIDriverCoreMIDI * driver );

#endif