#include <em_cmu.h>
#include <em_gpio.h>

#include <FreeRTOS.h>
#include <task.h>

#include "task_blink.hpp"

using namespace xXx;

Task_Blink::Task_Blink() : ArduinoTask(128, 1), _LastWakeTime(0) {}

Task_Blink::~Task_Blink() {}

void Task_Blink::setup() {
    _LastWakeTime = xTaskGetTickCount();

    CMU_ClockEnable(cmuClock_HFLE, true);
    CMU_ClockEnable(cmuClock_GPIO, true);

    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPull, 0);
}

void Task_Blink::loop() {
    vTaskDelayUntil(&_LastWakeTime, 900 / portTICK_PERIOD_MS);
    GPIO_PinOutToggle(gpioPortC, 10);
    vTaskDelayUntil(&_LastWakeTime, 100 / portTICK_PERIOD_MS);
    GPIO_PinOutToggle(gpioPortC, 10);
}
