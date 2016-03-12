#include <stdio.h>
#include <stdlib.h>

#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

#include "gpiointerrupt.h"

#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

typedef struct {
    GPIO_Port_TypeDef port;
    unsigned int pin;
    SemaphoreHandle_t semaphore;
} Task0_Parameter_TypeDef;

typedef struct {
    GPIO_Port_TypeDef port;
    unsigned int pin;
    SemaphoreHandle_t semaphore;
} Task1_Parameter_TypeDef;

Task0_Parameter_TypeDef parametersToTask0;
Task1_Parameter_TypeDef parametersToTask1;

void gpioCallback(uint8_t pin) {
    switch (pin) {
        case 8: {
            xSemaphoreGiveFromISR(parametersToTask1.semaphore, NULL);
        } break;
        case 9: {
            xSemaphoreGiveFromISR(parametersToTask0.semaphore, NULL);
        } break;
    }
}

void taskLed0(void* pParameters) {
    Task0_Parameter_TypeDef* pData = (Task0_Parameter_TypeDef*)pParameters;
    for (;;) {
        if (xSemaphoreTake(pData->semaphore, 0) == pdTRUE) {
            GPIO_PinOutToggle(pData->port, pData->pin);
        }
    }
}

void taskLed1(void* pParameters) {
    Task1_Parameter_TypeDef* pData = (Task1_Parameter_TypeDef*)pParameters;
    for (;;) {
        if (xSemaphoreTake(pData->semaphore, 0) == pdTRUE) {
            GPIO_PinOutToggle(pData->port, pData->pin);
        }
    }
}

int main(void) {
    CHIP_Init();

    CMU_ClockEnable(cmuClock_GPIO, true);

    GPIO_PinModeSet(gpioPortC, 8, gpioModeInput, 0);
    GPIO_IntConfig(gpioPortC, 8, false, true, true);

    GPIO_PinModeSet(gpioPortC, 9, gpioModeInput, 0);
    GPIO_IntConfig(gpioPortC, 9, false, true, true);

    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPullDrive, 0);
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPullDrive, 0);

    GPIOINT_CallbackRegister(8, gpioCallback);
    GPIOINT_CallbackRegister(9, gpioCallback);

    parametersToTask0.port = gpioPortC;
    parametersToTask0.pin = 10;
    parametersToTask0.semaphore = xSemaphoreCreateBinary();

    parametersToTask1.port = gpioPortC;
    parametersToTask1.pin = 11;
    parametersToTask1.semaphore = xSemaphoreCreateBinary();

    xTaskCreate(taskLed0, NULL, configMINIMAL_STACK_SIZE, &parametersToTask0,
                tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(taskLed1, NULL, configMINIMAL_STACK_SIZE, &parametersToTask1,
                tskIDLE_PRIORITY + 1, NULL);

    GPIOINT_Init();

    vTaskStartScheduler();

    return 0;
}
