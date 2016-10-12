#ifndef SLEEPMANAGER_HPP_
#define SLEEPMANAGER_HPP_

#include <cstdint>

#include <rtcdriver.h>
#include <sleep.h>

#include <FreeRTOS.h>

#include <xXx/templates/singleton.hpp>

using namespace xXx;

class SleepManager : public Singleton<SleepManager> {
    friend class Singleton<SleepManager>;

  public:
    void init();
    uint32_t sleep(TickType_t idleTicks);

  private:
    SleepManager()  = default;
    ~SleepManager() = default;

    RTCDRV_TimerID_t _id = 0;
};

#endif /* SLEEPMANAGER_HPP_ */
