#include <em_cmu.h>
#include <em_gpio.h>

#include <FreeRTOS.h>
#include <task.h>

#include <blinktask.hpp>

void BlinkTask::setup() {
    xLastWakeTime = xTaskGetTickCount();

    CMU_ClockEnable(cmuClock_GPIO, true);
    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPullDrive, 0);
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPullDrive, 0);

    GPIO_PinOutToggle(gpioPortC, 10);
}

void BlinkTask::loop() {
    vTaskDelayUntil(&xLastWakeTime, 500 / portTICK_PERIOD_MS);
    GPIO_PinOutToggle(gpioPortC, 10);
    GPIO_PinOutToggle(gpioPortC, 11);
}
