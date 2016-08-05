# ----- Configuration ----------------------------------------------------------

include ../config.mk

SDK_DIR = ../../Gecko_SDK

# ----- Sources ----------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

# Gecko_SDK
INCLUDES += $(SDK_DIR)/cmsis/Include
INCLUDES += $(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Include
INCLUDES += $(SDK_DIR)/emlib/inc
SOURCES += $(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Source/GCC/startup_efm32zg.c
SOURCES += $(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Source/system_efm32zg.c
SOURCES += $(SDK_DIR)/emlib/src/em_cmu.c
SOURCES += $(SDK_DIR)/emlib/src/em_gpio.c

# Project
SOURCES += src/main.cpp

# ----- Libraries --------------------------------------------------------------

LIBS += stdc++
LIBS += arm_cortexM0l_math

LIB_DIRS += $(SDK_DIR)/cmsis/Lib/GCC

# ----- Flags ------------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

# CPPFLAGS +=

CFLAGS   += -O3 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c11
CXXFLAGS += -O3 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c++14

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--script=$(SDK_DIR)/Device/SiliconLabs/EFM32ZG/Source/GCC/efm32zg.ld
LDFLAGS += -Wl,--gc-sections

# ----- Rules ------------------------------------------------------------------

include ../rules.mk
