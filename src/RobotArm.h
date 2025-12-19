#ifndef ROBOTARM_H_
#define ROBOTARM_H_

#include "I2CDevice.h"
#include "Servo.h"

class RobotArm {
public:
  RobotArm(I2CDevice &device)
      : servo4(device, 3), servo1(device, 0), servo2(device, 1), servo3(device, 2){}
  ~RobotArm();

  void moveTo(double targetX, double targetY, double targetZ);
  void home();
  void unstiff();
  void setAngles(double servo1_angle, double servo2_angle, double servo3_angle);
  void setAngles(double servo1_angle, double servo2_angle, double servo3_angle, double servo4_angle);

 Servo servo4;

private:
  Servo servo1, servo2, servo3;
};

#endif // !ROBOTARM_H_
