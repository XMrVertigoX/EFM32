#include <em_core.h>

#include <rtcdriver.h>
#include <sleep.h>

#include <FreeRTOS.h>
#include <task.h>

#include "sleepmanager.hpp"

static inline uint32_t ticks2ms(TickType_t ticks) {
    return (ticks / portTICK_PERIOD_MS);
}

static inline TickType_t ms2ticks(uint32_t milliseconds) {
    return (milliseconds * portTICK_PERIOD_MS);
}

void SleepManager::init() {
    RTCDRV_Init();
    RTCDRV_AllocateTimer(&_id);
    SLEEP_Init(NULL, NULL);
}

TickType_t SleepManager::sleep(TickType_t ticks) {
    uint32_t timeRemaining;

    RTCDRV_StartTimer(_id, rtcdrvTimerTypeOneshot, ticks2ms(ticks), NULL, NULL);
    SLEEP_Sleep();
    RTCDRV_TimeRemaining(_id, &timeRemaining);
    RTCDRV_StopTimer(_id);

    return ((TickType_t)(ticks - ms2ticks(timeRemaining)));
}

/*
 * FreeRTOS hook function
 */
extern "C" void vPortSuppressTicksAndSleep(TickType_t expectedIdleTime) {
    eSleepModeStatus sleepStatus = eTaskConfirmSleepModeStatus();

    if (sleepStatus == eAbortSleep) {
        return;
    }

    CORE_ATOMIC_IRQ_DISABLE();

    uint32_t actualSleepTicks;
    SleepManager &sleepManager = SleepManager::getInstance();

    if (sleepStatus == eStandardSleep) {
        actualSleepTicks = sleepManager.sleep(expectedIdleTime);
    } else {
        actualSleepTicks = sleepManager.sleep(portMAX_DELAY);
    }

    vTaskStepTick(actualSleepTicks);

    CORE_ATOMIC_IRQ_ENABLE();
}
