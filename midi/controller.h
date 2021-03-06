#ifndef MIDIKIT_MIDI_CONTROLLER_H
#define MIDIKIT_MIDI_CONTROLLER_H
#include "midi.h"

/**
 * @name MIDI control numbers.
 * Various MIDI control numbers, legal values for MIDIControl variables.
 * @{
 */

#define MIDI_CONTROL_BANK_SELECT           0x00
#define MIDI_CONTROL_MODULATION_WHEEL      0x01
#define MIDI_CONTROL_BREATH_CONTROLLER     0x02
#define MIDI_CONTROL_UNDEFINED0            0x03
#define MIDI_CONTROL_FOOT_CONTROLLER       0x04
#define MIDI_CONTROL_PORTAMENTO_TIME       0x05
#define MIDI_CONTROL_DATA_ENTRY            0x06
#define MIDI_CONTROL_CHANNEL_VOLUME        0x07
#define MIDI_CONTROL_BALANCE               0x08
#define MIDI_CONTROL_UNDEFINED1            0x09
#define MIDI_CONTROL_PAN                   0x0a
#define MIDI_CONTROL_EXPRESSION_CONTROLLER 0x0b
#define MIDI_CONTROL_EFFECT_CONTROL1       0x0c
#define MIDI_CONTROL_EFFECT_CONTROL2       0x0d
#define MIDI_CONTROL_UNDEFINED2            0x0e
#define MIDI_CONTROL_UNDEFINED3            0x0f
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER1 0x10
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER2 0x11
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER3 0x12
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER4 0x13
#define MIDI_CONTROL_UNDEFINED4            0x14
#define MIDI_CONTROL_UNDEFINED5            0x15
#define MIDI_CONTROL_UNDEFINED6            0x16
#define MIDI_CONTROL_UNDEFINED7            0x17
#define MIDI_CONTROL_UNDEFINED8            0x18
#define MIDI_CONTROL_UNDEFINED9            0x19
#define MIDI_CONTROL_UNDEFINED10           0x1a
#define MIDI_CONTROL_UNDEFINED11           0x1b
#define MIDI_CONTROL_UNDEFINED12           0x1c
#define MIDI_CONTROL_UNDEFINED13           0x1d
#define MIDI_CONTROL_UNDEFINED14           0x1e
#define MIDI_CONTROL_UNDEFINED15           0x1f
/* 0x20 - 0x3f = Control 0x01 - 0x1f LSB */

#define MIDI_CONTROL_DAMPER_PEDAL          0x40
#define MIDI_CONTROL_PORTAMENTO            0x41
#define MIDI_CONTROL_SOSTENUTO             0x42
#define MIDI_CONTROL_SOFT_PEDAL            0x43
#define MIDI_CONTROL_LEGATO_FOOTSWITCH     0x44
#define MIDI_CONTROL_HOLD2                 0x45
#define MIDI_CONTROL_SOUND_CONTROLLER1     0x46
#define MIDI_CONTROL_SOUND_VARIATION       MIDI_CONTROL_SOUND_CONTROLLER1
#define MIDI_CONTROL_SOUND_CONTROLLER2     0x47
#define MIDI_CONTROL_SOUND_TIMBRE          MIDI_CONTROL_SOUND_CONTROLLER2
#define MIDI_CONTROL_SOUND_CONTROLLER3     0x48
#define MIDI_CONTROL_SOUND_RELEASE_TIME    MIDI_CONTROL_SOUND_CONTROLLER3
#define MIDI_CONTROL_SOUND_CONTROLLER4     0x49
#define MIDI_CONTROL_SOUND_ATTACK_TIME     MIDI_CONTROL_SOUND_CONTROLLER4
#define MIDI_CONTROL_SOUND_CONTROLLER5     0x4a
#define MIDI_CONTROL_SOUND_BRIGHTNESS      MIDI_CONTROL_SOUND_CONTROLLER5
#define MIDI_CONTROL_SOUND_CONTROLLER6     0x4b
#define MIDI_CONTROL_SOUND_DECAY_TIME      MIDI_CONTROL_SOUND_CONTROLLER6
#define MIDI_CONTROL_SOUND_CONTROLLER7     0x4c
#define MIDI_CONTROL_SOUND_VIBRATO_RATE    MIDI_CONTROL_SOUND_CONTROLLER7
#define MIDI_CONTROL_SOUND_CONTROLLER8     0x4d
#define MIDI_CONTROL_SOUND_VIBRATO_DEPTH   MIDI_CONTROL_SOUND_CONTROLLER8
#define MIDI_CONTROL_SOUND_CONTROLLER9     0x4e
#define MIDI_CONTROL_SOUND_VIBRATO_DELAY   MIDI_CONTROL_SOUND_CONTROLLER9
#define MIDI_CONTROL_SOUND_CONTROLLER10    0x4f
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER5 0x50
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER6 0x51
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER7 0x52
#define MIDI_CONTROL_GENERAL_PURPOSE_CONTROLLER8 0x53
#define MIDI_CONTROL_PORTAMENTO_CONTROL    0x54
#define MIDI_CONTROL_UNDEFINED16           0x55
#define MIDI_CONTROL_UNDEFINED17           0x56
#define MIDI_CONTROL_UNDEFINED18           0x57
#define MIDI_CONTROL_UNDEFINED19           0x58
#define MIDI_CONTROL_UNDEFINED20           0x59
#define MIDI_CONTROL_UNDEFINED21           0x5a
#define MIDI_CONTROL_EFFECTS1_DEPTH        0x5b
#define MIDI_CONTROL_REVERB_SEND_LEVEL     MIDI_CONTROL_EFFECTS1_DEPTH
#define MIDI_CONTROL_EFFECTS2_DEPTH        0x5c
#define MIDI_CONTROL_EFFECTS3_DEPTH        0x5d
#define MIDI_CONTROL_CHORUS_SEND_LEVEL     MIDI_CONTROL_EFFECTS3_DEPTH
#define MIDI_CONTROL_EFFECTS4_DEPTH        0x5e
#define MIDI_CONTROL_EFFECTS5_DEPTH        0x5f
#define MIDI_CONTROL_DATA_INCREMENT        0x60
#define MIDI_CONTROL_DATA_DECREMENT        0x61
#define MIDI_CONTROL_NON_REGISTERED_PARAMETER_NUMBER     0x62
#define MIDI_CONTROL_NON_REGISTERED_PARAMETER_NUMBER_MSB MIDI_CONTROL_NON_REGISTERED_PARAMETER_NUMBER
#define MIDI_CONTROL_NON_REGISTERED_PARAMETER_NUMBER_LSB 0x63
#define MIDI_CONTROL_REGISTERED_PARAMETER_NUMBER         0x64
#define MIDI_CONTROL_REGISTERED_PARAMETER_NUMBER_MSB     MIDI_CONTROL_REGISTERED_PARAMETER_NUMBER
#define MIDI_CONTROL_REGISTERED_PARAMETER_NUMBER_LSB     0x65

/* channel mode controls */
#define MIDI_CONTROL_ALL_SOUND_OFF         0x78
#define MIDI_CONTROL_RESET_ALL_CONTROLLERS 0x79
#define MIDI_CONTROL_LOCAL_CONTROL         0x7a
#define MIDI_CONTROL_ALL_NOTES_OFF         0x7b
#define MIDI_CONTROL_OMNI_MODE_OFF         0x7c
#define MIDI_CONTROL_OMNI_MODE_ON          0x7d
#define MIDI_CONTROL_MONO_MODE_ON          0x7e
#define MIDI_CONTROL_POLY_MODE_ON          0x7f

/** @} */

/**
 * @name MIDI registered parameters
 * @{
 */

#define MIDI_CONTROL_RPN_PITCH_BEND_RANGE 0x0000
#define MIDI_CONTROL_RPN_FINE_TUNING      0x0001
#define MIDI_CONTROL_RPN_COARSE_TUNING    0x0002
#define MIDI_CONTROL_RPN_RESET            0x3fff

#define MIDI_CONTROL_RPN_PITCH_BEND_RANGE_SEMITONES 0
#define MIDI_CONTROL_RPN_PITCH_BEND_RANGE_CENTS     1
#define MIDI_CONTROL_RPN_FINE_TUNING_MSB            2
#define MIDI_CONTROL_RPN_FINE_TUNING_LSB            3
#define MIDI_CONTROL_RPN_COARSE_TUNING_MSB          4
#define MIDI_CONTROL_RPN_COARSE_TUNING_LSB          5

/** @} */

struct MIDIDevice;

struct MIDIController;
struct MIDIControllerDelegate {
  int (*recv_cc)( struct MIDIController * controller, struct MIDIDevice * device,
                  MIDIChannel channel, MIDIControl control, MIDILongValue value );
};

struct MIDIController * MIDIControllerCreate( struct MIDIControllerDelegate * delegate );
void MIDIControllerDestroy( struct MIDIController * controller );
void MIDIControllerRetain( struct MIDIController * controller );
void MIDIControllerRelease( struct MIDIController * controller );

int MIDIControllerSetControl( struct MIDIController * controller, MIDIControl control, size_t size,  void * value );
int MIDIControllerGetControl( struct MIDIController * controller, MIDIControl control, size_t size,  void * value );
int MIDIControllerSetRegisteredParameter( struct MIDIController * controller, MIDIControlParameter parameter, size_t size,  void * value );
int MIDIControllerGetRegisteredParameter( struct MIDIController * controller, MIDIControlParameter parameter, size_t size,  void * value );
int MIDIControllerSetNonRegisteredParameter( struct MIDIController * controller, MIDIControlParameter parameter, size_t size,  void * value );
int MIDIControllerGetNonRegisteredParameter( struct MIDIController * controller, MIDIControlParameter parameter, size_t size,  void * value );

int MIDIControllerStore( struct MIDIController * controller, size_t size, void * buffer, size_t * written );
int MIDIControllerRecall( struct MIDIController * controller, size_t size, void * buffer, size_t * read );

int MIDIControllerReceiveControlChange( struct MIDIController * controller, struct MIDIDevice * device,
                                        MIDIChannel channel, MIDIControl control, MIDIValue value );
int MIDIControllerSendControlChange( struct MIDIController * controller, struct MIDIDevice * device,
                                     MIDIChannel channel, MIDIControl control, MIDIValue value );

#endif
