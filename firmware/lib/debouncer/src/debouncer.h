#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include "Arduino.h"

class debouncer {
public:
  debouncer(uint16_t debounce_time = 30000, uint8_t group_id = 0);
  void set(bool set_value);
  void set_debounce(uint16_t debounce_time);
  uint8_t read_transition();
  bool read_value();
  uint32_t get_last_update();
  uint16_t get_debounce_value(); // Added getter for debounce_value
  static void reset_group_timer(uint8_t group_id);
private:
  uint16_t debounce_value;
  bool flag = false;
  bool pending_value = false;
  elapsedMicros last_update = 0;
  bool value = false;
  uint8_t group_id;
  static elapsedMicros group_last_update[8];
  static bool group_pending[8];
};

#endif