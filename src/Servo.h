#ifndef SERVO_H_
#define SERVO_H_

#include "I2CDevice.h"

#include <cassert>
#include <cstdint>
#include <cmath>

constexpr uint8_t PWM_FREQUENCY = 50;
constexpr uint8_t ADDRESS_LED_OFFSET = 4;
constexpr uint8_t CHANNEL_MAX = 15;

constexpr uint16_t SERVO_MIN_DUTY = 440;
constexpr uint16_t SERVO_MAX_DUTY = 2560;

constexpr uint8_t REGISTER_MODE1 =          0x00;
constexpr uint8_t REGISTER_MODE2 =          0x01;
constexpr uint8_t REGISTER_ALLCALLADR =     0x05;
constexpr uint8_t REGISTER_LED0_ON =        0x06;
constexpr uint8_t REGISTER_LED0_OFF =       0x08;
constexpr uint8_t REGISTER_ALL_LED_ON =     0xfa;
constexpr uint8_t REGISTER_ALL_LED_OFF =    0xfc;
constexpr uint8_t REGISTER_PRE_SCALE =      0xfe;
constexpr uint8_t REGISTER_TESTMODE =       0xff;

constexpr uint8_t MODE1_RESTART =    0b10000000;
constexpr uint8_t MODE1_EXTCLK =     0b01000000;
constexpr uint8_t MODE1_AI =         0b00100000;
constexpr uint8_t MODE1_SLEEP =      0b00010000;
constexpr uint8_t MODE1_SUB1 =       0b00001000;
constexpr uint8_t MODE1_SUB2 =       0b00000100;
constexpr uint8_t MODE1_SUB3 =       0b00000010;
constexpr uint8_t MODE1_ALLCALL =    0b00000001;

constexpr uint8_t MODE2_INVRT =      0b00010000;
constexpr uint8_t MODE2_OCH =        0b00001000;
constexpr uint8_t MODE2_OUTDRV =     0b00000100;
constexpr uint8_t MODE2_OUTNE1 =     0b00000010;
constexpr uint8_t MODE2_OUTNE0 =     0b00000001;

class Servo {
public:
  Servo(I2CDevice &device, uint8_t channel);
  ~Servo();

  void setAngle(double angle);
  void setDutyCycle(double duty_cycle);
  void setPWM(uint16_t duty_cycle);
  void unstiff();

private:
  I2CDevice &i2cDevice;
  uint8_t channel;

  double angle;
};

#endif // !SERVO_H_
