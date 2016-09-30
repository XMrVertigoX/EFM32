#include <em_cmu.h>
#include <em_gpio.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include "blinktask.hpp"

BlinkTask::BlinkTask(SemaphoreHandle_t &semaphore)
    : _semaphore(semaphore), _LastWakeTime(0) {}

BlinkTask::~BlinkTask() {}

void BlinkTask::setup() {
    _LastWakeTime = xTaskGetTickCount();
    _semaphore = xSemaphoreCreateBinary();

    CMU_ClockEnable(cmuClock_HFLE, true);
    CMU_ClockEnable(cmuClock_GPIO, true);

    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPullDrive, 0);
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPullDrive, 0);

    xSemaphoreGive(_semaphore);
}

void BlinkTask::loop() {
    vTaskDelayUntil(&_LastWakeTime, 900 / portTICK_PERIOD_MS);

    GPIO_PinOutToggle(gpioPortC, 10);

    if (xSemaphoreTake(_semaphore, 0) == pdTRUE) {
        GPIO_PinOutToggle(gpioPortC, 11);
        xSemaphoreGive(_semaphore);
    }

    vTaskDelayUntil(&_LastWakeTime, 100 / portTICK_PERIOD_MS);

    GPIO_PinOutToggle(gpioPortC, 10);

    if (xSemaphoreTake(_semaphore, 0) == pdTRUE) {
        GPIO_PinOutToggle(gpioPortC, 11);
        xSemaphoreGive(_semaphore);
    }
}
