#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <rtcdriver.h>

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

    RTCDRV_TimerID_t timerId;
};

#endif /* SLEEPMANAGER_HPP_ */
