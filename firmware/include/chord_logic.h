#ifndef CHORD_LOGIC_H
#define CHORD_LOGIC_H

#include <stdint.h>

// Chord definitions (semitones from root)
// After the four notes of the chord (fundamental, third, fifth, seventh/octave),
// the next notes are decorations (second, fourth, sixth)
struct ChordDefinition {
    uint8_t notes[7];
};

// Chord type definitions
namespace ChordTypes {
    const ChordDefinition MAJOR = {{0, 4, 7, 12, 2, 5, 9}};
    const ChordDefinition MINOR = {{0, 3, 7, 12, 1, 5, 8}};
    const ChordDefinition MAJ_SIXTH = {{0, 4, 7, 9, 2, 5, 12}};
    const ChordDefinition MIN_SIXTH = {{0, 3, 7, 9, 1, 5, 12}};
    const ChordDefinition SEVENTH = {{0, 4, 10, 7, 2, 5, 9}};
    const ChordDefinition MAJ_SEVENTH = {{0, 4, 11, 7, 2, 5, 9}};
    const ChordDefinition MIN_SEVENTH = {{0, 3, 10, 7, 1, 5, 8}};
    const ChordDefinition AUGMENTED = {{0, 4, 8, 12, 2, 5, 9}};
    const ChordDefinition DIMINISHED = {{0, 3, 6, 12, 2, 5, 9}};
    const ChordDefinition FULL_DIMINISHED = {{0, 3, 6, 9, 2, 5, 12}};
}

// Circle of fifths root notes (F, C, G, D, A, E, B)
const uint8_t CIRCLE_OF_FIFTHS[7] = {11, 4, 9, 2, 7, 0, 5};

/**
 * Calculate the MIDI note number for a chord voice
 * 
 * @param voice The voice index (0-3 typically for 4-voice chords)
 * @param chord The chord definition to use
 * @param shuffling_pattern The pattern defining which chord degree to play (e.g., [0, 2, 4, 10] for root, 3rd, 5th, oct)
 * @param fundamental_index Index into circle of fifths (0-6)
 * @param slash_value Alternative bass note (index into circle of fifths)
 * @param note_slash_level Which chord degree to replace with slash (0-2)
 * @param is_slashed Whether slash chord is active
 * @param is_sharp Whether sharp modifier is active
 * @param is_flat_modifier Whether flat modifier is active (inverts sharp behavior)
 * @return MIDI note number (0-127)
 */
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

/**
 * Calculate the MIDI note number for a harp string
 * 
 * @param string_index The string index (0-11)
 * @param chord The chord definition to use
 * @param shuffling_pattern The pattern defining which chord degree to play
 * @param fundamental_index Index into circle of fifths (0-6)
 * @param slash_value Alternative bass note (index into circle of fifths)
 * @param note_slash_level Which chord degree to replace with slash (0-2)
 * @param is_slashed Whether slash chord is active
 * @param is_sharp Whether sharp modifier is active
 * @param is_flat_modifier Whether flat modifier is active
 * @param chromatic_mode If true, ignore chord and play chromatic scale
 * @return MIDI note number (0-127)
 */
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

