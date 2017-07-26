# ----- Configuration ---------------------------------------------------------

TOOLCHAIN_PREFIX = arm-none-eabi-
PROJECT_NAME     = sleep

# ----- Source code------------------------------------------------------------

include sdk.mk

# SYMBOLS += NDEBUG

INCLUDE_DIRS += ../libs
SOURCE_FILES += $(wildcard ../libs/xXx/os/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/support/*.cpp)
SOURCE_FILES += $(wildcard ../libs/xXx/utils/*.cpp)

INCLUDE_DIRS += src
INCLUDE_DIRS += src/config
SOURCE_FILES += $(wildcard src/*.cpp)

# ----- Libraries -------------------------------------------------------------

# LIBRARIES += arm_cortexM0l_math

# ----- Flags -----------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

COMMON_CFLAGS += -g
COMMON_CFLAGS += -Og

CFLAGS += -std=gnu11

CXXFLAGS += -std=gnu++14

CPPFLAGS +=

LDFLAGS +=

# ----- Rules -----------------------------------------------------------------

include ../libs/xXx/utils/rules.mk

download: $(EXECUTABLE)
	arm-none-eabi-gdb -q -x download.gdb $<
