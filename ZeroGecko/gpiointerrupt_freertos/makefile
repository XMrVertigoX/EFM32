# ----- Configuration ----------------------------------------------------------

include ../config.mk

SRCDIR = src

# ----- Sources ----------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

include sdk.mk

INCLUDES += freertos/include
INCLUDES += freertos/portable/GCC/ARM_CM0
SOURCES += $(wildcard freertos/*.c)
SOURCES += freertos/portable/MemMang/heap_3.c
SOURCES += freertos/portable/GCC/ARM_CM0/port.c

# Global header files
INCLUDES += src/include

# Project sources files
SOURCES += $(wildcard src/*.cpp)

# ----- Libraries --------------------------------------------------------------

LIBRARIES += stdc++
LIBRARIES += arm_cortexM0l_math

# ----- Flags ------------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

CFLAGS   += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c11
CXXFLAGS += -O0 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c++11

LDFLAGS += -Wl,--gc-sections
LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs

# ----- Rules ------------------------------------------------------------------

include ../rules.mk
