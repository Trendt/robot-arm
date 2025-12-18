#ifndef ROBOTARM_H_
#define ROBOTARM_H_

#include "I2CDevice.h"
#include "Servo.h"

class RobotArm {
public:
  RobotArm(I2CDevice &device)
      : servo1(device, 0), servo2(device, 1), servo3(device, 2) {}
  ~RobotArm();

  void moveTo(double targetX, double targetY, double targetZ);
  void home();
  void unstiff();
  void setPWM(uint16_t servo1_pwm, uint16_t servo2_pwm, uint16_t servo3_pwm);

private:
  Servo servo1, servo2, servo3;
};

#endif // !ROBOTARM_H_
