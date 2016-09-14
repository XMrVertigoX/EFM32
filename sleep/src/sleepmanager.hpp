#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class SleepManager : public Singleton<SleepManager> {
    friend class Singleton<SleepManager>;

   public:
    void init();
    uint32_t sleep(TickType_t rtosTicks = 0);

   private:
    SleepManager() = default;
    ~SleepManager() = default;

    TickType_t rtc2rtos(uint32_t ticks);
    uint32_t rtos2rtc(TickType_t ticks);

    uint32_t _clockFreqency = 0;
};

#endif /* SLEEPMANAGER_HPP_ */
