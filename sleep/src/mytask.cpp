#include <em_cmu.h>
#include <em_gpio.h>

#include <FreeRTOS.h>
#include <task.h>

#include "mytask.hpp"

void MyTask::setup() {
    CMU_ClockEnable(cmuClock_GPIO, true);
    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPullDrive, 0);
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPullDrive, 0);
}

void MyTask::loop() {
    GPIO_PinOutToggle(gpioPortC, 10);
    vTaskDelay(250 / portTICK_PERIOD_MS);
    GPIO_PinOutToggle(gpioPortC, 11);
    vTaskDelay(500 / portTICK_PERIOD_MS);
}
