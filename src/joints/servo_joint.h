#ifndef SERVO_JOINT_H_
#define SERVO_JOINT_H_

#include "joint.h"
#include "joint_limits.h"
#include "../hardware/PWMController.h"
#include "../hardware/PWMLimits.h"

#include <cstdint>

class ServoJoint : public Joint {
public:
  ServoJoint(PWMController &pwm_controller, uint8_t channel,
             const PWMLimits &pwm_limits, const JointLimits limits)
      : pwm_controller(pwm_controller), channel(channel),
        pwm_limits(pwm_limits), joint_limits(limits) {};

  void setAngle(float angle) override;
  float position() override;
  void update(float dt) override;
  void unstiff() override;

private:
  PWMController &pwm_controller;
  uint8_t channel;

  JointLimits joint_limits;
  PWMLimits pwm_limits;

  float target_angle;
};

#endif // !SERVO_JOINT_H_
