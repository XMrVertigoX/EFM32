#include <cstdio>
#include <cstdlib>

#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

#include "sleep.h"

#include "FreeRTOS.h"
#include "task.h"

#include "util.hpp"

typedef struct task_params_t {
    GPIO_Port_TypeDef port;
    unsigned int pin;
    TickType_t delay;
} task_params_t;

task_params_t led0_params, led1_params;

static void setupClocks() {
    CMU_ClockEnable(cmuClock_GPIO, true);
}

static void setupGpio() {
    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPullDrive, 0);
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPullDrive, 0);
}

void task_blinkLed(void *user) {
    task_params_t *params = (task_params_t *)user;

    for (;;) {
        GPIO_PinOutToggle(params->port, params->pin);
        vTaskDelay(params->delay / portTICK_PERIOD_MS);
    }
}

extern "C" {
void vApplicationIdleHook(void) {
    GPIO_PinOutToggle(gpioPortC, 11);
    // SLEEP_Sleep();
}
}

int main(void) {
    CHIP_Init();
    SLEEP_Init(NULL, NULL);

    setupClocks();
    setupGpio();

    led0_params = {gpioPortC, 10, 1000};

    xTaskCreate(task_blinkLed, NULL, 128, &led0_params, 1, NULL);

    vTaskStartScheduler();

    return 0;
}
