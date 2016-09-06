#include <em_int.h>

#include <rtcdriver.h>
#include <sleep.h>

#include <FreeRTOS.h>
#include <task.h>

#include "sleepmanager.hpp"

void SleepManager::init() {
    RTCDRV_Init();
    RTCDRV_AllocateTimer(&timerId);
    SLEEP_Init(NULL, NULL);
}
void SleepManager::startTimer(uint32_t expectedSleepTime) {
    RTCDRV_StartTimer(timerId, rtcdrvTimerTypeOneshot, expectedSleepTime, NULL,
                      NULL);
}

uint32_t SleepManager::stopTimer() {
    uint32_t timeRemaining;

    RTCDRV_TimeRemaining(timerId, &timeRemaining);
    RTCDRV_StopTimer(timerId);

    return (timeRemaining);
}

uint32_t SleepManager::sleep(uint32_t expectedSleepTime) {
    uint32_t remainingSleepTime = 0;

    if (expectedSleepTime) {
        startTimer(expectedSleepTime);
    }

    SLEEP_Sleep();

    if (expectedSleepTime) {
        remainingSleepTime = stopTimer();
    }

    return (expectedSleepTime - remainingSleepTime);
}

// ----- FreeRTOS hook function -----------------------------------------------

void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime) {
    SleepManager &sleepManager = SleepManager::getInstance();

    uint32_t expectedSleepTime;
    uint32_t actualSleepTime;

    INT_Disable();

    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    switch (eSleepStatus) {
        case eAbortSleep: {
        } break;
        case eStandardSleep: {
            expectedSleepTime = xExpectedIdleTime * portTICK_PERIOD_MS;
            actualSleepTime = sleepManager.sleep(expectedSleepTime);
            vTaskStepTick(actualSleepTime / portTICK_PERIOD_MS);
        } break;
        case eNoTasksWaitingTimeout: {
            sleepManager.sleep();
        } break;
    }

    INT_Enable();
}
