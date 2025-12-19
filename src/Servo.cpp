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
Servo::Servo(I2CDevice &device, uint8_t channel)
    : i2cDevice(device), channel(channel) {}

void Servo::setAngle(double angle) {
  if (angle < 0.0)
    angle = 0.0;
  if (angle > 180.0)
    angle = 180.0;

  double duty_cycle = SERVO_MIN_DUTY + (angle / 180.0f) * (SERVO_MAX_DUTY - SERVO_MIN_DUTY);

  std::cout << "angle: " << angle << " | duty_cycle: " << duty_cycle
            << " | counts: " << usToCounts(duty_cycle) << std::endl;
  setDutyCycle(duty_cycle);
}

Servo::~Servo() { setDutyCycle(0); }

void Servo::setPWM(uint16_t duty_cycle) {
  i2cDevice.writeValue(REGISTER_LED0_ON  + (channel * ADDRESS_LED_OFFSET), (uint16_t) 0);
  i2cDevice.writeValue(REGISTER_LED0_OFF + (channel * ADDRESS_LED_OFFSET), duty_cycle);
}

void Servo::setDutyCycle(double duty_cycle) {
  assert((duty_cycle == 0) | (duty_cycle <= SERVO_MAX_DUTY && duty_cycle >= SERVO_MIN_DUTY));

  i2cDevice.writeValue(REGISTER_LED0_ON + (channel * ADDRESS_LED_OFFSET),
                       (uint16_t)0);
  i2cDevice.writeValue(REGISTER_LED0_OFF + (channel * ADDRESS_LED_OFFSET),
                       usToCounts(duty_cycle));
};

void Servo::unstiff() { setDutyCycle(0); }
