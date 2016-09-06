#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <em_rtc.h>

#include <xXx/utils/singleton.hpp>

class SleepManager : public Singleton<SleepManager> {
    friend class Singleton<SleepManager>;

   public:
    void init();
    uint32_t sleep(uint32_t expectedSleepTime = 0);

   private:
    SleepManager() = default;
    ~SleepManager() = default;

    uint32_t startTimer(uint32_t expectedSleepTime);
    uint32_t stopTimer(uint32_t &remainingSleepTime);

    RTC_Init_TypeDef rtcInit = {false, false, false};
};

#endif /* SLEEPMANAGER_HPP_ */
