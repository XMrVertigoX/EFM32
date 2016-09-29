#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <em_rtc.h>

#include <sleep.h>

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class SleepManager : public Singleton<SleepManager> {
    friend class Singleton<SleepManager>;

  public:
    void init();
    void blockBegin(SLEEP_EnergyMode_t eMode);
    void blockEnd(SLEEP_EnergyMode_t eMode);
    uint32_t sleep(TickType_t rtosTicks = 0);

  private:
    SleepManager() = default;
    ~SleepManager() = default;

    TickType_t rtc2rtos(uint32_t ticks);
    uint32_t rtos2rtc(TickType_t ticks);

    uint32_t _clockFreqency = 0;
    RTC_Init_TypeDef _rtcInit = {false, false, false};
};

#endif /* SLEEPMANAGER_HPP_ */
