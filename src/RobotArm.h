#ifndef ROBOTARM_H_
#define ROBOTARM_H_

#include "I2CDevice.h"
#include "Servo.h"

// export to config of some sort
constexpr uint16_t servo1_duty_min = 460;
constexpr uint16_t servo1_duty_max = 2540;
constexpr double servo1_angle_min = 45.0;
constexpr double servo1_angle_max = 135.0;

constexpr uint16_t servo2_duty_min = 460;
constexpr uint16_t servo2_duty_max = 2540;
constexpr double servo2_angle_min = 20.0;
constexpr double servo2_angle_max = 160.0;

constexpr uint16_t servo3_duty_min = 460;
constexpr uint16_t servo3_duty_max = 2540;
constexpr double servo3_angle_min = 00.0;
constexpr double servo3_angle_max = 125.0;

constexpr uint16_t servo4_duty_min = 460;
constexpr uint16_t servo4_duty_max = 2540;
constexpr double servo4_angle_min = 0.0;
constexpr double servo4_angle_max = 180.0;

class RobotArm {
public:
  RobotArm(I2CDevice &device)
      : servo1(device, 0, servo1_duty_min, servo1_duty_max, servo1_angle_min, servo1_angle_max),
        servo2(device, 1, servo2_duty_min, servo2_duty_max, servo2_angle_min, servo2_angle_max),
        servo3(device, 2, servo3_duty_min, servo3_duty_max, servo3_angle_min, servo3_angle_max),
        servo4(device, 3, servo4_duty_min, servo4_duty_max, servo4_angle_min, servo4_angle_max) {}
  ~RobotArm();

  void moveTo(double targetX, double targetY, double targetZ);
  void home();
  void unstiff();
  void setAngles(double servo1_angle, double servo2_angle, double servo3_angle);
  void setAngles(double servo1_angle, double servo2_angle, double servo3_angle, double servo4_angle);

  Servo servo1, servo2, servo3, servo4;
private:
};

#endif // !ROBOTARM_H_
