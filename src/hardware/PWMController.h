#ifndef PWM_CONTROLLER_H_
#define PWM_CONTROLLER_H_

#include "I2CDevice.h"

#include <algorithm>
#include <cstdint>

constexpr double OSC_FACTOR = 1.0f;
constexpr double PWM_FREQUENCY = 50;

constexpr uint8_t ADDRESS_LED_OFFSET = 4;

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

struct PWMLimits {
  uint16_t min_duty_cycle;
  uint16_t max_duty_cycle;

  float clamp_duty_cycle(uint16_t duty_cycle) {
    if (duty_cycle == 0)
      return duty_cycle;

    return std::clamp(duty_cycle, min_duty_cycle, max_duty_cycle);
  }
};

class PWMController {
public:
  PWMController(I2CDevice &i2c);
  ~PWMController();

  /**
   * @param duty_cycle length of duty cycle in ms
   */
  void setDutyCycle(uint8_t channel, double duty_cycle);

private:
  I2CDevice &i2c;
  PWMLimits limits;

  uint8_t calcPWMPrescale();
  uint16_t usToCounts(double us);
  void setPWM(uint8_t channel, uint16_t duty_cycle);
};

#endif // !PWM_CONTROLLER_H_
