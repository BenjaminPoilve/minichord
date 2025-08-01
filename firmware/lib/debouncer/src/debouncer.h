#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include "Arduino.h" 

class debouncer {
public:
  debouncer(uint16_t debounce_time = 30000); // Default to 30ms
  void set(bool set_value);
  void set_debounce(uint16_t debounce_time);
  uint8_t read_transition();
  bool read_value();
  uint32_t get_last_update();
private:
  uint16_t debounce_value;
  bool flag = false;
  elapsedMicros last_update = 0;
  bool value = false;
};

#endif