# ----- Configuration ---------------------------------------------------------

PROJECT_NAME = gpiointerrupt

# ----- Sources ---------------------------------------------------------------

SYMBOLS += NDEBUG

include sdk.mk

# Global header files
INCLUDE_DIRS += src/config

# Project sources files
SOURCE_FILES += $(wildcard src/*.cpp)

# ----- Libraries -------------------------------------------------------------

LIBRARIES += stdc++
LIBRARIES += arm_cortexM0l_math

# ----- Flags -----------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

# CPPFLAGS +=

CFLAGS   += -Og -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c11
CXXFLAGS += -Og -g -fdata-sections -ffunction-sections -fno-exceptions -fno-builtin -fno-common -fomit-frame-pointer -std=c++17

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules -----------------------------------------------------------------

include ../libs/xXx/utils/rules.mk
