#include <em_cmu.h>
#include <em_emu.h>
#include <em_gpio.h>
#include <em_int.h>
#include <em_rtc.h>

#include <FreeRTOS.h>
#include <task.h>

#include "sleepmanager.hpp"

#define LFRCO_FREQ 32768

void SleepManager::init() {
    CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);

    CMU_ClockEnable(cmuClock_CORELE, true);
    CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFRCO);
    CMU_ClockEnable(cmuClock_RTC, true);

    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);

    RTC_Init(&rtcInit);
}
uint32_t SleepManager::startTimer(uint32_t expectedSleepTime) {
    return (0);
}

uint32_t SleepManager::stopTimer(uint32_t &remainingSleepTime) {
    return (0);
}

uint32_t SleepManager::sleep(uint32_t expectedSleepTime) {
    uint32_t remainingSleepTime;

    startTimer(expectedSleepTime);
    EMU_EnterEM2(true);
    stopTimer(remainingSleepTime);

    return (expectedSleepTime - remainingSleepTime);
}

void RTC_IRQHandler(void) {
    // TODO: Check for correct interrupt
    RTC_IntClear(RTC_IFC_COMP0);
    // GPIO_PinOutToggle(gpioPortC, 11);
}

// ----- FreeRTOS hook function -----------------------------------------------

void vPortSuppressTicksAndSleep(TickType_t idleTicks) {
    SleepManager &sleepManager = SleepManager::getInstance();

    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();

    if (eSleepStatus == eAbortSleep) {
        return;
    }

    INT_Disable();

    RTC_CounterReset();

    if (eSleepStatus == eStandardSleep) {
        RTC_CompareSet(0, ((idleTicks * LFRCO_FREQ) / configTICK_RATE_HZ) - 1);
        RTC_IntEnable(RTC_IEN_COMP0);
    } else if (eSleepStatus == eNoTasksWaitingTimeout) {
        // TODO
    }

    EMU_EnterEM2(true);

    RTC_IntDisable(RTC_IEN_COMP0);

    uint32_t rtcAfter = RTC_CounterGet();
    uint32_t foo = ((rtcAfter + 1) * configTICK_RATE_HZ) / LFRCO_FREQ;

    vTaskStepTick(foo);

    INT_Enable();
}
