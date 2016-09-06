#include <cstdio>
#include <cstdlib>

#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

#include "rtcdriver.h"
#include "sleep.h"

#include <FreeRTOS.h>
#include <task.h>

#include "mytask.hpp"

RTCDRV_TimerID_t rtcTimer;

int main(void) {
    CHIP_Init();

    SLEEP_Init(NULL, NULL);
    RTCDRV_Init();
    RTCDRV_AllocateTimer(&rtcTimer);

    MyTask::getInstance().attachToScheduler(128, 1);

    vTaskStartScheduler();
}
