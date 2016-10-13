#include <em_chip.h>
#include <em_cmu.h>

#include "gpiointerrupt.h"

#include "hardwaremanager.hpp"

static void enableCrystalOscillators() {
    CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
    CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
}

static void switchClockBranches() {
    CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
    CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
    CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
}

static void disableRCOscillators() {
    CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);
    CMU_OscillatorEnable(cmuOsc_LFRCO, false, false);
}

static void enableGpioClock() {
    CMU_ClockEnable(cmuClock_HFLE, true);
    CMU_ClockEnable(cmuClock_GPIO, true);
}

static void gpioCallback(uint8_t pin) {
    switch (pin) {
        default: break;
    }
}

void HardwareManager::init() {
    // TODO: Necessary?
    // CHIP_Init();

    enableCrystalOscillators();
    switchClockBranches();
    disableRCOscillators();

    // TODO: Only enable on demand.
    enableGpioClock();

    GPIOINT_Init();
}

void enableGpioAsInput(GPIO_Port_TypeDef port, unsigned int pin) {
    GPIO_PinModeSet(port, pin, gpioModeInput, 0);
}

void enableGpioAsOutput(GPIO_Port_TypeDef port, unsigned int pin) {
    GPIO_PinModeSet(port, pin, gpioModePushPull, 0);
}

void HardwareManager::toggleGpio(GPIO_Port_TypeDef port, unsigned int pin) {
    GPIO_PinOutToggle(port, pin);
}

void HardwareManager::enableGpioInterrupt(GPIO_Port_TypeDef port,
                                          unsigned int pin) {
    GPIO_IntConfig(port, pin, false, true, true);
    GPIOINT_CallbackRegister(pin, gpioCallback);
}
