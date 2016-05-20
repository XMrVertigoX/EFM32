#include <cstdio>
#include <cstdlib>

#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

struct led0_params_t {
    GPIO_Port_TypeDef port;
    unsigned int pin;
    TickType_t delay;
} led0_params;

typedef struct led0_params_t led0_params_t;

struct led1_params_t {
    GPIO_Port_TypeDef port;
    unsigned int pin;
    TickType_t delay;
} led1_params;

typedef struct led1_params_t led1_params_t;

static void setupClocks() {
    CMU_ClockEnable(cmuClock_GPIO, true);
}

static void setupGpio() {
    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPullDrive, 0);
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPullDrive, 0);
}

void blinkLed_task(void *user) {
    led0_params_t *params = (led0_params_t *)user;
    for (;;) {
        GPIO_PinOutToggle(params->port, params->pin);
        vTaskDelay(params->delay / portTICK_PERIOD_MS);
    }
}

void taskLed1(void *user) {
    char *test = new char[10];

    led1_params_t *params = (led1_params_t *)user;
    for (;;) {
        GPIO_PinOutToggle(params->port, params->pin);
        vTaskDelay(params->delay / portTICK_PERIOD_MS);
    }
}

int main(void) {
    CHIP_Init();

    setupClocks();
    setupGpio();

    // led0_params.port = gpioPortC;
    // led0_params.pin = 10;
    // led0_params.delay = 1000;

    led0_params = {gpioPortC, 10, 1000};

    // led1_params.port = gpioPortC;
    // led1_params.pin = 11;
    // led1_params.delay = 500;

    led1_params = {gpioPortC, 11, 500};

    xTaskCreate(blinkLed_task, NULL, 128, &led0_params, tskIDLE_PRIORITY + 1,
                NULL);
    xTaskCreate(blinkLed_task, NULL, 128, &led1_params, tskIDLE_PRIORITY + 1,
                NULL);

    vTaskStartScheduler();

    return 0;
}
