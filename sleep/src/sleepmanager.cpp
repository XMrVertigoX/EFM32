#include <em_cmu.h>
#include <em_emu.h>
#include <em_gpio.h>
#include <em_int.h>
#include <em_rtc.h>

#include <FreeRTOS.h>
#include <task.h>

#include "sleepmanager.hpp"

void SleepManager::init() {
    RTC_Init_TypeDef rtcInit = RTC_INIT_DEFAULT;

    CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);

    CMU_ClockEnable(cmuClock_CORELE, true);
    CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFRCO);
    CMU_ClockEnable(cmuClock_RTC, true);

    _clockFreqency = CMU_ClockFreqGet(cmuClock_LFA);

    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);

    rtcInit.comp0Top = false;

    RTC_Init(&rtcInit);
}

TickType_t SleepManager::rtc2rtos(uint32_t rtcTicks) {
    return ((rtcTicks * configTICK_RATE_HZ) / _clockFreqency);
}

uint32_t SleepManager::rtos2rtc(TickType_t rtosTicks) {
    return ((rtosTicks * _clockFreqency) / configTICK_RATE_HZ);
}

uint32_t SleepManager::sleep(TickType_t sleepTicks) {
    uint32_t rtcAfter;
    uint32_t rtcBefore;

    rtcBefore = RTC_CounterGet();

    if (sleepTicks) {
        RTC_CompareSet(0, rtcBefore + rtos2rtc(sleepTicks) - 1);
        RTC_IntEnable(RTC_IEN_COMP0);
    }

    EMU_EnterEM2(true);

    if (sleepTicks) {
        RTC_IntDisable(RTC_IEN_COMP0);
    }

    rtcAfter = RTC_CounterGet();

    return (rtc2rtos(rtcAfter - rtcBefore + 1));
}

void RTC_IRQHandler(void) {
    RTC_IntClear(RTC_IFC_COMP0);
}

void vPortSuppressTicksAndSleep(TickType_t expectedSleepTicks) {
    SleepManager &sleepManager = SleepManager::getInstance();
    eSleepModeStatus eSleepStatus = eTaskConfirmSleepModeStatus();
    uint32_t actualSleepTicks = 0;

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
