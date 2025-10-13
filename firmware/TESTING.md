# MiniChord Firmware Testing Guide

This guide provides comprehensive information about testing the MiniChord firmware.

## Overview

The MiniChord firmware uses a hybrid testing approach:
- **Unit tests** for pure logic functions (chord calculations, serialization, etc.)
- **Integration tests** (future) for hardware interaction simulation
- **Manual testing** for actual hardware functionality

## Test Framework

We use [Unity](http://www.throwtheswitch.org/unity) as our test framework, which is:
- Lightweight and suitable for embedded systems
- Well-integrated with PlatformIO
- Simple to write and understand

## Running Tests

### Prerequisites

- PlatformIO Core or PlatformIO IDE (VSCode extension)
- Python 3.7+

### Command Line

```bash
# Run all tests
cd firmware
pio test -e native

# Run specific test
pio test -e native -f test_chord_logic

# Run tests with verbose output
pio test -e native --verbose
```

### VSCode

1. Install PlatformIO IDE extension
2. Open the firmware folder
3. Click the PlatformIO icon in the sidebar
4. Navigate to "Test" → "native"
5. Click "Test All" or select specific tests

## Test Organization

```
firmware/
├── test/
│   ├── test_chord_logic/
│   │   └── test_chord_logic.cpp      # Chord calculation tests
│   └── test_serialization/
│       └── test_serialization.cpp     # Serialization tests
├── src/
│   ├── chord_logic.cpp                # Testable chord logic
│   └── main.cpp                       # Main firmware
└── include/
    └── chord_logic.h                  # Chord logic interface
```

## Current Test Coverage

### Chord Logic (`test_chord_logic`)

Tests the core musical functionality:

- ✅ Basic chord construction (major, minor, 7th, etc.)
- ✅ Sharp modifier behavior
- ✅ Flat modifier behavior
- ✅ Slash chord functionality
- ✅ Different root notes (circle of fifths)
- ✅ Harp chromatic mode
- ✅ Harp chord mode

**Example:**
```cpp
void test_c_major_root_position(void) {
    uint8_t note = calculate_note(
        0,                              // voice 0 (root)
        ChordTypes::MAJOR.notes,        // C major chord
        TEST_PATTERN_ROOT_POSITION,     // voicing pattern
        1,                              // C in circle of fifths
        0, 0, false, false, false
    );
    TEST_ASSERT_EQUAL_UINT8(28, note);  // Expected MIDI note
}
```

### Serialization (`test_serialization`)

Tests parameter storage format:

- ✅ CSV deserialization
- ✅ Negative value handling
- ✅ Empty string handling
- ✅ Boundary conditions
- ✅ Partial data handling

## Writing New Tests

### 1. Create Test Directory

```bash
mkdir firmware/test/test_my_feature
```

### 2. Create Test File

`firmware/test/test_my_feature/test_my_feature.cpp`:

```cpp
#include <unity.h>
#include "my_feature.h"  // Include the code you're testing

void setUp(void) {
    // Runs before each test
    // Initialize test fixtures here
}

void tearDown(void) {
    // Runs after each test
    // Clean up here
}

void test_my_feature_basic(void) {
    // Arrange
    int input = 5;
    
    // Act
    int result = my_function(input);
    
    // Assert
    TEST_ASSERT_EQUAL_INT(10, result);
}

void test_my_feature_edge_case(void) {
    TEST_ASSERT_EQUAL_INT(0, my_function(0));
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_my_feature_basic);
    RUN_TEST(test_my_feature_edge_case);
    return UNITY_END();
}
```

### 3. Extract Testable Code

If testing existing code in `main.cpp`, extract it to a separate module:

1. Create header in `include/my_module.h`
2. Create implementation in `src/my_module.cpp`
3. Make functions pure (no global state if possible)
4. Use parameters instead of globals

**Before:**
```cpp
// In main.cpp - hard to test
uint8_t global_value = 5;

void do_something() {
    global_value = global_value * 2;
}
```

**After:**
```cpp
// In my_module.h - easy to test
uint8_t calculate_something(uint8_t input);

// In my_module.cpp
uint8_t calculate_something(uint8_t input) {
    return input * 2;
}
```

## Testing Best Practices

### 1. Test One Thing
Each test should verify one specific behavior:

```cpp
// Good
void test_major_chord_root_note(void) {
    uint8_t note = calculate_note(/* params */);
    TEST_ASSERT_EQUAL_UINT8(expected, note);
}

// Avoid
void test_all_chords(void) {
    // Testing multiple things in one test
}
```

### 2. Use Descriptive Names
Test names should describe what they test:

```cpp
void test_c_major_with_sharp_modifier(void) { /* ... */ }
void test_slash_chord_replaces_bass_note(void) { /* ... */ }
```

### 3. Follow AAA Pattern
- **Arrange**: Set up test data
- **Act**: Call the function
- **Assert**: Verify the result

```cpp
void test_example(void) {
    // Arrange
    uint8_t input = 5;
    uint8_t expected = 10;
    
    // Act
    uint8_t result = my_function(input);
    
    // Assert
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
```

### 4. Test Edge Cases
Don't just test the happy path:

```cpp
void test_boundary_max_value(void) { /* ... */ }
void test_boundary_min_value(void) { /* ... */ }
void test_null_input(void) { /* ... */ }
void test_empty_array(void) { /* ... */ }
```

## Common Unity Assertions

```cpp
TEST_ASSERT_TRUE(condition)
TEST_ASSERT_FALSE(condition)
TEST_ASSERT_EQUAL_INT(expected, actual)
TEST_ASSERT_EQUAL_UINT8(expected, actual)
TEST_ASSERT_EQUAL_FLOAT(expected, actual)
TEST_ASSERT_NULL(pointer)
TEST_ASSERT_NOT_NULL(pointer)
TEST_ASSERT_EQUAL_STRING(expected, actual)
TEST_ASSERT_EQUAL_MEMORY(expected, actual, length)
```

## Continuous Integration

Tests run automatically on GitHub Actions:
- On every push to `main` or `develop`
- On every pull request
- When firmware files or test workflow change

See `.github/workflows/firmware-tests.yml` for configuration.

## Future Testing Goals

### Short Term
- [ ] Add tests for rhythm mode logic
- [ ] Test waveshaper calculation
- [ ] Test frequency calculation functions

### Medium Term
- [ ] Mock hardware interfaces for integration tests
- [ ] Test MIDI message handling
- [ ] Test preset save/load logic

### Long Term
- [ ] Hardware-in-the-loop testing with Teensy
- [ ] Automated regression testing
- [ ] Performance benchmarks

## Troubleshooting

### Tests Won't Run

**Issue:** `pio: command not found`
**Solution:** Install PlatformIO:
```bash
pip install platformio
```

**Issue:** Compilation errors in native environment
**Solution:** Check that you're not including Arduino-specific headers in test files

### Tests Fail After Code Changes

1. Check if the logic changed intentionally
2. Update test expectations if behavior is correct
3. Fix the code if tests reveal a regression

### Adding New Dependencies

If tests need external libraries:

1. Add to `platformio.ini` under `[env:native]`:
```ini
[env:native]
platform = native
test_framework = unity
lib_deps = 
    your-library-name
```

## Contributing

When submitting PRs with firmware changes:

1. ✅ Run tests locally: `pio test -e native`
2. ✅ Add tests for new features
3. ✅ Update tests if changing behavior
4. ✅ Ensure CI passes
5. ✅ Document any new test patterns

## Resources

- [Unity Documentation](https://github.com/ThrowTheSwitch/Unity)
- [PlatformIO Testing Guide](https://docs.platformio.org/en/latest/advanced/unit-testing/index.html)
- [Test-Driven Development in Embedded C](http://www.throwtheswitch.org/tddec) (Book)

