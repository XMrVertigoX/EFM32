#include <em_cmu.h>
#include <em_gpio.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include "task_toggle.hpp"

using namespace xXx;

Task_Toggle::Task_Toggle(SemaphoreHandle_t &semaphore)
    : ArduinoTask(128, 1), _semaphore(semaphore) {}

Task_Toggle::~Task_Toggle() {}

void Task_Toggle::setup() {
    CMU_ClockEnable(cmuClock_HFLE, true);
    CMU_ClockEnable(cmuClock_GPIO, true);

    // GPIO for led
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPullDrive, 0);

    // GPIO for button
    GPIO_PinModeSet(gpioPortC, 9, gpioModeInput, 0);
    GPIO_IntConfig(gpioPortC, 9, false, true, true);
}

void Task_Toggle::loop() {
    if (xSemaphoreTake(_semaphore, 0) == pdTRUE) {
        GPIO_PinOutToggle(gpioPortC, 11);
    }
}
