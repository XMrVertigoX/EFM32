GECKO_SDK = ../libs/Gecko_SDK

CMSIS = $(GECKO_SDK)/cmsis
DEVICE = $(GECKO_SDK)/Device/SiliconLabs/EFM32ZG
EMDRV = $(GECKO_SDK)/emdrv
EMLIB = $(GECKO_SDK)/emlib
FREERTOS = $(GECKO_SDK)/reptile/FreeRTOS/Source

# ----- Symbols ---------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

# ----- CMSIS -----------------------------------------------------------------

INCLUDES += $(CMSIS)/Include
LIB_DIRS += $(CMSIS)/Lib/GCC

# ----- Device ----------------------------------------------------------------

INCLUDES += $(DEVICE)/Include
SOURCES += $(DEVICE)/Source/GCC/startup_efm32zg.c
SOURCES += $(DEVICE)/Source/system_efm32zg.c

# ----- emdrv -----------------------------------------------------------------

# INCLUDES += $(EMDRV)/common/inc

# INCLUDES += $(EMDRV)/rtcdrv/inc
# SOURCES += $(EMDRV)/rtcdrv/src/rtcdriver.c

# INCLUDES += $(EMDRV)/sleep/inc
# SOURCES += $(EMDRV)/sleep/src/sleep.c

# ----- emlib -----------------------------------------------------------------

INCLUDES += $(EMLIB)/inc
SOURCES += $(wildcard $(EMLIB)/src/*.c)

# ----- FreeRTOS --------------------------------------------------------------

INCLUDES += $(FREERTOS)/include
INCLUDES += $(FREERTOS)/portable/GCC/ARM_CM0
SOURCES += $(FREERTOS)/event_groups.c
SOURCES += $(FREERTOS)/list.c
SOURCES += $(FREERTOS)/queue.c
SOURCES += $(FREERTOS)/tasks.c
SOURCES += $(FREERTOS)/portable/MemMang/heap_3.c
SOURCES += $(FREERTOS)/portable/GCC/ARM_CM0/port.c

# ----- Flags -----------------------------------------------------------------

LINKERSCRIPT = $(DEVICE)/Source/GCC/efm32zg.ld

LDFLAGS += -T $(LINKERSCRIPT)
