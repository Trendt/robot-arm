#include "RobotArm.h"

void RobotArm::moveTo(double targetX, double targetY, double targetZ) {
    // servo1.setAngle(0.0);
    // servo2.setAngle(0.0);
    // servo3.setAngle(0.0);
};

void RobotArm::home() {
  servo1.setAngle(0.0);
  // servo2.setAngle(0.0);
  // servo3.setAngle(0.0);
};

void RobotArm::unstiff(){
  servo1.setPWM(0);
  servo2.setPWM(0);
  servo3.setPWM(0);
}

void RobotArm::setPWM(uint16_t servo1_pwm, uint16_t servo2_pwm,
                      uint16_t servo3_pwm) {
  servo1.setPWM(servo1_pwm);
  servo2.setPWM(servo2_pwm);
  servo3.setPWM(servo3_pwm);
}

RobotArm::~RobotArm() {
    home();
    unstiff();
}
