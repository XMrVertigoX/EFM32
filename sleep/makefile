# ----- Configuration ---------------------------------------------------------

include config.mk

PROJECT_NAME = sleep

# ----- Sources ---------------------------------------------------------------

include sdk.mk

# SYMBOLS += NDEBUG

INCLUDES += ../libs
SOURCES += $(wildcard ../libs/xXx/support/*.cpp)
SOURCES += $(wildcard ../libs/xXx/utils/*.cpp)

INCLUDES += src
INCLUDES += src/config
SOURCES += $(wildcard src/*.cpp)

# ----- Libraries -------------------------------------------------------------

LIBS += arm_cortexM0l_math

# ----- Flags -----------------------------------------------------------------

GCCFLAGS += -march=armv6-m
GCCFLAGS += -mtune=cortex-m0plus
GCCFLAGS += -mthumb

COMMON = -Og -g -fdata-sections -ffunction-sections -fno-exceptions -fno-unwind-tables -fno-builtin

CFLAGS += $(COMMON)
CFLAGS += -std=gnu11

CXXFLAGS += $(COMMON)
CXXFLAGS += -std=gnu++14
CXXFLAGS += -fno-rtti
CXXFLAGS += -fno-threadsafe-statics

# CPPFLAGS +=

LDFLAGS += --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections

# ----- Rules -----------------------------------------------------------------

include rules.mk
