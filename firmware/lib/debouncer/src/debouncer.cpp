#include "debouncer.h"

debouncer::debouncer(uint16_t debounce_time) : debounce_value(debounce_time) {
}

void debouncer::set_debounce(uint16_t debounce_time) {
  debounce_value = debounce_time;
}

void debouncer::set(bool set_value) {
  if (value != set_value) {
    flag = true;
    last_update = 0;
    value = set_value;
  }
}

uint8_t debouncer::read_transition() {
if (flag == true && last_update > debounce_value) {
    flag = false;
    last_update = 0; // Reset timer after transition
            if (value == true) {
            return 2; // Press transition
        } else {
            return 1; // Release transition
        }
  }
  return 0;
}

bool debouncer::read_value() {
  return value;
}

uint32_t debouncer::get_last_update() {
  return (uint32_t)last_update;
}