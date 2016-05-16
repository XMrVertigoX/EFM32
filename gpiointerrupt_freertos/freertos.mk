FREERTOS_DIR = ../../FreeRTOS

INCLUDES += $(FREERTOS_DIR)/include
INCLUDES += $(FREERTOS_DIR)/portable/GCC/ARM_CM0
SOURCES += $(wildcard $(FREERTOS_DIR)/*.c)
SOURCES += $(FREERTOS_DIR)/portable/MemMang/heap_3.c
SOURCES += $(FREERTOS_DIR)/portable/GCC/ARM_CM0/port.c
