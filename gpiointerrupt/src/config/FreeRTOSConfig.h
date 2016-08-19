#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "em_assert.h"

// Implement FreeRTOS configASSERT as emlib assert
#define configASSERT(x) EFM_ASSERT(x)

#define configUSE_PREEMPTION 1
#define configCPU_CLOCK_HZ 24000000
#define configTICK_RATE_HZ 1000
#define configMAX_PRIORITIES 4
#define configMINIMAL_STACK_SIZE 128
#define configUSE_16_BIT_TICKS 0
#define configUSE_CO_ROUTINES 0
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0

#define INCLUDE_vTaskPrioritySet 0
#define INCLUDE_uxTaskPriorityGet 0
#define INCLUDE_vTaskDelete 0
#define INCLUDE_vTaskSuspend 0
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 0

// Interrupt nesting behaviour configuration.
#define configKERNEL_INTERRUPT_PRIORITY 0xFF
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 0xA0  // equivalent priority 5.

// Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
// standard names.
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */
