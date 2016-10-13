#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <assert.h>

// ----- FreeRTOS configuration ------------------------------------------------

// clang-format off

#define GET_INTERRUPT_PRIORITY(x)            (x << (8 - __NVIC_PRIO_BITS))

#define INTERRUPT_PRIORITY_LOW               GET_INTERRUPT_PRIORITY(3)
#define INTERRUPT_PRIORITY_MID               GET_INTERRUPT_PRIORITY(2)
#define INTERRUPT_PRIORITY_HIGH              GET_INTERRUPT_PRIORITY(1)

#define configASSERT(x)                      assert(x)
#define configCPU_CLOCK_HZ                   (24000000)
#define configKERNEL_INTERRUPT_PRIORITY      INTERRUPT_PRIORITY_LOW
#define configMAX_PRIORITIES                 (3)
#define configMAX_SYSCALL_INTERRUPT_PRIORITY INTERRUPT_PRIORITY_HIGH
#define configMINIMAL_STACK_SIZE             (64)
#define configTICK_RATE_HZ                   (1000)
#define configTOTAL_HEAP_SIZE                (1024)
#define configUSE_16_BIT_TICKS               (0)
#define configUSE_CO_ROUTINES                (0)
#define configUSE_IDLE_HOOK                  (0)
#define configUSE_PREEMPTION                 (1)
#define configUSE_TICK_HOOK                  (0)
#define configUSE_TICKLESS_IDLE              (1)

#define INCLUDE_uxTaskPriorityGet            (1)
#define INCLUDE_vTaskDelay                   (1)
#define INCLUDE_vTaskDelayUntil              (1)
#define INCLUDE_vTaskDelete                  (1)
#define INCLUDE_vTaskPrioritySet             (1)
#define INCLUDE_vTaskSuspend                 (1)

#define vPortSVCHandler(x)                   SVC_Handler(x)
#define xPortPendSVHandler(x)                PendSV_Handler(x)
#define xPortSysTickHandler(x)               SysTick_Handler(x)

// clang-format on

#define portSUPPRESS_TICKS_AND_SLEEP(xExpectedIdleTime)                        \
    vPortSuppressTicksAndSleep(xExpectedIdleTime)

// ----- /FreeRTOS configuration -----------------------------------------------

#endif /* FREERTOS_CONFIG_H */
