# ----- Configuration ---------------------------------------------------------

include config.mk

# ----- Sources ---------------------------------------------------------------

SYMBOLS += EFM32ZG222F32

include sdk.mk
include freertos.mk

# Global header files
INCLUDES += src/include

# Project sources files
SOURCES += $(wildcard src/*.cpp)

# ----- Libraries -------------------------------------------------------------

LIBS += stdc++
LIBS += arm_cortexM0l_math

# ----- Flags -----------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

# CPPFLAGS +=

CFLAGS   += -O3 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c11
CXXFLAGS += -O3 -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c++17

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules -----------------------------------------------------------------

include rules.mk
