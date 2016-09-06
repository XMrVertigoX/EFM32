#include "em_gpio.h"
#include "em_int.h"

#include "rtcdriver.h"
#include "sleep.h"

#include <FreeRTOS.h>
#include <task.h>

extern RTCDRV_TimerID_t rtcTimer;

void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime) {
    uint32_t timeToSleep;
    uint32_t timeRemaining;
    uint32_t ticksToJump;

    INT_Disable();

    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    switch (eSleepStatus) {
        case eAbortSleep: {
        } break;
        case eStandardSleep: {
            timeToSleep = xExpectedIdleTime * portTICK_PERIOD_MS;

            RTCDRV_StartTimer(rtcTimer, rtcdrvTimerTypeOneshot, timeToSleep,
                              NULL, NULL);

            SLEEP_Sleep();

            RTCDRV_TimeRemaining(rtcTimer, &timeRemaining);
            RTCDRV_StopTimer(rtcTimer);

            ticksToJump = (timeToSleep - timeRemaining) / portTICK_PERIOD_MS;

            vTaskStepTick(ticksToJump);
        } break;
        case eNoTasksWaitingTimeout: {
            SLEEP_Sleep();
        } break;
    }

    INT_Enable();
}
