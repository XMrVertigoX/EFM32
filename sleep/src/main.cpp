#include <em_chip.h>

#include <FreeRTOS.h>
#include <task.h>

#include "mytask.hpp"
#include "sleepmanager.hpp"

int main(void) {
    CHIP_Init();

    SleepManager::getInstance().init();
    MyTask::getInstance().attachToScheduler(128, 1);

    vTaskStartScheduler();
}
