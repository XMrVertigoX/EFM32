#include <stdint.h>

#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

static volatile uint32_t msTicks;

static void Delay(uint32_t dlyTicks) {
    uint32_t curTicks = msTicks;
    while ((msTicks - curTicks) < dlyTicks) {
    }
}

void SysTick_Handler(void) {
    msTicks++;
}

int main(void) {
    CHIP_Init();

    SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000);

    CMU_ClockEnable(cmuClock_GPIO, true);

    GPIO_PinModeSet(gpioPortC, 10, gpioModePushPull, 0);
    GPIO_PinModeSet(gpioPortC, 11, gpioModePushPull, 0);

    while (1) {
        GPIO_PinOutToggle(gpioPortC, 10);
        Delay(250);
        GPIO_PinOutToggle(gpioPortC, 11);
        Delay(250);
    }
}
