#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <assert.h>

#define configASSERT(x) assert(x)
#define configCPU_CLOCK_HZ 24000000
#define configKERNEL_INTERRUPT_PRIORITY ((7 << 5) | 0b00011111)
#define configMAX_PRIORITIES 4
#define configMAX_SYSCALL_INTERRUPT_PRIORITY ((5 << 5) | 0b00011111)
#define configMINIMAL_STACK_SIZE 64
#define configTICK_RATE_HZ 1000
#define configTOTAL_HEAP_SIZE 2048
#define configUSE_16_BIT_TICKS 0
#define configUSE_CO_ROUTINES 0
#define configUSE_IDLE_HOOK 0
#define configUSE_PREEMPTION 1
#define configUSE_TICK_HOOK 0
#define configUSE_TICKLESS_IDLE 1

#define INCLUDE_vTaskPrioritySet 1
#define INCLUDE_uxTaskPriorityGet 1
#define INCLUDE_vTaskDelete 1
#define INCLUDE_vTaskSuspend 1
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1

#define portSUPPRESS_TICKS_AND_SLEEP(xExpectedIdleTime) \
    vPortSuppressTicksAndSleep(xExpectedIdleTime)

#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */
