#include "PWMController.h"

uint16_t PWMController::usToCounts(double us) {
  double period_us = 1e6f / PWM_FREQUENCY;
  return static_cast<uint16_t>((us / period_us) * 4096.0);
}

uint8_t PWMController::calcPWMPrescale() {
  double prescale = 25e6f * OSC_FACTOR / (4096.0f * PWM_FREQUENCY) - 1;
  return static_cast<uint8_t>(prescale + 0.5f); // + 0.5f to make it round up instead of floor
}

PWMController::PWMController(I2CDevice &i2c) : i2c(i2c) {
  // enable totem-pole structure
  i2c.setFlag(REGISTER_MODE2, MODE2_OUTDRV);

  // enable multi-byte writing / auto increment
  i2c.setFlag(REGISTER_MODE1, MODE1_AI);
  i2c.setFlag(REGISTER_MODE1, MODE1_SLEEP);

  // set prescale (frequency)
  i2c.writeValue(REGISTER_PRE_SCALE, calcPWMPrescale());

  // wake
  i2c.unsetFlag(REGISTER_MODE1, MODE1_SLEEP);
  usleep(500);
  i2c.setFlag(REGISTER_MODE1, MODE1_RESTART);
}

PWMController::~PWMController() {
  // disable chip
  i2c.writeValue(0, (uint8_t)0);
}

void PWMController::setDutyCycle(uint8_t channel, double duty_cycle_ms) {
  setPWM(channel, usToCounts(duty_cycle_ms));
}

void PWMController::setPWM(uint8_t channel, uint16_t duty_cycle_counts) {
  i2c.writeValue(REGISTER_LED0_ON  + (channel * ADDRESS_LED_OFFSET), (uint16_t) 0);
  i2c.writeValue(REGISTER_LED0_OFF + (channel * ADDRESS_LED_OFFSET), duty_cycle_counts);
}
