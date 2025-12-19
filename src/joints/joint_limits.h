#ifndef JOINT_LIMITS_H_
#define JOINT_LIMITS_H_

#include <algorithm>

struct JointLimits {
  float angle_min;
  float angle_max;

  inline float clampAngle(float angle) {
    return std::clamp(angle, angle_min, angle_max);
  }
};

#endif // !JOINT_LIMITS_H_
