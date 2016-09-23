#include <em_chip.h>

#include <FreeRTOS.h>
#include <task.h>

#include "blinktask.hpp"
#include "sleepmanager.hpp"

SleepManager &sleepManager = SleepManager::getInstance();
BlinkTask &blinkTask = BlinkTask::getInstance();

int main(void) {
    CHIP_Init();
    sleepManager.init();
    blinkTask.attach(128, 1);
    vTaskStartScheduler();
}
