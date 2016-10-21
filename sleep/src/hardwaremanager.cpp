#include <em_chip.h>
#include <em_cmu.h>

#include "hardwaremanager.hpp"

static inline void enableCrystalOscillators() {
    CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
    CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
}

static inline void switchClockBranches() {
    CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
    CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
    CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
}

static inline void disableRCOscillators() {
    CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);
    CMU_OscillatorEnable(cmuOsc_LFRCO, false, false);
}

void HardwareManager::init() {
    // TODO: Necessary?
    CHIP_Init();
}

void HardwareManager::switchClocks() {
    enableCrystalOscillators();
    switchClockBranches();
    disableRCOscillators();
}
