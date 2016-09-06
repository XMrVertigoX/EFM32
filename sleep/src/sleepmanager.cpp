#include <em_int.h>

#include <rtcdriver.h>
#include <sleep.h>

#include <FreeRTOS.h>
#include <task.h>

#include "sleepmanager.hpp"

void SleepManager::init() {
    SLEEP_Init(NULL, NULL);
    RTCDRV_Init();
    RTCDRV_AllocateTimer(&timerId);
}
uint32_t SleepManager::startTimer(uint32_t expectedSleepTime) {
    RTCDRV_StartTimer(timerId, rtcdrvTimerTypeOneshot, expectedSleepTime, NULL,
                      NULL);

    return (0);
}

uint32_t SleepManager::stopTimer(uint32_t &remainingSleepTime) {
    RTCDRV_TimeRemaining(timerId, &remainingSleepTime);
    RTCDRV_StopTimer(timerId);

    return (0);
}

uint32_t SleepManager::sleep(uint32_t expectedSleepTime) {
    uint32_t remainingSleepTime;

    if (expectedSleepTime) {
        startTimer(expectedSleepTime);
    }

    SLEEP_Sleep();

    if (expectedSleepTime) {
        stopTimer(remainingSleepTime);
    }

    return (expectedSleepTime - remainingSleepTime);
}

// ----- FreeRTOS hook function -----------------------------------------------

void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTicks) {
    SleepManager &sleepManager = SleepManager::getInstance();

    uint32_t expectedSleepTime;
    uint32_t actualSleepTime;

    INT_Disable();

    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    switch (eSleepStatus) {
        case eAbortSleep: {
        } break;
        case eStandardSleep: {
            expectedSleepTime = xExpectedIdleTicks * portTICK_PERIOD_MS;
            actualSleepTime = sleepManager.sleep(expectedSleepTime);
            vTaskStepTick(actualSleepTime / portTICK_PERIOD_MS);
        } break;
        case eNoTasksWaitingTimeout: {
            sleepManager.sleep();
        } break;
    }

    INT_Enable();
}
