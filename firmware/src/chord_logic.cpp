#include "chord_logic.h"

// Musical constants and enums
enum KeySig {
    KEY_SIG_C, KEY_SIG_G, KEY_SIG_D, KEY_SIG_A, KEY_SIG_E, KEY_SIG_B,
    KEY_SIG_F, KEY_SIG_Bb, KEY_SIG_Eb, KEY_SIG_Ab, KEY_SIG_Db, KEY_SIG_Gb
};

enum Button {
    BTN_B, BTN_E, BTN_A, BTN_D, BTN_G, BTN_C, BTN_F
};

// Base note offsets for buttons in key of C (relative to C4 = MIDI 60), in hardware order B, E, A, D, G, C, F
const int8_t base_notes[7] = {11, 4, 9, 2, 7, 0, 5};

// Number of sharps or flats for each key: Sharps for C, G, D, A, E, B; flats for F, Bb, Eb, Ab, Db, Gb
const int8_t key_signatures[12] = {0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6};

// Notes affected by sharps in each key, in hardware order (B, E, A, D, G, C, F)
const int8_t sharp_notes[6][6] = {
    {BTN_F},          // 1 sharp: F#
    {BTN_F, BTN_C},   // 2 sharps: F#, C#
    {BTN_F, BTN_C, BTN_G}, // 3 sharps: F#, C#, G#
    {BTN_F, BTN_C, BTN_G, BTN_D}, // 4 sharps: F#, C#, G#, D#
    {BTN_F, BTN_C, BTN_G, BTN_D, BTN_A}, // 5 sharps: F#, C#, G#, D#, A#
    {BTN_F, BTN_C, BTN_G, BTN_D, BTN_A, BTN_E} // 6 sharps: F#, C#, G#, D#, A#, E#
};

// Notes affected by flats in each key, in hardware order (B, E, A, D, G, C, F)
const int8_t flat_notes[6][6] = {
    {BTN_B},          // 1 flat: Bb
    {BTN_B, BTN_E},   // 2 flats: Bb, Eb
    {BTN_B, BTN_E, BTN_A}, // 3 flats: Bb, Eb, Ab
    {BTN_B, BTN_E, BTN_A, BTN_D}, // 4 flats: Bb, Eb, Ab, Db
    {BTN_B, BTN_E, BTN_A, BTN_D, BTN_G}, // 5 flats: Bb, Eb, Ab, Db, Gb
    {BTN_B, BTN_E, BTN_A, BTN_D, BTN_G, BTN_C} // 6 flats: Bb, Eb, Ab, Db, Gb, Cb
};

// Chord definitions (semitones from root)
namespace ChordTypes {
    const uint8_t major_notes[7] = {0, 4, 7, 12, 2, 5, 9};
    const uint8_t minor_notes[7] = {0, 3, 7, 12, 1, 5, 8};
    const uint8_t maj_sixth_notes[7] = {0, 4, 7, 9, 2, 5, 12};
    const uint8_t min_sixth_notes[7] = {0, 3, 7, 9, 1, 5, 12};
    const uint8_t seventh_notes[7] = {0, 4, 10, 7, 2, 5, 9};
    const uint8_t maj_seventh_notes[7] = {0, 4, 11, 7, 2, 5, 9};
    const uint8_t min_seventh_notes[7] = {0, 3, 10, 7, 1, 5, 8};
    const uint8_t augmented_notes[7] = {0, 4, 8, 12, 2, 5, 9};
    const uint8_t diminished_notes[7] = {0, 3, 6, 12, 2, 5, 9};
    const uint8_t full_diminished_notes[7] = {0, 3, 6, 9, 2, 5, 12};

    const ChordDefinition MAJOR = {major_notes};
    const ChordDefinition MINOR = {minor_notes};
    const ChordDefinition MAJ_SIXTH = {maj_sixth_notes};
    const ChordDefinition MIN_SIXTH = {min_sixth_notes};
    const ChordDefinition SEVENTH = {seventh_notes};
    const ChordDefinition MAJ_SEVENTH = {maj_seventh_notes};
    const ChordDefinition MIN_SEVENTH = {min_seventh_notes};
    const ChordDefinition AUGMENTED = {augmented_notes};
    const ChordDefinition DIMINISHED = {diminished_notes};
    const ChordDefinition FULL_DIMINISHED = {full_diminished_notes};
}

const uint8_t CIRCLE_OF_FIFTHS[7] = {11, 4, 9, 2, 7, 0, 5}; // F, C, G, D, A, E, B (semitone offset from C)

// Function to compute MIDI note offset dynamically with circular frame shift
int8_t get_root_button(uint8_t key, uint8_t shift, uint8_t button) { 
    int8_t note = base_notes[button]; // Start with base note in C (e.g., B = 11, E = 4, ..., F = 5)
    
    // Apply circular frame shift: move notes C, D, E, F, G, A, B up an octave based on shift
    // Map button to musical note index (C=0, D=1, E=2, F=3, G=4, A=5, B=6)
    int8_t musical_index;
    switch (button) {
        case BTN_B: musical_index = 6; break; // B
        case BTN_E: musical_index = 2; break; // E
        case BTN_A: musical_index = 5; break; // A
        case BTN_D: musical_index = 1; break; // D
        case BTN_G: musical_index = 4; break; // G
        case BTN_C: musical_index = 0; break; // C
        case BTN_F: musical_index = 3; break; // F
        default: musical_index = 0; // Should not happen
    }
    if (musical_index < shift) {
        note += 12; // Move up one octave if the note is shifted "on top"
    }
    
    int8_t num_accidentals = key_signatures[key];   // Apply key signature (sharps or flats)
    if (key <= KEY_SIG_B) { // Sharp keys (C, G, D, A, E, B)
        for (int i = 0; i < num_accidentals; i++) {
            if (button == sharp_notes[num_accidentals - 1][i]) {
                note += 1; // Add sharp
            }
        }
    } else { // Flat keys (F, Bb, Eb, Ab, Db, Gb)
        for (int i = 0; i < num_accidentals; i++) {
            if (button == flat_notes[num_accidentals - 1][i]) {
                note -= 1; // Add flat
            }
        }
    }

    return note; //No need to constrain here
}

// Chord note calculation function
uint8_t calculate_note_chord(uint8_t voice, const uint8_t* chord_notes, const uint8_t* shuffling_pattern, 
                             uint8_t key_signature_selection, uint8_t chord_frame_shift, 
                             uint8_t fundamental, uint8_t slash_value, uint8_t note_slash_level,
                             bool slashed, bool sharp, bool flat_button_modifier) {
    uint8_t note = 0;
    uint8_t level = shuffling_pattern[voice];
    if (slashed && level % 10 == note_slash_level) {
        if (!flat_button_modifier) {
            note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, slash_value) + sharp * 1.0);
        } else {
            note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, slash_value) - sharp * 1.0);
        }
    } else {
        if (!flat_button_modifier) {
            note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, fundamental) + sharp * 1.0 + chord_notes[level % 10]);
        } else {
            note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, fundamental) - sharp * 1.0 + chord_notes[level % 10]);
        }
    }
    return note;
}

// Harp note calculation function
uint8_t calculate_note_harp(uint8_t string, const uint8_t* chord_notes, const uint8_t* shuffling_pattern,
                            uint8_t key_signature_selection, uint8_t chord_frame_shift,
                            uint8_t fundamental, uint8_t slash_value, uint8_t note_slash_level,
                            bool slashed, bool sharp, bool flat_button_modifier, bool chromatic_harp_mode) {
    if (!chromatic_harp_mode) {
        uint8_t note = 0;
        uint8_t level = shuffling_pattern[string];
        if (slashed && level % 10 == note_slash_level) {
            if (!flat_button_modifier) {
                note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, slash_value) + sharp * 1.0);
            } else {
                note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, slash_value) - sharp * 1.0);
            }
        } else {
            if (!flat_button_modifier) {
                note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, fundamental) + sharp * 1.0 + chord_notes[level % 10]);
            } else {
                note = (12 * int(level / 10) + get_root_button(key_signature_selection, chord_frame_shift, fundamental) - sharp * 1.0 + chord_notes[level % 10]);
            }
        }
        return note;
    } else {
        return string + 24; // Chromatic mode
    }
}

// Simplified interface functions
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
    // Use default values for key signature and frame shift
    return calculate_note_chord(
        voice, chord_notes, shuffling_pattern,
        0,  // key_signature_selection (C major)
        0,  // chord_frame_shift (no shift)
        fundamental_index, slash_value, note_slash_level,
        is_slashed, is_sharp, is_flat_modifier
    );
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
    // Use default values for key signature and frame shift
    return calculate_note_harp(
        string_index, chord_notes, shuffling_pattern,
        0,  // key_signature_selection (C major)
        0,  // chord_frame_shift (no shift)
        fundamental_index, slash_value, note_slash_level,
        is_slashed, is_sharp, is_flat_modifier, chromatic_mode
    );
}