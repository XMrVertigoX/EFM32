#include <em_cmu.h>
#include <em_gpio.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include "hardwaremanager.hpp"
#include "task_toggle.hpp"

using namespace xXx;

Task_Toggle::Task_Toggle(SemaphoreHandle_t &semaphore)
    : ArduinoTask(128, 1), _semaphore(semaphore) {}

Task_Toggle::~Task_Toggle() {}

void Task_Toggle::setup() {
    // GPIO for LED1
    _hardwareManager.enableGpioAsOutput(gpioPortC, 11);

    // GPIO for BUTTON1
    _hardwareManager.enableGpioAsInput(gpioPortC, 9);
    _hardwareManager.enableGpioInterrupt(gpioPortC, 9);
}

void Task_Toggle::loop() {
    if (xSemaphoreTake(_semaphore, portMAX_DELAY) == pdTRUE) {
        _hardwareManager.toggleGpio(gpioPortC, 11);
    }
}
