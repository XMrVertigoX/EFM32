#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <em_rtc.h>

#include <xXx/utils/singleton.hpp>

class SleepManager : public Singleton<SleepManager> {
    friend class Singleton<SleepManager>;

   public:
    void init();
    uint32_t sleep(TickType_t rtosTicks = 0);
    TickType_t rtc2rtos(uint32_t rtcTicks);
    uint32_t rtos2rtc(TickType_t rtosTicks);

   private:
    SleepManager() = default;
    ~SleepManager() = default;

    uint32_t _clockFreqency = 0;
};

#endif /* SLEEPMANAGER_HPP_ */
