#include "Servo.h"
#include "I2CDevice.h"

extern const unsigned int BASE_START_ADDRESS = 0x06;
extern const unsigned int BASE_STOP_ADDRESS = 0x08;
extern const unsigned int OFFSET = sizeof(char) * 4;
extern const unsigned int CHANNEL_MAX = 15;

void Servo::setAngle(double angle) {
  // TODO: compute position between 0..4069 from angle and write
  uint16_t position = 1250;

  setPWM(position);
}

Servo::~Servo() { setPWM(0); }

void Servo::setPWM(uint16_t pwm) {
  assert((pwm == 0) | (pwm <= 2000 && pwm >= 1000));

  // write start time
  uint8_t buffer[3];
  buffer[0] = BASE_START_ADDRESS + channel * OFFSET;
  buffer[1] = 0;
  buffer[2] = 0;
  i2cDevice.writeBuffer(buffer, 3);

  // write stop time
  buffer[0] = BASE_STOP_ADDRESS + channel * OFFSET;
  buffer[1] = (char)(pwm & 0xff);
  buffer[2] = (char)((pwm >> 8) & 0xff);
  i2cDevice.writeBuffer(buffer, 3);
};
