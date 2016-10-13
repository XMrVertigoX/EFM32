#include <em_int.h>

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
void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime) {
    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    if (eSleepStatus == eAbortSleep) {
        return;
    }

    INT_Disable();

    uint32_t actualSleepTicks;
    SleepManager &sleepManager = SleepManager::getInstance();

    if (eSleepStatus == eStandardSleep) {
        actualSleepTicks = sleepManager.sleep(xExpectedIdleTime);
    } else {
        actualSleepTicks = sleepManager.sleep(portMAX_DELAY);
    }

    vTaskStepTick(actualSleepTicks);

    INT_Enable();
}
