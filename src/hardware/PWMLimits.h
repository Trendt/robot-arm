#ifndef PWM_LIMITS_H_
#define PWM_LIMITS_H_

#include <algorithm>
#include <cstdint>

struct PWMLimits {
  uint16_t min_duty_cycle;
  uint16_t max_duty_cycle;

  float clamp_duty_cycle(uint16_t duty_cycle) {
    if (duty_cycle == 0)
      return duty_cycle;

    return std::clamp(duty_cycle, min_duty_cycle, max_duty_cycle);
  }
};

#endif // !PWM_LIMITS_H_
