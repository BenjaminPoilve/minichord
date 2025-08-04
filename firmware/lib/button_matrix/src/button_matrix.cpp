#include "button_matrix.h"

button_matrix::button_matrix(uint8_t d_in, uint8_t storage_clock, uint8_t shift_clock, uint8_t read_pin_1, uint8_t read_pin_2, uint8_t read_pin_3) {
  this->d_in = d_in;
  this->storage_clock = storage_clock;
  this->shift_clock = shift_clock;
  this->read_pin_1 = read_pin_1;
  this->read_pin_2 = read_pin_2;
  this->read_pin_3 = read_pin_3;
}

void button_matrix::setup() {
  pinMode(d_in, OUTPUT);
  pinMode(storage_clock, OUTPUT);
  pinMode(shift_clock, OUTPUT);
  pinMode(read_pin_1, INPUT);
  pinMode(read_pin_2, INPUT);
  pinMode(read_pin_3, INPUT);
}

void button_matrix::write_bit(bool data) {
  digitalWrite(shift_clock, LOW);
  digitalWrite(d_in, data ? HIGH : LOW);
  digitalWrite(shift_clock, HIGH);
}

void button_matrix::write_byte(byte data) {
  byte mask = 0x1;
  byte bits = data;
  digitalWrite(storage_clock, LOW);
  for (int i = registersBits - 1; i >= 0; i--) {
    write_bit(bits & mask);
    bits = bits >> 1;
  }
  digitalWrite(storage_clock, HIGH);
}

void button_matrix::update(debouncer (&data_array)[22]) {
  static bool initialized = false;
  if (!initialized) {
    data_array[0] = debouncer(20000, 0); // 20ms debounce for sharp
    for (int i = 1; i < 22; i++) {
      uint8_t group_id = ((i - 1) / 3) + 1;
      data_array[i] = debouncer(20000, group_id); // 20ms debounce for rows
    }
    initialized = true;
  }

  bool readings[22] = {false};
  byte index = 7;
  byte mask = 0x1;
  while (index > 0) {
    write_byte(~(mask << index));
    delayMicroseconds(5);
    readings[index * 3 - 2] = !digitalRead(read_pin_1); // Major
    readings[index * 3 - 1] = !digitalRead(read_pin_2); // Minor
    readings[index * 3] = !digitalRead(read_pin_3); // Seventh
    index--;
  }
  write_byte(~mask);
  delayMicroseconds(5);
  readings[0] = !digitalRead(read_pin_1);
  write_byte(~0x0);

  for (index = 1; index <= 7; index++) {
    uint8_t group_id = index;
    bool any_change = false;
    for (int i = index * 3 - 2; i <= index * 3; i++) {
      if (data_array[i].read_value() != readings[i]) {
        any_change = true;
        break;
      }
    }
    if (any_change) {
      debouncer::reset_group_timer(group_id);
      for (int i = index * 3 - 2; i <= 3 * index; i++) {
        data_array[i].set(readings[i]);
      }
    }
  }
  if (data_array[0].read_value() != readings[0]) {
    debouncer::reset_group_timer(0);
    data_array[0].set(readings[0]);
  }
}