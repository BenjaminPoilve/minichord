#include "chord_logic.h"

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
) {
    uint8_t note = 0;
    uint8_t level = shuffling_pattern[voice];
    
    // Extract octave (tens digit) and degree (ones digit) from level
    uint8_t octave = level / 10;
    uint8_t degree = level % 10;
    
    // Only slash the selected level of the chord (ignored if degree > 6)
    if (is_slashed && degree == note_slash_level) {
        // Use the slash value as the root
        if (!is_flat_modifier) {
            note = (12 * octave + CIRCLE_OF_FIFTHS[slash_value] + (is_sharp ? 1 : 0));
        } else {
            note = (12 * octave + CIRCLE_OF_FIFTHS[slash_value] - (is_sharp ? 1 : 0));
        }
    } else {
        // Use the fundamental as the root
        if (!is_flat_modifier) {
            note = (12 * octave + CIRCLE_OF_FIFTHS[fundamental_index] + (is_sharp ? 1 : 0) + chord_notes[degree]);
        } else {
            note = (12 * octave + CIRCLE_OF_FIFTHS[fundamental_index] - (is_sharp ? 1 : 0) + chord_notes[degree]);
        }
    }
    
    return note;
}

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
) {
    if (!chromatic_mode) {
        // Use the same logic as chord calculation
        return calculate_note(
            string_index,
            chord_notes,
            shuffling_pattern,
            fundamental_index,
            slash_value,
            note_slash_level,
            is_slashed,
            is_sharp,
            is_flat_modifier
        );
    } else {
        // Chromatic mode: two octaves up to avoid being too low
        return string_index + 24;
    }
}

