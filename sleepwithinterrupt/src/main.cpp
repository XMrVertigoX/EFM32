#include <em_gpio.h>

#include <gpiointerrupt.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include "hardwaremanager.hpp"
#include "sleepmanager.hpp"
#include "task_blink.hpp"
#include "task_toggle.hpp"

SemaphoreHandle_t semaphore;

HardwareManager &hardwareManager = HardwareManager::getInstance();
SleepManager &sleepManager       = SleepManager::getInstance();

Task_Blink task_blink;
Task_Toggle task_toggle(semaphore);

int main(void) {
    hardwareManager.init();
    hardwareManager.switchClocks();
    sleepManager.init();

    semaphore = xSemaphoreCreateBinary();

    GPIOINT_Init();

    vTaskStartScheduler();
}
