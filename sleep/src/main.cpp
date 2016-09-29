#include <em_chip.h>
#include <em_cmu.h>

#include <FreeRTOS.h>
#include <task.h>

#include "blinktask.hpp"
#include "sleepmanager.hpp"

SleepManager &sleepManager = SleepManager::getInstance();
BlinkTask &blinkTask = BlinkTask::getInstance();

int main(void) {
    CHIP_Init();

    CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
    CMU_OscillatorEnable(cmuOsc_LFXO, true, true);

    CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
    CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
    CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);

    CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);
    CMU_OscillatorEnable(cmuOsc_LFRCO, false, false);

    sleepManager.init();

    blinkTask.attach(128, 1);

    vTaskStartScheduler();
}
