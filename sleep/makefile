# ----- Configuration ---------------------------------------------------------

include config.mk

PROJECT_NAME = blink_freertos

# ----- Sources ---------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

include sdk.mk

# Global header files
INCLUDES += src/config

# Project sources files
SOURCES += $(wildcard src/*.cpp)

# ----- Libraries -------------------------------------------------------------

LIBS += arm_cortexM0l_math

# ----- Flags -----------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

COMMON = -O3 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer

CFLAGS += $(COMMON)
CFLAGS += -std=c11

CXXFLAGS += $(COMMON)
CXXFLAGS += -std=c++17
CXXFLAGS += -fno-rtti

# CPPFLAGS +=

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules -----------------------------------------------------------------

include rules.mk
