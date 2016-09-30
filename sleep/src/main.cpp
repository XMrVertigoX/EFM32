#include <FreeRTOS.h>
#include <task.h>

#include "blinktask.hpp"
#include "hardwaremanager.hpp"
#include "sleepmanager.hpp"

HardwareManager &hardwareManager = HardwareManager::getInstance();
SleepManager &sleepManager = SleepManager::getInstance();
BlinkTask &blinkTask = BlinkTask::getInstance();

int main(void) {
    hardwareManager.init();
    hardwareManager.switchClocks();

    sleepManager.init();

    blinkTask.attach(128, 1);

    vTaskStartScheduler();
}
