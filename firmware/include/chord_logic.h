#ifndef CHORD_LOGIC_H
#define CHORD_LOGIC_H

#include <stdint.h>

// Chord definitions (semitones from root)
// After the four notes of the chord (fundamental, third, fifth, seventh/octave),
// the next notes are decorations (second, fourth, sixth)
struct ChordDefinition {
    const uint8_t* notes;
};

// Chord type definitions (declarations only - defined in chord_logic.cpp)
namespace ChordTypes {
    extern const ChordDefinition MAJOR;
    extern const ChordDefinition MINOR;
    extern const ChordDefinition MAJ_SIXTH;
    extern const ChordDefinition MIN_SIXTH;
    extern const ChordDefinition SEVENTH;
    extern const ChordDefinition MAJ_SEVENTH;
    extern const ChordDefinition MIN_SEVENTH;
    extern const ChordDefinition AUGMENTED;
    extern const ChordDefinition DIMINISHED;
    extern const ChordDefinition FULL_DIMINISHED;
}

extern const uint8_t CIRCLE_OF_FIFTHS[7]; // F, C, G, D, A, E, B (semitone offset from C)

// Original functions from main.cpp (exact behavior)
uint8_t calculate_note_chord(uint8_t voice, const uint8_t* chord_notes, const uint8_t* shuffling_pattern, 
                             uint8_t key_signature_selection, uint8_t chord_frame_shift, 
                             uint8_t fundamental, uint8_t slash_value, uint8_t note_slash_level,
                             bool slashed, bool sharp, bool flat_button_modifier);

uint8_t calculate_note_harp(uint8_t string, const uint8_t* chord_notes, const uint8_t* shuffling_pattern,
                            uint8_t key_signature_selection, uint8_t chord_frame_shift,
                            uint8_t fundamental, uint8_t slash_value, uint8_t note_slash_level,
                            bool slashed, bool sharp, bool flat_button_modifier, bool chromatic_harp_mode);

// Simplified wrapper functions for testing
uint8_t calculate_note(
    uint8_t voice,
    const uint8_t* chord_notes,
    const uint8_t* shuffling_pattern,
    uint8_t fundamental_index,
    uint8_t slash_value,
    uint8_t note_slash_level,
    bool is_slashed,
    bool is_sharp,
    bool is_flat_modifier
);

uint8_t calculate_harp_note(
    uint8_t string_index,
    const uint8_t* chord_notes,
    const uint8_t* shuffling_pattern,
    uint8_t fundamental_index,
    uint8_t slash_value,
    uint8_t note_slash_level,
    bool is_slashed,
    bool is_sharp,
    bool is_flat_modifier,
    bool chromatic_mode
);

#endif // CHORD_LOGIC_H

