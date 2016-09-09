#include <em_chip.h>

#include <FreeRTOS.h>
#include <task.h>

#include "mytask.hpp"
#include "sleepmanager.hpp"

SleepManager &sleepManager = SleepManager::getInstance();
MyTask &task0 = MyTask::getInstance();

int main(void) {
    CHIP_Init();

    sleepManager.init();
    task0.attachToScheduler(128, 1);

    vTaskStartScheduler();
}
