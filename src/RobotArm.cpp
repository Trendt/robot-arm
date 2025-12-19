#include "RobotArm.h"
#include <unistd.h>

void RobotArm::moveTo(double targetX, double targetY, double targetZ) {
    // servo1.setAngle(0.0);
    // servo2.setAngle(0.0);
    // servo3.setAngle(0.0);
};

void RobotArm::home() {
  servo1.setAngle(90.0);
  servo2.setAngle(90.0);
  servo3.setAngle(90.0);
  servo4.setAngle(90.0);
};

void RobotArm::unstiff(){
  servo1.unstiff();
  servo2.unstiff();
  servo3.unstiff();
  servo4.unstiff();
}

void RobotArm::setAngles(double servo1_angle, double servo2_angle, double servo3_angle){
    setAngles(servo1_angle, servo2_angle, servo3_angle, 90.0f);
}

void RobotArm::setAngles(double servo1_angle, double servo2_angle, double servo3_angle, double servo4_angle){
    servo1.setAngle(servo1_angle);
    servo2.setAngle(servo2_angle);
    servo3.setAngle(servo3_angle);
    servo4.setAngle(servo4_angle);
};

RobotArm::~RobotArm() {
    unstiff();
}
