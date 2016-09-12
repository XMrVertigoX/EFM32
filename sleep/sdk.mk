GECKO_SDK = ../libs/Gecko_SDK

CMSIS     = $(GECKO_SDK)/cmsis
DEVICE    = $(GECKO_SDK)/Device/SiliconLabs/EFM32ZG
EMDRV     = $(GECKO_SDK)/emdrv
EMLIB     = $(GECKO_SDK)/emlib
FREERTOS  = $(GECKO_SDK)/reptile/FreeRTOS/Source

# ----- Symbols ---------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

# ----- CMSIS -----------------------------------------------------------------

INCLUDE_DIRS += $(CMSIS)/Include
LIBRARY_DIRS += $(CMSIS)/Lib/GCC

# ----- Device ----------------------------------------------------------------

INCLUDE_DIRS += $(DEVICE)/Include
SOURCE_FILES += $(DEVICE)/Source/GCC/startup_efm32zg.c
SOURCE_FILES += $(DEVICE)/Source/system_efm32zg.c

# ----- emdrv -----------------------------------------------------------------

# INCLUDE_DIRS += $(EMDRV)/common/inc

# INCLUDE_DIRS += $(EMDRV)/rtcdrv/inc
# SOURCE_FILES += $(EMDRV)/rtcdrv/src/rtcdriver.c

# INCLUDE_DIRS += $(EMDRV)/sleep/inc
# SOURCE_FILES += $(EMDRV)/sleep/src/sleep.c

# ----- emlib -----------------------------------------------------------------

INCLUDE_DIRS += $(EMLIB)/inc
SOURCE_FILES += $(wildcard $(EMLIB)/src/*.c)

# ----- FreeRTOS --------------------------------------------------------------

INCLUDE_DIRS += $(FREERTOS)/include
INCLUDE_DIRS += $(FREERTOS)/portable/GCC/ARM_CM0
SOURCE_FILES += $(FREERTOS)/event_groups.c
SOURCE_FILES += $(FREERTOS)/list.c
SOURCE_FILES += $(FREERTOS)/queue.c
SOURCE_FILES += $(FREERTOS)/tasks.c
SOURCE_FILES += $(FREERTOS)/portable/MemMang/heap_3.c
SOURCE_FILES += $(FREERTOS)/portable/GCC/ARM_CM0/port.c

# ----- Flags -----------------------------------------------------------------

LDFLAGS += -T $(DEVICE)/Source/GCC/efm32zg.ld
