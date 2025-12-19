#include "Servo.h"
#include "I2CDevice.h"
#include <cstdint>
#include <iostream>
#include <unistd.h>

uint16_t usToCounts(double us) {
  double period_us = 1e6f / PWM_FREQUENCY;
  return static_cast<uint16_t>((us / period_us) * 4096.0);
}

//
// Servo class stuff
//
Servo::Servo(I2CDevice &device, uint8_t channel, uint16_t duty_min,
             uint16_t duty_max, double angle_min, double angle_max)
    : i2cDevice(device), channel(channel), duty_min(duty_min),
      duty_max(duty_max), angle_min(angle_min), angle_max(angle_max) {}

void Servo::setAngle(double angle) {
  if (angle < angle_min)
    angle = angle_min;
  if (angle > angle_max)
    angle = angle_max;

  double duty_cycle = duty_min + (angle / 180.0f) * (duty_max - duty_min);

  std::cout << "Servo: " << std::to_string(channel) << "\t| angle: " << angle << "\t| duty_cycle: " << duty_cycle
            << "\t| counts: " << usToCounts(duty_cycle) << std::endl;
  setDutyCycle(duty_cycle);
}

Servo::~Servo() { unstiff(); }

void Servo::setPWM(uint16_t duty_cycle) {
  i2cDevice.writeValue(REGISTER_LED0_ON  + (channel * ADDRESS_LED_OFFSET), (uint16_t) 0);
  i2cDevice.writeValue(REGISTER_LED0_OFF + (channel * ADDRESS_LED_OFFSET), duty_cycle);
}

void Servo::setDutyCycle(double duty_cycle) {
  assert((duty_cycle == 0) |
         (duty_cycle <= duty_max && duty_cycle >= duty_min));

  i2cDevice.writeValue(REGISTER_LED0_ON + (channel * ADDRESS_LED_OFFSET), (uint16_t)0);
  i2cDevice.writeValue(REGISTER_LED0_OFF + (channel * ADDRESS_LED_OFFSET), usToCounts(duty_cycle));
};

void Servo::unstiff() { setDutyCycle(0); }
