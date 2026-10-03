// Temperament arithmetic, kept free of Arduino and audio code so it can be
// checked on a computer (generator/temperament_test.cpp) as well as used by
// the firmware. The tables themselves are generated: see temperament_profiles.h.
#pragma once
#include <stdint.h>
#include <math.h>
#include "temperament_profiles.h"

// Frequency ratio of a note, in semitones above the reference, in temperament t.
// Temperament 0 is equal and returns exactly the expression the firmware has
// always used, so the default path is bit-for-bit unchanged.
inline double temperament_ratio(uint8_t t, int note) {
  if (t == 0 || t >= temperament_count) return pow(2, note / 12.0);
  int pitch_class = ((note % 12) + 12) % 12;
  return pow(2, (note + temperament_cents[t][pitch_class] / 100.0) / 12.0);
}

// The same temperament's offset alone, as a frequency factor, for sounds that
// are built as an interval above a note rather than from the note number.
inline double temperament_offset_factor(uint8_t t, int note) {
  if (t == 0 || t >= temperament_count) return 1.0;
  int pitch_class = ((note % 12) + 12) % 12;
  return pow(2, temperament_cents[t][pitch_class] / 1200.0);
}
