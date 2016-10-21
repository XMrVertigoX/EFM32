#ifndef HARDWAREMANAGER_HPP_
#define HARDWAREMANAGER_HPP_

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class HardwareManager : public Singleton<HardwareManager> {
    friend class Singleton<HardwareManager>;

  public:
    void init();
    void enableGpioAsInput(GPIO_Port_TypeDef port, unsigned int pin);
    void enableGpioAsOutput(GPIO_Port_TypeDef port, unsigned int pin);
    void enableGpioInterrupt(GPIO_Port_TypeDef port, unsigned int pin);
    void toggleGpio(GPIO_Port_TypeDef port, unsigned int pin);

  private:
    HardwareManager()  = default;
    ~HardwareManager() = default;
};

#endif /* HARDWAREMANAGER_HPP_ */
