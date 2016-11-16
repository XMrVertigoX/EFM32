# ----- Configuration ---------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-
PROJECT_NAME     = gpiointerrupt

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

COMMON_CFLAGS += -g
COMMON_CFLAGS += -Og

CFLAGS += -std=c11

CXXFLAGS += -std=c++17

CPPFLAGS +=

LDFLAGS += 

# ----- Rules -----------------------------------------------------------------

include ../libs/xXx/utils/rules.mk

download: $(EXECUTABLE)
	arm-none-eabi-gdb -q -x download.gdb $<
