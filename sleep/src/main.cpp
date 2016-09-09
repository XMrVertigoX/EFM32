#include <em_chip.h>

#include <FreeRTOS.h>
#include <task.h>

#include "mytask.hpp"
#include "sleepmanager.hpp"

SleepManager &sleepManager = SleepManager::getInstance();
MyTask &task = MyTask::getInstance();

int main(void) {
    CHIP_Init();

    sleepManager.init();
    task.attachToScheduler(128, 1);

    vTaskStartScheduler();
}
