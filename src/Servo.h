#ifndef SERVO_H_
#define SERVO_H_

#include "I2CDevice.h"

#include <cassert>
#include <cstdint>

extern const unsigned int BASE_START_ADDRESS;
extern const unsigned int BASE_STOP_ADDRESS;
extern const unsigned int OFFSET;
extern const unsigned int CHANNEL_MAX;

inline int channel_to_address(unsigned int channel) {
  assert(channel <= CHANNEL_MAX);
  return BASE_START_ADDRESS + (channel * OFFSET);
};

class Servo {
public:
  Servo(I2CDevice &device, uint8_t channel)
      : i2cDevice(device), channel(channel) {}
  ~Servo();

  void setAngle(double angle);
  void setPWM(uint16_t pwm);

private:
  I2CDevice &i2cDevice;
  uint8_t channel;

  double angle;
};

#endif // !SERVO_H_
