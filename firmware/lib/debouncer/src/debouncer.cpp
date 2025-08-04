#include "debouncer.h"

elapsedMicros debouncer::group_last_update[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool debouncer::group_pending[8] = {false, false, false, false, false, false, false, false};

debouncer::debouncer(uint16_t debounce_time, uint8_t group_id) : debounce_value(debounce_time), group_id(group_id) {
}

void debouncer::set_debounce(uint16_t debounce_time) {
  debounce_value = debounce_time;
}

void debouncer::set(bool set_value) {
  if (value != set_value) {
    flag = true;
    pending_value = set_value;
    group_pending[group_id] = true;
    if (last_update == 0) {
      last_update = 0;
      group_last_update[group_id] = 0;
    }
  }
}

uint8_t debouncer::read_transition() {
  if (flag && group_pending[group_id] && group_last_update[group_id] > debounce_value) {
    flag = false;
    value = pending_value;
    if (!group_pending[group_id]) {
      group_last_update[group_id] = 0;
    }
    if (value) {
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

uint16_t debouncer::get_debounce_value() {
  return debounce_value;
}

void debouncer::reset_group_timer(uint8_t group_id) {
  bool any_pending = false;
  for (int i = 1; i <= 7; i++) {
    if (group_pending[i]) {
      any_pending = true;
      break;
    }
  }
  if (!any_pending) {
    group_last_update[group_id] = 0;
    group_pending[group_id] = false;
  }
}