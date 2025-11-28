#include <unity.h>
#include "chord_logic.h"

// Include implementation for native testing
#include "../../src/chord_logic.cpp"

// Test shuffling patterns
// Format: octave*10 + chord_degree (e.g., 20 = octave 2, degree 0)
const uint8_t TEST_PATTERN_ROOT_POSITION[4] = {20, 22, 24, 30};
const uint8_t TEST_PATTERN_FIRST_INVERSION[4] = {22, 24, 30, 32};

void setUp(void) {
}

void tearDown(void) {
}

void test_c_major_root_position(void) {
    // CIRCLE_OF_FIFTHS[1] = 4 semitones from MIDI note 0
    uint8_t fundamental_index = 1;
    
    uint8_t note = calculate_note(
        0,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        0, 0, false, false, false
    );
    
    // Expected: octave 2 (24) + root offset (4) + chord degree 0 (0) = 28
    TEST_ASSERT_EQUAL_UINT8(28, note);
}

void test_c_major_third(void) {
    uint8_t fundamental_index = 1;
    
    uint8_t note = calculate_note(
        1,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        0, 0, false, false, false
    );
    
    // Expected: octave 2 (24) + root (4) + fifth (7) = 35
    TEST_ASSERT_EQUAL_UINT8(35, note);
}

void test_c_major_with_sharp(void) {
    uint8_t fundamental_index = 1;
    
    uint8_t note = calculate_note(
        0,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        0, 0, false,
        true,  // sharp modifier
        false
    );
    
    // Expected: 24 + 4 + 1 (sharp) + 0 = 29
    TEST_ASSERT_EQUAL_UINT8(29, note);
}

void test_c_major_with_flat_modifier(void) {
    uint8_t fundamental_index = 1;
    
    uint8_t note = calculate_note(
        0,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        0, 0, false,
        true,  // sharp button pressed
        true   // flat modifier inverts sharp
    );
    
    // Expected: 24 + 4 - 1 (flat) + 0 = 27
    TEST_ASSERT_EQUAL_UINT8(27, note);
}

void test_slash_chord(void) {
    uint8_t fundamental_index = 1;
    uint8_t slash_value = 0;  // F
    
    uint8_t note = calculate_note(
        0,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        slash_value,
        0,     // slash replaces degree 0 (root)
        true,  // slash chord enabled
        false, false
    );
    
    // Expected: 24 + CIRCLE_OF_FIFTHS[0] = 24 + 11 = 35
    TEST_ASSERT_EQUAL_UINT8(35, note);
}

void test_minor_chord(void) {
    uint8_t fundamental_index = 1;
    
    uint8_t note = calculate_note(
        1,
        ChordTypes::MINOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        0, 0, false, false, false
    );
    
    // Expected: 24 + 4 + 7 (fifth) = 35
    TEST_ASSERT_EQUAL_UINT8(35, note);
}

void test_harp_chromatic_mode(void) {
    for (uint8_t i = 0; i < 12; i++) {
        uint8_t note = calculate_harp_note(
            i,
            ChordTypes::MAJOR.notes,
            TEST_PATTERN_ROOT_POSITION,
            0, 0, 0, false, false, false,
            true  // chromatic mode
        );
        // Chromatic mode returns string index + 24
        TEST_ASSERT_EQUAL_UINT8(i + 24, note);
    }
}

void test_harp_chord_mode(void) {
    uint8_t fundamental_index = 1;
    
    uint8_t note = calculate_harp_note(
        0,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        0, 0, false, false, false,
        false  // chord mode
    );
    
    // Expected: same as chord calculation = 28
    TEST_ASSERT_EQUAL_UINT8(28, note);
}

void test_seventh_chord(void) {
    uint8_t fundamental_index = 1;
    
    uint8_t note = calculate_note(
        2,
        ChordTypes::SEVENTH.notes,
        TEST_PATTERN_ROOT_POSITION,
        fundamental_index,
        0, 0, false, false, false
    );
    
    // Expected: 24 + 4 + 2 (ninth decoration) = 30
    TEST_ASSERT_EQUAL_UINT8(30, note);
}

void test_different_fundamentals(void) {
    // F major
    uint8_t note_f = calculate_note(
        0,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        0, 0, 0, false, false, false
    );
    TEST_ASSERT_EQUAL_UINT8(35, note_f);
    
    // G major
    uint8_t note_g = calculate_note(
        0,
        ChordTypes::MAJOR.notes,
        TEST_PATTERN_ROOT_POSITION,
        2, 0, 0, false, false, false
    );
    TEST_ASSERT_EQUAL_UINT8(33, note_g);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    
    RUN_TEST(test_c_major_root_position);
    RUN_TEST(test_c_major_third);
    RUN_TEST(test_c_major_with_sharp);
    RUN_TEST(test_c_major_with_flat_modifier);
    RUN_TEST(test_slash_chord);
    RUN_TEST(test_minor_chord);
    RUN_TEST(test_harp_chromatic_mode);
    RUN_TEST(test_harp_chord_mode);
    RUN_TEST(test_seventh_chord);
    RUN_TEST(test_different_fundamentals);
    
    return UNITY_END();
}

