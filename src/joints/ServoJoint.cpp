#include "ServoJoint.h"

void ServoJoint::setAngle(float angle) {
  angle = joint_limits.clampAngle(angle);
  target_angle = angle;
}

float ServoJoint::getAngle() {
  // TODO: actual current angle readable from register?
  return target_angle;
};

void ServoJoint::update(float dt) {
  double duty_cycle = pwm_limits.min_duty_cycle + (target_angle / 180.0f)
                    * (pwm_limits.max_duty_cycle - pwm_limits.min_duty_cycle);
  pwm_controller.setDutyCycle(channel, duty_cycle);
};

void ServoJoint::unstiff() { pwm_controller.setDutyCycle(channel, 0.0); }
