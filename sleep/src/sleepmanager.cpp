#include <em_cmu.h>
#include <em_int.h>
#include <em_rtc.h>

#include <sleep.h>

#include <FreeRTOS.h>
#include <task.h>

#include "sleepmanager.hpp"

// ----- public ---------------------------------------------------------------

void SleepManager::init() {
    _clockFreqency = CMU_ClockFreqGet(cmuClock_RTC);

    CMU_ClockEnable(cmuClock_HFLE, true);
    CMU_ClockEnable(cmuClock_RTC, true);

    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);

    RTC_Init(&_rtcInit);

    SLEEP_Init(NULL, NULL);
}

void SleepManager::blockBegin(SLEEP_EnergyMode_t eMode) {
    SLEEP_SleepBlockBegin(eMode);
}

void SleepManager::blockEnd(SLEEP_EnergyMode_t eMode) {
    SLEEP_SleepBlockEnd(eMode);
}

uint32_t SleepManager::sleep(TickType_t sleepTicks) {
    RTC_CompareSet(0, rtos2rtc(sleepTicks) - 1);

    RTC_CounterReset();

    if (sleepTicks) {
        RTC_IntEnable(RTC_IEN_COMP0);
    }

    SLEEP_Sleep();

    if (sleepTicks) {
        RTC_IntDisable(RTC_IEN_COMP0);
    }

    return (rtc2rtos(RTC_CounterGet() + 1));
}

// ----- private --------------------------------------------------------------

TickType_t SleepManager::rtc2rtos(uint32_t ticks) {
    return ((ticks * configTICK_RATE_HZ) / _clockFreqency);
}

uint32_t SleepManager::rtos2rtc(TickType_t ticks) {
    return ((ticks * _clockFreqency) / configTICK_RATE_HZ);
}

// ----- external -------------------------------------------------------------

/*
 * Interrupt service routine
 */
void RTC_IRQHandler(void) {
    RTC_IntClear(RTC_IFC_COMP0);
}

/*
 * FreeRTOS hook function
 */
void vPortSuppressTicksAndSleep(TickType_t expectedSleepTicks) {
    uint32_t actualSleepTicks = 0;

    SleepManager &sleepManager = SleepManager::getInstance();
    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    if (eSleepStatus == eAbortSleep) {
        return;
    }

    INT_Disable();

    if (eSleepStatus == eStandardSleep) {
        actualSleepTicks = sleepManager.sleep(expectedSleepTicks);
    } else {
        actualSleepTicks = sleepManager.sleep();
    }

    vTaskStepTick(actualSleepTicks);

    INT_Enable();
}
