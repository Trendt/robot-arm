#ifndef ROBOTARM_H_
#define ROBOTARM_H_

#include "../hardware/PWMController.h"
#include "../joints/joint_limits.h"
#include "../joints/servo_joint.h"

// TODO: export to config of some sort
constexpr PWMLimits   servo1_pwm_limits   {460, 2540};
constexpr JointLimits servo1_joint_limits {45.0, 135.0};

constexpr PWMLimits   servo2_pwm_limits   {460, 2540};
constexpr JointLimits servo2_joint_limits {20.0, 160.0};

constexpr PWMLimits   servo3_pwm_limits   {460, 2540};
constexpr JointLimits servo3_joint_limits {0.0, 125.0};

constexpr PWMLimits   servo4_pwm_limits   {460, 2540};
constexpr JointLimits servo4_joint_limits {0.0, 180.0};

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
  void setAngles(double servo1_angle, double servo2_angle, double servo3_angle, double servo4_angle);

  ServoJoint servo1, servo2, servo3, servo4;
private:
};

#endif // !ROBOTARM_H_
