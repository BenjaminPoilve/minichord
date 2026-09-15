// Project-local override of the Teensy core's USB descriptor parameters.
//
// The stock USB_MIDI16_AUDIO_SERIAL type in the framework's usb_desc.h declares
// 16 MIDI cables; the minichord only exposes 2. Rather than editing the file in
// ~/.platformio/packages/framework-arduinoteensy (which is shared with every
// other project on the machine), this header is force-included in front of every
// translation unit via the -include flag in platformio.ini.
//
// The trick: the core's usb_desc.h starts with `#pragma once`, so pulling it in
// from here means the core sources that later `#include "usb_desc.h"` get a
// no-op and keep the values set below.

#ifndef __ASSEMBLER__

// usb.c and usb_desc.c define this before including usb_desc.h to get the
// descriptor list declarations. Since we read the header first, define it here
// so those declarations are present for them.
#define USB_DESC_LIST_DEFINE
#include <usb_desc.h>

#ifdef MIDI_NUM_CABLES
#undef MIDI_NUM_CABLES
#define MIDI_NUM_CABLES 2
#endif

#endif // __ASSEMBLER__
