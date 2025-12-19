#ifndef ROBOTARM_H_
#define ROBOTARM_H_

#include "../hardware/PWMController.h"
#include "../joints/servo_joint.h"
#include "RobotArmModel.h"

class RobotArm {
public:
  RobotArm(PWMController &pwm_controller)
      : servo1(pwm_controller, 0, servo1_pwm_limits, servo1_joint_limits),
        servo2(pwm_controller, 1, servo2_pwm_limits, servo2_joint_limits),
        servo3(pwm_controller, 2, servo3_pwm_limits, servo3_joint_limits),
        servo4(pwm_controller, 3, servo4_pwm_limits, servo4_joint_limits) {}
  ~RobotArm();

  void home();
  void unstiff();
  void update(float dt);
  void setAngles(double servo1_angle, double servo2_angle, double servo3_angle);
  void setAngles(double servo1_angle, double servo2_angle, double servo3_angle,
                 double servo4_angle);

  ServoJoint servo1, servo2, servo3, servo4;

private:
};

#endif // !ROBOTARM_H_
